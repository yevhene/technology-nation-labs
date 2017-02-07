#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int rotate(int c, int delta);

bool prepare_key(string key, int keylen);

int normalize_alpha(int c);

char rotate_in_scope(int c, int delta, int left_border, int right_border);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./vigenere key\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);
    if (!prepare_key(key, keylen))
    {
        printf("Please use valid key!\n");
        return 1;
    }

    printf("plaintext:  ");
    string str = get_string();

    printf("ciphertext: ");
    int char_count = 0;
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (isalpha(str[i]))
        {
            int delta = key[char_count % keylen];

            int encoded = rotate(str[i], delta);
            printf("%c", encoded);

            char_count++;
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    printf("\n");

    return 0;
}

bool prepare_key(string key, int keylen)
{
    for (int i = 0 ; i < keylen; i++) {
        if (!isalpha(key[i]))
        {
            return false;
        }

        key[i] = normalize_alpha(key[i]);
    }

    return true;
}

int rotate(int c, int delta)
{
    c = rotate_in_scope(c, delta, 'a', 'z');
    c = rotate_in_scope(c, delta, 'A', 'Z');

    return c;
}

int normalize_alpha(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }

    return c;
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
