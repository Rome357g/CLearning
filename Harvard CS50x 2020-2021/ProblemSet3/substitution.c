// Created for CS50 by Rome357g, this program
// Takes a substituted alphabet as a cipher and applies that
// To inputted text.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Getting length of the command argument, should be 26
        int length = strlen(argv[1]);
        int letters = 0;
        // Using isalpha to determine if user entered letters in argument vector
        for (int counterA = 0; counterA < length; counterA++)
        {
            if isalpha(argv[1][counterA])
            {
                letters++;
            }
        }
        // If the letters are equal to length of 26, then all is good
        if (letters == length && length == 26)
        {
            string upper = argv[1];
            int lettercount = 0;
            int letterint = 0;
            int alphabet[26] = {0};
            for (int countB = 0; countB <= 25; alphabet[countB] = 0, countB++)
            {
                // Adding each unique letter in key to alphabet array
                // If total does not equal 26 there are not 26 unique values
                if (isalpha(upper[countB]))
                {
                    lettercount = toupper(upper[countB]) - 65;
                    upper[countB] = toupper(upper[countB]);
                    alphabet[lettercount]++;
                    letterint += alphabet[lettercount];
                }
            }
            if (letterint == 26)
            {
                string plain = get_string("plaintext: ");
                int plainLength = strlen(plain);
                for (int countC = 0; countC < plainLength; countC++)
                {
                    // Iterating through all uppercase letters and substituting
                    if (isupper(plain[countC]))
                    {
                        int indexU = plain[countC];
                        indexU -= 65;
                        indexU = upper[indexU];
                        // ASCII value 65-90 for uppercase
                        plain[countC] = indexU;
                    }
                    // Iterating through all lowercase letters and substituting
                    else if (islower(plain[countC]))
                    {
                        int indexL = plain[countC];
                        indexL -= 97;
                        indexL = upper[indexL] + 32;
                        // ASCII value 97-122 for lowercase
                        plain[countC] = indexL;
                    }
                }
                //printf("%s", upper);
                printf("ciphertext: %s\n", plain);
            }
            else
            {
                printf("Key must contain 26 unique characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
