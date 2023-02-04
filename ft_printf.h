
#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *string, ...);
int		ft_strlen(char *s);
void	ft_printchar(va_list *list, int *sum, int *i);
void	ft_printstr(char *str, int *sum, int *i);

#endif
