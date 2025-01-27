#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stddef.h>

/**
 * @brief Searches for a value in an array using Linear search algorithm
 * @param array Pointer to the first element of the array to search in
 * @param size Number of elements in the array
 * @param value Value to search for
 * @return Index where value is located, or -1 if not found or array is NULL
 */
int linear_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
