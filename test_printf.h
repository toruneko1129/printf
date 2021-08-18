#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

# include <stdio.h>
# define rep(i, n) for (int i = 0; i < (n); ++i)
# define rep2(i, m, n) for (int i = (m); i < (n); ++i)

void	check_fmt_content(t_fmt fmt);
void	check_fmt_free(void);
void	check_fmt_buf1(const char *str, int res, t_fmt fmt);
void	test_fmt_buf1(void);
void	check_fmt_flags(const char *str, t_fmt fmt);
void	test_fmt_flags(void);
void	check_fmt_mfw(const char *str, t_fmt fmt);
void	test_fmt_mfw(void);
void	check_fmt_point(const char *str, t_fmt fmt);
void	test_fmt_point(void);
void	check_fmt_type(const char *str, t_fmt fmt);
void	test_fmt_type(void);
void	check_fmt_all(const char *str);
void	test_fmt_all(void);

#endif
