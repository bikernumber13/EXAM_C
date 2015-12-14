#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
		write(1, &c, 1);
}

void	ft_solve(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * 2048)))
		return ;
	while (i < 2048)
		ptr[i++] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			ptr++;
		else if (str[i] == '<')
			ptr--;
		else if (str[i] == '+')
			(*ptr)++;
		else if (str[i] == '-')
			(*ptr)--;
		else if (str[i] == '.')
			ft_putchar(*ptr);
		else if ((str[i] == '[') && ((*ptr) == 0))
		{
			j = 1;
			while (j)
			{
				i++;
				if (str[i] == ']')
					j--;
				else if (str[i] == '[')
					j++;
			}
		}
		else if (str[i] == ']')
		{
			j = 1;
			while (j)
			{
				i--;
				if (str[i] == '[')
					j--;
				else if (str[i] == ']')
					j++;
			}
			i--;
		}
		i++;
	}
}

int	main(int ac, char ** av)
{
	if (ac == 2)
		ft_solve(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
