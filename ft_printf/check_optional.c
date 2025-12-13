/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_optional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:04:16 by szapata-          #+#    #+#             */
/*   Updated: 2024/01/23 16:32:58 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	check_flags(const char **ptr, unsigned char *flags)
{
	while (ft_strchr("#0 -+", **ptr))
	{
		set_flags(flags, **ptr);
		(*ptr)++;
	}
}

int	check_width(const char **format)
{
	const char	*tmp;

	tmp = *format;
	while (ft_isdigit(**format))
		(*format)++;
	return (ft_atoi(tmp));
}
