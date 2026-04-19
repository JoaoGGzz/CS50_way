// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 756;

// Hash table
node *table[N];

// Global word counting variable
int words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash the word received
    unsigned int hash_bucket_number = hash(word);

    // Go to hash bucket, using a aux cursor
    node *tmp = table[hash_bucket_number];

    // Loop each element
    while (tmp != NULL)
    {
        // Check if the word is the same
        if (strcasecmp(tmp->word, word) == 0)
        {
            // Return true if was found
            return true;
        }

        // Update cursor
        tmp = tmp->next;
    }

    // Return false if was not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // Mapping possible words to my whole bucket size
    unsigned int mapping_first_word = 0;
    unsigned int mapping_second_word = 0;

    // Deal with small word (One letter only)
    if (word[1] == '\0')
    {
        // Mapping the first word without extra checkings because the current problem contract don't allow entering word type here
        mapping_first_word = toupper(word[0]) - 'A';

        // Returning the bucket value (Will be stored at the first bucket set)
        return mapping_first_word;
    }

    // Dealing with words bigger than one letter
    else
    {
        // First and second word mapping
        mapping_first_word = toupper(word[0]) - 'A';

        if (isalpha(word[1]))
        {
            mapping_second_word = toupper(word[1]) - 'A';
        }

        else if (word[1] == '\'')
        {
            mapping_second_word = 26;
        }
    }

    // Applying in kind of 'offset' number to always jump the only one letter condition
    return (((mapping_first_word * 27) + 27) + mapping_second_word);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *dict_file = fopen(dictionary, "r");

    // Check if file dict_file wasn't opened
    if (dict_file == NULL)
    {
        printf("Couldn't load dictionary.\n");
        return false;
    }

    // Initialize Hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Creating the variables to read a word
    char letter;
    char word[LENGTH + 1];
    int index = 0, hash_number = 0;
    bool valid = true;

    // Reseting words counter in case of load be called twice or more
    words = 0;

    // Reading each letter
    while (fread(&letter, sizeof(char), 1, dict_file))
    {
        // First state (WORD IN CONSTRUCTION): Assembling a valid word
        // Checking if the current letter is valid (Alphabetical, apostrophe and not more than length) to append
        if (isalpha(letter) || letter == '\'')
        {
            // Appending the letters to create a complete word if it doesn't overflow the buffer
            if (index < LENGTH)
            {
                word[index] = letter;
                index++;
            }

            // Second state (INVALID WORD): Doesn't assemble if the limit was reached
            // If index bigger than the limit, the word becomes invalid
            else
            {
                valid = false;
            }
        }

        // Third state (ENDING THE WORD): Stop when reachs the end of the word and check
        else if (letter == '\n' && index > 0)
        {
            // If word current stored is valid
            if (valid)
            {
                // To create a word need to apply null character at the end
                word[index] = '\0';

                // Creating the block on memory to store the word
                node *n = malloc(sizeof(node));

                // Checking if malloc was successfull
                if (n == NULL)
                {
                    printf("Can't malloc.\n");
                    fclose(dict_file);
                    return false;
                }

                // Storing the current word and initializating the next pointer
                strcpy(n->word, word);
                n->next = NULL;

                // Call hash function to define which bucket to store
                hash_number = hash(word);

                // CURRENT WAY TO STORE WORDS IN BUCKTES LIKE SINGLY-LINKED-LIST
                if (table[hash_number] != NULL)
                {
                    n->next = table[hash_number];
                    table[hash_number] = n;
                }

                // Special condition: First node added into table[N]
                else
                {
                    table[hash_number] = n;
                }

                // Counting words loaded
                words++;

                // Reseting index indicator
                index = 0;

                // Reseting the valid indicator
                valid = true;
            }

            // If the word isn't valid just reset index and valid signal
            else
            {
                index = 0;
                valid = true;
            }
        }

        // Fourth state (INVALID WORD FOUND):Dealing with other cases (Symbols not allowed)
        else
        {
            // Sinalizing my current word became invalid
            valid = false;
        }
    }

    // Close the file opened
    fclose(dict_file);

    // Return true if all do well
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // FIRST APPROACH: Just use words counted in load function
    return words;

    // // SECOND APROACH: Count the words in table[N] traversing it. BAD DESIGN for speller.
    // unsigned int word_counter = 0;

    // // Loop into table[N]
    // for (int i = 0; i < N; i++)
    // {
    //     if (table[i] != NULL)
    //     {
    //         // Creating a cursor to navigate through
    //         node *temp = table[i];
    //         // Can I assume that if a table[i] isn't NULL, does it have a word?
    //         // Adding one to count the first node
    //         word_counter++;

    //         // If my next pointer isn't NULL, loop into it
    //         while (temp != NULL)
    //         {
    //             // Add one to word counter
    //             word_counter++;

    //             // Updating the current table[i] pointer to the next one
    //             temp = temp->next;
    //         }
    //     }
    // }

    // return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Aux node variable to store next position
    node *next_node = NULL;

    // Loop through the hash table
    for (int i = 0; i < N; i++)
    {
        // Iterate through the bucket's elements
        while (table[i] != NULL)
        {
            // Store the next element
            next_node = table[i]->next;

            // Free the current element
            free(table[i]);

            // Update the cursor to the stored element
            table[i] = next_node;
        }

        // WHEN I ASKED AI OPINION IT SHOWED ME THIS ANSWER:
        // UNNECESSARY IF STATMENT BECAUSE PREVIOUS WHILE ALREADY DO THAT CHECK AND IT WILL DELIVER A TABLE[I] = NULL BY CONSTRUCTION
        // Check if the bucket was cleared
        // if (table[i] != NULL)
        // {
        //     return false;
        // }

    }

    return true;
}
