
#ifndef FT_PRINT_H
#define FT_PRINT_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *string, ...);
int ft_strlen(char *s);
void ft_printchar(char c, int *sum);
void ft_printstr(char *str, int *sum);
void ft_printnbr(int nbr, int *sum);
void ft_unsigned_printnbr(unsigned int nbr, int *sum);

#endif