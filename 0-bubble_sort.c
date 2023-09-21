#include <stdio.h>

/**
 * swap - Function that swaps the numbers.
 * @x: Pointer to the first number to be looked at.
 * @y: Pointer to the second number to compare.
 *
 * Return: void.
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * bubble_sort - Function that sorts through an array.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				/* Print the array after each swap */
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
