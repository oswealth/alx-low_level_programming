#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The starting index of the subarray to print
 * @right: The ending index of the subarray to print
 */
void print_array(const int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence of a value
 * @array: Pointer to the first element of the array to search in
 * @left: The starting index of the subarray to search
 * @right: The ending index of the subarray to search
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right >= left)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;

		if ((mid == left || value > array[mid - 1]) &&
				array[mid] == value)
			return (mid);

		if (array[mid] >= value)
			return (recursive_search(array, left, mid, value));

		return (recursive_search(array, mid + 1, right, value));
	}

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if value is not present or
 * array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
