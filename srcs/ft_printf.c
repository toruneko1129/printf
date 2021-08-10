#include "../includes/ft_printf.h"
#include "../test_printf.h"

static void	ft_load_fmt(const char **str, t_fmt *fmt)
{
	fmt->len = ft_load_upto_percent(str, fmt);
	if (fmt->len == -1 || !**str)
		return ;
	ft_load_flags(str, fmt);
	ft_load_mfw(str, fmt);
	if (fmt->mfw == INT_MAX)
		return ;
	ft_load_precision(str, fmt);
	ft_load_type(str, fmt);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_fmt	fmt;

	res = 0;
	va_start(ap, str);
	while (*str)
	{
		fmt = ft_fmtnew();
		ft_load_fmt(&str, &fmt);
		check_fmt_content(fmt);
		ft_fmtfree(&fmt);
	}
	va_end(ap);
	return (res);
}
