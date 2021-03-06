#include "../includes/ft_printf.h"

void	ft_fmtnew(t_fmt *new)
{
	new->len = 0;
	new->buf = NULL;
	new->hash = 0;
	new->zero = 0;
	new->minus = 0;
	new->space = 0;
	new->plus = 0;
	new->mfw = 0;
	new->point = -1;
	new->type = '\0';
	new->len2 = 0;
	new->buf2 = NULL;
}

void	ft_fmtfree(t_fmt *fmt)
{
	free(fmt->buf);
	fmt->buf = NULL;
	free(fmt->buf2);
	fmt->buf2 = NULL;
}

int	ft_isoverflow(const char *str)
{
	int		off;
	int		lim;
	int		res;

	off = INT_MAX / 10;
	lim = INT_MAX % 10;
	res = 0;
	while (ft_isdigit(*str) && (res < off || (res == off && *str - '0' <= lim)))
		res = res * 10 + *(str++) - '0';
	return (ft_isdigit(*str));
}

int	ft_getwidth(const char **str)
{
	int		res;

	if (ft_isoverflow(*str))
		return (INT_MAX);
	res = ft_atoi(*str);
	while (ft_isdigit(**str))
		++(*str);
	return (res);
}

void	ft_printf_end(va_list *ap, t_fmt *fmt)
{
	va_end(*ap);
	ft_fmtfree(fmt);
	free(fmt);
	fmt = NULL;
}
