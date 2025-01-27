#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted linked list using Jump search
 * @list: pointer to the head of the list
 * @size: number of nodes in the list
 * @value: value to search for
 * Return: pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step, step_size;
    listint_t *prev, *curr;

    if (list == NULL || size == 0)
        return (NULL);

    step = sqrt(size);
    curr = list;
    prev = list;

    /* Jump forward */
    while (curr->index < size && curr->n < value)
    {
        prev = curr;
        step_size = step;
        /* Move step nodes forward or until end of list */
        while (step_size > 0 && curr->next != NULL)
        {
            curr = curr->next;
            step_size--;
        }
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, curr->index);

    /* Linear search in the found block */
    curr = prev;
    while (curr->index < size && curr->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        if (curr->n == value)
            return (curr);
        curr = curr->next;
        if (curr == NULL)
            break;
    }

    return (NULL);
}
