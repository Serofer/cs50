#include <cs50.h>
#include <stdio.h>

int get_height();
void draw_pyramid(int h);

int main(void)
{
    draw_pyramid(get_height());
}

int get_height()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void draw_pyramid(int h)
{
    int i = 1;
    while (i < h + 1)
    {
        for (int k = 0; k < 2; k++)
        {
            if (k == 0)
            {
                for (int j = h; j > i; j--)
                {
                    printf(" ");
                }
            }

            for (int j = 0; j < i; j++)
            {
                printf("#");
            }

            if (k == 1)
            {
                printf("\n");
            }
            else
            {
                printf("  ");
            }
        }
        i++;
    }

}
