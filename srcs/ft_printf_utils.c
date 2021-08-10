#include "../includes/ft_printf.h"

void	ft_load_type(const char **str, t_fmt *fmt)
{
	if (fmt->len == -1 || fmt->mfw == INT_MAX || !**str)
		return ;
	fmt->type = *((*str)++);
}
