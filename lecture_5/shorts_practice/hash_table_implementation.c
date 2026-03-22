#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

// Size of our table of bucktes, based on alphabet letters
#define SIZE 26

// Singly linked list struct
typedef struct _node
{
    char *name;
    struct _node *next;
} node;

// Prototypes
unsigned int hash(char *user_name);
void insert_hash(node **table, char *user_name);
void print_hash(node *table[]);
char *delete_hash(node **bucket, char *user_name);
char *search_hash(node **table, char *user_name);

int main(void)
{
    // Creating the buckets of our hash table with NULL to ensure a clear initial table
    node *table[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = NULL;
    }

    // Looping indefinitely
    while (true)
    {
        // Taking user's choice
        int looping_variable = get_int("\n1 - Insert Hash | 2 - Delete Hash | 3 - Lookup | 4 - Exit \nUser choice: ");

        // Inserting itens into a hash table
        if ( looping_variable == 1)
        {
            // User's name input
            char *user_input = get_string("Name to insert: ");

            // Applying hash function
            unsigned int n = hash(user_input);

            // Calling the insert function
            insert_hash(&table[n], user_input);

            // Printing the current hash table
            print_hash(table);
        }

        // Deleting itens from a hash table
        else if (looping_variable == 2)
        {
            // User's name to search and delete
            char *user_input = get_string("Name to remove: ");

            // Applyinh hash function
            unsigned int n = hash(user_input);

            // Calling delete function and storing the name deleted
            char *removed_name = delete_hash(&table[n], user_input);

            // Printing current hash table
            print_hash(table);

            // Printing the removed name just to simulate an usage for it
            printf("Check name removed: %s\n", removed_name);
        }

        // Searching names on hash table
        else if (looping_variable == 3)
        {
            // Receiving user's input name
            char *user_input = get_string("Name to search: ");

            // Calling search function
            char *name_to_search = search_hash(table, user_input);

            // Printing the name found and simulating an usage for search function return
            printf("%s\n", name_to_search);

            // Printing current hash table
            print_hash(table);
        }

        // Exit condition
        else if (looping_variable == 4)
        {
            printf("Program closed.\n");
            break;
        }
    }
}

// Hash function
unsigned int hash(char *user_name)
{
    // Creating a unsigned number using the -A logic calculus to always have a number between 0 to 25
    unsigned int hash_number = toupper(user_name[0]) - 'A';

    // Returning the generated number
    return hash_number;
}

// Inserting hash table function
void insert_hash(node **bucket, char *user_name)
{
    // Creating the block of memory to store the name and next pointer and starting the linked list process
    node *element = malloc(sizeof(node));
    if (element == NULL)
    {
        printf("Can't malloc.\n");
        return;
    }

    // Storing the name on it and NULL to next pointer
    element->name = user_name;
    element->next = NULL;

    // Special condition: Bucket on hash table with no elements
    if (*bucket == NULL)
    {
        *bucket = element;
    }

    // Another condition: Bucket with elements and dealing with the linked list process
    else
    {
        element->next = *bucket;
        *bucket = element;
    }
}

// Printing current hash table elements
void print_hash(node *table[])
{
    // Sentinel to sinalize if the list is empty or not
    int list_empty_sentinel = 0;

    // Looping all possible buckets
    for (int i = 0; i < SIZE; i++)
    {
        // Copy of bucket head to deal without messing up
        node *tmp = table[i];

        // Looping on it
        while (tmp != NULL)
        {
            // Printinf the current name and table buckte from
            printf("Table[%i]: %s\n", i, tmp->name);

            // Updating the next element
            tmp = tmp->next;

            // Updating the sentinel variable
            list_empty_sentinel++;
        }
    }

    // If sentinel variable wasn't updated, we can assume that the hash table is empty
    if (list_empty_sentinel == 0)
    {
        printf("Hash table is empty!\n");
    }

}

// Delete names from hash table function
char *delete_hash(node **bucket, char *user_name)
{
    // Security linked list reference copy to not messing up within it
    node *list = *bucket;

    // Previous node to allow us delete elements from linked list
    node *previous = NULL;

    // Special condition: Bucket with just one element
    if (list->next == NULL)
    {
        // String compare function to help comparing strings
        if (strcmp(list->name, user_name) == 0)
        {
            // Printing a message if so
            printf("Found!\n");

            // Storing the name in a given variable
            char *tmp = list->name;

            // Liberating the block of memory that was storing the old element
            free(*bucket);

            // Cleaning the first bucket to null
            *bucket = NULL;

            // Returning the name to use it after
            return tmp;
        }

        // Case if didn't delete the given name
        else
        {
            printf("Not found!\n");
            return NULL;
        }
    }

    // Other conditions: More than one element
    else
    {
        // Looping on bucket
        while (list != NULL)
        {
            // Checking if the name exists
            if (strcmp(list->name, user_name) == 0)
            {
                // Printing a message to inform that was able to find
                printf("Found!\n");

                // Storing the name found in a tmp aux variable
                char *tmp = list->name;

                // Using the previous node to allow the reconnecting to linked list elements
                previous->next = list->next;

                // Liberating the current element
                free(list);

                // Returning the deleted name to use it after
                return tmp;
            }

            // Storing the previous element to allow linking process from linked list
            previous = list;

            // Updating the next element to continue iterating on bucket linked list
            list = list->next;
        }

        // Printing if not possible to find
        printf("Not found!\n");
    }

    // Returning null
    return NULL;
}

// Search hash table function
char *search_hash(node **table, char *user_name)
{
    // Sentinel variable to sinalize if doesn't exist the searched name
    int sentinel = 0;

    // Loopíng through all hash table buckets
    for (int i = 0; i < SIZE; i++)
    {
        // Creating a copy of first address to not messing up with original
        node *hash_table_bucket = table[i];

        // Looping on linked list
        while (hash_table_bucket != NULL)
        {
            // Check if the searched name exists
            if (strcmp(hash_table_bucket->name, user_name) == 0)
            {
                // Printing a message to notificate the user
                printf("Name exists!\n");

                // Storing the name in a aux variable
                char *tmp = hash_table_bucket->name;

                // Updating the sentinel
                sentinel++;

                // Returning the name found
                return tmp;
            }

            // Updating the linked list locator
            hash_table_bucket = hash_table_bucket->next;
        }
    }

    // If the name doesn't exist
    if (sentinel == 0)
    {
        printf("Name doesn't exist!\n");
        return "";
    }

    return NULL;
}
