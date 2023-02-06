/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:18:38 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/06 20:21:39 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_check(char c, va_list *list, int *sum)
{
	if (c == '%')
		ft_printchar('%', sum);
	else if (c == 's')
		ft_printstr(va_arg(*list, char *), sum);
	else if (c == 'c')
		ft_printchar(va_arg(*list, int), sum);
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(*list, int), sum);
	else if (c == 'u')
		ft_unsigned_printnbr(va_arg(*list, unsigned int), sum);
	else if (c == 'x' || c == 'X')
		ft_hexadecimal_printnbr(va_arg(*list, unsigned int), sum, c);
	else if (c == 'p')
	{
		ft_printchar('0', sum);
		ft_printchar('x', sum);
		ft_pointer(va_arg(*list, uintptr_t), sum);
	}
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		sum;
	va_list	list;

	i = 0;
	sum = 0;
	va_start(list, string);
	while (string[i])
	{
		if (string[i] == '%')
		{

			ft_print_check(string[++i], &list, &sum);
			i++;
		}
		else
		{
			ft_printchar((char)string[i], &sum);
			i++;
		}
	}
	va_end(list);
	return (sum);
}
