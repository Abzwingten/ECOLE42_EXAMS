#include <unistd.h>
static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int ft_contain_until(char c, const char *s, int max_i)
{
	int i = 0;
	i = 0;

	while (i < max_i && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return(0);
}

static void ft_inter(const char *s1, const char *s2)
{
	int i;
	i = 0;
	while (s1[i])
	{
		if (!ft_contain_until(s1[i], s1, i) && \
			ft_contain_until(s1[i], s2, 100000))
				ft_putchar(s1[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
