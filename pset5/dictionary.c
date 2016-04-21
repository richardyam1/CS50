cd/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"


//Create linked list
typedef struct node
{
    char word[LENGTH +1];
    struct node* next;
}
node;

//Creates hash table
node* hashtable[50000];

/*
node* node1 = malloc(sizeof(node));
node* node2 = malloc(sizeof(node));
*/

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE* file = fopen(dictionary, "r");
    if (file = NULL);
    {
        return false;
    }
    
    node* new_node = malloc(sizeof(node));
    fscanf(fp, "%s", new_node->word);
   
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
