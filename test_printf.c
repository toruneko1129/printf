#include <stdio.h>
#include "./includes/ft_printf.h"

void	check_fmt_content(t_fmt fmt)
{
	printf("len:%d\n", fmt.len);
	printf("buf1:%s\n", fmt.buf1);
	printf("hash:%d\n", fmt.hash);
	printf("zero:%d\n", fmt.zero);
	printf("minus:%d\n", fmt.minus);
	printf("space:%d\n", fmt.space);
	printf("plus:%d\n", fmt.plus);
	printf("mfw:%lu\n", fmt.mfw);
	printf("point:%lu\n", fmt.point);
	if (ft_isprint(fmt.type))
		printf("type:%c\n", fmt.type);
	else
		printf("type:%d\n", fmt.type);
	printf("buf2:%s\n", fmt.buf2);
	printf("\n");
}

void	check_fmt_point(void)
{
	t_fmt	fmt;

	fmt = ft_fmtnew();
	fmt.type = 's';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt = ft_fmtnew();
	fmt.type = 'd';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt = ft_fmtnew();
	fmt.type = 'i';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt = ft_fmtnew();
	fmt.type = 'u';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt = ft_fmtnew();
	fmt.type = 'x';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
}

void	check_fmt_free(void)
{
	t_fmt	fmt;

	fmt = ft_fmtnew();
	fmt.buf1 = ft_strdup("hoge");
	check_fmt_content(fmt);
	ft_fmtfree(&fmt);
	fmt = ft_fmtnew();
	fmt.buf2 = ft_strdup("fuga");
	check_fmt_content(fmt);
	ft_fmtfree(&fmt);
	fmt = ft_fmtnew();
	fmt.buf1 = ft_strdup("hoge");
	fmt.buf2 = ft_strdup("fuga");
	check_fmt_content(fmt);
	ft_fmtfree(&fmt);
	check_fmt_content(fmt);
}

void	check_fmt_buf1(const char *str, int res, t_fmt fmt)
{
	//need to call in ft_printf
	printf("%c\n", *str);
	printf("res:%d\n", res);
	check_fmt_content(fmt);
}

void	test_fmt_buf1(void)
{
	ft_printf("test case 1");
	ft_printf("test case 2%failed");
	ft_printf("test case 3  %failed%");
}

void	check_fmt_flags(const char *str, t_fmt fmt)
{
	//need to call in ft_printf
	printf("str:%s\n", str);
	check_fmt_content(fmt);
}

void	test_fmt_flags(void)
{
	ft_printf("test case 1");
	ft_printf("test case 2%d");
	ft_printf("hoge%#x");
	ft_printf("fuga %0d");
	ft_printf("%-d");
	ft_printf("hoge % d");
	ft_printf("%+d");
	ft_printf("%###d");
	ft_printf("%+#0d");
	ft_printf("%---   ##d");
	ft_printf("#0- +%#0x");
	ft_printf("%-0d");
	ft_printf("%+ d");
}

void	check_fmt_mfw(const char *str, t_fmt fmt)
{
	//need to call in ft_printf
	printf("str:%s\n", str);
	check_fmt_content(fmt);
}

void	test_fmt_mfw(void)
{
	ft_printf("test case 1");
	ft_printf("test case 2%d");
	ft_printf("hoge%#42x");
	ft_printf("fuga %053d");
	ft_printf("%-46236d");
	ft_printf("hoge % 242135d");
	ft_printf("%+7696907d");
	ft_printf("%###2147483647d");
	ft_printf("%+#02147483648d");
	ft_printf("%---   ##2147483898d");
	ft_printf("#0- +%#09223372036854775807x");
	ft_printf("%-09223372036854775808d");
	ft_printf("%+ 9223372036854776058d");
	ft_printf("%18446744073709551615d");
	ft_printf("%18446744073709551616d");
	ft_printf("%18446744073709551658d");
}

int	main(void)
{
	//int res = printf("%d%2147483647s", 1, "hoge");
	//printf("\n%d\n", res);
	//int res = printf("%.0x%.0x", 0, 10);
	//printf("\n%d\n", res);
	//check_fmt_content(ft_fmtnew());
	//check_fmt_point();
	//check_fmt_free();
	//test_fmt_buf1();
	//test_fmt_flags();
	test_fmt_mfw();
	return (0);
}
