#include "../includes/ft_printf.h"
#include "../test_printf.h"

static int	ft_load_upto_percent(const char **str, t_fmt *fmt)
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

static void	ft_load_flags(const char **str, t_fmt *fmt)
{
	if (**str != '%')
		return ;
	while (ft_strchr("#0- +", *(++(*str))) != NULL)
	{
		if (**str == '#')
			fmt->hash = 1;
		else if (**str == '0')
			fmt->zero = 1;
		else if (**str == '-')
			fmt->minus = 1;
		else if (**str == ' ')
			fmt->space = 1;
		else if (**str == '+')
			fmt->plus = 1;
	}
	if (fmt->minus)
		fmt->zero = 0;
	if (fmt->plus)
		fmt->space = 0;
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_fmt	fmt;

	res = 0;
	va_start(ap, str);
	//while (*str)
	char	*str2 = ft_strdup(str);
	for (int i = 0;i < 1; ++i)
	{
		fmt = ft_fmtnew();
		ft_load_upto_percent(&str, &fmt);
		ft_load_flags(&str, &fmt);
		check_fmt_flags(str2, fmt);
		ft_fmtfree(&fmt);
	}
	free(str2);
	va_end(ap);
	return (res);
}
