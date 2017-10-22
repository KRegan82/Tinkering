#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>


// data types for the standard MS sruct values for the headers
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

//bmp file header struct
typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

//bmp info header struct
typedef struct
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

//bmp pixel struct
typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
// this program is designed to 'build' a sierpinski triangle of n layers given the users input. triangle built from top down using 2 x 2 pixel structure
// the structs above are completely 'borrowed' from the team at harvards cs50 class, whose mobile IDE is also wehre I wrote this
// and a special thank you to Irene Naya and Aditya Singhania two strangers on facebook for whom I couldn't have made this without
int main(void)
{
    //prompt for and store height (in 2x2 pixel size)
    fprintf(stderr, "How many layers do you want? ");
    int n = get_int();

    //setup paramaters to write to .bmp file and filename

    char ofName[21];
    sprintf(ofName,"sierpinski%05i.bmp",n);
    FILE *outfile = fopen(ofName,"w");

    // setup file header and info header assignments
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    //calculate header and header info values to write using structs in bmp.h
    bi.biWidth = (n * 2) + 4;
    bi.biHeight = 0 -((n * 2) + 4);

    //calculate padding that will be needed
    int pad = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // assign new image size
    bi.biSizeImage = abs(bi.biHeight) * ((bi.biWidth * sizeof(RGBTRIPLE)) + pad);

    // assign new file header parameters

    bf.bfType = 0x4d42;
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = 0x36;

    //assign new info header parameters
    bi.biSize = 0x28;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = 0;
    bi.biXPelsPerMeter = 0xb12;
    bi.biYPelsPerMeter = 0xb12;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    // assign new file size
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outfile);

    //necessary variables for triangle algorithm
    long long body[n][n];
    int print = 0;

    //create rgp triple for manipulation
    RGBTRIPLE pixel;

    //add buffer lines to top of .bmp
    for(int i = 0; i< ((n * 2) + 4); i++)
    {
        pixel.rgbtRed = 0xff;
        pixel.rgbtBlue = 0xff;
        pixel.rgbtGreen = 0xff;
        fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
    }

    //add padding in if necessary
    for (int l = 0; l < pad; l++)
    {
        fputc(0x00, outfile);
    }

    // second layer of top buffer lining
    for(int i = 0; i< ((n * 2) + 4); i++)
    {
        pixel.rgbtRed = 0xff;
        pixel.rgbtBlue = 0xff;
        pixel.rgbtGreen = 0xff;
        fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
    }
    //add padding in if necessary
    for (int l = 0; l < pad; l++)
    {
        fputc(0x00, outfile);
    }
    // iterate over the area and print necessary digits
    for(int i = 0; i < n ; i++)
    {
        // blank space that borders triangle value
        int blankCount = (n + 1) - i;
        //write blank space surrounding start of triangle
        for(int j = 0; j < blankCount; j++ )
        {
            pixel.rgbtRed = 0xff;
            pixel.rgbtBlue = 0xff;
            pixel.rgbtGreen = 0xff;
            fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
        }
        //draw first line of this rows triangle values
        for(int j = 0; j<=i; j++)
        {


            if (j == 0 || i == j)
            {
                print = 1;
                body[i][j] = 1;
            }

            else if( body[i-1][j-1] + body[i-1][j] == 2 || body[i-1][j-1] + body[i-1][j] == 0)
            {
                print = 0;
                body[i][j] = 0;

            }
            else if(body[i-1][j-1] + body[i-1][j] == 1 )
            {
                print = 1;
                body[i][j] = 1;

            }

            if ( print == 0)
            {
                pixel.rgbtRed = 0xff;
                pixel.rgbtBlue = 0xff;
                pixel.rgbtGreen = 0xff;
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
            }
            else if (print == 1)
            {
                pixel.rgbtRed = 0x00;
                pixel.rgbtBlue = 0x00;
                pixel.rgbtGreen = 0x00;
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
            }

        }
        // proceeding blank space bordering back end of triangle
        for(int j = 0; j < blankCount; j++ )
            {
                pixel.rgbtRed = 0xff;
                pixel.rgbtBlue = 0xff;
                pixel.rgbtGreen = 0xff;
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
            }
        //add back in if necessary
        for (int l = 0; l < pad; l++)
        {
            fputc(0x00, outfile);
        }
        //this is really just a second iteration of drawing the same row. each row has to be drawn twice because each element is 2 pixels by two pixels

        for(int j = 0; j <blankCount ; j++ )
        {
            pixel.rgbtRed = 0xff;
            pixel.rgbtBlue = 0xff;
            pixel.rgbtGreen = 0xff;
            fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
        }

        for(int j = 0; j<=i; j++)
        {


            if (j == 0 || i == j)
            {
                print = 1;
                body[i][j] = 1;
            }

            else if( body[i-1][j-1] + body[i-1][j] == 2 || body[i-1][j-1] + body[i-1][j] == 0)
            {
                print = 0;
                body[i][j] = 0;

            }
            else if(body[i-1][j-1] + body[i-1][j] == 1 )
            {
                print = 1;
                body[i][j] = 1;

            }

            if ( print == 0)
            {
                pixel.rgbtRed = 0xff;
                pixel.rgbtBlue = 0xff;
                pixel.rgbtGreen = 0xff;
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
            }
            else if (print == 1)
            {
                pixel.rgbtRed = 0x00;
                pixel.rgbtBlue = 0x00;
                pixel.rgbtGreen = 0x00;
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
            }

        }
        for(int j = 0; j < blankCount; j++ )
            {
                pixel.rgbtRed = 0xff;
                pixel.rgbtBlue = 0xff;
                pixel.rgbtGreen = 0xff;
                fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
            }
        //add padding in if necessary
        for (int l = 0; l < pad; l++)
        {
            fputc(0x00, outfile);
        }

    }
    // add buffer lines to bottom of .bmp
    for(int i = 0; i< ((n * 2) + 4); i++)
    {
        pixel.rgbtRed = 0xff;
        pixel.rgbtBlue = 0xff;
        pixel.rgbtGreen = 0xff;
        fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
    }
    //add padding in if necessary
    for (int l = 0; l < pad; l++)
    {
        fputc(0x00, outfile);
    }
    for(int i = 0; i< ((n * 2) + 4); i++)
    {
        pixel.rgbtRed = 0xff;
        pixel.rgbtBlue = 0xff;
        pixel.rgbtGreen = 0xff;
        fwrite(&pixel, sizeof(RGBTRIPLE), 1, outfile);
    }
    //add padding in if necessary
    for (int l = 0; l < pad; l++)
    {
        fputc(0x00, outfile);
    }
    // just tidying up here
    fclose(outfile);
    return 0;
}

