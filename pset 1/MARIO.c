#include <cs50.h>
#include <stdio.h>

int h;

int main(void)
{

//To prompt the user to enter a number between 1 and 8 inclusive
//Using do..while loop to prompt the user at least once
do
 {
  h = get_int("Height: ");
 }
while (h<1 || h>8);




 for (int i=1; i<=h; i++)
  {

    for (int k=0; k<h-i; k++)      //Using h-i to print the adequate number of spaces before hashes
     {
      printf(" ");
     }


    for (int j=0; j<i; j++)
     {
      printf("#");
     }
     printf("  ");                 //To print the spaces in between



    for (int b=0; b<i; b++)        //To print the right side
     {
      printf("#");
     }




     printf("\n");                //To print new line
   }
}
