#include "../includes/stack.h"

void	bubbleSort(int *arr, int count)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < count)
	{
		j = i;
		while (++j < count)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
