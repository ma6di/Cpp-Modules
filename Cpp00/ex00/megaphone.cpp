#include <iostream>

void	lowerToUpper(char *str)
{
	int i;

	i = 0;
	while ((str)[i])
	{
		if ((str)[i] >= 'a' && (str)[i] <= 'z')
			(str)[i] -= 32;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)		
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
        for (int i = 1; i < argc; ++i)
        {
            lowerToUpper(argv[i]);
            std::cout << argv[i];
        }
		std::cout << std::endl;
	}
	return (0);
}