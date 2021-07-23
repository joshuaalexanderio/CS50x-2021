#include <cs50.h>
#include <stdio.h>



int main(void)
{
    //gets credit card number from user
    long num = get_long("Number: ");


    //CHECK SUM
    //
    //
    //Multiplies every other digit, starting with the second to last, then stores the sum of those digits in "x"
    long num1 = num / 10;
    int lastDigits = 0;
    int x = 0;
    for (int i = 0; i < 12; i++)
    {
        lastDigits = num1 % 10;
        lastDigits = lastDigits * 2;
        x = x + (lastDigits % 10) + (lastDigits / 10 % 10);
        num1 = num1/100;

    }
  //Adds the sum(x) to the sum of the digits that weren’t multiplied by 2
    long num2 = num;
    long lastDigits1 = 0;
    int z = 0;
    for (int i = 0; i < 12; i++)
    {
        lastDigits1 = num2 % 10;
        z = z + (lastDigits1 % 10) + (lastDigits1 / 10 % 10);
        num2 = num2/100;
    }
    x = x + z;


//Checks if the card is valid or not
    bool validity = true;
    if (x % 10 != 0)
    {
        printf("INVALID");
        validity = false;
    }








    //IDENTIFIES TYPE
    //
    //
    if (validity)
    {
        //gets first two digits of number
        for (; num >= 100; num = num/10)
        {

        }


        //finds which type of card the number belongs to based on first two digits
        if ((num == 34) || (num == 37))
        {
            printf("AMEX");
        }
        else if((num == 51) || (num == 52) || (num == 53) || (num == 54) || (num == 55))
        {
            printf("MASTERCARD");
        }
        else if(num / 10 == 4)
        {
            printf("VISA");
        }
        else {
            printf("INVALID");
        }
    }
}





