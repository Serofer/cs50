#include <cs50.h>
#include <stdio.h>

int check_firstTwoDigits(int x);

int main(void)
{
    long n = get_long("Card Number: ");

    string cardtype = "";
    int firstTwoDigits = 0;
    int evenNumbers = 0;
    int oddNumbers = 0;
    int run = 1;
    int digit = 0;
    bool MasterDigits = false;

    while (n > 0)
    {

        //printf("Number: %li\n", n);
        for (int i = 0; i < 10; i++)
        {
            if ((n-i) % 10 == 0)
            {
                digit = i;
                //printf("%i\n", digit);
            }

        }

        if ( run % 2 == 0)
        {
            int toAdd = digit*2;
            if (toAdd > 9)
            {
                for (int i = 0; i < 10; i++)
                {
                    if ((toAdd-i) % 10 == 0)
                    {
                        toAdd = 1 + i;
                        break;
                    }
                }
            }
            //printf("toAdd: %i\n", toAdd);
            evenNumbers += toAdd;
        }
        else
        {
            oddNumbers += digit;
        }
        run++;
        if ( n / 100 == 0 && n > 9)
        {
            firstTwoDigits = n;
            //printf("firstTwoDigits: %i\n", firstTwoDigits);
        }
        n = n/10;
    }
    if ((oddNumbers + evenNumbers) % 10 == 0)
    {
        //check for cardtype
        if( (run-1) == 13 && check_firstTwoDigits(firstTwoDigits))
        {
            cardtype = "VISA";
        }

        else if ( (run-1) == 16)
        {
            if (check_firstTwoDigits(firstTwoDigits))
            {
                cardtype = "VISA";
            }
            else
            {
                for ( int j = 51; j < 56; j++)
                {
                    if (firstTwoDigits == j)
                    {
                        MasterDigits = true;
                    }
                }
                if (MasterDigits)
                {
                    cardtype = "MASTERCARD";
                }
                else
                {
                    cardtype = "INVALID";
                }
            }
        }
        else if ( (run-1) == 15 )
        {
            if(firstTwoDigits == 34 || firstTwoDigits == 37)
            {
                cardtype = "AMEX";
            }
            else
            {
                cardtype = "INVALID";
            }
        }
        else
        {
            cardtype = "INVALID";
        }
    }
    else
    {
        cardtype = "INVALID";
    }

    printf("%s\n", cardtype);

}

int check_firstTwoDigits(int x)
{
    if (x < 50 && x > 39)
    {
        return true;
    }
    else
    {
        return false;
    }
}
