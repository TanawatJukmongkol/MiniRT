/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:18 by tjukmong          #+#    #+#             */
/*   Updated: 2023/09/03 01:28:19 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	rgba_to_hex(int r, int g, int b, int alpha)
{
	return ((r << 24) + (g << 16) + (b << 8) + alpha);
}

void	putpixel(t_mlx *window, int x, int y, unsigned int color)
{
	unsigned char	*pixel_addr;

	pixel_addr = window->canvas.buff + (
			y * window->canvas.ln_bytes) + (x * 4);
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
