/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:11:16 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/06 20:15:15 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
void	ft_printchar(char c, int *sum);
void	ft_printstr(char *str, int *sum);
void	ft_printnbr(int nbr, int *sum);
void	ft_unsigned_printnbr(unsigned int nbr, int *sum);
void	ft_hexadecimal_printnbr(unsigned int nbr, int *sum, char c);
void	ft_pointer(uintptr_t nbr, int *sum);

#endif