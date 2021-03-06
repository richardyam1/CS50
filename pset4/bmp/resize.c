/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize (number) infile outfile\n");
        return 1;
    }

    // remember filenames
    int size = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if (size < 1 || size > 100)
    {
        printf("Please input a number equal or less than 100.\n");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //Stores old dimensions declare new ones.
    
    int old_width = bi.biWidth;
    int old_height = bi.biHeight;
    bi.biWidth = old_width * size;
    bi.biHeight = old_height * size;
   
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (old_width * sizeof(RGBTRIPLE)) % 4) % 4;
    // Calculate new padding (My code)
    int new_padding = (4 -(bi.biWidth * sizeof(RGBTRIPLE)) %4 ) %4; 
    
    //Size of header is 54 bytes (My code).
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight);
    bf.bfSize = 54 + bi.biSizeImage;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(old_height); i < biHeight; i++)
    {
        //Copies the lines vertically (My code)
        for (int g = 0; g < size; g++)
        {
        // iterate over pixels in scanline
            for (int j = 0; j < old_width; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                //Copies the line horizontally (My code) (My code)
                for (int h = 0; h < size; h++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }
            
            //Moves the pointer to the start of the infile line. (My code) (My code)
            fseek(inptr, -(old_width * sizeof(RGBTRIPLE) + padding), SEEK_CUR);
        }
        //Moves the pointer to the next infile line.  (My code)
        fseek(inptr, old_width * sizeof(RGBTRIPLE) + padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
    
    
    // that's all folks
    return 0;
}
