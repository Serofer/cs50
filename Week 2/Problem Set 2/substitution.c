#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        argv[1][i] = toupper(argv[1][i]);
    }

    // convert all to upper case and make everything ready
    string key = argv[1];

    int alphabet[26];
    int check[26];

    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = i + 65;
        check[i] = i + 65;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (key[i] == check[j])
            {
                check[j] = 0;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (check[i] > 0)
        {
            printf("Key must contain each letter of the alphabet once\n");
            return 1;
        }
    }

    // get plaintext, then convert to uppper and translate
    string plaintext = get_string("plaintext: ");

    int converter[strlen(plaintext)];

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] > 65 && plaintext[i] < 91)
        {
            converter[i] = 1;
        }
        if(plaintext[i] > 96 && plaintext[i] < 123)
        {
            converter[i] = 0;
        }
        plaintext[i] = toupper(plaintext[i]);

        for (int j = 0; j < 26; j++)
        {
            if (plaintext[i] == alphabet[j])
            {
                plaintext[i] = key[j];
                break;
            }
        }
    }

    // reconvert

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (converter[i] == 0)
        {
            plaintext[i] = tolower(plaintext[i]);
        }
        else
        {
            plaintext[i] = toupper(plaintext[i]);
        }
    }
    // output
    printf("ciphertext: %s\n", plaintext);
}
