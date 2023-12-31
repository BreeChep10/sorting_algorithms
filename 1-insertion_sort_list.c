#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order.
 * @list: Double pointer to the head of the list.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap temp and its previous node */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			/* Adjust the previous node's next pointer */
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			/* Print the list after each swap */
			print_list(*list);
		}
		current = current->next;
	}
}
