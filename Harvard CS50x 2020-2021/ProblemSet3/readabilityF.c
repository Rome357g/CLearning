//Created for CS50 by Rome357g

#import <stdio.h>
#import <cs50.h>
#import <ctype.h>
#import <string.h>
#import <math.h>

int count_letters(int length, string array); 
int count_words(int length, string array);
int count_sentences(int length, string array);

int main(void)
{
    string intro = get_string("Text: ");
    int introLength = strlen(intro);
    float letters = count_letters(introLength, intro);
    float words = count_words(introLength, intro);
    float sentences = count_sentences(introLength, intro);

    //Coleman-Liau index is 0.0588 * L - 0.296 * S - 15.8
    //where L is average number of letters per 100 words
    //and S is average number of sentences per 100 words
    float L = letters / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    //printf("%i letter(s)\n", letters);
    //printf("%i word(s)\n", words);
    //printf("%i sentence(s)\n", sentences);

    int index1 = index;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index1);
    }
}

int count_letters(int length, string array)
//using isalpha to count letters
{
    int letters = 0;
    for (int counterL = 0; counterL < length; counterL++)
    {
        if isalpha(array[counterL])
        {
            letters++;
        }
    }
    return letters;
}

int count_words(int length, string array)
//using isspace to count white spaces, +1 for words
{
    int words = 1;
    for (int counterW = 0; counterW < length; counterW++)
    {
        if isspace(array[counterW])
        {
            words++;
        }
    }
    return words;
}   

int count_sentences(int length, string array)
//using counter to for periods, question marks, and exclamation points
{
    int sentences = 0;
    for (int counterS = 0; counterS < length; counterS++)
    {
        if (array[counterS] == '.' || array[counterS] == '?' || array[counterS] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
