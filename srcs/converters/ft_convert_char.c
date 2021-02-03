/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:37:51 by hjordan           #+#    #+#             */
/*   Updated: 2021/01/20 17:10:46 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_put_width(t_printf *pf, char c)
{
	int			i;
	int			width;

	width = pf->width;
	i = 0;
	if (width != 0)
		(width - 1 >= 0 ? width-- : width++);
	if (width < 0)
		width = -width;
	while (i < width)
	{
		pf->additional_size += ft_putchar(c);
		i++;
	}
	return (TRUE);
}

int				ft_convert_char(t_printf *pf, char c)
{
	if (pf->width <= 0)
	{
		pf->additional_size += ft_putchar(c);
		ft_put_width(pf, ' ');
	}
	else
	{
		ft_put_width(pf, ' ');
		pf->additional_size += ft_putchar(c);
	}
	return (TRUE);
}
