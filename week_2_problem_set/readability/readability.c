#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float avr_letter(string text);
float avr_sentence(string text);
int main(void)
{
    string text = get_string("text: ");
    float index = 0.0, L = 0.0, S = 0.0;
    L = avr_letter(text);
    S = avr_sentence(text);
    index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float avr_letter(string text)
{
    // space is initialized with 1 because it would instantly give the numbers of words. Exp.Hey, my
    // name is Prince. 4spaces 5 words
    int spaces = 1, letters = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        // this would count every space in the string
        if (text[i] == 32)
        {
            spaces++;
        }
        else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }
    // now i have to do a proportion for the average
    float avr = 0.0;
    avr = letters * 100.0 / (float) spaces;
    return avr;
}
float avr_sentence(string text)
{
    int spaces = 1, sentence = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == 32)
        {
            spaces++;
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;
        }
    }

    float avr = 0.0;
    avr = sentence * 100.0 / (float) spaces;
    return avr;
}
