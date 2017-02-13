#include <stdio.h>
#include <cs50.h>
#include <string.h>

char rotate(char c, char delta);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar n\n");
        return 1;
    }

    int delta = atoi(argv[1]);

    printf("plaintext:  ");
    string str = get_string();

    printf("ciphertext: ");
    for(int i = 0, len = strlen(str); i < len; i++)
    {
        printf("%c", rotate(str[i], delta));
    }

    printf("\n");

    return 0;
}

char rotate(char c, char delta)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (c -'A' + delta) % 26;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return 'a' + (c - 'a' + delta) % 26;
    }
    else
    {
        return c;
    }
}
