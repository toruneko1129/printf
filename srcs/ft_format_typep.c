#include "../includes/ft_printf.h"

static int	ft_typep_get_strsize(uintptr_t p)
{
	int		size;

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

	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	*res = '0';
	*(res + 1) = 'x';
	*(res + size) = '\0';
	while (p)
	{
		--size;
		if (p % 16 <= 9)
			*(res + size) = '0' + p % 16;
		else
			*(res + size) = 'a' + p % 16;
		p /= 16;
	}
	return (res);
}

static int ft_typep_getlen2(int res, t_fmt *fmt, const int size)
{
	fmt->len2 = size;
	if (fmt->mfw > size)
		fmt->len2 = fmt->mfw;
	if (fmt->len >= INT_MAX - res - fmt->len2)
		return (FAILED);
	return (SUCCESS);
}

static int	ft_typep_bufinit(t_fmt *fmt)
{
	fmt->buf2 = (char *)malloc((fmt->len2 + 1) * sizeof(char));
	if (fmt->buf2 == NULL)
		return (FAILED);
}

int	ft_fmt_typep(int res, va_list *ap, t_fmt *fmt)
{
	const uintptr_t	p = va_arg(*ap, uintptr_t);
	const int		size = ft_typep_get_strsize(p);
	const char		*str = ft_typep_get_str(p, (int)size);

	if (str == NULL)
		return (FAILED);
	return (SUCCESS);
}
