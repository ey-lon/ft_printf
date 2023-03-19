/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:53:26 by abettini          #+#    #+#             */
/*   Updated: 2023/03/19 09:49:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_dec(int n);
int	ft_print_uns(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(long unsigned int n);

#endif
