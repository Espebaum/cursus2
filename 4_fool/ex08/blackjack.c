#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
	int		sum = 0;
	char 	*str = argv[1];
	if (argc != 2)
		return (0);
	for(int i = 0;i<strlen(str);i++)
	{
		if (isdigit(str[i]))
		{
			sum += str[i] - '0';
		}
		else if (str[i] == 'J' || str[i] == 'K' || str[i] == 'Q')
			sum += 10;
		else if (str[i] == 'A')
		{
			if (sum += 11 > 21)
				sum++;
			else
				sum += 11;
		}
	}
	if (sum != 21)
		printf("%d\n", sum);
	else
		printf("Blackjack!\n");
}
