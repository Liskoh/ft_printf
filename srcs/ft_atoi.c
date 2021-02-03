/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:11:03 by hjordan           #+#    #+#             */
/*   Updated: 2021/01/20 16:42:59 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_init_vars(int *idx, long int *result, int *size, int *neg)
{
	*idx = 0;
	*neg = 0;
	*result = 0;
	*size = 0;
}

int			ft_set_result(int size, int neg, int result)
{
	if (size >= 20)
		return (neg ? 0 : -1);
	return ((neg) ? result * -1 : result);
}

int			ft_atoi(const char *str)
{
	int			idx;
	long int	result;
	int			size;
	int			neg;

	ft_init_vars(&idx, &result, &size, &neg);
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
		{
			neg = 1;
			size++;
		}
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result = result * 10 + str[idx] - '0';
		idx++;
		size++;
	}
	return (ft_set_result(size, neg, result));
}
