# include <stdio.h>
# include <stdlib.h>

/**
Take in positive int
Display its prime factors on stdout
	- In ascending order
	- Separated by "*"
Display newline
 */

/**
	1, 3, 5, 7, 11, 13, 17, 19, 23, 29
	i, i + 2, i + 2, i + 4, i + 2, i + 4,...
 */
int is_prime(int value)
{
	int i;

	i = 2;
	if (value <= 1)
		return 0;

	while (value / i >= i){
		if (value % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[]){
	if (argc == 2){
		if (!argv[1] || argv[1][0] == '-'){
			return (printf("\n"));
		}

		int value = atoi(argv[1]);

		if (value == 1){
			printf("1");
		}
		
		int i = 2;

		// e.g. 42

		// while (remainder >= 0)
			// (42 % 2) > 0
			// (21 % 3) == 0
			// (7 % 5) == 2 -> >=0
		while (value % i >= 0){
			printf("%i", i); // 235

			value = value / i; //21 //7 //1

			if (value == 1){
				break;
			}
			printf("*"); // 2*3*5*
			if (value % i != 0) // 21 % 2 != 0
			{
				// Check if checker is prime number
				i++; // i = 3
				while (is_prime(i) == 0){
					i++;
				}
			}
		}

		
	}
	printf("\n");
}