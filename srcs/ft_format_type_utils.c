#include "../includes/ft_printf.h"

int	ft_fmt_check_size(int res, t_fmt fmt)
{
	if (fmt.len >= INT_MAX - res - fmt.len2)
		return (FAILED);
	return (SUCCESS);
}
