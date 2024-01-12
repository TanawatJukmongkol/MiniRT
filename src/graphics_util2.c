/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:53:39 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 17:02:04 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_mult_norm(t_color dst, double magnitude)
{
	if (magnitude > 1)
		magnitude = 1;
	else if (magnitude < 0)
		magnitude = 0;
	dst.r *= magnitude;
	dst.g *= magnitude;
	dst.b *= magnitude;
	return (dst);
}

unsigned int	rgb_to_hex(t_color c)
{
	return (
		(c.r >> FIXED_BIT_FRAC << 24)
		+ (c.g >> FIXED_BIT_FRAC << 16)
		+ (c.b >> FIXED_BIT_FRAC << 8)
		+ (255 >> FIXED_BIT_FRAC)
	);
}

// Canvas drawing utilities

void	putpixel(t_mlx *window, int x, int y, t_color c)
{
	unsigned char	*pixel_addr;
	unsigned int	color;

	color = rgb_to_hex(c);
	if (!window->canvas.buff || x < 0 || x > window->width
		|| y < 0 || y > window->height)
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

	if (!window->canvas.buff || x < 0 || x > window->width
		|| y < 0 || y > window->height)
		return (NULL);
	pixel_addr = window->canvas.buff + (
			y * window->canvas.ln_bytes) + (x << 2);
	if (!window->canvas.endian)
		c = rgb(*(pixel_addr + 2), *(pixel_addr + 1), *pixel_addr);
	else
		c = rgb(*pixel_addr, *(pixel_addr + 1), *(pixel_addr + 2));
	return (&c);
}
