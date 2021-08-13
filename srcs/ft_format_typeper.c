#include "../includes/ft_printf.h"

int	ft_fmt_typeper(int res, t_fmt *fmt)
{
	fmt->len2 = fmt->mfw;
	if (!fmt->len2)
		fmt->len2 = 1;
	if (ft_fmt_check_size(res, *fmt) || ft_type_bufinit(fmt))
		return (FAILED);
	if (fmt->minus)
		*(fmt->buf2) = '%';
	else
		*(fmt->buf2 + fmt->len2 - 1) = '%';
	return (SUCCESS);
}

