#include <cs50.h>
#include <stdio.h>


long num;
int m,n,o,p,q;
int b,c;

int main (void)
{
 int sum = 0;                   //To calculate the sum of digits as per Luhn's algorithm

 int Nod = 0;                   //To count the Number of digits(Nod)

 num = get_long("Number: ");



 for (long x= num; x>=10; x=(x-m)/100)
 {
  m = x % 100;                        //arithmetic to find every other digits
  n = m % 10;                        //starting with second to last digit
  o = (m-n)/10;
  p = 2*o;

  if (p>=10)
  {
   q=p%10;
   sum = sum + q + 1;             //To add the products' digits together if it is >= 10
  }

  if (p<10)
  {
   sum = sum + p;                 //To add the products' digits if it is less than 10
  }

  Nod = Nod + 1;
 }



 for (long a=num; a!=0; a=(a-b)/100)
 {
  b = a % 100;                       //arithmetic to find the sum of remaining digits and
  c = b % 10;                        //also to count the number of digits(Nod)
  sum = sum + c;
  Nod = Nod + 1;
 }


 if (sum%10 != 0)                   //To check if the card is valid as per Luhn's algorithm
 {
  printf("INVALID\n");
  return 1;
 }

 if (Nod != 13 && Nod != 15 && Nod != 16)
 {
  printf("INVALID\n");
  return 2;
 }


 if (Nod==15 && sum%10==0)            //To check if it is American express card number
 {
  long g = 10000000000000;
  long h = num % g;
  long i = (num-h)/g;                //To find the first two digits of the number

   if (i==34 || i==37)
   {
    printf("American Express\n");
    return 0;
   }

   else
   {
    printf("INVALID\n");
    return 3;
   }
 }

 if (Nod==13 && sum%10==0)              //To check if it is VISA card number
 {
  long ab=1000000000000;
  long bc=num % ab;
  long cd=(num-bc)/ab;                  //To find the first digit of the number

   if (cd==4)
   {
    printf("VISA\n");
    return 0;
   }

   else
   {
    printf("INVALID\n");
    return 4;
   }

 }

 if (Nod==16 && sum%10==0)             //To check if it is VISA or Master card
 {
  long mn=100000000000000;
  long no=num % mn;
  long op=(num-no)/mn;                //To find the first two digits of the number

   if (op>=40 && op<=49)              //To check for VISA card
   {
    printf("VISA\n");
   }

   else if (op>=51 && op<=55)         //To check for Master card
   {
    printf("MASTER CARD\n");
   }

   else
   {
    printf("INVALID\n");
    return 5;
   }
 }

}