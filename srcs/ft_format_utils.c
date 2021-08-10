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
	new.mfw = 0;
	new.point = 0;
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

int		ft_isoverflow(const char *str)
{
	int		off;
	int		lim;
	int		res;

	off = INT_MAX / 10;
	lim = INT_MAX % 10;
	res = 0;
	while (ft_isdigit(*str) && (res < off || (res == off && *str - '0' <= lim)))
	{
		res = res * 10 + *(str++) - '0';
	}
	return (ft_isdigit(*str));
}

void	ft_noprecision(t_fmt *fmt)
{
	if (fmt->type == 's')
		fmt->point = INT_MAX;
	else if (ft_strchr("diux", fmt->type) != NULL)
		fmt->point = 1;
}
