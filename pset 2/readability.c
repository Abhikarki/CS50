#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int count_letters(string abc);
int count_words(string xyz);
int count_sentence(string ghi);


//To do the readability test and find grade level

int main (void)
{
 string text = get_string("Text: ");
 int l = count_letters(text);
 int w = count_words(text);
 int s = count_sentence(text);

 float L = (l*100)/w;
 float S = (s*100)/w;

 float index= (0.0588*L) - (0.296*S) - 15.8;     //formula to calculate Coleman-Liau index
 int grade = round(index);

 if (grade<=16 && grade>=1)
  {
  printf("Grade: %i\n", grade);
  }

 else if (grade > 16)
  {
    printf("Grade 16+\n");
  }

 else
  {
    printf("Before Grade 1\n");
  }
}



//To count the number of letters

int count_letters(string abc)
{
 int let=0;
 int N= strlen(abc);
 for (int i=0; i<N; i++)
  {
    if((int) abc[i]>=65 && (int) abc[i]<=90)
      {
        let =let +1;
      }

    if  ( (int) abc[i]>=97 && (int) abc[i]<=122)
      {
        let =let +1;
      }
  }
  return let;
}



//To count the number of words

int count_words(string xyz)
{
 int wor=1;
 int m = strlen(xyz);
 for (int j=0; j<m; j++)
  {
   if ((int)xyz[j]== 32)
    {
      wor = wor+1;
    }
  }
    return wor;
}



//To count the number of sentences

int count_sentence(string ghi)
{
 int sent=0;
 int s= strlen(ghi);
 for (int k=0; k<s; k++)
  {
   if ( (char)ghi[k]=='.' || (char)ghi[k]=='?' || (char)ghi[k]=='!'  )
    {
      sent = sent+1;
    }
  }
  return sent;
}