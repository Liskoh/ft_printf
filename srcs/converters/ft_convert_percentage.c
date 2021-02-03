/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percentage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:48:40 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 12:58:14 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int			ft_apply_width(t_printf *pf)
{
	int		width;
	int		i;

	i = 1;
	width = pf->width;
	width = (width < 0 ? -width : width);
	while (i < width)
	{
		pf->additional_size += ft_putchar(pf->contains_zero ? '0' : ' ');
		i++;
	}
	return (TRUE);
}

int					ft_convert_percentage(t_printf *pf)
{
	int		width;

	width = pf->width;
	if (width >= 0)
	{
		ft_apply_width(pf);
		pf->additional_size += ft_putchar('%');
	}
	else
	{
		pf->additional_size += ft_putchar('%');
		ft_apply_width(pf);
	}
	return (TRUE);
}
