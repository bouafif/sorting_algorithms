#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 *              sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}

		print_array(array, size);
	}
}
