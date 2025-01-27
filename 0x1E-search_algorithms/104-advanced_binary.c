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
 * binary_recursive - Recursive helper function for advanced binary search
 * @array: Pointer to the first element of the array
 * @left: Left boundary of current subarray
 * @right: Right boundary of current subarray
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found
 */
int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);
	mid = left + (right - left) / 2;

	/* If element found and it's the first occurrence */
	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);

	/* If element found but might not be first occurrence, or element is greater */
	if (array[mid] >= value)
		return (binary_recursive(array, left, mid, value));

	/* If element is in right half */
	return (binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for first occurrence of value in sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
