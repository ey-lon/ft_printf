/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:27:10 by abettini          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:12 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	ft_put_str(char *str, int len)
{
	int	i;

	if (!str && len >= 6)
		write(1, "(null)", 6);
	else if (str)
	{
		i = 0;
		while (str[i] && len--)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

static int	ft_str_len(char *str, t_ptf ptf)
{
	int	len;

	len = 0;
	if (!ft_flag_check(ptf.flags, PTF_PREC))
	{
		if (!str)
			len = 6;
		else
		{
			while (str[len])
				len++;
		}
	}
	else
	{
		if (!str && ptf.prec_count >= 6)
			len = 6;
		else if (str)
		{
			while (str[len] && ptf.prec_count--)
				len++;
		}
	}
	return (len);
}

int	ft_print_str(char *str, t_ptf ptf)
{
	int	print_len;
	int	len;

	len = ft_str_len(str, ptf);
	print_len = len;
	print_len += ft_print_special(ptf.pad, ptf.pad_count - len);
	ft_put_str(str, len);
	return (print_len);
}
