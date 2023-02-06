/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:14:28 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/05 20:40:21 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//??
int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_printchar(char c, int *sum)
{
	write(1, &c, 1);
	(*sum)++;
}

void ft_printstr(char *str, int *sum)
{
	int k;

	k = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*sum) += 6;
		return;
	}
	while (str[k])
	{
		ft_printchar(str[k], sum);
		k++;
	}
}
