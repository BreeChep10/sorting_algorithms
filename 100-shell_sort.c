#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort.
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				/* Swap elements with a gap */
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		/* Print the array each time the interval decreases */
		print_array(array, size);

		/* Calculate the next gap using the Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
