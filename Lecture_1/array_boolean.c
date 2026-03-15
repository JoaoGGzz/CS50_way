#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool truthtable[10];

int main(void)
{
    truthtable[2] = false;
    truthtable[7] = true;
    if(truthtable[7] == true)
    {
        printf("TRUE!\n");
    }
    truthtable[9] = true;
}
