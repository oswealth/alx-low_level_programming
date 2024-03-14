#include "search_algos.h"

/**
 * min - Returns the minimum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The smaller of a and b
 */
int min(int a, int b)
{
	return (a < b ? a : b);
}


/**
 * binary_search - Helper function to perform binary search
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;
	size_t i;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of
 * integers using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if
 * value is not present or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t low, high;
	int result;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound,
				array[bound]);
		bound *= 2;
	}
	low = bound / 2;
	high = min(bound, size - 1);

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	result = binary_search(array + low, high - low + 1, value);

	if (result != -1)
	{
		return (result + low);
	}
	else
	{
		return (-1);
	}
}
