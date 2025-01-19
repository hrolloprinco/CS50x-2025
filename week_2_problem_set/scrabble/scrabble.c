#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int value (string word);

int main(void)
{
    string word1 = get_string("player 1: ");
    string word2 = get_string("player 2: ");
    int point1= value (word1);
}
int value (string word)
{
    string uppered;
     for (int i = 0 , n= strlen(word); i<n ; i++)
     {
        uppered[i] = toupper(word[i]);
     }
     printf("%s,uppered");
     return 0;
}
