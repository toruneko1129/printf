#include "../includes/ft_printf.h"

int	ft_fmt_typec(int res, va_list *ap, t_fmt *fmt)
{
	int		c;

	fmt->len2 = fmt->mfw;
	if (!fmt->len2)
		fmt->len2 = 1;
	if (fmt->len >= INT_MAX - res - fmt->len2)
		return (FAILED);
	fmt->buf2 = (char *)malloc((fmt->len2 + 1) * sizeof(char));
	if (fmt->buf2 == NULL)
		return (FAILED);
	ft_memset(fmt->buf2, ' ', fmt->len2);
	*(fmt->buf2 + fmt->len2) = '\0';
	c = va_arg(*ap, int);
	if (fmt->minus)
		*(fmt->buf2) = (unsigned char)c;
	else
		*(fmt->buf2 + fmt->len2 - 1) = (unsigned char)c;
	return (SUCCESS);
}
