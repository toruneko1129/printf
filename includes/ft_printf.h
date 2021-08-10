#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_fmt
{
	int		len;
	char	*buf1;
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		mfw;
	int		point;
	char	type;
	char	*buf2;
}	t_fmt;

int		ft_printf(const char *str, ...);
t_fmt	ft_fmtnew(void);
void	ft_fmtfree(t_fmt *fmt);
int		ft_isoverflow(const char *str);
int		ft_getwidth(const char **str);

#endif
