/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 09:49:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_put_hex(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		n = n % 16;
	}
	if (n >= 10)
	{
		if (format == 'X')
			n = n + 'A' - 10;
		else
			n = n + 'a' - 10;
	}
	else
		n = n + '0';
	write(1, &n, 1);
}

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	len = ft_hex_len(n);
	print_len = len;
	ptf.prec_count = ft_n_of(len, ptf.prec_count);
	ptf.pad_count = ft_n_of(len + ptf.prec_count, ptf.pad_count);
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	print_len += ft_print_special('0', ptf.prec_count);
	ft_put_hex(n, ptf.format);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	return (print_len);
}
