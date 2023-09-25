#include "sort.h"
#define f printf


/**
 *paste - duplicates an array
 *@src: the source array
 *@dest: the array to copy the contents to
 *@n: the size of the array
 *Return: nothing
 */
void paste(int *src, int *dest, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
}

/**
 *divide_conquer - a function to perform the divide conquer of mergesort
 *@array: the array input
 *@tmp: the copy of the array
 *@min: the minimum of the array
 *@max: the max of the array
 *@n: the size of the array
 *Return: nothing
 */
void divide_conquer(int *array, int *tmp, int min, int max, size_t n)
{
	int mid, left_min, left_max, right_min, right_max, copy;

	if (max <= min)
		return;

	mid = (max + min + 1) / 2;
	copy = max, max = mid - 1, left_min = min, left_max = max;
	divide_conquer(array, tmp, min, max, n);

	min = mid, max = copy, right_min = mid, right_max = copy;
	divide_conquer(array, tmp, min, max, n);

	f("Merging...\n"), f("[left]: ");
	display(array, left_min, left_max);
	f("[right]: ");
	display(array, right_min, right_max);

	sort(array, left_min, left_max, right_min, right_max, tmp);
	f("[Done]: ");
	display(array, left_min, right_max);
	paste(array, tmp, n);
}

/**
 *sort - helps do the merge sort
 *@array: the array input
 *@l_min: the minimum of the left sort
 *@l_max: the maximum of the left sort
 *@r_min: the minimum of the right sort
 *@r_max: the maximum of the right sort
 *@tmp: the copy of the array
 *
 *
 *Return: nothing
 */
void sort(int *array, int l_min, int l_max, int r_min, int r_max, int *tmp)
{
	int i, j, k;

	i = k = l_min, j = r_min;


	while (i <= l_max || j <= r_max)
	{
		if (i <= l_max && j <= r_max)
		{
			if (tmp[i] <= tmp[j])
				array[k++] = tmp[i++];
			else
				array[k++] = tmp[j++];
		}
		else if (i > l_max && j <= r_max)
			array[k++] = tmp[j++];
		else
			array[k++] = tmp[i++];
	}
}

/**
 *merge_sort - performs the merge sort
 *@array: the input array
 *@size: the size of the array
 *Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	tmp = malloc(size * sizeof(int));
	if (!tmp)
		return;

	paste(array, tmp, size);
	divide_conquer(array, tmp, 0, size - 1, size);
	free(tmp);
}

/**
 *display - prints a  display to the standard output
 *@array: the array to print
 *@min: the lower range
 *@max: the upper range
 *return: nothing
 */
void display(int *array, int min, int max)
{
	int i;

	for (i = min; i <= max; i++)
	{
		f("%d", array[i]);
		if (i != max)
			f(", ");
	}
	f("\n");
}
