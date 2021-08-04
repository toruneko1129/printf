#include "../includes/ft_printf.h"
#include "../test_printf.h"

static int	ft_read_upto_percent(const char **str, t_fmt *fmt)
{
	char	*end;
	size_t	len;

	end = ft_strchr(*str, '%');
	if (end == NULL)
		end = ft_strchr(*str, '\0');
	len = end - *str;
	if (len >= (size_t)INT_MAX)
		return (-1);
	fmt->buf1 = ft_substr(*str, 0, len);
	if (fmt->buf1 == NULL)
		return (-1);
	*str = end;
	return ((int)len);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_fmt	fmt;

	res = 0;
	va_start(ap, str);
	//while (*str)
	for (int i = 0;i < 1; ++i)
	{
		fmt = ft_fmtnew();
		ft_read_upto_percent(&str, &fmt);
		check_fmt_buf1(str, res, fmt);
		ft_fmtfree(&fmt);
	}
	va_end(ap);
	return (res);
}
