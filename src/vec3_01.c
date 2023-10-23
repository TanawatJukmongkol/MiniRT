/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:30:44 by tjukmong          #+#    #+#             */
/*   Updated: 2023/10/07 19:30:02 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Fast Inverse Square Root using fixed point number and Newton's square root method
// The function was explained here: https://www.youtube.com/watch?v=p8u_k2LIZyo
t_fixed_pt	q_rsqrt(t_fixed_pt num)
{
	long long	i;
	double		x2;
	double		y;

	x2 = fixed_to_double(num >> 1);
	y = fixed_to_double(num);
	i = *(long long *)&y;
	i = 0x5f3759df - ( i >> 1 );
	y = y * ( 1.5F - (x2 * y * y));
	return (double_to_fixed(*(double *)&y));
}

