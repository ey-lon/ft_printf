/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:23:55 by abettini          #+#    #+#             */
/*   Updated: 2023/03/18 17:18:09 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_print_chr(int c, t_ptf ptf)
{
	int	print_len;

	print_len = 1;
	print_len += ft_print_special(ptf.pad, ptf.pad_count - 1);
	write(1, &c, 1);
	return (print_len);
}
