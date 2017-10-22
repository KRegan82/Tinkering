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

    //necessary variables for triangle algorithm
    int body[n][n];
    int print = 0;


    for(int i = 0; i< ((n*2)+4); i++)
    {
        fprintf(stderr,"0");
    }
    fprintf(stderr,"\n");
    for(int i = 0; i< ((n*2)+4); i++)
    {
        fprintf(stderr,"0");
    }
    fprintf(stderr,"\n");
    // iterate over the area and print necessary digits
    for(int i = 0; i < n ; i++)
    {
        int blankCount = (n + 1) - i;

        for(int j = 0; j < blankCount ; j++ )
        {
            fprintf(stderr,"0");
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
                fprintf(stderr," ");
                fprintf(stderr," ");
            }
            else if (print == 1)
            {
                fprintf(stderr,"1");
                fprintf(stderr,"1");
            }

        }
        for(int j = 0; j < blankCount ; j++ )
            {
                fprintf(stderr,"0");
            }

        fprintf(stderr,"\n");

        for(int j = 0; j <blankCount ; j++ )
        {
            fprintf(stderr,"0");
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
                fprintf(stderr," ");
                fprintf(stderr," ");
            }
            else if (print == 1)
            {
                fprintf(stderr,"1");
                fprintf(stderr,"1");
            }

        }
        for(int j = 0; j <blankCount; j++ )
            {
                fprintf(stderr,"0");
            }
        fprintf(stderr,"\n");

    }
    // add buffer lines to bottom of .bmp
    for(int i = 0; i< ((n*2)+4); i++)
    {
        fprintf(stderr,"0");
    }
    fprintf(stderr,"\n");
    for(int i = 0; i< ((n*2)+4); i++)
    {
        fprintf(stderr,"0");
    }
    fprintf(stderr,"\n");

    return 0;
}

