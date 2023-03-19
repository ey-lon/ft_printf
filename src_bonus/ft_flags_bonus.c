/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:09:56 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 09:49:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

void	ft_flags_init(t_ptf *ptf)
{
	ptf->flags = PTF_NOFLAGS;
	ptf->format = 0;
	ptf->prec_count = 0;
	ptf->pad_count = 0;
	ptf->pad = ' ';
}

char	ft_pad_check(int flags)
{
	if (ft_flag_check(flags, PTF_ZERO)
		&& !ft_flag_check(flags, PTF_MINUS)
		&& !ft_flag_check(flags, PTF_PREC))
		return ('0');
	return (' ');
}

void	ft_set_flags1(t_ptf *ptf, char c)
{
	if (c == '#')
		ptf->flags |= PTF_HASH;
	else if (c == ' ')
		ptf->flags |= PTF_SPACE;
	else if (c == '+')
		ptf->flags |= PTF_PLUS;
	else if (c == '-')
		ptf->flags |= PTF_MINUS;
	else if (c == '0')
		ptf->flags |= PTF_ZERO;
}

void	ft_set_flags2(t_ptf *ptf, const char *s, int *i)
{
	if (s[*i] == '.')
	{
		ptf->flags |= PTF_PREC;
		*i += 1;
		ptf->prec_count = ft_atoi(&s[*i]);
		while (ft_isdigit(s[*i]))
			*i += 1;
		*i -= 1;
	}
	else if (ft_isdigit(s[*i]))
	{
		ptf->pad_count = ft_atoi(&s[*i]);
		while (ft_isdigit(s[*i]))
			*i += 1;
		*i -= 1;
	}
}

int	ft_flags(va_list ap, const char *s, int *i)
{
	int		print_len;
	t_ptf	ptf;

	print_len = 0;
	ft_flags_init(&ptf);
	while (s[*i] == '#' || s[*i] == ' ' || s[*i] == '+'
		|| s[*i] == '-' || s[*i] == '.' || ft_isdigit(s[*i]))
	{
		ft_set_flags1(&ptf, s[*i]);
		ft_set_flags2(&ptf, s, i);
		*i += 1;
	}
	ptf.pad = ft_pad_check(ptf.flags);
	ptf.format = s[*i];
	print_len = ft_conv(ap, ptf);
	return (print_len);
}
