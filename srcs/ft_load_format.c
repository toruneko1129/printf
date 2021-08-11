#include "../includes/ft_printf.h"

int	ft_load_upto_percent(const char **str, int res, t_fmt *fmt)
{
	char	*end;
	size_t	len;

	end = ft_strchr(*str, '%');
	if (end == NULL)
		end = ft_strchr(*str, '\0');
	len = end - *str;
	if (len >= (size_t)INT_MAX - res)
		return (-1);
	fmt->buf1 = ft_substr(*str, 0, len);
	if (fmt->buf1 == NULL)
		return (-1);
	*str = end;
	return ((int)len);
}

void	ft_load_flags(const char **str, t_fmt *fmt)
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

void	ft_load_mfw(const char **str, t_fmt *fmt)
{
	fmt->mfw = ft_getwidth(str);
}

void	ft_load_precision(const char **str, t_fmt *fmt)
{
	if (**str != '.')
		return ;
	++(*str);
	fmt->point = ft_getwidth(str);
}

void	ft_load_type(const char **str, t_fmt *fmt)
{
	fmt->type = *((*str)++);
}
