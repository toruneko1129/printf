#include <stdio.h>

int	main(void)
{
	int		res;

	//res = printf("%2s", "hoge");
	//printf("\n%d\n", res);
	res = printf("%.*s", 3, "hoge");
	printf("\n%d\n", res);
	return (0);
}
