#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 9

// To define struct called candidate having two fields.

typedef struct
{
 char *name;
 int votes;
}candidate;

candidate candidates [MAX];
int candidate_count;

int vote(char *mn);
void print_winners();


int main (int argc, char *argv[])
{
//To check if the user enters candidates as command line arguments or not.
if (argc == 1)
{
 printf("enter the name of candidates(upto 9) \n");
 return 1;
}

if (argc > 10)
{
 printf("enter max of 9 candidates. \n");
 return 1;
}

candidate_count = argc -1;             //Number of candidates

// To store the user entered candidates in an array.

for (int i =0; i<candidate_count; i++)
{
int s = strlen(argv[i+1]);

candidates[i].name = malloc(s+1);
strcpy(candidates[i].name, argv[i+1]);

candidates[i].votes =0;

}

int n;
printf("number of votes: ");
scanf("%i",  &n);

char s[n][30];

for (int j =0;  j<n;  j++)
{
printf("vote: ");
scanf("%s", s[j]);

if (vote(s[j])==1)
{
 printf("invalid \n");
}

}
print_winners();


//To de-allocate the memory allocated by malloc() and return it to heap.

for(int h=0; h<candidate_count; h++)
{
 free(candidates[h].name);
}

}


//Function to increase the vote count of the candidates.

int vote(char *mn)
{
int q = 1;
for (int k=0; k<candidate_count; k++)
 {
  if (strcmp(candidates[k].name,mn) == 0)      //To check if the vote is valid
   {
    candidates[k].votes++;
    q = 0;
   }
 }
return q;
}

//Function to print out the winner(or winners) of the election.

void print_winners()
{
int max_votes=0;
for (int u=0; u<candidate_count; u++)
{
if (candidates[u].votes > max_votes)
 {
  max_votes=candidates[u].votes;                  //To find maximum number of votes.
 }
}

for (int z=0; z<candidate_count; z++)
{
if (candidates[z].votes == max_votes )
 {
  printf("%s\n", candidates[z].name);           //To print the winner/s
 }
}

}

