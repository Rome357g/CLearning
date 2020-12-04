// Created for CS50 by Rome357g, this program 
// Takes one command line argument as a cipher key and
// Rotates that through the alphabet "Caesar Cipher"

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {   
        // Getting length of the command argument
        int length = strlen(argv[1]);
        int numbers = 0;
        // Using isdigit to determine if user entered numerical argument vector
        for (int counterA = 0; counterA < length; counterA++)
        {
            if isdigit(argv[1][counterA])
            {
                numbers++;
            }
        }
        // If the numbers are equal to length of string, then all is good
        if (numbers == length)
        {
            int key = atoi(argv[1]);
            string plain = get_string("plaintext: ");
            int plainLength = strlen(plain);
            // For the math to work right I created an array for the alphabet ASCII
            int alphabet[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
            for (int counterB = 0; counterB < plainLength; counterB++)
            {
                // Iterating through all uppercase letters and moving them by key
                if (isupper(plain[counterB]))
                {
                    int indexU = plain[counterB];
                    indexU -= 65;
                    int indexUN = (alphabet[indexU] + key) % 26; 
                    indexU = indexUN + 65;
                    // ASCII value 65-90 for uppercase
                    plain[counterB] = indexU;
                }
                // Iterating through all lowercase letters and moving them by key
                else if (islower(plain[counterB]))
                {
                    int indexL = plain[counterB];
                    indexL -= 97;
                    int indexLN = (alphabet[indexL] + key) % 26; 
                    indexL = indexLN + 97;
                    // ASCII value 97-122 for lowercase
                    plain[counterB] = indexL;
                }    
            }
            printf("ciphertext: %s\n", plain);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
