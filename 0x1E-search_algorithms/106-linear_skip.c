#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or if list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *prev;

    /* Check if list is NULL */
    if (!list)
        return (NULL);

    /* Initialize express pointer to current node's express lane */
    express = list->express;
    prev = list;

    /* Print first node being checked */
    printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

    /* While we have an express lane and haven't found the value */
    while (express && express->n < value)
    {
        /* Update prev to last express node checked */
        prev = express;
        /* Move to next express node */
        express = express->express;
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    }

    /* If we've reached end of express lane */
    if (!express)
    {
        /* Find the last node in the list */
        express = prev;
        while (express->next)
            express = express->next;
    }

    /* Print the range where value might be found */
    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, express->index);

    /* Search in the identified range */
    while (prev && prev->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    /* Value not found */
    return (NULL);
}
