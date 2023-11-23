
#include "minirt.h"

#ifndef __APPLE__

int	ft_loop_end(t_glob *g)
{
	return (mlx_loop_end(g->mlx.mlx));
}

#else

int	ft_loop_end(t_glob *g)
{
	(void)g;
	return (0);
}

#endif
