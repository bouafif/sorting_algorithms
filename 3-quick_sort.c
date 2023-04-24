#include "sort.h"
/**
 * swap - swaps two values
 * @a: first integer
 * @b: second integer
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
 * partition - partitions an array using Lomuto partition scheme
 * @array: the array to be sorted
 * @low: the lowest index of the partition to be sorted
 * @high: the highest index of the partition to be sorted
 * @size: size of the array
 * Return: index of the partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

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

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - sorts an array of integers using quicksort
 * @array: the array to be sorted
 * @low: the lowest index of the partition to be sorted
 * @high: the highest index of the partition to be sorted
 * @size: size of the array
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using quicksort
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
	{
		quicksort(array, 0, size - 1, size);
	}
}
