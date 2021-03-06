#include <stdio.h>
#include <stdlib.h>

/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

/*
psudocode:
open card file
repeat until end of card
    read 512 bytes into a buffer
    if start of new jpg
        .....
    else if already found jpg    
        .....
close file
*/


/*
JPG starts with:
0xff 0xd8 0xff 0xe0 
0xff 0xd8 0xff 0xe1
*/
int main(int argc, char* argv[])
{
    // TODO
    //Opens the file
    FILE* file = fopen("card.raw", "r");
    
    //Ends the program if NULL
    if (file == NULL)
    {
        printf("Could not open file \n");
        return 1;
    }
    
    unsigned char buffer[512]; 
    fread(&buffer, 512, 1, file);
    
    //Keeps track of amount of jpgs found
    int jpgcounter = 0; 
    
    //Implements loop as long as it's not the eof
    do
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            char title[8];
            
            //makes new jpg
            sprintf(title, "%d.jpg", jpgcounter);
            FILE* img = fopen(title, "w");
            jpgcounter++;
            
            fwrite(&buffer, sizeof(buffer), 1, img);
        }
        
    } while(!feof(file));
        
    fclose(file);
    return 1;
}
