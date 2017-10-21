#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

#define HEADERS 54

int main(void)
{
    //prompt for and store height (in 4^ pixel size)
    fprintf(stderr, "How many layers do you want? ");
    int n = get_int();

    //setup paramaters to write to .bmp file

    char ofName[20];
    sprintf(ofName,"sierpinski%05i.bmp",n);
    FILE *outfile = fopen(ofName,"w");

    // setup file header and info header assignments
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    //calculate header and header info values to write using structs in bmp.h
    bi.biWidth = ((sizeof(RGBTRIPLE) * (2 * n)) + (sizeof(RGBTRIPLE) * 4));
    bi.biHeight = ((sizeof(RGBTRIPLE) * (2 * n)) + (sizeof(RGBTRIPLE) * 4));
    //int width = bi.biWidth;
    //int height = abs(bi.biHeight);

    //calculate padding that will be needed
    int pad = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // write new image size
    bi.biSizeImage = bi.biHeight * (bi.biWidth + pad);

    // write new file size
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write new file header parameters

    bf.bfType = 0x4d42;
    bf.bfReserved1 = 0x0000;
    bf.bfReserved2 = 0x0000;
    bf.bfOffBits = 0x00000036;

    //write new info header parameters
    bi.biPlanes = 0x0001;
    bi.biBitCount = 0x0018;
    bi.biCompression = 0x0000000;
    bi.biXPelsPerMeter = 0x00000b12;
    bi.biYPelsPerMeter = 0x00000b12;
    bi.biClrUsed = 0x00000000;
    bi.biClrImportant = 0x00000000;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outfile);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outfile);

    //necessary variables for triangle algorithm
    int body[n][n];
    int print = 0;

    //create rgp triple for manipulation
    RGBTRIPLE pixel;
    //add buffer lines to top of .bmp
    for(int i = 0; i< ((n*2)+2); i++)
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


    for(int i = 0; i< ((n*2)+2); i++)
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
        for(int j = 0; j <( n ) - i ; j++ )
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
        for(int j = 0; j <( n ) - i ; j++ )
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
        for(int j = 0; j <( n ) - i ; j++ )
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
        for(int j = 0; j <( n ) - i ; j++ )
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
    for(int i = 0; i< ((n*2)+2); i++)
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
    for(int i = 0; i< ((n*2)+2); i++)
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

    fclose(outfile);
    return 0;
}

