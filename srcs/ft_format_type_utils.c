#include "../includes/ft_printf.h"

int	ft_fmt_check_size(int res, t_fmt fmt)
{
	if (fmt.len >= INT_MAX - res - fmt.len2)
		return (FAILED);
	return (SUCCESS);
}

int	ft_type_bufinit(t_fmt *fmt)
{
	fmt->buf2 = (char *)malloc((fmt->len2 + 1) * sizeof(char));
	if (fmt->buf2 == NULL)
		return (FAILED);
	ft_memset(fmt->buf2, ' ', fmt->len2);
	*(fmt->buf2 + fmt->len2) = '\0';
	return (SUCCESS);
}
