#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"
# define SUCCESS 0
# define FAILED 1

typedef struct s_fmt
{
	int		len;
	char	*buf;
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		mfw;
	int		point;
	char	type;
	int		len2;
	char	*buf2;
}	t_fmt;

int		ft_printf(const char *str, ...);
void	ft_fmtnew(t_fmt *new);
void	ft_fmtfree(t_fmt *fmt);
int		ft_isoverflow(const char *str);
int		ft_getwidth(const char **str);
void	ft_printf_end(va_list *ap, t_fmt *fmt);
int		ft_fmt_check_size(int res, t_fmt *fmt);
int		ft_type_bufinit(t_fmt *fmt);
int		ft_need_sign(int d, t_fmt fmt);
char	*ft_strfree(char *tmp, char *res);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_hex(unsigned int n);
int		ft_load_upto_percent(const char **str, int res, t_fmt *fmt);
void	ft_load_flags(const char **str, t_fmt *fmt);
void	ft_load_mfw(const char **str, t_fmt *fmt);
void	ft_load_precision(const char **str, t_fmt *fmt);
void	ft_load_type(const char **str, t_fmt *fmt);
int		ft_fmt_typec(int res, va_list *ap, t_fmt *fmt);
int		ft_fmt_types(int res, va_list *ap, t_fmt *fmt);
int		ft_fmt_typep(int res, va_list *ap, t_fmt *fmt);
int		ft_fmt_typedi(int res, va_list *ap, t_fmt *fmt);
int		ft_fmt_typeu(int res, va_list *ap, t_fmt *fmt);
int		ft_fmt_typex(int res, va_list *ap, t_fmt *fmt);
int		ft_fmt_typeper(int res, t_fmt *fmt);

#endif
