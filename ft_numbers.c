/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:19:27 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/06 11:52:54 by rdolzi           ###   ########.fr       */
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