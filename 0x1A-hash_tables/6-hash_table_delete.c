#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 *
 * Description: Frees all memory associated with the hash table,
 * including the nodes, keys, values, array, and the table itself
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node, *temp;

    if (ht == NULL)
        return;

    /* Iterate through the array */
    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        /* Free all nodes in the linked list at this index */
        while (node != NULL)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }

    /* Free the array and the hash table structure */
    free(ht->array);
    free(ht);
}
