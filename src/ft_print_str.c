/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:27:10 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 09:49:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
		i = write(1, "(null)", 6);
	else
	{
		i = 0;
		while (str[i])
			i += write(1, &str[i], 1);
	}
	return (i);
}
