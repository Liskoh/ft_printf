/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:16:20 by hjordan           #+#    #+#             */
/*   Updated: 2021/01/20 16:44:59 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i])
		i++;
	return (i);
}
