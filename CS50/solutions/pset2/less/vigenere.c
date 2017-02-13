#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool prepare_key(string key, int keylen);
char rotate(char c, char delta);

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
            
        key[i] = toupper(key[i]) - 'A';
    }

    return true;
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
