#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  int sum, avg;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
      {
        sum = 0;
        sum = sum + image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;

        //Taking the average of the sum and rounding it.
        avg = round(sum / 3);

        //Updating the color values.
        image[i][j].rgbtBlue = avg;
        image[i][j].rgbtGreen = avg;
        image[i][j].rgbtRed = avg;
     }
  }
    return;
}

//This function in used below in function 'sepia' to return a integer value <= 255.
int range(float n)
{
   int result = round(n);
   if (result > 255)
   {
       return 255;
   }
   else
   {
       return result;
   }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int blue, green, red;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;
            red = image[i][j].rgbtRed;

           //range function returns an integer value that is less than or equal to 255.
           image[i][j].rgbtBlue = range((.272 * red) + (.534 * green) + (.131 * blue));
           image[i][j].rgbtGreen = range((.349 * red) + (.686 * green) + (.168 * blue));
           image[i][j].rgbtRed = range((.393 * red) + (.769 * green) + (.189 * blue));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int j, last;
    int blue, green, red;             //Temporary values for swapping.
    for (int i = 0; i < height; i++)
    {
        j = 0 ; last = width - 1;
        //The following while loop continues until values of 'j' and 'last' coincide.
        while (j <= last)
        {
            blue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][last].rgbtBlue;
            image[i][last].rgbtBlue = blue;

            green = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][last].rgbtGreen;
            image[i][last].rgbtGreen = green;

            red = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][last].rgbtRed;
            image[i][last].rgbtRed = red;

            //updating values of j and last.
            j = j + 1;
            last = last -1;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height + 2][width +2];

/*creating a temporary array 'tmp' similar to the
'image' but surrounded by 0s
so, if image:      then tmp is:
 1  2  3           0  0  0  0  0
 4  5  6           0  1  2  3  0
 7  8  9           0  4  5  6  0
                   0  7  8  9  0
                   0  0  0  0  0
this helps us to use the same loop code for every pixels.
The average of color values will be taken in array 'tmp'
but will be updated in the corresponding pixel of 'image'.*/


//Initializing all pixels' color values of tmp to 0.
for (int i = 0; i < height + 2; i++)
{
    for (int j = 0; j < width + 2; j++)
       {
        tmp[i][j].rgbtBlue = 0;
        tmp[i][j].rgbtGreen = 0;
        tmp[i][j].rgbtRed= 0;
       }
}

//Copying the pixels from 'image' to 'tmp' except the outer layer.
for (int a = 0; a < height; a++)
{
    for (int b = 0; b < width; b++)
    {
        tmp[a + 1][b + 1].rgbtBlue = image[a][b].rgbtBlue;
        tmp[a + 1][b + 1].rgbtGreen = image[a][b].rgbtGreen;
        tmp[a + 1][b + 1].rgbtRed = image[a][b].rgbtRed;
    }
}

int blue, green, red;
//The loops to iterate through 'tmp' starting from [1][1].
for (int x = 1; x <= height; x++)
{
    for (int y = 1; y <= width; y++)
    {
     blue = 0; green = 0; red = 0;

    /*The following loops iterate through all of the pixels that are
    within 1 row and column of the original pixel(including itself)
    in the temporary arrray 'tmp'.*/

      for (int l = -1; l <= 1; l++)
      {
          for (int m = -1; m <= 1; m++)
          {
              blue = blue + tmp[x + l][y + m].rgbtBlue;
              green = green + tmp[x + l][y + m].rgbtGreen;
              red = red + tmp[x + l][y + m].rgbtRed;
          }

      }
      //Taking the average of the color values and rounding them.
      blue = round(blue / 9);
      green = round(green / 9);
      red = round(red / 9);

      /*Finally updating the color values of corresponding pixel
       in "image"(not tmp).*/
      image[x - 1][y - 1].rgbtBlue = blue;
      image[x - 1][y - 1].rgbtGreen = green;
      image[x - 1][y - 1].rgbtRed = red;
    }
}
    return;
}

