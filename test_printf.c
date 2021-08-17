#include <stdio.h>
#include "./includes/ft_printf.h"

void	check_fmt_content(t_fmt fmt)
{
	printf("<fmt>\n");
	printf("len:%d\n", fmt.len);
	printf("buf:%s\n", fmt.buf);
	printf("hash:%d\n", fmt.hash);
	printf("zero:%d\n", fmt.zero);
	printf("minus:%d\n", fmt.minus);
	printf("space:%d\n", fmt.space);
	printf("plus:%d\n", fmt.plus);
	printf("mfw:%d\n", fmt.mfw);
	printf("point:%d\n", fmt.point);
	if (ft_isprint(fmt.type))
		printf("type:%c\n", fmt.type);
	else
		printf("type:%d\n", fmt.type);
	printf("len2:%d\n", fmt.len2);
	printf("buf2:%s\n", fmt.buf2);
	printf("\n");
}

/*
void	check_fmt_free(void)
{
	t_fmt	fmt;

	fmt = ft_fmtnew();
	fmt.buf = ft_strdup("hoge");
	check_fmt_content(fmt);
	ft_fmtfree(&fmt);
	fmt = ft_fmtnew();
	fmt.buf2 = ft_strdup("fuga");
	check_fmt_content(fmt);
	ft_fmtfree(&fmt);
	fmt = ft_fmtnew();
	fmt.buf = ft_strdup("hoge");
	fmt.buf2 = ft_strdup("fuga");
	check_fmt_content(fmt);
	ft_fmtfree(&fmt);
	check_fmt_content(fmt);
}
*/

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
	ft_printf("24235");
	ft_printf("hoge%#42x");
	ft_printf("fuga %053d");
	ft_printf("%-46236d");
	ft_printf("hoge % 242135d");
	ft_printf("%+7696907d");
	ft_printf("%2147483646d");
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

void	check_fmt_point(const char *str, t_fmt fmt)
{
	//need to call in ft_printf
	printf("str:%s\n", str);
	check_fmt_content(fmt);
}

void	test_fmt_point(void)
{
	ft_printf("test case 1");
	ft_printf("test case 2%d");
	ft_printf("24235");
	ft_printf("hoge%#42x");
	ft_printf("fuga %053.42d");
	ft_printf("%-46236.d");
	ft_printf("hoge % 242135.2147483646d");
	ft_printf("%+7696907.2147483647d");
	ft_printf("%2147483646.2147483648d");
	ft_printf("%###2147483647.0024d");
	ft_printf("%+#02147483648.52d");
	ft_printf("%---   ##.00000000000000000037d");
	ft_printf("#0- +%#.000024608675x");
}

void	check_fmt_type(const char *str, t_fmt fmt)
{
	//need to call in ft_printf
	printf("str:%s\n", str);
	check_fmt_content(fmt);
}

void	test_fmt_type(void)
{
	ft_printf("test case 1");
	ft_printf("test case 2%d");
	ft_printf("24235");
	ft_printf("hoge%#42c");
	ft_printf("fuga %053.42s");
	ft_printf("%-46236.d");
	ft_printf("hoge % 242135.2147483646i");
	ft_printf("%+7696907.2147483647u");
	ft_printf("%2147483646.2147483648x");
	ft_printf("%###2147483647.0024p");
	ft_printf("%+#02147483648.52d");
	ft_printf("%---   ##.00000000000000000037d");
	ft_printf("#0- +%#.000024608675p");
}

void	check_fmt_all(const char *str)
{
	int		res;

	printf("str:%s\n\n", str);
	res = ft_printf(str);
	printf("res:%d\n", res);
	for (int i = 0; i < 25; ++i)
		printf("-");
	printf("\n");
}

void	test_fmt_all(void)
{
	check_fmt_all("test case 1");
	check_fmt_all("test case 2%d");
	check_fmt_all("24235");
	check_fmt_all("hoge%#42c");
	check_fmt_all("fuga %053.42s");
	check_fmt_all("%-46236.d");
	check_fmt_all("hoge % 242135.2147483646i");
	check_fmt_all("%+7696907.2147483647u");
	check_fmt_all("%2147483646.2147483648x");
	check_fmt_all("%###2147483647.0024p");
	check_fmt_all("%+#02147483648.52d");
	check_fmt_all("%---   ##.00000000000000000037d");
	check_fmt_all("#0- +%#.000024608675p");
	check_fmt_all("hoge%dfuga%s");
	check_fmt_all("fuga %053.42s%-46236.d");
	check_fmt_all("hoge%dfuga%shoga");
	check_fmt_all("hoge%pfuga%2147483647u");
}

void	check_output(const char *str, int res)
{
	ft_putstr_fd("\n\nstr:", 1);
	ft_putstr_fd((char *)str, 1);
	ft_putstr_fd("\nres:", 1);
	ft_putnbr_fd(res, 1);
	ft_putchar_fd('\n', 1);
	for (int i = 0; i < 25; ++i)
		ft_putchar_fd('-', 1);
	ft_putchar_fd('\n', 1);
}

void	check_typec(void)
{
	char	*str;
	int		res;

	str = "test:%c";
	res = ft_printf(str, 'a');
	check_output(str, res);
	str = "c:%3c, d:%-5c";
	res = ft_printf(str, 'c', 'd');
	check_output(str, res);
	str = "non ascii:%cyay";
	res = ft_printf(str, '\200');
	check_output(str, res);
	str = "multi flags:%-------4c";
	res = ft_printf(str, '@');
	check_output(str, res);
	str = "invalid:%2147483640c";
	res = ft_printf(str, 'g');
	check_output(str, res);
	str = "hoge:%cfuga:%2147483640c";
	res = ft_printf(str, 'x', 'y');
	check_output(str, res);
	str = "%1c";
	res = ft_printf(str, 'a');
	check_output(str, res);
}

void	check_types(void)
{
	char	*str;
	int		res;

	str = "test:%s";
	res = ft_printf(str, "hogehoge");
	check_output(str, res);
	str = "I'm %s.%s%s";
	res = ft_printf(str, "hkawakit", "Hello", "World");
	check_output(str, res);
	str = "empty string:%s";
	res = ft_printf(str, "");
	check_output(str, res);
	str = "mfw:%6s";
	res = ft_printf(str, "hoge");
	check_output(str, res);
	str = "mfw:%-6s";
	res = ft_printf(str, "hoge");
	check_output(str, res);
	str = "pre:%.6s";
	res = ft_printf(str, "hogefuga");
	check_output(str, res);
	str = "mix:%10.6s";
	res = ft_printf(str, "hogefuga");
	check_output(str, res);
	str = "mix:%-10.6s";
	res = ft_printf(str, "hogefuga");
	check_output(str, res);
	str = "null:%s";
	res = ft_printf(str, NULL);
	check_output(str, res);
	str = "short:%4s";
	res = ft_printf(str, "hogefuga");
	check_output(str, res);
	str = "%2147483647s";
	res = ft_printf(str, "invalid");
	check_output(str, res);
}

void	check_typep(void)
{
	void	*p;
	char	*str;
	int		res;

	p = ft_strdup("hoge");
	printf("p:%p\n", p);
	str = "test:%p";
	res = ft_printf(str, p);
	check_output(str, res);
	str = "minus:%-20p";
	res = ft_printf(str, p);
	check_output(str, res);
	str = "mfw:%20p";
	res = ft_printf(str, p);
	check_output(str, res);
	str = "invalid%2147483640p";
	res = ft_printf(str, p);
	check_output(str, res);
	str = "null:%p%p";
	res = ft_printf(str, 0, 0);
	check_output(str, res);
	str = "%s%c %p";
	res = ft_printf(str, "mix test", ':', p);
	check_output(str, res);
	free(p);

}

void	check_typedi(void)
{
	char	*str;
	int		res;

	str = "test:%d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%010d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "% 010d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "% 0d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%+010d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%+.10d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-5.10d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "test:%d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "%010d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "% 010d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "% 0d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "%+010d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "%+.10d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "%-5.10d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "%10.5d";
	res = ft_printf(str, -42);
	check_output(str, res);
	str = "%10.5d";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-10.5d";
	res = ft_printf(str, 42);
	check_output(str, res);
}

void check_typeu(void)
{
	char	*str;
	int		res;

	str = "%u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%10u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%010u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-010u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%10.5u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-10.5u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%5.10u";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%010.5u";
	res = ft_printf(str, 42);
	check_output(str, res);
}

void check_typex(void)
{
	char	*str;
	int		res;

	str = "%x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%10x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%010x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-010x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%10.5x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-10.5x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%5.10x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%010.5x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%#10x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%-#10x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%0#10x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%0#1x";
	res = ft_printf(str, 42);
	check_output(str, res);
	str = "%0#0x";
	res = ft_printf(str, 0);
	check_output(str, res);
	str = "%#x";
	res = ft_printf(str, 0);
	check_output(str, res);
}

void	check_typeper(void)
{
	char	*str;
	int		res;

	str = "%%";
	res = ft_printf(str);
	check_output(str, res);
	str = "%%%%";
	res = ft_printf(str);
	check_output(str, res);
	str = "hoge%%%%fuga%%";
	res = ft_printf(str);
	check_output(str, res);
	str = "%10.5%";
	res = ft_printf(str);
	check_output(str, res);
	str = "%-+ 10%";
	res = ft_printf(str);
	check_output(str, res);
}

void	test_typec(int argc)
{
	
}

int	main(int argc, char **argv)
{
	//int res = printf("%d%2147483647s", 1, "hoge");
	//printf("\n%d\n", res);
	//int res = printf("%.0x%.0x", 0, 10);
	//printf("\n%d\n", res);
	//check_fmt_content(ft_fmtnew());
	//check_fmt_free();
	//test_fmt_buf1();
	//test_fmt_flags();
	//test_fmt_mfw();
	//test_fmt_point();
	//test_fmt_type();
	//test_fmt_all();
	//check_typec();
	//check_types();
	//check_typep();
	//check_typedi();
	//check_typeu();
	//check_typex();
	//check_typeper();
	return (0);
}
