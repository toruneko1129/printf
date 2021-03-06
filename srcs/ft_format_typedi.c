#include "../includes/ft_printf.h"

static int	ft_typedi_get_strsize(int d, t_fmt *fmt, int sign)
{
	int		size;

	size = sign;
	if (!d && fmt->point)
		++size;
	while (d)
	{
		++size;
		d /= 10;
	}
	return (size);
}

static int	ft_typedi_getlen2(int res, t_fmt *fmt, int size, int sign)
{
	fmt->len2 = size;
	if (fmt->point > size - sign)
	{
		fmt->len2 = fmt->point;
		if (fmt->point == INT_MAX)
			return (FAILED);
		fmt->len2 += sign;
	}
	else
		fmt->point = size - sign;
	if (fmt->mfw > fmt->len2)
		fmt->len2 = fmt->mfw;
	if (ft_fmt_check_size(res, fmt))
		return (FAILED);
	return (SUCCESS);
}

static char	*ft_typedi_getstr(t_fmt *fmt, int d, int sign, int size)
{
	char		*res;
	char		*tmp;
	const int	start = fmt->point - size + sign * 2;

	res = (char *)malloc(((size_t)fmt->point + sign + 1) * sizeof(char));
	tmp = ft_itoa(d);
	if (res == NULL || tmp == NULL)
		return (ft_strfree(tmp, res));
	*(res + fmt->point + sign) = '\0';
	ft_memset(res, '0', fmt->point + sign);
	if (d < 0)
		*res = '-';
	else if (fmt->plus)
		*res = '+';
	else if (fmt->space)
		*res = ' ';
	if (d >= 0)
		ft_memcpy(res + start, tmp, size - sign);
	else
		ft_memcpy(res + start, tmp + sign, size - sign);
	free(tmp);
	return (res);
}

static void	ft_typedi_getbuf(t_fmt *fmt, int d, int sign, char *str)
{
	const int	len = ft_strlen(str);

	if (fmt->minus)
	{
		ft_memcpy(fmt->buf2, str, len);
		return ;
	}
	ft_memcpy(fmt->buf2 + fmt->len2 - len, str, len);
	if (fmt->zero)
	{
		ft_memset(fmt->buf2, '0', fmt->len2 - len + sign);
		if (d < 0)
			*(fmt->buf2) = '-';
		else if (fmt->plus)
			*(fmt->buf2) = '+';
		else if (fmt->space)
			*(fmt->buf2) = ' ';
	}
}

int	ft_fmt_typedi(int res, va_list *ap, t_fmt *fmt)
{
	const int	d = va_arg(*ap, int);
	const int	sign = ft_need_sign(d, fmt);
	int			size;
	char		*str;

	size = ft_typedi_get_strsize(d, fmt, sign);
	if (ft_typedi_getlen2(res, fmt, size, sign) || ft_type_bufinit(fmt))
		return (FAILED);
	str = ft_typedi_getstr(fmt, d, sign, size);
	if (str == NULL)
		return (FAILED);
	ft_typedi_getbuf(fmt, d, sign, str);
	free(str);
	return (SUCCESS);
}
