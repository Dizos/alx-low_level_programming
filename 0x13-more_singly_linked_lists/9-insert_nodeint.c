#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: index of the list where the new node should be added. Index starts at 0
 * @n: data for the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node;
    listint_t *current = *head;
    unsigned int i;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    for (i = 0; current != NULL && i < idx - 1; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
