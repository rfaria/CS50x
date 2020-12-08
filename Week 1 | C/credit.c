#include <stdio.h>
#include <cs50.h> // including cs50's team functions
#include <math.h>

/*
    Luhn’s Algorithm
    Check if a credit card is valid
*/

int countDigits(long number);
int checkCardValidity(long cardNumber);
void cardBrand(long cardNumber);

int main(void)
{
    long number;
    int isValid;


    // getting user input
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    isValid = checkCardValidity(number);

    // check if the card is valid based on Luhn's algorithm
    if (!isValid)
    {
        printf("INVALID\n");
    }

    // if the card is valid, check its brand (AMEX, MASTERCARD, VISA) and print it
    else
    {
        cardBrand(number);
    }

}

// function to measure the quantity of digits in a number
int countDigits(long number)
{
    int count = 0;

    if (number == 0)
    {
        return 1;
    }

    while (number != 0)
    {
        number = number / 10;
        ++count;
    }

    return count;

}

// Luhn’s Algorithm
int checkCardValidity(long cardNumber)
{
    int lastDigit,
        sumProd = 0,
        sum = 0,
        finalSum = 0,
        even = 0;

    do
    {
        lastDigit = cardNumber % 10;

        if (even == 1)
        {
            int mult = lastDigit * 2;

            if (countDigits(mult) == 1)
            {
                sumProd = sumProd + mult;
            }
            else
            {
                sumProd = sumProd + (mult % 10);
                mult = mult / 10;
                sumProd = sumProd + mult;
            }

            even = 0;
        }
        else
        {
            sum = sum + lastDigit;

            even = 1;
        }

        cardNumber = cardNumber / 10;

    }
    while (cardNumber > 0);

    finalSum = sumProd + sum;

    if ((finalSum % 10) == 0)
    {
        return 1; // if the last digit of finalSum is 0 then the card is valid
    }
    else
    {
        return 0; // if the last digit of finalSum is different from 0 then the card is invalid
    }
}

/*
Selection Criteria

American Express numbers start with 34 or 37
MasterCard numbers start with 51, 52, 53, 54, or 55
Visa numbers start with 4

American Express uses 15-digit numbers
MasterCard uses 16-digit numbers
Visa uses 13- and 16-digit
*/

// even if a card is considered valid according to Luhn's algorithm we say it is invalid if the criteria above (lines 118 through 126) is not satisfied
void cardBrand(long cardNumber)
{
    int digits = countDigits(cardNumber), // temporary digits to be updated at each iteration
        i = digits,
        fisrtDigit,
        secondDigit,
        digit,
        quantityOfDigits;

    quantityOfDigits = digits; // fixed quantity of digits

    while (i >= 2)
    {
        digit = cardNumber % 10;
        cardNumber = cardNumber / 10;
        i--;
    }

    secondDigit = digit;
    digit = cardNumber % 10;
    fisrtDigit = digit;

    if (fisrtDigit == 3 && quantityOfDigits == 15)
    {
        if (secondDigit == 4 || secondDigit == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else if (fisrtDigit == 5 && quantityOfDigits == 16)
    {
        if (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4 || secondDigit == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else if (fisrtDigit == 4 && (quantityOfDigits == 13 || quantityOfDigits == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

}
