/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:53 by tjukmong          #+#    #+#             */
/*   Updated: 2023/09/05 00:53:04 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../lib/mlx/mlx_int.h"
#include "../lib/libft/libft.h"
#include <X11/X.h>

typedef struct s_canvas
{
	void	*ptr;
	void	*buff;
	int		px_bits;
	int		ln_bytes;
	int		endian;
}				t_canvas;

typedef struct s_mlx
{
	char		*title;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_canvas	canvas;
}				t_mlx;

int				init_canvas(t_mlx *window, char *title, int w, int h);
void			update_canvas(t_mlx *window);
unsigned int	rgba_to_hex(int r, int g, int b, int alpha);
void			putpixel(t_mlx *window, int x, int y, int unsigned color);
