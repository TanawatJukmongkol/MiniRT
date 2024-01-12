/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:16 by tjukmong          #+#    #+#             */
/*   Updated: 2024/01/10 16:36:25 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_fixed_pt	double_to_fixed(double num)
{
	return (round(num * (1LL << FIXED_BIT_FRAC)));
}

double	fixed_to_double(t_fixed_pt num)
{
	return (round((double)num * 10e4 / (1LL << FIXED_BIT_FRAC)) / 10e4);
}

t_fixed_pt	fixed_mult(t_fixed_pt a, t_fixed_pt b)
{
	return ((a * b) >> FIXED_BIT_FRAC);
}
