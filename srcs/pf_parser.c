/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:32:10 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 14:28:28 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_perform_pf(t_printf *pf)
{
	while (pf->content[pf->i] && ft_is_pf_char(pf->content[pf->i]))
	{
		if (pf->content[pf->i] == '0' && pf->width == 0 && !pf->negative)
			pf->contains_zero = TRUE;
		if (pf->content[pf->i] == '*')
			ft_apply_stars(pf);
		if (ft_is_integer(pf->content[pf->i]) && pf->content[pf->i] != '0')
			ft_apply_digits(pf, TRUE);
		if (pf->content[pf->i] == '.')
			ft_apply_precision(pf);
		if (pf->content[pf->i] == '-')
		{
			pf->negative = TRUE;
			pf->contains_zero = FALSE;
		}
		if (ft_is_conversion(pf->content[pf->i]))
		{
			pf->type = ft_get_type_by_char(pf->content[pf->i]);
			ft_convert_by_flags(pf);
			break ;
		}
		pf->i++;
	}
	return (TRUE);
}

void			ft_parse_pf(t_printf *pf)
{
	while (pf->content[pf->i])
	{
		if (pf->content[pf->i] == PERCENTAGE)
		{
			ft_reset_pf(pf);
			if (pf->content[pf->i + 1] && ft_is_pf_char(pf->content[pf->i + 1]))
			{
				pf->i++;
				ft_perform_pf(pf);
			}
		}
		else
			pf->additional_size += ft_putchar(pf->content[pf->i]);
		pf->i++;
	}
}

t_type			ft_get_type_by_char(char c)
{
	if (c == 'c')
		return (CHAR);
	else if (c == 's')
		return (STRING);
	else if (c == 'd' || c == 'i')
		return (INTEGER);
	else if (c == 'u')
		return (UNSIGNED_INTEGER);
	else if (c == 'x')
		return (HEXADECIMAL_LOWER);
	else if (c == 'X')
		return (HEXADECIMAL_UPPER);
	else if (c == 'p')
		return (POINTER);
	else if (c == '%')
		return (PERCENT);
	else if (c == 'n')
		return (SIZE);
	return (NONE);
}

void			ft_convert_by_flags(t_printf *pf)
{
	t_type		type;

	type = pf->type;
	if (type == CHAR)
		ft_convert_char(pf, va_arg(pf->params, int));
	else if (type == INTEGER)
		ft_convert_int(pf, va_arg(pf->params, int));
	else if (type == STRING)
		ft_convert_string(pf, va_arg(pf->params, char *));
	else if (type == UNSIGNED_INTEGER)
		ft_convert_unsigned_int(pf, va_arg(pf->params, unsigned int));
	else if (type == PERCENT)
		ft_convert_percentage(pf);
	else if (type == HEXADECIMAL_LOWER || type == HEXADECIMAL_UPPER)
		ft_convert_hexadecimal(pf, va_arg(pf->params, int));
	else if (type == POINTER)
		ft_convert_pointer(pf, va_arg(pf->params, void *));
	else if (type == SIZE)
		ft_apply_size_converter(pf,
			(unsigned long long **)va_arg(pf->params, void **));
}
