#include <stdio.h>
#include <cs50.h>

int digit_sum(long long number);

bool card_is_valid(long long number);

int first_two_digits(long long number)

string card_type(long long number);

int main(void)
{
    printf("Number: ");
    long long number = get_long_long();

    if (card_is_valid(number))
    {
        printf("%s\n", card_type(number));
    }
    else
    {
        printf("INVALID\n");
    }
}

int digit_sum(long long number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

bool card_is_valid(long long number)
{
    int digit;

    int sum = 0;

    int i = 0;
    while (number > 0)
    {
        digit = number % 10;

        if (i % 2 == 1)
        {
            sum += digit_sum(digit * 2);
        }
        else
        {
            sum += digit;
        }

        i++;
        number /= 10;
    }

    return sum % 10 == 0;
}

int first_two_digits(long long number)
{
    while (number > 100)
    {
        number /= 10;
    }

   return number;
}

string card_type(long long number)
{
    int code = first_two_digits(number);

    if (code == 34 || code == 37)
    {
        return "AMEX";
    }
    else if (code >= 51 && code <= 55)
    {
        return "MASTERCARD";
    }
    else if (code >= 40 && code <= 49)
    {
        return "VISA";
    }

    return "UNKNOWN";
}

