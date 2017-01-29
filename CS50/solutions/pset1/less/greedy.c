#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int change;
    int coins = 0;

    do
    {
        printf("change: ");
        change = round(get_float() * 100);
    }
    while (change < 0);

    int costs[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        while (change >= costs[i])
        {
            change -= costs[i];
            coins++;
        }
    }

    printf("%i\n", coins);
}

