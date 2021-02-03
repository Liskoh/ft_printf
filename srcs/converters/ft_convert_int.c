/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:53:44 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 12:58:12 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int				ft_apply_int_width(
	t_printf *pf, char *itoa, int negative)
{
	int			width;
	int			len;

	len = ft_strlen(itoa);
	len--;
	if (negative)
		len++;
	width = (pf->width < 0) ? -pf->width : pf->width;
	if (pf->width <= 0)
	{
		if (negative)
			pf->additional_size += ft_putchar('-');
		pf->additional_size += ft_putstr(itoa);
		while (++len < width)
			pf->additional_size += ft_putchar(' ');
		return (TRUE);
	}
	if (negative && pf->contains_zero)
		pf->additional_size += ft_putchar('-');
	while (++len < width)
		pf->additional_size += ft_putchar(pf->contains_zero ? '0' : ' ');
	if (negative && !pf->contains_zero)
		pf->additional_size += ft_putchar('-');
	pf->additional_size += ft_putstr(itoa);
	return (TRUE);
}

static int				ft_apply_only_precision(
	t_printf *pf, char *itoa, int negative, int silent)
{
	int				len;

	len = ft_strlen(itoa);
	if (negative && !silent)
		pf->additional_size += ft_putchar('-');
	while (len < pf->precision)
	{
		if (!silent)
			pf->additional_size += ft_putchar('0');
		len++;
	}
	if (!silent)
		pf->additional_size += ft_putstr(itoa);
	if (silent && negative)
		len++;
	return (len);
}

static int				ft_apply_prec_p_width(
	t_printf *pf, int negative, char *itoa, int i)
{
	int		size;

	size = ft_apply_only_precision(pf, itoa, negative, TRUE);
	while (pf->width > size)
	{
		if (pf->contains_zero && pf->precision != 0)
		{
			pf->additional_size += ft_putchar(' ');
		}
		else
			pf->additional_size += ft_putchar(' ');
		pf->width--;
	}
	if (i == 0 && pf->precision == 0)
		pf->additional_size += ft_putchar(' ');
	else
		ft_apply_only_precision(pf, itoa, negative, FALSE);
	return (TRUE);
}

static int				ft_apply_prec_width(
	t_printf *pf, char *itoa, int negative, int i)
{
	int				size;

	size = ft_apply_only_precision(pf, itoa, negative, TRUE);
	if (pf->contains_precision && pf->contains_zero &&
		pf->precision < 0 && pf->width != 0 && pf->precision < pf->width)
	{
		pf->precision = (negative ? pf->width - 1 : pf->width);
		pf->width = 0;
	}
	if (pf->width >= 0)
		ft_apply_prec_p_width(pf, negative, itoa, i);
	else
	{
		if (i == 0 && pf->precision == 0)
			pf->additional_size += ft_putchar(' ');
		else
			ft_apply_only_precision(pf, itoa, negative, FALSE);
		pf->width = -pf->width;
		while (pf->width > size)
		{
			pf->additional_size += ft_putchar(' ');
			pf->width--;
		}
	}
	return (TRUE);
}

int						ft_convert_int(t_printf *pf, int i)
{
	char			*itoa;
	int				negative;

	negative = FALSE;
	if (pf->contains_precision && pf->precision == 0
		&& i == 0 && pf->precision == 0 && pf->width == 0)
		return (TRUE);
	negative = (i < 0 ? TRUE : FALSE);
	if (i < 0 && i != INT_MIN)
		i = -i;
	if (!(itoa = ft_init_itoa(i)))
		return (FALSE);
	if (!pf->contains_precision && pf->width != 0)
		ft_apply_int_width(pf, itoa, negative);
	else if (!pf->contains_precision && pf->width == 0)
	{
		if (negative)
			pf->additional_size += ft_putchar('-');
		pf->additional_size += ft_putstr(itoa);
	}
	else if (pf->contains_precision && pf->width == 0)
		ft_apply_only_precision(pf, itoa, negative, FALSE);
	else if (pf->contains_precision && pf->width != 0)
		ft_apply_prec_width(pf, itoa, negative, i);
	return (ft_str_del(&itoa));
}
