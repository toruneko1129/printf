#include "../includes/ft_printf.h"

static int	ft_types_getlen2(int res, t_fmt *fmt, const char *s)
{
	size_t	size;

	size = ft_strlen(s);
	if (fmt->point != -1 && size > (size_t)fmt->point)
		size = fmt->point;
	else
		fmt->point = (int)size;
	if (size < (size_t)fmt->mfw)
		size = fmt->mfw;
	if (size >= (size_t)INT_MAX)
		return (FAILED);
	fmt->len2 = size;
	if (ft_fmt_check_size(res, fmt))
		return (FAILED);
	return (SUCCESS);
}

int	ft_fmt_types(int res, va_list *ap, t_fmt *fmt)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(null)";
	if (ft_types_getlen2(res, fmt, s) || ft_type_bufinit(fmt))
		return (FAILED);
	if (fmt->minus)
		ft_memcpy(fmt->buf2, s, fmt->point);
	else
		ft_memcpy(fmt->buf2 + fmt->len2 - fmt->point, s, fmt->point);
	return (SUCCESS);
}
