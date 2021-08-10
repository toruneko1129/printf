#include "../includes/ft_printf.h"

void	ft_load_precision(const char **str, t_fmt *fmt)
{
	if (fmt->len == -1 || fmt->mfw == INT_MAX || **str != '.')
		return ;
	++(*str);
	fmt->point = ft_getwidth(str);
}

void	ft_load_type(const char **str, t_fmt *fmt)
{
	if (fmt->len == -1 || fmt->mfw == INT_MAX || !**str)
		return ;
	fmt->type = *((*str)++);
}
