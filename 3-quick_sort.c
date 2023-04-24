#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 *
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - helper function for quick_sort that uses recursion
 *
 * @array: the array to be sorted
 * @lo: the low index of the array
 * @hi: the high index of the array
 * @size: size of the array
 */
void quick_sort_rec(int *array, ssize_t lo, ssize_t hi, size_t size)
{
    ssize_t pivot;

    if (lo < hi)
    {
        pivot = partition(array, lo, hi, size);
        quick_sort_rec(array, lo, pivot - 1, size);
        quick_sort_rec(array, pivot + 1, hi, size);
    }
}

/**
 * partition - function that creates a partition in the array
 *
 * @array: the array to be partitioned
 * @lo: the low index of the array
 * @hi: the high index of the array
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
ssize_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
    int pivot, temp;
    ssize_t i, j;

    pivot = array[hi];
    i = lo - 1;

    for (j = lo; j <= hi - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }
    if (array[i + 1] > array[hi])
    {
        temp = array[i + 1];
        array[i + 1] = array[hi];
        array[hi] = temp;
        print_array(array, size);
    }

    return (i + 1);
}
