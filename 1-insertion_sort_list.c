#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;

			if (curr->next != NULL)
				curr->next->prev = prev;

			prev->next = curr->next;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;

			prev = curr->prev;
			print_list(*list);
		}

		curr = curr->next;
	}
}
