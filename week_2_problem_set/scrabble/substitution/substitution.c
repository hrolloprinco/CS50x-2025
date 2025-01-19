#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc, string argv[])
{

    if (argc != 2) // enters if you don't type any key
    {
        printf("Usage ./substitution Key \n");
        return 1; // to indicate error (exits)
    }
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        { // checks for alphabetical char if not exits out
            printf("Usage ./substitution Key \n");
            return 1;
        }
    }
    if (length != 26) // checks lenth
    {
        printf("Key must contain 26 characters. \n");
        return 1; // to indicate error
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            argv[1][i] = toupper(argv[1][i]); // transforms the key  to  uppper
            for (int j = 0; j < length; j++)
            {
                argv[1][j] = toupper(argv[1][j]); // transforms the key  to  uppper
                if (j != i)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Keys must not contain repeated characters. \n");
                        return 1;
                    }
                }
            }
        }
    }
    // vadations done
    string printext = get_string("Printext: ");
    for (int i = 0, lengthtext = strlen(printext); i < lengthtext; i++)
    {
        if (isalpha(printext[i]))
        {
            if (isupper(printext[i]))
            {
                int position = printext[i] - 'A';
                printext[i] = argv[1][position];
            }
            else
            {
                int position = printext[i] - 'a';
                printext[i] = argv[1][position] + 32;
            }
        }
    }
    printf("ciphertext: %s\n", printext);
}
