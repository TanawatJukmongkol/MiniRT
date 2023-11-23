
#include "minirt.h"

#ifndef __APPLE__

int	ft_destroy_display(t_glob *g)
{
	return (mlx_destroy_display(g->mlx.mlx));
}

#else

int	ft_destroy_display(t_glob *g)
{
	(void)g;
	return (0);
}

#endif
