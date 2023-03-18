/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/18 17:21:44 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	n = n + '0';
	write(1, &n, 1);
}

static int	ft_int_len(int n)
{
	int	len;

	if (n == -2147483648)
		len = 10;
	else
	{
		len = 1;
		if (n < 0)
			n = -n;
		while (n >= 10)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

static int	ft_dec_no_min(int n, int len, t_ptf ptf)
{
	int	print_len;

	print_len = 0;
	if (n < 0)
	{
		print_len += ft_print_special(ptf.pad, \
			ptf.pad_count - (len + 1) - ft_quant(len, ptf.prec_count));
		print_len += write(1, "-", 1);
	}
	else if (ft_flag_check(ptf.flags, PTF_PLUS))
	{
		print_len += ft_print_special(ptf.pad, \
			ptf.pad_count - (len + 1) - ft_quant(len, ptf.prec_count));
		print_len += write(1, "+", 1);
	}
	else
		print_len += ft_print_special(ptf.pad, \
			ptf.pad_count - len - ft_quant(len, ptf.prec_count));
	print_len += ft_print_special('0', ptf.prec_count - len);
	ft_putnbr(n);
	return (print_len);
}

static int	ft_dec_min(int n, int len, t_ptf ptf)
{
	int	print_len;

	print_len = 0;
	if (ft_flag_check(ptf.flags, PTF_PLUS))
		print_len += write(1, "+", 1);
	print_len += ft_print_special('0', ptf.prec_count - len);
	ft_putnbr(n);
	print_len += ft_print_special(ptf.pad, ptf.pad_count - (len + print_len));
	return (print_len);
}

int	ft_print_dec(int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	len = ft_int_len(n);
	print_len = len;
	if (ft_flag_check(ptf.flags, PTF_SPACE) \
		&& !ft_flag_check(ptf.flags, PTF_PLUS))
	{
		print_len += write(1, &ptf.pad, 1);
		if (!ft_flag_check(' ', PTF_MINUS))
			ptf.pad_count--;
	}
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_dec_no_min(n, len, ptf);
	else
		print_len += ft_dec_min(n, len, ptf);
	return (print_len);
}
