/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unknown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:37:09 by abettini          #+#    #+#             */
/*   Updated: 2023/03/20 17:33:18 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_check_format(char format)
{
	char	*formats;
	int		i;

	formats = "cspdiuxX%";
	i = 0;
	while (formats[i])
	{
		if (format == formats[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_print_unknown(const char *s, int *i, t_ptf ptf)
{
	int		print_len;

	print_len = 0;
	while (s[*i] != '%')
		*i -= 1;
	*i += 1;
	print_len += write(1, "%", 1);
	while (s[*i] == '#' || s[*i] == '+' || s[*i] == ' ')
		*i += 1;
	if (ft_flag_check(ptf.flags, PTF_HASH))
		print_len += write(1, "#", 1);
	if (ft_flag_check(ptf.flags, PTF_PLUS))
		print_len += write(1, "+", 1);
	if (ft_flag_check(ptf.flags, PTF_SPACE))
		print_len += write(1, " ", 1);
	while (s[*i] != '%' && s[*i] != '\0')
	{
		print_len += write(1, &s[*i], 1);
		*i += 1;
	}
	*i -= 1;
	return (print_len);
}