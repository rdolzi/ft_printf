/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:19:27 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/06 15:06:18 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
// come includere versione di libft.h?

void ft_printnbr(int nbr, int *sum)
{
    // printf("nbr:%d|itoa:%s", nbr, ft_itoa(nbr));
    //  ft_printstr(ft_itoa(nbr), sum);
    if (nbr < 0)
    {
        ft_printchar('-', sum);
        nbr *= -1;
    }
    if (nbr > 9)
        ft_printnbr(nbr / 10, sum);
    ft_printchar((nbr % 10) + '0', sum);
}

void ft_unsigned_printnbr(unsigned int nbr, int *sum)
{
    if (nbr > 9)
        ft_unsigned_printnbr(nbr / 10, sum);
    ft_printchar((nbr % 10) + '0', sum);
}

void ft_hexadecimal_printnbr(unsigned int nbr, int *sum, char c)
{
    char *base_char;
    if (c == 'x')
        base_char = "0123456789abcdef";
    else
        base_char = "0123456789ABCDEF";
    if (nbr > 15)
        ft_hexadecimal_printnbr(nbr / 16, sum, c);
    ft_printchar(base_char[nbr % 16], sum);
}

void ft_pointer(uintptr_t nbr, int *sum)
{
    char *base_char;

    base_char = "0123456789abcdef";
    if (nbr > 15)
        ft_pointer(nbr / 16, sum);
    ft_printchar(base_char[nbr % 16], sum);
}