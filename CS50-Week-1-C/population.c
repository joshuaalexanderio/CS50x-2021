#include <cs50.h>
#include <stdio.h>

int getStartSize(void);
int getEndSize(int ss);
int main(void)
{
    // Prompts for start size
    int ss = getStartSize();
    // Prompts for end size
    int es = getEndSize(ss);
    int years = 0;

    // Calculates number of years until we reach threshold
    for (; ss < es; years++)
         ss = ss + ss/3 - ss/4;

    // Prints number of years
    printf("Years: %i\n", years);
}

// Prompts user for a positive integer >=9 for start size
int getStartSize(void)
{
    int ss = 0;

    do
    {
        ss = get_int("Start size: ");
        if (ss < 9)
        {
            printf("Please enter a positive integer of at least 9\n");
        }
    }
    while (ss < 9);
    return ss;
}

// Prompts user for a positive integer >= start size for end size
int getEndSize(int ss)
{
    int es = 0;
    do
    {
        es = get_int("End size: ");
        if (es < ss)
        {
            printf("Please enter an integer equal to or greater than start size.\n");
        }
    }
    while (es < ss);
    return es;

}