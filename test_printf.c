#include <stdio.h>
#include "./includes/ft_printf.h"

void	check_fmt_content(t_fmt fmt)
{
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
	printf("\n");
}

void	check_fmt_point(void)
{
	t_fmt	fmt;

	fmt = ft_fmtnew();
	fmt.type = 's';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt.type = 'd';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt.type = 'i';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt.type = 'u';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
	fmt.type = 'x';
	ft_noprecision(&fmt);
	check_fmt_content(fmt);
}

int	main(void)
{
	//int res = printf("%d%2147483647s", 1, "hoge");
	//printf("\n%d\n", res);
	//int res = printf("%.0x%.0x", 0, 10);
	//printf("\n%d\n", res);
	check_fmt_point();
	return (0);
}
