/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:12:31 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 17:24:40 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_format(const char *format)
{
	char	flags;

	flags = 0;
	while (ft_strchr("#0 -+", *format) && *++format)
		flags = flags | 1;
	while (ft_isdigit(*format) && *++format)
		flags = flags | 2;
	if (*format == '.' && *++format)
		flags = flags | 4;
	while (ft_isdigit(*format))
		format++;
	if (!(ft_strchr("cspdiuxX%", *format)))
		flags = -1;
	return (flags);
}
