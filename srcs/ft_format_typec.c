#include "../includes/ft_printf.h"

int	ft_fmt_typec(int res, va_list *ap, t_fmt *fmt)
{
	const int	c = va_arg(*ap, int);

	fmt->len2 = fmt->mfw;
	if (!fmt->len2)
		fmt->len2 = 1;
	if (ft_fmt_check_size(res, *fmt) || ft_type_bufinit(fmt))
		return (FAILED);
	if (fmt->minus)
		*(fmt->buf2) = (unsigned char)c;
	else
		*(fmt->buf2 + fmt->len2 - 1) = (unsigned char)c;
	return (SUCCESS);
}
