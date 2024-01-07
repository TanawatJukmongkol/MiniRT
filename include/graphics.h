
#ifndef GRAPHICS_H
# define GRAPHICS_H

// #include <OpenGL/gl.h>
#include "../lib/mlx/mlx.h"
// #include "../lib/mlx/mlx_int.h"
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
	char				*title;
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	double				aspect_ratio;
	unsigned long long	frame;
	t_canvas			canvas;
}				t_mlx;

typedef union u_color
{
	struct
	{
		t_fixed_pt		r;
		t_fixed_pt		g;
		t_fixed_pt		b;
	};
	t_fixed_pt			v[3];
}				t_color;

// Canvas
int				init_canvas(t_mlx *window, char *title, int w, int h);
int				update_canvas(t_mlx *window);
void			putpixel(t_mlx *window, int x, int y, t_color c);
t_color			*getpixel(t_mlx *window, int x, int y);

// Color
t_color			rgb(int r, int g, int b);
t_color			color_invrt(t_color dst);
void			set_color(t_color *dst, t_color c);
unsigned int	rgb_to_hex(t_color c);
t_color			color_add(t_color dst, t_color c);
t_color			color_sub(t_color dst, t_color c);
t_color			color_mult_norm(t_color dst, double magnitude);

#endif
