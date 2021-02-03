/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:35:34 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 13:10:03 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int				ft_apply_str_width(t_printf *pf, char *s, int len)
{
	int			width;

	if (len > 0)
		len--;
	width = (pf->width < 0) ? -pf->width : pf->width;
	if (pf->width <= 0)
	{
		pf->additional_size += ft_putstr(s);
		while (++len < width)
			pf->additional_size += ft_putchar(pf->contains_zero ? '0' : ' ');
		return (TRUE);
	}
	while (++len < width)
		pf->additional_size += ft_putchar(pf->contains_zero ? '0' : ' ');
	pf->additional_size += ft_putstr(s);
	return (TRUE);
}

static int				ft_apply_str_prec_pos(t_printf *pf, char *s, int i)
{
	while (++i < pf->precision && s[i])
		;
	pf->width = pf->width - i;
	i = -1;
	while (++i < pf->width)
		pf->additional_size += ft_putchar(' ');
	i = -1;
	while (++i < pf->precision && s[i])
		pf->additional_size += ft_putchar(s[i]);
	return (TRUE);
}

int						ft_apply_str_prec(t_printf *pf, char *s, int len)
{
	int			i;

	i = -1;
	if (pf->precision <= 0)
	{
		if (pf->precision < 0)
			return (ft_apply_str_width(pf, s, len));
		pf->width = (pf->width < 0 ? -pf->width : pf->width);
		while (++i < pf->width)
			pf->additional_size += ft_putchar(' ');
		return (TRUE);
	}
	if (pf->width <= 0)
	{
		pf->width = -pf->width;
		while (++i < pf->precision && s[i])
			pf->additional_size += ft_putchar(s[i]);
		i--;
		while (++i < pf->width)
			pf->additional_size += ft_putchar(' ');
	}
	else
		return (ft_apply_str_prec_pos(pf, s, i));
	return (TRUE);
}

int						ft_convert_string(t_printf *pf, char *s)
{
	int			len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if ((!pf->contains_precision ||
		(pf->contains_precision && pf->precision < 0)) && pf->width == 0)
		pf->additional_size += ft_putstr(s);
	else if (pf->width != 0 && !pf->contains_precision)
		ft_apply_str_width(pf, s, len);
	else if (pf->contains_precision)
		ft_apply_str_prec(pf, s, len);
	return (TRUE);
}
