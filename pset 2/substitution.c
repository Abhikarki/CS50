#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
 //To check the number of command line arguments
 if (argc != 2)
 {
  printf("usage: ./substitution key");
  return 1;
 }

int bv = strlen (argv[1]);

//To check the length of the argument
if (bv != 26)
{
 printf("key should be 26 characters\n");
 return 1;
}

//To check if it contains only alphabets
for (int i = 0; i<bv; i++)
 {
  if ( isalpha(argv[1][i]) == 0)
   {
    printf("key should contain only characters.\n");
    return 1;
    break;
   }
 }

string g = get_string ("plaintext: ");

int sd = strlen(g);
int k[sd];
printf("ciphertext: ");

//To print the ciphertext
for (int j =0; j < sd; j++)
{

if ( isupper(g[j]) )
 {
  int b = (int)g[j] - 65;
  printf("%c", toupper(argv[1][b]));
 }

else if (islower(g[j]))
 {
  int b = (int)g[j] - 97;
  printf("%c", tolower(argv[1][b]));
 }

else
 {
  printf("%c", g[j]);
 }

 }
 printf("\n");
}