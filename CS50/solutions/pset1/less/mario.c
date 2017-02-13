#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        printf("height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    for (int i = 0; i < height; i++)
    {
        int hashes = i + 2;
        int spaces = height + 1 - hashes;

        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

