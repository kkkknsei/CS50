// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
const unsigned int N = 1000;

// Hash table
node *table[N];

unsigned int words = 0;
bool loaded = false;

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    int n;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' - 1;
        }
        else
        {
            n = 27;
        }

        hash = ((hash << 3 ) + n) % N; 
    }
    return hash;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char checkword[strlen(word)];
    strcpy(checkword, word);
    
    for (int i = 0; checkword[i] != '\0'; i++)
    {
        checkword[i] = tolower(checkword[i]);
    }
    
    int a = hash(checkword);
    if (table[a] != NULL)
    {
        for (node* nodeptr = table[a]; nodeptr != NULL; nodeptr = nodeptr->next)
        {
            if (strcmp(nodeptr->word, checkword) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE* file = fopen(dictionary, "r");
    
    if (file == NULL)
    {
        printf("INVALID\n");
        return false;
    }
    
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    node* nodeptr2;
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        words++;
        do
        {
            nodeptr2 = malloc(sizeof(node));

            if (nodeptr2 == NULL)
            {
                free(nodeptr2);
            }
        }
        while(nodeptr2 == NULL);

        strcpy(nodeptr2->word, word);

        int a = hash(word);

        nodeptr2->next = table[a];
        table[a] = nodeptr2;
    }
    
    fclose(file);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!loaded)
    {
        return 0;
    }
    
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!loaded)
    {
        return false;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node* ptr = table[i];

            while (ptr != NULL)
            {
                node* storeptr = ptr;
                ptr = ptr->next;
                free(storeptr);
            }
        }
    }
    return true;
}
