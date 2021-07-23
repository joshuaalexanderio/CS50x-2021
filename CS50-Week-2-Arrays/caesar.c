#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string preserveCase (string letterText, string cipherText);
string toTwentyFiveIndex (string cipherText);
string toASCII (string cipherText);
int main(int argc, string argv[])
{
    // Check if there is exactly 1 decimal digit command-line argument; else, returns error code.
    //
    if (!(argc == 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Check if each character is a decimal digit
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

    }

    // Convert key given in command-line argument to an integer
    int key = atoi(argv[1]);
    // Transposes key to correct value in range to account for possible overflow.
    key = key % 25;


    char *plainText = get_string("Enter string: ");
    char *cipherText = malloc(strlen(plainText) + 1);
    if (cipherText == NULL)
    {
        return 2;
    }
    strcpy(cipherText, plainText);





    // Convert every character to uppercase
    for (int i = 0, n = strlen(cipherText); i < n; i++)
    {
        cipherText[i] = toupper(cipherText[i]);
    }

    // Convert cipherText to 1-25 base
    cipherText = toTwentyFiveIndex(cipherText);

    // Apply cipher key to each character
    for (int i = 0, n = strlen(cipherText); i < n; i++)
    {
        cipherText[i] += key;
        cipherText[i] = cipherText[i] % 25; // In case of overflow wrap around beginning of ASCII alphabet
    }

    // Convert cipherText back to correct ASCII codes for proper display.
    cipherText = toASCII(cipherText);

    // Preserves case info from plainText to cipherText
    cipherText = preserveCase(plainText, cipherText);

    // Prints final result
    printf("Cipher text: %s\n", cipherText);

    free(cipherText); // Free memory allocated by malloc at line 40
    return 0;


}

// Convert each char in cipherText to same case as plainText
string preserveCase (string plainText, string cipherText)

{
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        if (islower(plainText[i]))
        {
            cipherText[i] = tolower(cipherText[i]);
        }

        else
        {
            cipherText[i] = toupper(cipherText[i]);
        }
    }
    return cipherText;
}

// Convert cipher text to an index of 0-25
string toTwentyFiveIndex (string cipherText)
{
        // Convert every character to 0-25 index
        for (int i = 0, n = strlen(cipherText); i < n; i++)
        {
            cipherText[i] -= 65;
        }
    return cipherText;
}

// Undo toTwentyFiveIndex function by converting back to correct ASCII codes
string toASCII (string cipherText)
{
    for (int i = 0, n = strlen(cipherText); i < n; i++) // Iterate over each character
    {
        cipherText[i] += 65; // Convert back to ASCII from our base 25 index


    }
    return cipherText;
}
