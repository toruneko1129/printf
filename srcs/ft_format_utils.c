#include "../includes/ft_printf.h"

t_fmt	ft_fmtnew(void)
{
	t_fmt	new;

	new.len = 0;
	new.buf1 = NULL;
	new.hash = 0;
	new.zero = 0;
	new.minus = 0;
	new.space = 0;
	new.plus = 0;
	new.mfw = (unsigned long)0;
	new.point = (unsigned long)0;
	new.type = '\0';
	new.buf2 = NULL;
	return (new);
}

void	ft_fmtfree(t_fmt *fmt)
{
	free(fmt->buf1);
	fmt->buf1 = NULL;
	free(fmt->buf2);
	fmt->buf2 = NULL;
}

unsigned long	ft_atoul(const char **str)
{
	unsigned long	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res = res * 10 + **str - '0';
		++(*str);
	}
	return (res);
}

void	ft_noprecision(t_fmt *fmt)
{
	if (fmt->type == 's')
		fmt->point = INT_MAX;
	else if (ft_strchr("diux", fmt->type) != NULL)
		fmt->point = 1;
}
