#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_fmt
{
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		mfl;
	int		dot;
	char	type;
}	t_fmt;

int		ft_printf(const char *str, ...);

#endif
