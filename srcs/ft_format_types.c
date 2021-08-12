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
	if (fmt->len >= INT_MAX - res - fmt->len2)
		return (FAILED);
	return (SUCCESS);
}

static int	ft_types_bufinit(t_fmt *fmt)
{
	fmt->buf2 = (char *)malloc((fmt->len2 + 1) * sizeof(char));
	if (fmt->buf2 == NULL)
		return (FAILED);
	ft_memset(fmt->buf2, ' ', fmt->len2);
	*(fmt->buf2 + fmt->len2) = '\0';
	return (SUCCESS);
}

int	ft_fmt_types(int res, va_list *ap, t_fmt *fmt)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
		s = "(null)";
	if (ft_types_getlen2(res, fmt, s) || ft_types_bufinit(fmt))
		return (FAILED);
	if (fmt->minus)
		ft_memcpy(fmt->buf2, s, fmt->point);
	else
		ft_memcpy(fmt->buf2 + fmt->len2 - fmt->point, s, fmt->point);
	return (SUCCESS);
}
