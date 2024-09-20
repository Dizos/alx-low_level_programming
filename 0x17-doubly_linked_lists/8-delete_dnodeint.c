int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    for (i = 0; i < index; i++)
    {
        if (current->next == NULL)
            return (-1);
        current = current->next;
    }

    if (current->next != NULL)
        current->next->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    return (1);
}
