#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_fmt	fmt;

	res = 0;
	va_start(ap, str);
	while (0)
	{
		fmt = ft_fmtnew();
		ft_fmtfree(&fmt);
	}
	va_end(ap);
	return (res);
}
