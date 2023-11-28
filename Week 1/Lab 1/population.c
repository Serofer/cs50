#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Start Size: ");
    }
    while(n<9);

    int m;
    do
    {
        m = get_int("End Size: ");
    }
    while(m<n);

    int years = 0;

    while (n < m)
    {
        n = n + n / 3 - n / 4;
        years++;
    }

    printf("Years: %i \n", years);

}