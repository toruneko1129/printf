#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_fmt
{
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		mfw;
	int		point;
	char	type;
}	t_fmt;

int		ft_printf(const char *str, ...);
t_fmt	ft_fmtnew(void);
void	ft_noprecision(t_fmt *fmt);

#endif
