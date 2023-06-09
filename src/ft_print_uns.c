/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 09:49:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	ft_print_uns(unsigned int n)
{
	int	len;

	ft_put_uns(n);
	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
