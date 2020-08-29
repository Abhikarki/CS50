#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>


#define MAX_VOTERS 9
#define MAX_CANDIDATES 9


int voter_count;
int candidate_count;

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct{
    string name;
    int votes;
    bool eliminated;
}candidate;
candidate candidates[MAX_CANDIDATES];


bool vote(int voter, int rank, string name);
void tabulate();
bool print_winners ();
int find_min();
void eliminate (int ac);
bool is_tie(int qb);


int main (int argc, string argv[])
{
    //Check the number of command line arguments.
    if(argc<2)
     {
         printf("Enter the name of candidates.\n");
         return  2;
     }

if (argc>10)
{
    printf("Maximum number of candidates =9\n");
    return 3;
}



// check Number of candidates from command line arguments
candidate_count = argc-1;
for(int i=0; i<candidate_count; i++)
    {
    int s = strlen(argv[i+1]);
    //Memory allocation using malloc.
    candidates[i].name = malloc(s+1);
    strcpy(candidates[i].name, argv[i+1]);

    candidates[i].votes=0;

    candidates[i].eliminated=false;
    }


voter_count = get_int("Number of votes:  ");


    for (int a = 0; a < voter_count; a++)
    {
        for (int b = 0; b < candidate_count; b++)
        {
            string name = get_string("Rank %i: ",b+1);

            if (vote(a, b, name)==false)
            {
                printf("invalid vote.\n");
                return 3;
            }

        }
        printf("\n");
    }

tabulate();

while (print_winners ()==false)
{
    int min = find_min();

    if (is_tie(min) ==true)
    {
       for (int mp = 0; mp < candidate_count; mp++)
       {
           if (candidates[mp].eliminated == false)
           {
               printf("%s\n", candidates[mp].name);
           }
       }
       /*Break the while loop if is_tie(min) == true i.e if there is tie between
         remaining non-eliminated candidates */
       break;
     }
    else
    {
      eliminate(min);

      /*The following loop sets the votes of all candidates to zero before the tabulate
        function is called so that the votes for non-eliminated candidates donot increase
        again and again everytime the tabulate function is called */

      for (int candidate_num = 0; candidate_num < candidate_count; candidate_num ++)
      {
          candidates[candidate_num].votes = 0;
      }

      tabulate();
    }

}

for (int free_num = 0; free_num < candidate_count; free_num++)
{
    //free the memory allocated by malloc.
    free(candidates[free_num].name);
}

}


//This function returns 'true' if the name entered by voter matches with that of one of the candidates of election otherwise returns 'false'.
bool vote(int voter, int rank, string name)
{
    bool result = false;

   for (int uv = 0; uv < candidate_count; uv++)
   {
       //Check if the name of the candidate is valid.
       if (strcmp(candidates[uv].name , name) == 0)
       {

       preferences[voter][rank] = uv;
       result = true;
       break;
       }
   }
   return result;
}



//To tabulate the votes of the candidates.
void tabulate()
{
    for (int g = 0; g < voter_count; g++)
    {
        for (int h = 0; h < candidate_count; h ++)
        {
          int ak = preferences[g][h];

          if (candidates[ak].eliminated == false)
          {
            candidates[ak].votes++;
            break;
          }
        }

    }
}



//To print winner(if there's any yet)and return true , else return false.
bool print_winners ()
{
    bool final = false;
    for (int kg = 0; kg < candidate_count; kg++)
    {
        if (candidates[kg].votes > (voter_count / 2))
        {
        printf("%s\n", candidates[kg].name);
        final = true;
        }

     }
     return final;

}




//To find the minimum number of votes among non-eliminated candidates.
int find_min()
{
    int min_votes = 20;
    for (int xy=0; xy<candidate_count; xy++)
    {
        if (candidates[xy].eliminated==false)
        {
            if (candidates[xy].votes<min_votes)
            {
                min_votes=candidates[xy].votes;
            }
        }
    }

   return min_votes;

}



//To eliminate the candidate with minimum votes(among non-eliminated candidates).
void eliminate (int min)
{
    for (int xz = 0; xz < candidate_count; xz++)
    {
        if (candidates[xz].eliminated == false)
        {
        if (candidates[xz].votes == min)
        {
            candidates[xz].eliminated = true;
        }
        }
    }


}


//To check if there is tie among non-eliminated candidates.
bool is_tie(int min)
{

    bool tie = false;
    int min_can = 0;
    int remaining = 0;
    for (int pq = 0; pq < candidate_count; pq++)
    {
        if (candidates[pq].eliminated == false)
        {
         remaining++;
         if (candidates[pq].votes == min)
         {
             min_can++;
         }
        }
    }

    if (remaining == min_can)
    {
        tie = true;
    }

    return tie;
}