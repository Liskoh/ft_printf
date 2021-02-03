/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:27:57 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 14:33:32 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_init_pf(t_printf *pf, const char *format)
{
	pf->content = ft_strdup((char *)format);
	pf->i = 0;
	pf->width = 0;
	pf->precision = 0;
	pf->additional_size = 0;
	pf->type = NONE;
	pf->negative = FALSE;
	pf->contains_precision = FALSE;
	pf->contains_zero = FALSE;
}

void		ft_reset_pf(t_printf *pf)
{
	pf->width = 0;
	pf->precision = 0;
	pf->type = NONE;
	pf->negative = FALSE;
	pf->contains_zero = FALSE;
	pf->contains_precision = FALSE;
}

int			ft_exit_pf(t_printf *pf)
{
	va_end(pf->params);
	ft_reset_pf(pf);
	ft_str_del(&pf->content);
	return (pf->additional_size);
}

int			ft_contains_char(char *s, char c)
{
	int			i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (TRUE);
	return (FALSE);
}
