/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:19:27 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/05 18:49:11 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
// come includere versione di libft.h?

int n_len(int a)
{
    int i;

    i = 0;
    if (a < 0)
    {
        i++;
        a = -a;
    }
    while (a > 0)
    {
        a /= 10;
        i++;
    }
    return (i);
}
char *ft_strdup(const char *s1)
{
    char *s2;
    int len;
    int i;

    i = 0;
    len = ft_strlen((char *)s1);
    s2 = (char *)malloc((len + 1) * sizeof(char));
    if (!s2)
        return (NULL);
    while (i < len)
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char *init_str(int n)
{
    char *str;
    int nlen;

    nlen = n_len(n);
    str = (char *)malloc(sizeof(char) * (nlen + 1));
    if (!str)
        return (NULL);
    if (n < 0)
    {
        str[0] = '-';
        str[nlen] = '\0';
        return (str);
    }
    else
    {
        str[nlen] = 0;
        return (str);
    }
}

char *ft_itoa(int n)
{
    char *str;
    int nlen;

    if (n == 0)
        return (ft_strdup("0"));
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    nlen = n_len(n);
    str = init_str(n);
    if (!str)
        return (NULL);
    if (n < 0)
        n = -n;
    while (n != 0)
    {
        str[nlen - 1] = (n % 10) + '0';
        n /= 10;
        nlen--;
    }
    return (str);
}

// --

void ft_printnbr(int nbr, int *sum)
{
    // printf("nbr:%d|itoa:%s", nbr, ft_itoa(nbr));
    ft_printstr(ft_itoa(nbr), sum);
}