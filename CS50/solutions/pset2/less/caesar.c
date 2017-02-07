#include <stdio.h>
#include <cs50.h>
#include <string.h>

int rotate(int c, int delta);

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
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        printf("%c", rotate(str[i], delta));
    }

    printf("\n");

    return 0;
}

char rotate_in_scope(int c, int delta, int left_border, int right_border)
{
    if (c >= left_border && c <= right_border)
    {
        int range = right_border - left_border + 1;
        c += delta;
        c = ((c - left_border) % range) + left_border;
    }

    return c;
}

int rotate(int c, int delta)
{
    c = rotate_in_scope(c, delta, 'a', 'z');
    c = rotate_in_scope(c, delta, 'A', 'Z');

    return c;
}
