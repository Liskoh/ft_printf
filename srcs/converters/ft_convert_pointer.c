/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 06:39:01 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/03 13:36:19 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void				ft_put_ptr(t_printf *pf, char *itoa, int null_ptr)
{
	if (null_ptr)
		pf->additional_size += ft_putstr(
		pf->contains_precision && pf->precision == 0 ? "0x" : "0x0");
	else
	{
		pf->additional_size += ft_putstr("0x");
		pf->additional_size += ft_putstr(itoa);
	}
}

int						ft_apply_ptr_width(
	t_printf *pf, char *itoa, int null_ptr)
{
	int			width;
	int			len;
	int			size;

	size = (null_ptr && pf->contains_precision && pf->precision == 0 ? 2 : 3);
	len = null_ptr ? size : ft_strlen(itoa) + 2;
	len--;
	width = (pf->width < 0) ? -pf->width : pf->width;
	if (null_ptr && pf->width == 0
		&& pf->contains_precision && pf->precision == 0)
		return (pf->additional_size += ft_putstr("0x"));
	if (pf->width <= 0)
	{
		ft_put_ptr(pf, itoa, null_ptr);
		while (++len < width)
			pf->additional_size += ft_putchar(' ');
		return (TRUE);
	}
	while (++len < width)
		pf->additional_size += ft_putchar(' ');
	ft_put_ptr(pf, itoa, null_ptr);
	return (TRUE);
}

static int				ft_apply_only_precision(
	t_printf *pf, char *itoa, int null_ptr, int silent)
{
	int			len;

	len = (null_ptr ? 1 : ft_strlen(itoa));
	if (!silent)
		pf->additional_size += ft_putstr("0x");
	while (len++ < pf->precision)
		if (!silent)
			pf->additional_size += ft_putchar('0');
	if (!silent)
		pf->additional_size += ft_putstr(null_ptr ? "0" : itoa);
	return (len + 1);
}

static int				ft_apply_wp(t_printf *pf, char *itoa, int null_ptr)
{
	int					size;

	size = ft_apply_only_precision(pf, itoa, null_ptr, TRUE);
	if (pf->width >= 0)
	{
		while (size < pf->width)
		{
			pf->additional_size += ft_putchar(' ');
			size++;
		}
		ft_apply_only_precision(pf, itoa, null_ptr, FALSE);
	}
	else
	{
		ft_apply_only_precision(pf, itoa, null_ptr, FALSE);
		pf->width = -pf->width;
		while (size < pf->width)
		{
			pf->additional_size += ft_putchar(' ');
			size++;
		}
	}
	return (TRUE);
}

int						ft_convert_pointer(t_printf *pf, void *ptr)
{
	char		*itoa;
	int			null_ptr;

	null_ptr = FALSE;
	if (ptr == NULL || (long int)ptr == 0)
		null_ptr = TRUE;
	if (!null_ptr)
		if (!(itoa = ft_ltoa_base((long int)ptr, HEXA_LOWER)))
			return (FALSE);
	if ((pf->width == 0 && !pf->contains_precision)
		|| (pf->contains_precision && pf->precision <= 0))
	{
		if (pf->contains_precision && pf->precision == 0)
			ft_apply_ptr_width(pf, itoa, null_ptr);
		else
			ft_put_ptr(pf, itoa, null_ptr);
	}
	else if (pf->width != 0 && !pf->contains_precision)
		ft_apply_ptr_width(pf, itoa, null_ptr);
	else if (pf->width == 0 && pf->contains_precision)
		ft_apply_only_precision(pf, itoa, null_ptr, FALSE);
	else if (pf->width != 0 && pf->contains_precision)
		ft_apply_wp(pf, itoa, null_ptr);
	return ((!null_ptr ? ft_str_del(&itoa) : TRUE));
}
