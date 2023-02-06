/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:18:38 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/06 11:50:02 by rdolzi           ###   ########.fr       */
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
		ft_printchar('%', sum);
	else if (c == 's')
		ft_printstr(va_arg(*list, char *), sum);
	else if (c == 'c')
		ft_printchar(va_arg(*list, int), sum);
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(*list, int), sum);
	else if (c == 'u')
	{
		// ft_printnbr(va_arg(*list, unsigned int), sum);
		printf("\n\n%u\n\n ", va_arg(*list, unsigned int));
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
	int b = -123;
	char a[] = "ciao";
	// ft_printf("%%%cciao", 'K');
	// ft_printf("%d  %i", b, b);
	// ft_printf("%s", NULL);
	int d = -37;
	ft_printf("%d", d);
}
