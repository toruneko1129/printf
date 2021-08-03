#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, str);
	va_end(ap);
	return (res);
}
