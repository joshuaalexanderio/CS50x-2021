#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
int main(void)
{
    //get positive number 1-8 height from user
    int height = get_positive_int();

    //finds and stores amount of spaces to put on left
    int s = (height - 1);
    //finds and stores amount of left hashes
    int lh = 1;
    //finds and stores amonut of right hashes
    int rh = 1;

    //prints pyramid
    int n = 0;
    do
    {
        for (int a = 0; a < s; a++)
        {
            printf(" ");
        }
        for (int b = 0; b < lh; b++)
        {
            printf("#");
        }
        for (int c = 0; c < 2; c++)
        {
            printf(" ");
        }
        for (int d = 0; d < rh; d++)
        {
            printf("#");
        }
        printf("\n");
        s--;
        lh++;
        rh++;
        n++;
    } while (n < height);

}

//Prompt user for a positive integer 1-8 for height
int get_positive_int(void)
{
    int w;
    do
    {
        w = get_int("Height: ");
        if (w < 1 || w > 8)
        {
            printf("Please enter a positive integer 1-8\n");
        }
    }
    while (w < 1 || w > 8);
    return w;
}
