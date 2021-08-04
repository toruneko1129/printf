#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H

void	check_fmt_content(t_fmt fmt);
void	check_fmt_point(void);
void	check_fmt_free(void);
void	check_fmt_buf1(const char *str, int res, t_fmt fmt);
void	test_fmt_buf1(void);
void	check_fmt_flags(const char *str, t_fmt fmt);
void	test_fmt_flags(void);

#endif
