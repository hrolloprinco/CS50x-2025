#include <cs50.h>
#include <stdio.h>
_Bool checksum(long num);
int main(void)
{
    long num = get_long("what is your credit card number? \n");
    if (checksum(num) == true)
    {
        int count = 0;
        int lastdigit, last2digit;
        while (num > 0)
        {
            if (count % 2 == 0)
            {
                lastdigit = num % 10;
                num = num / 10;
                count++;
            }
            else
            {
                last2digit = num % 10;
                num = num / 10;
                count++;
            }
        }
        switch (count)
        {
            case 15:
                if (lastdigit == 3)
                {
                    if (last2digit == 4 || last2digit == 7)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 13:
                if (lastdigit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16:
                if (last2digit == 5)
                {
                    if (lastdigit <= 5)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else if (last2digit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

_Bool checksum(long num)
{
    int count = 0, sum = 0, sumX2 = 0, total = 0, checksum = 0;

    do
    {
        if (count % 2 == 0)
        {
            sum = sum + num % 10;
            count++;
        }
        else
        {
            int doubledigit = (2 * (num % 10));
            // to see if it has more than 1 digit
            if (doubledigit > 9)
            {

                while (doubledigit > 0)
                {
                    sumX2 = sumX2 + doubledigit % 10;
                    doubledigit = doubledigit / 10;
                }
                count++;
            }
            else
            {
                sumX2 = sumX2 + doubledigit;
                count++;
            }
        }
        // deleting the last digit
        num = num / 10;
    }
    while (num != 0);
    total = sum + sumX2;
    checksum = total % 10;
    if (checksum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
