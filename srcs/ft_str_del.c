/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 08:12:57 by hjordan           #+#    #+#             */
/*   Updated: 2021/01/26 10:48:40 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_str_del(char **str)
{
	if (str == NULL)
		return (TRUE);
	free(*str);
	*str = NULL;
	return (TRUE);
}
