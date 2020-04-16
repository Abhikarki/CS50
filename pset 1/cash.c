#include <cs50.h>
#include <stdio.h>
#include <math.h>

float dollars;                       //Using data type float to handle dollars and cents

int main (void)
{
 int coins = 0;                       //The counter for minimum number of coins is set to 0

 do{
 dollars = get_float("change owed: ");
 }
 while (dollars < 0);                  //To prompt the user to enter valid number(positive number)

 int cents = round(dollars * 100);     //To round the cents to nearest penny

 do
 {
   if (cents>=25)
   {
    cents = cents - 25;
    coins =  coins + 1;
   }

   else if (cents>=10 && cents<25)
   {
    cents = cents - 10;
    coins = coins + 1;
   }

   else if (cents>=5 && cents<10)
   {
    cents = cents - 5;
    coins = coins + 1;
   }

   else if (cents>=1 && cents<5)
   {
    cents = cents - 1;
    coins = coins + 1;
   }


 }
 while(cents!=0);

printf("%i\n",coins);               //Prints the minimum number of coins
}