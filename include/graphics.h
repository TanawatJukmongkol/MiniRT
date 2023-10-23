
#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "../lib/mlx/mlx.h"
#include "../lib/mlx/mlx_int.h"
#include "math.h"

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

typedef struct s_color
{
	t_fixed_pt L;
	t_fixed_pt A;
	t_fixed_pt B;
}				t_color;

// Canvas
int				init_canvas(t_mlx *window, char *title, int w, int h);
void			update_canvas(t_mlx *window);
void			putpixel(t_mlx *window, int x, int y, int unsigned color);

// Color
unsigned int	rgba_to_hex(int r, int g, int b, int alpha);
unsigned int	oklab_to_hex(t_color *oklab);

// Colorspace conversion (Image pre-processing)
t_color			rgba_to_colorspace(int r, int g, int b, int alpha);

#endif
