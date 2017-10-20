#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t  BYTE;


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile \n");
        return 1;
    }
    // input the new file into a char*
    char *infile = argv[1];
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    //setup array for the buffer
    BYTE buf[512];
    //counter for .jpg number
    int count = 0;
    //file for output file
    FILE *outfile = NULL;
    //start reading the infile to check for .jpg header signature
    for (int i = 0; (fread(buf,512,1,inptr)) > 0 ; i++ )
    {
        //check to see if the first four bytes match our .jpg header conditions
        if( buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            char ofName[8];
            sprintf(ofName,"%03i.jpg",count);
            for (int j = 0; j < 2048; j++)
            {
                outfile = fopen(ofName,"w");
                fwrite(&buf[j],512,1,outfile);
            }
            count++;
            fclose(outfile);

        }
    }
    fclose(inptr);

    return 0;
}