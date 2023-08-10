// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100;
int nrwords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int has = hash(word);
    if (table[has] == NULL)
    {
        return false;
    }
    for (node *ptr = table[has]; ptr != NULL; ptr = ptr->next)
    {
        if(strcasecmp(ptr->word, word)==0)
            return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {

        hash+= toupper(word[i]);

    }

    hash %= 100;
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char wordf[LENGTH +1];
    int has = 0;

    while (fscanf(file, "%s", wordf)!=EOF)
    {
        has = hash(wordf);
        node* ptr = malloc(sizeof(node));
        if(ptr == NULL)
        {
            return false;
        }

        ptr->next = NULL;
        strcpy(ptr->word,wordf);

        if(table[has] == NULL)
        {
            table[has] = ptr;
        }
        else
        {
            ptr->next = table[has];
            table[has] = ptr;
        }
        nrwords++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return nrwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i=0; i<100; i++)
    {
        node* ptr = table[i];
        if (ptr == NULL)
            continue;

        while(ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;

        }

    }
    return true;
}
