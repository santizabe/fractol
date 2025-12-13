/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:06:54 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/22 14:24:53 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(char const *format, ...);
void	check_flags(const char **ptr, unsigned char *flags);
int		check_width(const char **format);
void	set_flags(unsigned char *flags, char c);
int		ft_numlen(unsigned int num, unsigned int base_len);
int		ft_putnchar(char *s, int count);
int		ft_putlchar(int len, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, int base_len);
int		print_string(char flags, const char **format, va_list ap);
char	check_format(const char *format);
int		print_err(const char **format, va_list ap);
int		h_u(unsigned char flags, int *w_p_h, unsigned int nbr, char f);
int		h_hex(unsigned char flags, int *w_p_h, unsigned int n, char *b);
int		handle_pointer(unsigned char flags, int *w_p_h, void *ptr);
int		handle_char(unsigned char flags, int *w_p_h, int c);
int		handle_int(unsigned char flags, int *w_p_h, int num);
int		handle_string(unsigned char flags, int *w_p_h, char *s);

#endif