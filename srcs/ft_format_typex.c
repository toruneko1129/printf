#include "../includes/ft_printf.h"

static int	ft_typex_get_strsize(unsigned int x, t_fmt *fmt, int sign)
{
	int		size;

	size = 0;
	if (x == 0 && fmt->point != 0)
		++size;
	size += sign;
	while (x)
	{
		++size;
		x /= 16;
	}
	return (size);
}

static int	ft_typex_getlen2(int res, t_fmt *fmt, int size, int sign)
{
	fmt->len2 = size;
	if (fmt->point > size - sign)
	{
		fmt->len2 = fmt->point;
		if (fmt->point >= INT_MAX - 1)
			return (FAILED);
		fmt->len2 += sign;
	}
	else
		fmt->point = size - sign;
	if (fmt->mfw > fmt->len2)
		fmt->len2 = fmt->mfw;
	if (ft_fmt_check_size(res, *fmt))
		return (FAILED);
	return (SUCCESS);
}

static char	*ft_typex_getstr(t_fmt *fmt, unsigned int x, int sign, int size)
{
	char		*res;
	char		*tmp;
	const int	start = fmt->point - size + sign * 2;
	int			i;

	res = (char *)malloc((fmt->point + sign + 1) * sizeof(char));
	tmp = ft_uitoa_hex(x);
	if (fmt->type == 'X')
	{
		i = -1;
		while (*(tmp + ++i))
			*(tmp + i) = ft_toupper(*(tmp + i));
	}
	if (res == NULL || tmp == NULL)
		ft_strfree(tmp, res);
	*(res + fmt->point + sign) = '\0';
	ft_memset(res, '0', fmt->point + sign);
	if (fmt->hash)
		*(res + 1) = fmt->type;
	ft_memcpy(res + start, tmp, size - sign);
	free(tmp);
	return (res);
}

static void	ft_typex_getbuf(t_fmt *fmt, int sign, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (fmt->minus)
	{
		ft_memcpy(fmt->buf2, str, len);
		return ;
	}
	ft_memcpy(fmt->buf2 + fmt->len2 - len, str, len);
	if (fmt->zero)
	{
		ft_memset(fmt->buf2, '0', fmt->len2 - len + sign);
		if (fmt->hash)
			*(fmt->buf2 + 1) = fmt->type;
	}
}

int	ft_fmt_typex(int res, va_list *ap, t_fmt *fmt)
{
	const unsigned int	x = va_arg(*ap, unsigned int);
	int					sign;
	int					size;
	char				*str;

	if (x == 0)
		fmt->hash = 0;
	sign = fmt->hash * 2;
	size = ft_typex_get_strsize(x, fmt, sign);
	if (ft_typex_getlen2(res, fmt, size, sign) || ft_type_bufinit(fmt))
		return (FAILED);
	str = ft_typex_getstr(fmt, x, sign, size);
	if (str == NULL)
		return (FAILED);
	ft_typex_getbuf(fmt, sign, str);
	free(str);
	return (SUCCESS);
}
