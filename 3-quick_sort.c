#include "sort.h"

/**
 * swap - Swaps two elements of an array
 * @a: first element to be swapped
 * @b: second element to be swapped
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Takes last element as pivot, places the pivot element
 * at its correct position in sorted array and places all smaller (smaller
 * than pivot) to left of pivot and all greater elements to right of pivot
 * @array: array to sort
 * @low: starting index of array
 * @high: ending index of array
 * @size: size of the array
 * Return: index of pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort - implementation of quicksort algorithm
 * @array: array to sort
 * @low: starting index of array
 * @high: ending index of array
 * @size: size of the array
 * Return: void
 */
void sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		sort(array, low, pi - 1, size);
		sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
