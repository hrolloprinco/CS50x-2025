#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int value(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int point1 = value(word1);
    int point2 = value(word2);
    if (point1 > point2)
    {
        printf("Player 1 wins!\n");
    }
    else if (point1 < point2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int value(string word)
{
    int point = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char x = toupper(word[i]);
        switch (x)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'L':
            case 'U':
                point += 1;
                break;
            case 'D':
            case 'G':
                point += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                point += 3;
                break;
            case 'F':
            case 'V':
            case 'W':
            case 'Y':
            case 'H':
                point += 4;
                break;
            case 'K':
                point += 5;
                break;
            case 'J':
            case 'X':
                point += 8;
                break;
            case 'Z':
            case 'Q':
                point += 10;
                break;
        }
    }

    return point;
}
