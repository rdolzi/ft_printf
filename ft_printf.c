/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:18:38 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/04 15:04:04 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 * se
 *printf("ciao %  ciao");
stampare: ciao   ciao (con 3 spazi)

in generale % non viene contato come numero

se
printf("ciao %m  ciao"); ( anche nel caso %E)

stampare: ciao E  ciao

*/

void ft_print_check(char c, va_list *list, int *sum, int *i)
{
	int len;
	char *str;
	int d;
	if (c == '%')
	{
		ft_printchar('%', sum);
	}
	else if (c == 's')
	{
		ft_printstr(va_arg(*list, char *), sum);

		/*str = va_arg(*list, char *);
		len = ft_strlen(str);
		write(1, str, len);
		*sum += len;*/
	}
	else if (c == 'c')
	{
		ft_printchar(va_arg(*list, int), sum);
	}
	else
		printf("+\n");
}

int ft_printf(const char *string, ...)
{
	int i;
	int sum;
	va_list list;

	i = 0;
	sum = 0;
	va_start(list, string);
	while (string[i])
	{
		if (string[i] == '%')
		{

			ft_print_check(string[++i], &list, &sum, &i);
			printf("|if(i):%d| \n", i);
			i++;
		}
		else
		{
			ft_printchar((char)string[i], &sum);
			printf("|else(i):%d| \n", i);
			i++;
		}
	}
	printf("||sum:%d||i:%d|| \n", sum, i);
	va_end(list);
	return (sum);
}

int main()
{
	char a[] = "ciao";
	ft_printf("%%%cciao", 'K');
}
