#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **deep_copy(char **str, char *t)
{
	char **ret;
	if (!str)
	{
		ret = malloc(sizeof(char *) * 2);
		ret[0] = strdup(t);
		ret[1] = 0;
		return ret;
	}
	else
	{
		int i = 0;
		while (str[i])
			i++;
		ret = malloc(sizeof(char *) * (i + 2));
		ret[i + 1] = 0;
		ret[i] = strdup(t);
		while (--i >= 0)
		{
			ret[i] = str[i];
		}
		free(str);
		return ret;
	}

}

void print_frame(char *argv)
{

	char **str = 0;
	char *t;
	int	size = 0;
	int max = 0;
	t = strtok(argv, " ");
	while (t != NULL)
	{
		size++;
		if (max < strlen(t))
			max = strlen(t);
		str = deep_copy(str, t);
		t = strtok(NULL, " ");
	}
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < max + 4; j++)
		{
			if (i == 0 || j == 0 || i == size + 1 || j == max + 3)
				write(1, "*", 1);
			else if (j == 1 || j >= strlen(str[i - 1]) + 2)
				write(1, " ", 1);
			else
				write(1, &str[i - 1][j - 2], 1);
		}
		write(1, "\n", 1);
	}
	for (int i = 0; str[i]; i++)
		free(str[i]);
	free(str);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	for(int i = 1; argv[i]; i++)
	{
		print_frame(argv[i]);
		if (argc - 1 != i)
			write(1, "\n", 1);
	}
	system("leaks a.out");
}