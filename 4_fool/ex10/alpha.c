#include <stdio.h>
#include <ctype.h>


int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	for (int j = 1; j < 27; j++)
	{
		for (int i = 0; argv[1][i]; i++)
		{
			if (isalpha(argv[1][i]))
			{
				printf("%c", argv[1][i] + j);
			}
			else if (argv[1][i] == ' ')
				printf(" ");
		}
		printf("\n");
	}
}