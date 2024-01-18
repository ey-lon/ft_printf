/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2024/01/18 11:22:41 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putnbr(n / 10);
		n = -(n % 10);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
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

	len = 1;
	if (n == INT_MIN)
	{
		n = n / 10;
		len++;
	}
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_dec(int n)
{
	int	len;

	ft_putnbr(n);
	len = ft_int_len(n);
	return (len);
}
