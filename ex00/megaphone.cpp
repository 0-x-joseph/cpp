#include <iostream>

void	toupper(char *str);

int	main(int ac, char *av[]) {
	int	i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		i = 1;
		while (av[i]) {
			toupper(av[i]);
			std::cout << av[i];
			if (av[i + 1])
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

void	toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i]) {
		if ( (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= str[i] >= 'a' ? 32 : 0;

		i++;
	}
}
