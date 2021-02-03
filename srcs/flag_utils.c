/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:38:41 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 14:11:19 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%' || c == 'n')
		return (TRUE);
	return (FALSE);
}

int			ft_is_integer(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int			ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (TRUE);
	return (FALSE);
}

int			ft_is_pf_char(char c)
{
	if (ft_is_conversion(c) || ft_is_flag(c) || ft_is_integer(c))
		return (TRUE);
	return (FALSE);
}
