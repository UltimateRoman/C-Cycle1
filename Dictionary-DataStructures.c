// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Size of the dictionary
int dict_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);// Hashes given word
    node *temp = table[h];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp->word) == 0)// Compares words case-insensitively
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int h;
    h = toupper(word[0]) - 65;
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r"); // Opens file in read mode
    if (dict == NULL)
    {
        return false;
    }
    char dword[LENGTH + 1];
    while (fscanf(dict, "%s", dword) != EOF) // Reads through the file
    {
        int h = hash(dword);
        node *in = malloc(sizeof(node));
        if (in == NULL)
        {
            return false;
        }
        strcpy(in->word, dword);
        if (table[h] == NULL)
        {
            table[h] = in;
            table[h]->next = NULL;
        }
        else
        {
            in->next = table[h];
            table[h] = in;
        }
        dict_size++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (dict_size > 0)
    {
        return dict_size;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *t = table[i];
        while (t != NULL)
        {
            node *d = t;
            t = t->next;
            free(d); // Frees memory
        }
    }
    return true;
}
