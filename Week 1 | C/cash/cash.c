#include <stdio.h>
#include <cs50.h> // including cs50's team functions
#include <math.h>

/*
    Greedy Algorithm
    Assuming that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
*/

int coins(int centsLeft, int coinValue); // returns the number of times coinValue fits in centsLeft considering only integers

int main(void)
{
    float dollars;
    int minimum = 0;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100); // converting dollars into cents, so we can work with integers
    
    minimum = minimum + coins(cents, 25);
    cents = cents - 25 * coins(cents, 25);
    
    minimum = minimum + coins(cents, 10);
    cents = cents - 10 * coins(cents, 10);
    
    minimum = minimum + coins(cents, 5);
    cents = cents - 5 * coins(cents, 5);
    
    minimum = minimum + coins(cents, 1);
    cents = cents - 1 * coins(cents, 1);
    
    printf("%i\n", minimum);
}

int coins(int centsLeft, int coinValue)
{
    int counter = 0;
    
    while (centsLeft >= coinValue)
    {
        centsLeft = centsLeft - coinValue;
        counter++;
    }
    
    return counter;
}
