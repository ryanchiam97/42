#include <string>
#include <iostream>

void toUpperString (char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		toUpperString(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}
