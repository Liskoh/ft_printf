/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:51:05 by hjordan           #+#    #+#             */
/*   Updated: 2021/01/28 17:24:35 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int				ft_get_size(long int nb)
{
	int			size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size = 1;
	}
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char					*ft_itoa(int nb)
{
	char		*itoa;
	int			size;
	int			negative;

	if (nb == 0)
		return (ft_strdup("0"));
	size = ft_get_size(nb);
	negative = (nb < 0 ? TRUE : FALSE);
	nb = (nb < 0 ? -nb : nb);
	if (!(itoa = malloc((size + 1) * sizeof(char))))
		return (NULL);
	itoa[size] = '\0';
	while (--size)
	{
		itoa[size] = nb % 10 + '0';
		nb /= 10;
	}
	itoa[0] = (negative ? '-' : nb % 10 + '0');
	return (itoa);
}
