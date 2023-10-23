/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:18 by tjukmong          #+#    #+#             */
/*   Updated: 2023/10/23 21:51:19 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Retina color space conversion (sRGB <-> OKLAB)

t_fixed_pt	gamma_to_lin(t_fixed_pt gamma)
{
	if (gamma >= double_to_fixed(0.04045))
		return (powl((gamma + double_to_fixed(0.055)) / double_to_fixed(1.055), double_to_fixed(2.4)));
	return (gamma / double_to_fixed(12.92));
}

// Format conversion (sRGBA <-> RGBA Hex)

unsigned int	rgba_to_hex(int r, int g, int b, int alpha)
{
	return ((r << 24) + (g << 16) + (b << 8) + alpha);
}

// Canvas drawing utilities

void	putpixel(t_mlx *window, int x, int y, unsigned int color)
{
	unsigned char	*pixel_addr;

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
