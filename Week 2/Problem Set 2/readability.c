#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int calculate_index(int l, int s, int w);
int main(void)
{
    int lettercount = 0;
    int sentencecount = 0;
    int wordcount = 1;//text has at least one word and last word of sentence has to be counted (although it isn't followed by [SPACE])
    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))//if a letter, increase lettercount
        {
            lettercount++;
        }
        if (text[i] == 32 && text[i+1] != 32)
        {
            wordcount++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentencecount++;
        }

    }

    int index = calculate_index(lettercount, sentencecount, wordcount);
    if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    printf("Grade %i\n", index);


}

int calculate_index(int l, int s, int w)
{
    //printf("letters: %i\nsentences: %i\nwords: %i\n", l, s, w);
    float L = (float)l / (float)w * 100.0;
    float S = (float)s / (float)w * 100.0;
    //printf("L: %f\nS: %f\n", L, S);
    return round(0.0588 * L - 0.296 * S - 15.8);
}
