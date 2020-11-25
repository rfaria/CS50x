#include <stdio.h>
#include <cs50.h> // including cs50's team functions

int main(void)
{
    int height, blocks; // declaring variables

    do
    {
        height = get_int("Height: ");  // getting user's input
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        blocks = i + 1;
        
        for (int j = 0; j < (height - blocks); j++) // prints space character * (height-blocks) : at each iteration this number decreases
        {
            printf(" ");
        }
        
        for (int j = 0; j < blocks; j++) // prints # character * (blocks) : at each iteration this number increases
        {
            printf("#");
        }
        
        printf("  "); // prints two spaces between the blocks in the same row : at each iteration this number is constant
        
        for (int j = 0; j < blocks; j++) // prints # character * (blocks) : at each iteration this number increases
        {
            printf("#");
        }
        
        printf("\n");  // print new line after spaces and blocks are printed
    }
}
