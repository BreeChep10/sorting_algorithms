#include "sort.h"

/**
 *heap_tree - uses the heap technique to sort
 *@array: array to sort
 *@size: the size of the array
 *@index: the value index to compare and swap
 *@n: the innitial size of the array
 *Return: nothing
 */
void heap_tree(int *array, size_t n, size_t size, size_t index)
{
	size_t s1, s2;
	int val1, val2, tmp;

	s1 = index * 2 + 1, s2 = s1 + 1;
	val1 = array[s1], val2 = array[s2];

	if ((s1 < size && s2 < size && val1 >= val2 && val1 > array[index])
	    || (s1 + 1 == size && val1 > array[index]))
	{
		tmp = array[index], array[index] = array[s1], array[s1] = tmp;
		print_array(array, n);
	}
	else if ((s1 < size && s2 < size && val2 > val1 && val2 > array[index]))
	{
		tmp = array[index], array[index] = array[s2], array[s2] = tmp;
		print_array(array, n);
	}
	if (s1 < size)
		heap_tree(array, n, size, s1);
	if (s2 < size)
		heap_tree(array, n, size, s2);
}


/**
 *heap_sort - performs a sift-down heap sort
 *@array: the array to sort
 *@size: the size of the array
 *Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int tmp;

	if (!array)
		return;
	for (i = 0; i < size / 2; i++)
		heap_tree(array, size, size, size / 2 - 1 - i);
	for (i = 0; i < size; i++)
	{
		tmp = array[0], array[0] = array[size - 1 - i];
		array[size - 1 - i] = tmp, print_array(array, size);
		heap_tree(array, size, size - 1 - i, 0);
	}
}
