#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();

    bool isFirstLetter = true;
    for (int i = 0, len = strlen(name); i < len; i++)
    {
        if (name[i] == ' ')
        {
            isFirstLetter = true;
            continue;
        }

        if (isFirstLetter)
        {
            printf("%c", toupper(name[i]));
            isFirstLetter = false;
        }
    }

    printf("\n");

    return 0;
}
