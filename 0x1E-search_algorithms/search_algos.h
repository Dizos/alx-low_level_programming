#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stddef.h>
#include <math.h>

/**
 * @brief Searches for a value in an array using Linear search algorithm
 * @param array Pointer to the first element of the array to search in
 * @param size Number of elements in the array
 * @param value Value to search for
 * @return Index where value is located, or -1 if not found or array is NULL
 */
int linear_search(int *array, size_t size, int value);

int binary_search(int *array, size_t size, int value);

int exponential_search(int *array, size_t size, int value);

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

listint_t *jump_list(listint_t *list, size_t size, int value);

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);
#endif /* SEARCH_ALGOS_H */
