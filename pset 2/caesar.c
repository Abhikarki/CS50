#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
  // Checking the number of command line arguments

 if (argc != 2)
  {
   printf("USAGE: ./caesar.c key\n");
   return 1;
  }

  // To check whether the key is integer or not.

 int mp= strlen (argv[1]);
 for (int j = 0; j<mp; j++)
 {
  if (isdigit(argv[1][j]) ==0 )
   {
    printf("USAGE:./caesar key(Digits only)\n");
    return 1;
    break;
   }
 }

 // To check if the key is negative

 int k= atoi(argv[1]);
 if (k<0)
  {
   printf("USAGE: ./caesar key(+ve integer)\n");
  }

  // To get the plaintext from the user

 string ut= get_string("plaintext: ");
 int len=strlen(ut);

 printf("ciphertext: ");



 // checking for uppercase and lowercase

 for (int i=0; i<len; i++ )
  {
   char uc = ut[i];
   if (isupper(uc))
    {
     int q = (int)uc;
     char m = (char)  ( (q - 65 + k)%26 + 65 );
     printf("%c",m);
    }

   else if (islower(uc))
    {
     int q = (int)uc;
     char m = (char) ( (q - 97 + k)%26 + 97 );
     printf("%c", m);
    }

   else
    {
     printf ("%c", uc);
    }
  }
printf("\n");           //To print new line
}



