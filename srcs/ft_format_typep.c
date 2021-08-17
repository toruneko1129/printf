#include "../includes/ft_printf.h"

static int	ft_typep_get_strsize(uintptr_t p)
{
	int		size;

	if (p == (uintptr_t)0)
		return (3);
	size = 2;
	while (p)
	{
		++size;
		p /= 16;
	}
	return (size);
}

static char	*ft_typep_get_str(uintptr_t p, int size)
{
	char	*res;

	res = (char *)malloc(((size_t)size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	*res = '0';
	*(res + 1) = 'x';
	*(res + size) = '\0';
	while (--size - 1)
	{
		if (p % 16 <= 9)
			*(res + size) = '0' + p % 16;
		else
			*(res + size) = 'a' + p % 16 - 10;
		p /= 16;
	}
	return (res);
}

static int	ft_typep_getlen2(int res, t_fmt *fmt, int size)
{
	fmt->len2 = size;
	if (fmt->mfw > size)
		fmt->len2 = fmt->mfw;
	if (ft_fmt_check_size(res, fmt))
		return (FAILED);
	return (SUCCESS);
}

int	ft_fmt_typep(int res, va_list *ap, t_fmt *fmt)
{
	const uintptr_t	p = va_arg(*ap, uintptr_t);
	int				size;
	char			*str;

	size = ft_typep_get_strsize(p);
	str = ft_typep_get_str(p, size);
	if (str == NULL)
		return (FAILED);
	if (ft_typep_getlen2(res, fmt, size) || ft_type_bufinit(fmt))
	{
		free(str);
		return (FAILED);
	}
	if (fmt->minus)
		ft_memcpy(fmt->buf2, str, size);
	else
		ft_memcpy(fmt->buf2 + fmt->len2 - size, str, size);
	free(str);
	return (SUCCESS);
}
