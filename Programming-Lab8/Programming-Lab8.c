#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND_BOUND (-100)
#define MAX_RAND_BOUND 100
#define RAND_RANGE (MAX_RAND_BOUND - MIN_RAND_BOUND + 1)

int main()
{
	srand(time(NULL));

	int n;
	printf("Enter size of matrix:\n");
	scanf_s("%d", &n);

	int** matrix = calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		matrix[i] = calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % RAND_RANGE + MIN_RAND_BOUND;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	int sum_under_diagonal = 0;
	int sum_above_diagonal = 0;

	for (int i = 0; i < n; i++)
	{
		if (matrix[i][0] < 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (j < i)
				{
					sum_under_diagonal += matrix[i][j];
				}
				else if (j > i)
				{
					sum_above_diagonal += matrix[i][j];
				}
			}
		}
	}

	printf("Sum of the elements of the rows that begin with a negative number that:\n");
	printf("- lay under the main diagonal: %d\n", sum_under_diagonal);
	printf("- lay above the main diagonal: %d\n", sum_above_diagonal);

	for (int i = 0; i < n; i++)
	{
		free(matrix[i]);
	}

	free(matrix);

	getch();
	return 0;
}