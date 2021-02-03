/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_size_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:15:46 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 14:31:37 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				ft_apply_size_converter(t_printf *pf, unsigned long long **ptr)
{
	unsigned long long			size;

	size = pf->additional_size;
	*ptr = (unsigned long long *)size;
	return (TRUE);
}
