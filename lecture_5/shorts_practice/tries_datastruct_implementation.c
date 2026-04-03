#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20
#define PATH_SIZE 10

// Trie struct, now instead of node (One destination) we have paths (Array to 10 destinations)
typedef struct _trie
{
    char university_name[NAME_SIZE];
    bool is_end;
    struct _trie *paths[PATH_SIZE];
} trie;

// Declaring some variable to make them global
char *uni_name = NULL;
char *user_key = NULL;
char *search_key = NULL;
int key_length = 0;
int uni_length = 0;

// Prototypes
trie *init_trie_node();
void insert_trie(trie *root, char *key, char *name, int k_length);
bool valid_name(char *name);
bool valid_key(char *key);
void search_trie(trie *root, char *key);

int main (void)
{
    // Creating the root trie node
    trie *t = init_trie_node();

    // Name length validation
    while (true)
    {
        // Receiving the University name
        uni_name = get_string("Universiry name: ");

        // Using function concept to check if valid name (up to 20 chars)
        if (valid_name(uni_name))
        {
            printf("University name is valid.\n");
            break;
        }
    }

    // Key validation
    while (true)
    {
        // Receiving the foundation year (4 digit key)
        user_key = get_string("4 digit key: ");

        if (valid_key(user_key))
        {
            printf("University key is valid.\n");
            break;
        }
    }

    // Calling insert function
    insert_trie(t, user_key, uni_name, key_length);

    // Searching section: Key validation + Search function calling
    while (true)
    {
        search_key = get_string("Search key: ");

        if (valid_key(search_key))
        {
            search_trie(t, search_key);
            break;
        }
    }

}

// FUNCTIONS
// Create and initialize one trie node
trie *init_trie_node()
{
    // Creating the block on memory
    trie *t = malloc(sizeof(trie));

    // Checking if malloc was successfull
    if (t == NULL)
    {
        printf("Can't malloc.\n");
        return NULL;
    }

    // Initiating the is_end variable
    t->is_end = false;

    // Looping to initialize all the paths with NULL
    for (int i = 0; i < PATH_SIZE; i++)
    {
        t->paths[i] = NULL;
    }
    // Looping to initialize the name array with NULL
    for (int i = 0; i < NAME_SIZE; i++)
    {
        t->university_name[i] = '\0';
    }

    // Returning the address of created block on memory
    return t;
}

// Function to insert into the trie
void insert_trie(trie *root, char *key, char *name, int k_length)
{
    // Create a copy of root trie node
    trie *current = root;

    // Looping length times
    for (int i = 0; i < k_length; i++)
    {
        // Calculating the index
        int index = key[i] - '0';

        // Checking if the path doesn't exist, if not, create it
        if (current->paths[index] == NULL)
        {
            // Creating the block of memory to store the next path trie node
            trie *next_trie_node = init_trie_node();

            // Storing the new created node on the index path
            current->paths[index] = next_trie_node;
        }
        // Updating the pointer to the next
        current = current->paths[index];
    }

    // Updating the "is_end" marker
    current->is_end = true;

    // Writting the university name
    strcpy(current->university_name, name);

    printf("University name was added to the end of path.\n");
}

// Checking if the input has 20 characters
bool valid_name(char *name)
{
    // Taking the length
    uni_length = strlen(name);

    // Checking if is bigger than 20 characters
    if (uni_length >= 20)
    {
        printf("Invalid university name, just 20 characters are allowd. Use a smaller name.\n");
        return false;
    }

    // If not, proceed
    else
    {
        return true;
    }
}

// Function to validate the key
bool valid_key(char *key)
{
    // Sentinel variable
    bool invalid = false;

    // Taking the input length to loop on it
    key_length = strlen(key);

    if (key_length != 4)
    {
        printf("Invalid key, only 4 numbers are allowed.\n");
        return false;
    }

    // Loopíng on it
    for (int i = 0; i < key_length; i++)
    {
        // Checking if my key is a valid number between 0 - 9
        if (key[i] < 48 || key[i] > 57)
        {
            invalid = true;;
            break;
        }
    }

    // If not, repeat until the key is valid
    if (invalid)
    {
        printf("Invalid key, just numbers are allowed.\n");
        return false;
    }

    // If is valid, proceed
    else
    {
        return true;
    }
}

// Function to search on the trie
void search_trie(trie *root, char *key)
{
    // Creating a copy from the root to move onto the trie
    trie *current = root;

    // Taking key length
    int length = strlen(key);

    // Looping on it
    for (int i = 0; i < length; i++)
    {
        // Create the index
        int index = key[i] - '0';

        // Check if the current path doesn't exist
        if (current->paths[index] == NULL)
        {
            printf("Key / Path doesn't exist.\n");
            break;
        }

        // Update the current pointer to the next of the trie
        current = current->paths[index];
    }

    // Check if the end is the correct node
    if (current != NULL && current->is_end == true)
    {
        printf("Found %s\n", current->university_name);
    }
}
