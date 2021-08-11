#include "../includes/ft_printf.h"

int	ft_fmt_typec(va_list *ap, t_fmt *fmt)
{
	int		len2;
	int		c;

	len2 = fmt->mfw;
	if (!len2)
		len2 = 1;
	if (fmt->len >= INT_MAX - len2)
		return (FAILED);
	fmt->len += len2;
	fmt->buf2 = (char *)malloc((len2 + 1) * sizeof(char));
	if (fmt->buf2 == NULL)
		return (FAILED);
	ft_memset(fmt->buf2, ' ', len2);
	*(fmt->buf2 + len2) = '\0';
	c = va_arg(*ap, int);
	if (fmt->minus)
		*(fmt->buf2) = (unsigned char)c;
	else
		*(fmt->buf2 + len2 - 1) = (unsigned char)c;
	return (SUCCESS);
}
