#include "../includes/ft_printf.h"

int	ft_fmt_typedx(int res, va_list *ap, t_fmt *fmt)
{
	const unsigned int	x = va_arg(*ap, unsigned int);
	const int			sign = fmt->sharp * 2;
	int					size;
	char				*str;
}
