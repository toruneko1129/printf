#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_fmt
{
	char	type;
}	t_fmt;

int		ft_printf(const char *str, ...);

#endif
