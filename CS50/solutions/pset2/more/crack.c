#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 4
#define FIRST_CHAR 'A'
#define LAST_CHAR 'z'

void reset_password(char password[]);
bool next_password(char password[]);
char next_char(char prev_char);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    string hash = argv[1];
    char salt[3];
    strncat(salt, hash, 2);

    char password[LIMIT + 1];
    reset_password(password);

    while (next_password(password))
    {
        string encrypted_password = crypt(password, salt);
        if (strcmp(encrypted_password, hash) == 0)
        {
            printf("%s\n", password);
            break;
        }
    }

    return 0;
}

void reset_password(char password[])
{
    for (int i = 0; i < LIMIT + 1; i++)
    {
        password[i] = '\0';
    }
}

bool next_password(char password[])
{
    int length = strlen(password);

    int cursor = length - 1;
    while (cursor >= 0)
    {
        if (password[cursor] != LAST_CHAR)
        {
            break;
        }

        cursor--;
    }

    if (cursor == -1)
    {
        if (length == LIMIT)
        {
            return false;
        }

        cursor = length;
        while (cursor >= 0)
        {
            password[cursor] = FIRST_CHAR;
            cursor--;
        }
    }
    else
    {
        password[cursor] = next_char(password[cursor]);
        while (cursor + 1 < length)
        {
            password[++cursor] = FIRST_CHAR;
        }
    }

    return true;
}

char next_char(char prev_char)
{
    if (prev_char == 'Z')
    {
        return 'a';
    }

    return prev_char + 1;
}
