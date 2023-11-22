/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:18 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/22 19:41:32 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Init RGBa
t_color	rgb(int r, int g, int b)
{
	static t_color	c;

	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	c.r = r << FIXED_BIT_FRAC;
	c.g = g << FIXED_BIT_FRAC;
	c.b = b << FIXED_BIT_FRAC;
	return (c);
}

void	set_color(t_color *dst, t_color c)
{
	dst->r = c.r;
	dst->g = c.g;
	dst->b = c.b;
}

void	color_invrt(t_color *dst)
{
	dst->r = (255 << FIXED_BIT_FRAC) - dst->r;
	dst->g = (255 << FIXED_BIT_FRAC) - dst->g;
	dst->b = (255 << FIXED_BIT_FRAC) - dst->b;
}

void	color_add(t_color *dst, t_color c)
{
	dst->r = dst->r + c.r;
	dst->g = dst->g + c.g;
	dst->b = dst->b + c.b;
	if (dst->r > (255 << FIXED_BIT_FRAC))
		dst->r = 255 << FIXED_BIT_FRAC;
	if (dst->g > (255 << FIXED_BIT_FRAC))
		dst->g = 255 << FIXED_BIT_FRAC;
	if (dst->r > (255 << FIXED_BIT_FRAC))
		dst->r = 255 << FIXED_BIT_FRAC;
}

void	color_sub(t_color *dst, t_color c)
{
	dst->r -= c.r;
	dst->g -= c.g;
	dst->b -= c.b;
	if (dst->r < 0)
		dst->r = 0;
	if (dst->g < 0)
		dst->g = 0;
	if (dst->b < 0)
		dst->b = 0;
}

void	color_mult_norm(t_color *dst, double magnitude)
{
	if (magnitude > 1)
		magnitude = 1;
	else if (magnitude < 0)
		magnitude = 0;
	dst->r *= magnitude;
	dst->g *= magnitude;
	dst->b *= magnitude;
}

unsigned int	rgb_to_hex(t_color c)
{
	return (
		(c.r >> FIXED_BIT_FRAC << 24) +
		(c.g >> FIXED_BIT_FRAC << 16) +
		(c.b >> FIXED_BIT_FRAC << 8) +
		(255 >> FIXED_BIT_FRAC)
	);
}

// Canvas drawing utilities

void	putpixel(t_mlx *window, int x, int y, t_color c)
{
	unsigned char	*pixel_addr;
	unsigned int	color;

	color = rgb_to_hex(c);
	if (!window->canvas.buff || x < 0 || x > window->width ||
			y < 0 || y > window->height)
		return ;
	pixel_addr = window->canvas.buff + (
			y * window->canvas.ln_bytes) + (x << 2);
	if (!window->canvas.endian)
	{
		*pixel_addr = (color >> 8) & 0xff;
		*(pixel_addr + 1) = (color >> 16) & 0xff;
		*(pixel_addr + 2) = (color >> 24) & 0xff;
		*(pixel_addr + 3) = color & 0xff;
		return ;
	}
	*pixel_addr = (color >> 24) & 0xff;
	*(pixel_addr + 1) = (color >> 16) & 0xff;
	*(pixel_addr + 2) = (color >> 8) & 0xff;
	*(pixel_addr + 3) = color & 0xff;
}

t_color	*getpixel(t_mlx *window, int x, int y)
{
	unsigned char	*pixel_addr;
	static t_color	c;

	if (!window->canvas.buff || x < 0 || x > window->width ||
			y < 0 || y > window->height)
		return (NULL);
	pixel_addr = window->canvas.buff + (
			y * window->canvas.ln_bytes) + (x << 2);
	if (!window->canvas.endian)
		c = rgb(*(pixel_addr + 2), *(pixel_addr + 1), *pixel_addr);
	else
		c = rgb(*pixel_addr, *(pixel_addr + 1), *(pixel_addr + 2));
	return &c;
}

