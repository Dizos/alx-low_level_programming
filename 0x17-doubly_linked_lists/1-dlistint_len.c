#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a dlistint_t list
 * @h: Pointer to the head of the list
 * Return: Number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
    const dlistint_t *current = h;
    size_t count = 0;

    if (h == NULL)
        return 0;

    // Move to the last node
    while (current->next != NULL)
        current = current->next;

    // Count nodes moving backwards
    do {
        count++;
        current = current->prev;
    } while (current != NULL);

    return count;
}
