/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:09:56 by abettini          #+#    #+#             */
/*   Updated: 2023/03/20 17:34:00 by abettini         ###   ########.fr       */
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

void	ft_set_flags1(t_ptf *ptf, const char *s, int *i)
{
	while (s[*i] == '#' || s[*i] == '+' || s[*i] == ' ')
	{
		if (s[*i] == '#')
			ptf->flags |= PTF_HASH;
		else if (s[*i] == ' ')
			ptf->flags |= PTF_SPACE;
		else if (s[*i] == '+')
			ptf->flags |= PTF_PLUS;
		*i += 1;
	}
}

void	ft_set_flags2(t_ptf *ptf, const char *s, int *i)
{
	while (s[*i] == '-' || s[*i] == '0')
	{
		if (s[*i] == '-')
			ptf->flags |= PTF_MINUS;
		else if (s[*i] == '0')
			ptf->flags |= PTF_ZERO;
		*i += 1;
	}
	if (ft_isdigit(s[*i]))
	{
		ptf->pad_count = ft_atoi(&s[*i]);
		while (ft_isdigit(s[*i]))
			*i += 1;
	}
}

void	ft_set_flags3(t_ptf *ptf, const char *s, int *i)
{
	if (s[*i] == '.')
	{
		ptf->flags |= PTF_PREC;
		*i += 1;
		if (ft_isdigit(s[*i]))
		{
			ptf->prec_count = ft_atoi(&s[*i]);
			while (ft_isdigit(s[*i]))
				*i += 1;
		}
	}
}

int	ft_flags(va_list ap, const char *s, int *i)
{
	int		print_len;
	t_ptf	ptf;

	*i += 1;
	ft_flags_init(&ptf);
	ft_set_flags1(&ptf, s, i);
	ft_set_flags2(&ptf, s, i);
	ft_set_flags3(&ptf, s, i);
	if (ft_flag_check(ptf.flags, PTF_PLUS))
		ptf.flags = ft_remove_flag(ptf.flags, PTF_SPACE);
	if (ft_flag_check(ptf.flags, PTF_PREC) \
		|| ft_flag_check(ptf.flags, PTF_MINUS))
		ptf.flags = ft_remove_flag(ptf.flags, PTF_ZERO);
	if (ft_flag_check(ptf.flags, PTF_ZERO))
		ptf.pad = '0';
	ptf.format = s[*i];
	if (ft_check_format(ptf.format))
		print_len = ft_conv(ap, ptf);
	else
		print_len = ft_print_unknown(s, i, ptf);
	return (print_len);
}
