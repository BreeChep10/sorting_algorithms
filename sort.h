#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*data structure*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*prototypes used*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **Head);
void dll_swap(listint_t **node, listint_t **Head);
void merge_sort(int *array, size_t size);
void paste(int *src, int *dest, size_t n);
void divide_conquer(int *array, int *tmp, int min, int max, size_t n);
void sort(int *array, int l_min, int l_max, int r_min, int r_max, int *tmp);
void display(int *array, int min, int max);
void heap_sort(int *array, size_t size);
void heap_tree(int *array, size_t n, size_t size, size_t index);

#endif /*LEEBREE*/
