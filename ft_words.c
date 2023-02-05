/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:14:28 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/04 15:37:37 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_printchar(char c, int *sum, int *i)
{
	write(1, &c, 1);
	(*sum)++;
	(*i)++;
}

void ft_printstr(char *str, int *sum, int *i)
{
	int k;

	k = 0;
	while (str[k])
		ft_printchar(str[k++], sum, i);
}
