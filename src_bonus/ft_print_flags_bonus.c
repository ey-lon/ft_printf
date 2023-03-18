/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:48:26 by abettini          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:11 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_flag_check(int flags, int flag_to_find)
{
	int	i;

	if (flag_to_find && flags)
	{
		i = 0;
		while (!(flag_to_find & 1 << i))
			i++;
		if (flags & 1 << i)
			return (1);
	}
	return (0);
}

int	ft_print_special(int c, int count)
{
	int	len;

	len = 0;
	while (count-- > 0)
		len += write(1, &c, 1);
	return (len);
}

//controllare incompatibilita' flags!!!!!!!