/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:23:55 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 11:23:00 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_print_chr(int c, t_ptf ptf)
{
	int	print_len;

	print_len = 0;
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count - 1);
	print_len += write(1, &c, 1);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count - 1);
	return (print_len);
}
