#include "../includes/ft_printf.h"

t_fmt	ft_fmtnew(void)
{
	t_fmt	new;

	new.buf1 = NULL;
	new.hash = 0;
	new.zero = 0;
	new.minus = 0;
	new.space = 0;
	new.plus = 0;
	new.mfw = 0;
	new.point = -1;
	new.type = '\0';
	new.buf2 = NULL;
	return (new);
}

void	ft_noprecision(t_fmt *fmt)
{
	if (fmt->type == 's')
		fmt->point = INT_MAX;
	else if (ft_strchr("diux", fmt->type) != NULL)
		fmt->point = 1;
}
