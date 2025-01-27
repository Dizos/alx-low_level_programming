#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at a given position in a listint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to be deleted, starting at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current = *head;
    listint_t *temp_node = NULL;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = current->next;
        free(current);
        return (1);
    }

    for (i = 0; current != NULL && i < index - 1; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
        return (-1);

    temp_node = current->next->next;
    free(current->next);
    current->next = temp_node;

    return (1);
}
