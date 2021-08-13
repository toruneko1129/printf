#include "../includes/ft_printf.h"

static void	ft_init(unsigned int n, int *len)
{
	*len = 0;
	if (n == 0)
		*len = 1;
	while (n)
	{
		++(*len);
		n /= 10;
	}
}

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		len;

	ft_init(n, &len);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
		*res = '0';
	while (n)
	{
		--len;
		*(res + len) = '0' + n % 10;
		n /= 10;
	}
	return (res);
}

static void	ft_init_hex(unsigned int n, int *len)
{
	*len = 0;
	if (n == 0)
		*len = 1;
	while (n)
	{
		++(*len);
		n /= 16;
	}
}

char	*ft_uitoa_hex(unsigned int n)
{
	char	*res;
	int		len;

	ft_init_hex(n, &len);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
		*res = '0';
	while (n)
	{
		--len;
		if (n <= 9)
			*(res + len) = '0' + n % 16;
		else
			*(res + len) = 'a' + n % 16 - 10;
		n /= 16;
	}
	return (res);
}
