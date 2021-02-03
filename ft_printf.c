/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:55:40 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/01 17:26:02 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf		pf;

	if (!ft_contains_char((char *)format, '%'))
		return (ft_putstr(format));
	ft_init_pf(&pf, format);
	va_start(pf.params, format);
	ft_parse_pf(&pf);
	return (ft_exit_pf(&pf));
}
