/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:12 by abettini         ###   ########.fr       */
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

int	ft_print_ptr(long unsigned int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	len = ft_ptr_len(n);
	print_len = len;
	print_len += ft_print_special(ptf.pad, ptf.pad_count - len);
	if (!n)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_put_long_hex(n);
	}
	return (print_len);
}
