#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int x;
    do
    {
        x = get_int("hieght: ");
    }
    while (x < 1 || x > 8);
    // for each row
    for (int j = 0; j < x; j++)
    {
        // prints spaces starting from height-1
        for (int i = (x - 1); i > j; i--)
        {
            printf(" ");
        }
        // prints # for the number of row
        for (int k = -1; k < j; k++)
        {
            printf("#");
        }
        // prints spaces
        printf("  ");
        for (int i = -1; i < j; i++)
        {
            printf("#");
        }

        printf("\n");
    }
}
