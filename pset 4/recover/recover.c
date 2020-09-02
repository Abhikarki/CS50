#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;



int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("USAGE: ./recover image\n");
        return 1;
    }

    //To keep track of the number of images.
    int num = 0;
    //To store the name of the image file.
    char name[8];
    FILE *fname;
    //buffer stores the bytes read from the card.
    BYTE buffer[512];

    /*To open the file for reading, argv[1] is the name
    of the file given by user in command line*/
    FILE *fp = fopen(argv[1], "r");

    /*The following while loop reads 512 bytes from the
    card at a time until the end of the file is reached.*/
    while (fread(buffer, 1, 512, fp) != 0)
     {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0 )       //Bitwise operator '&'.
          {
            //To print the filename.
            sprintf(name, "%03i.jpg", num);

            num = num + 1;
            //open the file for writing
            fname = fopen(name, "w");
            fwrite(buffer, 1, 512, fname);
            fclose(fname);
          }

    else
    {
        /*The code executes only if the first image
        has already been found*/
        if (num != 0)
        {
            //open the file for appending.
            fname = fopen(name, "a");
            fwrite(buffer, 1, 512, fname);
            fclose(fname);
        }
    }

}

}
