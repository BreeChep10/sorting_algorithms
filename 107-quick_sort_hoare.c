#include "sort.h"

/**
 * hoare_partition - Partition array using Hoare's scheme.
 * @array: The array to be partitioned.
 * @low: The starting index.
 * @high: The ending index.
 * @size: The size of the array.
 * Return: The index of the pivot element.
 */
int hoare_partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int left = low - 1;
	int right = high + 1, temp;

	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);
		do {
			right--;
		} while (array[right] > pivot);
		if (left >= right)
			return (left);
		if (left != right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			print_array(array, size);
		}
	}
}

/**
 * quick_sort_recursive - Recursive function for quick sort.
 * @array: The array to be sorted.
 * @low: The low index of the subarray.
 * @high: The high index of the subarray.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the quicksort algorithm with Hoare's partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
