/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:05:14 by hjordan           #+#    #+#             */
/*   Updated: 2021/02/02 14:00:12 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			ft_get_itoa_size(unsigned int n, char *base)
{
	int				i;
	int				base_len;

	i = 0;
	base_len = ft_strlen(base);
	while (n)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

static char			*ft_fill_itoa
	(unsigned int n, char *base, int size, char *itoa)
{
	int				base_len;

	base_len = ft_strlen(base);
	while (n)
	{
		itoa[--size] = base[n % base_len];
		n /= base_len;
	}
	return (itoa);
}

char				*ft_itoa_base(int n, char *base)
{
	char			*itoa;
	int				size;
	unsigned int	nb;

	nb = (unsigned int)n;
	size = ft_get_itoa_size(nb, base);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(itoa = malloc((size + 1) * sizeof(char))))
		return (NULL);
	itoa[size] = '\0';
	return (ft_fill_itoa(n, base, size, itoa));
}
