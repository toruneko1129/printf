#include "../includes/ft_printf.h"

t_fmt	ft_fmtnew(void)
{
	t_fmt	new;

	new.hash = 0;
	new.zero = 0;
	new.minus = 0;
	new.space = 0;
	new.plus = 0;
	new.mfw = 0;
	new.point = -1;
	new.type = '\0';
	return (new);
}
