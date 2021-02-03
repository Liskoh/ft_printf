/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:11:18 by hjordan           #+#    #+#             */
/*   Updated: 2021/01/20 16:42:48 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_addr_del(void **ptr)
{
	if (ptr != NULL)
		return (TRUE);
	free(*ptr);
	*ptr = NULL;
	return (TRUE);
}
