#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("minutes: ");

    int minutes = get_int();
    float gallons = minutes * 1.5;
    float ounces = gallons * 128;
    float bottles = ceil(ounces / 16);

    printf("bottles: %i\n", (int) bottles);
}
