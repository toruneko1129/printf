#include "../includes/ft_printf.h"

int	ft_fmt_types(int res, va_list *ap, t_fmt *fmt)
{
	const char	*s = va_arg(*ap, char *);
	size_t		size;

	size = ft_strlen(s);
	if (fmt->point != -1 && size > (size_t)fmt->point)
		size = (size_t)fmt->point;
}
