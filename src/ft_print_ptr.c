/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 09:49:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_put_un_hex(long unsigned int n)
{
	if (n >= 16)
	{
		ft_put_un_hex(n / 16);
		n = n % 16;
	}
	if (n >= 10)
		n = n + 'a' - 10;
	else
		n = n + '0';
	write(1, &n, 1);
}

int	ft_print_ptr(long unsigned int n)
{
	int					len;

	if (!n)
		len = write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_put_un_hex(n);
		len = 3;
		while (n >= 16)
		{
			n = n / 16;
			len++;
		}
	}
	return (len);
}
