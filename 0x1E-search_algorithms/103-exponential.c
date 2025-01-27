#include "search_algos.h"

/**
 * print_array - Prints an array between two indices
 * @array: The array to print
 * @left: Starting index
 * @right: Ending index
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
 * binary_search_exp - Binary search implementation for exponential search
 * @array: Pointer to the first element of the array
 * @left: Left boundary
 * @right: Right boundary
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found
 */
int binary_search_exp(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;

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
 * exponential_search - Searches for value using Exponential search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index where value is located, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t right;

	if (array == NULL || size == 0)
		return (-1);

	/* If first element is the value we're looking for */
	if (array[0] == value)
		return (0);

	/* Find range for binary search using exponential growth */
	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	/* Set right boundary for binary search */
	right = (bound < size - 1) ? bound : size - 1;

	/* Print the range message */
	printf("Value found between indexes [%lu] and [%lu]\n",
			bound / 2, right);

	/* Perform binary search */
	return (binary_search_exp(array, bound / 2, right, value));
}
