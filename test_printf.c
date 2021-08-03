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
}

int	main(void)
{
	//int res = printf("%2s", "hoge");
	//printf("\n%d\n", res);
	//res = printf("%.*s", 3, "hoge");
	//printf("\n%d\n", res);
	t_fmt fmt = ft_fmtnew();
	check_fmt_content(fmt);
	return (0);
}
