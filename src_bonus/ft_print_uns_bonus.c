/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/18 17:20:38 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_put_uns(unsigned int n)
{
	if (n >= 10)
	{
		ft_put_uns(n / 10);
		n = n % 10;
	}
	n = n + '0';
	write(1, &n, 1);
}

static int	ft_uns_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_uns(unsigned int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	len = ft_uns_len(n);
	print_len = len;
	print_len += ft_print_special(ptf.pad, \
		ptf.pad_count - len - ft_quant(len, ptf.prec_count));
	print_len += ft_print_special('0', ptf.prec_count - len);
	ft_put_uns(n);
	return (print_len);
}
