#include "sort.h"

/**
 * partition - Partitions an array using Hoare's scheme.
 * @array: The array to partition.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 * Return: The pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1, temp;
	size_t k;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);


		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		for (k = 0; k < size; k++)
		{
			if (k != 0)
				printf(", ");
			printf("%d", array[k]);
		}
		printf("\n");
	}
}

/**
 * quicksort - Sorts an array using the quicksort algorithm.
 * @array: The array to sort.
 * @low: The low index of the array.
 * @high: The high index of the array.
 * @size: The size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quicksort(array, low, pivot, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Initiates the quicksort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
