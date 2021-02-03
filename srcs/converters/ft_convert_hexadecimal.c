/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 07:16:40 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 13:11:22 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int				ft_apply_hex_width(
	t_printf *pf, char *itoa)
{
	int			width;
	int			len;

	len = ft_strlen(itoa);
	len--;
	width = (pf->width < 0) ? -pf->width : pf->width;
	if (pf->width <= 0)
	{
		pf->additional_size += ft_putstr(itoa);
		while (++len < width)
			pf->additional_size += ft_putchar(' ');
		return (TRUE);
	}
	while (++len < width)
		pf->additional_size += ft_putchar(pf->contains_zero ? '0' : ' ');
	pf->additional_size += ft_putstr(itoa);
	return (TRUE);
}

static int				ft_apply_only_precision(
	t_printf *pf, char *itoa, int silent)
{
	int				len;

	len = ft_strlen(itoa);
	while (len < pf->precision)
	{
		if (!silent)
			pf->additional_size += ft_putchar('0');
		len++;
	}
	if (!silent)
		pf->additional_size += ft_putstr(itoa);
	return (len);
}

static int				ft_apply_prec_p_width(
	t_printf *pf, char *itoa, int i)
{
	int		size;

	size = ft_apply_only_precision(pf, itoa, TRUE);
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
		ft_apply_only_precision(pf, itoa, FALSE);
	return (TRUE);
}

static int				ft_apply_prec_width(
	t_printf *pf, char *itoa, int i)
{
	int				size;

	size = ft_apply_only_precision(pf, itoa, TRUE);
	if (pf->contains_precision && pf->contains_zero &&
		pf->precision < 0 && pf->width != 0 && pf->precision < pf->width)
	{
		pf->precision = pf->width;
		pf->width = 0;
	}
	if (pf->width >= 0)
		ft_apply_prec_p_width(pf, itoa, i);
	else
	{
		if (i == 0 && pf->precision == 0)
			pf->additional_size += ft_putchar(' ');
		else
			ft_apply_only_precision(pf, itoa, FALSE);
		pf->width = -pf->width;
		while (pf->width > size)
		{
			pf->additional_size += ft_putchar(' ');
			pf->width--;
		}
	}
	return (TRUE);
}

int						ft_convert_hexadecimal(t_printf *pf, int i)
{
	char			*itoa;
	char			*base;

	if (pf->contains_precision && pf->precision == 0
		&& i == 0 && pf->precision == 0 && pf->width == 0)
		return (TRUE);
	base = (pf->type == HEXADECIMAL_UPPER ? HEXA_UPPER : HEXA_LOWER);
	if (!(itoa = ft_itoa_base(i, base)))
		return (FALSE);
	if (!pf->contains_precision && pf->width != 0)
		ft_apply_hex_width(pf, itoa);
	else if (!pf->contains_precision && pf->width == 0)
	{
		pf->additional_size += ft_putstr(itoa);
	}
	else if (pf->contains_precision && pf->width == 0)
		ft_apply_only_precision(pf, itoa, FALSE);
	else if (pf->contains_precision && pf->width != 0)
		ft_apply_prec_width(pf, itoa, i);
	return (ft_str_del(&itoa));
}
