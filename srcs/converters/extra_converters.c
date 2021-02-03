/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:41:10 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 14:30:15 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_init_itoa(int i)
{
	char *itoa;

	if (i == INT_MIN)
	{
		if (!(itoa = ft_strdup("2147483648")))
			return (NULL);
	}
	else
	{
		if (!(itoa = ft_itoa(i)))
			return (NULL);
	}
	return (itoa);
}

char		*ft_init_unsigned_itoa(unsigned int i)
{
	char *itoa;

	if ((int)i == INT_MIN)
	{
		if (!(itoa = ft_strdup("2147483648")))
			return (NULL);
	}
	else
	{
		if (!(itoa = ft_unsigned_itoa(i)))
			return (NULL);
	}
	return (itoa);
}
