#include "../includes/ft_printf.h"

static int	ft_typeu_get_strsize(unsigned int u)
{
	int		size;

	if (u == 0)
		return (1);
	size = 0;
	while (u)
	{
		++size;
		u /= 10;
	}
	return (size);
}

static int	ft_typeu_getlen2(int res, t_fmt *fmt, int size)
{
	fmt->len2 = size;
	if (fmt->point > size)
		fmt->len2 = fmt->point;
	else
		fmt->point = fmt->len2;
	if (fmt->mfw > fmt->len2)
		fmt->len2 = fmt->mfw;
	if (ft_fmt_check_size(res, *fmt))
		return (FAILED);
	return (SUCCESS);
}

static char	*ft_typeu_getstr(t_fmt *fmt, unsigned int u, int size)
{
	char		*res;
	char		*tmp;
	const int	start = fmt->point - size;

	res = (char *)malloc((fmt->point + 1) * sizeof(char));
	tmp = ft_uitoa(u);
	if (res == NULL || tmp == NULL)
		ft_strfree(tmp, res);
	*(res + fmt->point) = '\0';
	ft_memset(res, '0', fmt->point);
	ft_memcpy(res + start, tmp, size);
	free(tmp);
	return (res);
}

static void	ft_typeu_getbuf(t_fmt *fmt, char *str)
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
		ft_memset(fmt->buf2, '0', fmt->len2 - len);
}

int	ft_fmt_typeu(int res, va_list *ap, t_fmt *fmt)
{
	const unsigned int	u = va_arg(*ap, unsigned int);
	int					size;
	char				*str;

	if (u == 0 && fmt->point == 0)
		return (SUCCESS);
	size = ft_typeu_get_strsize(u);
	if (ft_typeu_getlen2(res, fmt, size) || ft_type_bufinit(fmt))
		return (FAILED);
	str = ft_typeu_getstr(fmt, u, size);
	if (str == NULL)
		return (FAILED);
	ft_typeu_getbuf(fmt, str);
	free(str);
	return (SUCCESS);
}
