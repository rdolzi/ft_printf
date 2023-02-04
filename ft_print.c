/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:18:38 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/03 15:58:15 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

/*
 * se 
 *printf("ciao %  ciao");
stampare: ciao   ciao (con 3 spazi)

in generale % non viene contato come numero

se 
printf("ciao %m  ciao"); ( anche nel caso %E)

stampare: ciao E  ciao

*/

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_print_check(char c, va_list *list, int *sum)
{
	int i = 0;
	int len;
	char *str;

	if (c == '%')
	{
		write(1,"%",1);
		*sum +=1;
	}
	else if (c == 's')
	{
		str = va_arg(*list,char *);
		len = ft_strlen(str);
			write(1,str,len);
		*sum += len;
	}
	else
	printf("+\n");
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
			write(1, &string[i], 1);
			sum++;
			i++;
		}
	}
	printf("||sum:%d|| \n", sum);
	va_end(list);
	return (sum);
}



int main()
{
	ft_printf("%s", "ciao");
}
