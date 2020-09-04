// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table = 2^16
const unsigned int N = 65536;
//variable to count the number of words
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len = strlen(word);
    char tmp_word[len + 1];    //+1 for null terminating character
    tmp_word[len] = '\0';
    //copy the word to tmp_word.
    for (int a = 0; a < len; a++)
    {
        tmp_word[a] = word[a];
    }
    //get the hash code for the word to be checked.
    unsigned int hash_index = hash(tmp_word);
    //creating a node to iterate through the linked list.
    node* tmp = table[hash_index];
    if (tmp == NULL)
    {
        return false;
    }
    while (tmp != NULL)
    {
         if(strcasecmp(tmp->word, tmp_word) == 0)
           {
               return true;   //found
           }

         tmp=tmp->next;   //keep traversing.
    }
    return false;     //Not found.
}

// Hashes word to a number
//source -> https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

    int c = *word;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    //array to store the characters of words
    char buffer[LENGTH + 1];

    //set all the pointers in the hash table to NULL;
    for (unsigned int i = 0; i < N; i++)
      {
        table[i] = NULL;
      }

    //The following loop continues until end of file is reached.
    while(fscanf(fp, "%s", buffer) != EOF)
    {
      //create a new node for the word.
      node *new = malloc(sizeof(node));
      if (new == NULL)
      {
          fclose(fp);     //close the file.
          return false;
      }
      //copy the word to the node.
      strcpy(new->word, buffer);
      new->next = NULL;
      // Hash the word to a number
      unsigned int index = hash(buffer);

      //Insert the node to the hash table.
      /*the pointers should be set in correct order to
       prevent the orphaning of rest of the nodes*/
          new->next = table[index];
          table[index] = new;
      //update the word_count until the end of the file.
          word_count++;
    }
    //close the file and return true.
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //create two nodes to free the memory.
    node *tmp1;
    node *tmp2;
    for (unsigned int i = 0; i < N; i++)
    {
      tmp1 = table[i];
      while(tmp1 != NULL)
      {
          tmp2 = tmp1->next;
          free(tmp1);
          tmp1 = tmp2;
      }
    }
    return true;
}
