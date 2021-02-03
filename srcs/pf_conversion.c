/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:31:16 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 13:08:59 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_apply_d_norme(t_printf *pf, char *str, int is_width)
{
	if (is_width)
		pf->width = (pf->negative ? -ft_atoi(str) : ft_atoi(str));
	else
		pf->precision = ft_atoi(str);
	ft_str_del(&str);
	return (TRUE);
}

int				ft_apply_digits(t_printf *pf, int is_width)
{
	int			size;
	char		*str;
	int			last_index;

	size = 0;
	last_index = pf->i;
	while (pf->content[pf->i] && ft_is_integer(pf->content[pf->i]))
	{
		size++;
		pf->i++;
	}
	pf->i = last_index;
	if (!(str = malloc((size + 1) * sizeof(char))))
		return (FALSE);
	size = 0;
	while (pf->content[pf->i] && ft_is_integer(pf->content[pf->i]))
	{
		str[size] = pf->content[pf->i];
		size++;
		pf->i++;
	}
	str[size] = '\0';
	return (ft_apply_d_norme(pf, str, is_width));
}

void			ft_apply_stars(t_printf *pf)
{
	int width;

	width = va_arg(pf->params, int);
	if (pf->negative && width > 0)
		width = -width;
	pf->width = width;
}

void			ft_apply_precision(t_printf *pf)
{
	pf->i++;
	pf->contains_precision = TRUE;
	if (pf->content[pf->i] == '*')
		pf->precision = va_arg(pf->params, int);
	else
		ft_apply_digits(pf, FALSE);
}
