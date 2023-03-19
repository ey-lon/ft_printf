/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 14:03:02 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_put_long_hex(long unsigned int n)
{
	if (n >= 16)
	{
		ft_put_long_hex(n / 16);
		n = n % 16;
	}
	if (n >= 10)
		n = n - 10 + 'a';
	else
		n = n + '0';
	write(1, &n, 1);
}

static int	ft_ptr_len(long unsigned int n)
{
	int	len;

	if (!n)
		len = 5;
	else
	{
		len = 3;
		while (n >= 16)
		{
			n = n / 16;
			len++;
		}
	}
	return (len);
}

static int	ft_ptr_symbol(t_ptf ptf, long unsigned int n, int x)
{
	int	len;

	len = 0;
	if (ft_flag_check(ptf.flags, PTF_SPACE))
	{
		len++;
		if (x == 0)
			write(1, " ", 1);
	}
	if (ft_flag_check(ptf.flags, PTF_PLUS) && n >= 0)
	{
		len++;
		if ((ft_flag_check(ptf.flags, PTF_ZERO) && x == 0) \
			|| (!ft_flag_check(ptf.flags, PTF_ZERO) && x == 1))
			write(1, "+", 1);
	}
	if ((ft_flag_check(ptf.flags, PTF_ZERO) && x == 0) \
			|| (!ft_flag_check(ptf.flags, PTF_ZERO) && x == 1))
		write(1, "0x", 2);
	return (len);
}

int	ft_print_ptr(long unsigned int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	len = ft_ptr_len(n);
	print_len = len;
	ptf.prec_count = ft_n_of(len, ptf.prec_count);
	ptf.pad_count = ft_n_of(len + ptf.prec_count, ptf.pad_count);
	if (n)
		ptf.pad_count -= ft_ptr_symbol(ptf, n, 0);
	else
		ptf.pad = ' ';
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	if (n)
		print_len += ft_ptr_symbol(ptf, n, 1);
	print_len += ft_print_special('0', ptf.prec_count);
	if (n)
		ft_put_long_hex(n);
	else
		write(1, "(nil)", 5);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	return (print_len);
}
