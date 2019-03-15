/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_di_string_part_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:34:27 by bsprigga          #+#    #+#             */
/*   Updated: 2019/02/06 13:20:33 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_zero_di(char **str)
{
	int		i;
	int		j;
	char	sign;

	sign = 0;
	if (g_f->curr_flags[4]
	&& (g_f->width_value < g_f->prec_value || g_f->prec_value < 0))
	{
		i = -1;
		while (ft_strchr("+- ", (*str)[++i]))
			if (ft_strchr("+-", (*str)[i]))
				sign = (*str)[i];
		j = 0;
		if (sign || g_f->curr_flags[2])
		{
			if (sign)
				(*str)[0] = sign;
			else if (g_f->curr_flags[2])
				(*str)[0] = ' ';
			j++;
		}
		while (j < i)
			(*str)[j++] = '0';
	}
}
