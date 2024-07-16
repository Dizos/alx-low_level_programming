#include <stdlib.h>
#include "main.h"

int count_words(char *str)
{
    int count = 0, in_word = 0;
    while (*str)
    {
        if (*str == ' ')
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return (count);
}

char **strtow(char *str)
{
    char **words, *word;
    int i, j, k, len = 0, word_count, word_len;
    if (str == NULL || *str == '\0')
        return (NULL);
    word_count = count_words(str);
    if (word_count == 0)
        return (NULL);
    words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    for (i = 0, j = 0; i < word_count; i++)
    {
        while (str[j] == ' ')
            j++;
        len = 0;
        while (str[j + len] != ' ' && str[j + len] != '\0')
            len++;
        word = malloc((len + 1) * sizeof(char));
        if (word == NULL)
        {
            for (k = 0; k < i; k++)
                free(words[k]);
            free(words);
            return (NULL);
        }
        for (k = 0; k < len; k++)
            word[k] = str[j + k];
        word[len] = '\0';
        words[i] = word;
        j += len;
    }
    words[word_count] = NULL;
    return (words);
}
