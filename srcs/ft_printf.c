#include "../includes/ft_printf.h"
#include "../test_printf.h"

static void	ft_load_fmt(const char **str, int res, t_fmt *fmt)
{
	fmt->len = ft_load_upto_percent(str, res, fmt);
	if (fmt->len == -1 || !**str)
		return ;
	ft_load_flags(str, fmt);
	ft_load_mfw(str, fmt);
	if (fmt->mfw == INT_MAX)
		return ;
	ft_load_precision(str, fmt);
	ft_load_type(str, fmt);
}

static int	ft_fmt_to_str(int res, va_list *ap, t_fmt *fmt)
{
	if (fmt->len == -1 || fmt->mfw == INT_MAX)
		return (FAILED);
	if (fmt->type == 'c')
		return (ft_fmt_typec(res, ap, fmt));
	if (fmt->type == 's')
		return (ft_fmt_types(res, ap, fmt));
	return (SUCCESS);
}

static int	ft_write_buf(int *res, t_fmt fmt)
{
	if (fmt.len && write(1, fmt.buf, fmt.len) == -1)
		return (FAILED);
	if (fmt.len2 && write(1, fmt.buf2, fmt.len2) == -1)
		return (FAILED);
	*res += fmt.len + fmt.len2;
	return (SUCCESS);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_fmt	*fmt;

	res = 0;
	va_start(ap, str);
	fmt = (t_fmt *)malloc(sizeof(t_fmt));
	if (fmt == NULL)
		return (-1);
	while (*str)
	{
		ft_fmtnew(fmt);
		ft_load_fmt(&str, res, fmt);
		if (ft_fmt_to_str(res, &ap, fmt) || ft_write_buf(&res, *fmt))
		{
			ft_printf_end(&ap, fmt);
			return (-1);
		}
		//check_fmt_content(fmt);
		ft_fmtfree(fmt);
	}
	ft_printf_end(&ap, fmt);
	return (res);
}
