// Hello, (name)

// Including libraries
#include <stdio.h>
#include <cs50.h>

// Main function
int main(void)
{
    // Get user's name
    string name = get_string("What's your name?\n");

    // Print user's input
    printf("hello, %s\n", name);
}