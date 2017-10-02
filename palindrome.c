#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //declare and initiat vars
    string word;
    int count;
    int nakedcount = 0;


    //prompt for and take in word
    printf("Check to see if a string is a palindrome: ");
    word = get_string();
    count = strlen(word);

    if (count > 24)
    {
        printf("Too many characters in string. 25 or less.\n");
        return 0;
    }

    // find count of all pertinent characters
    for (int i = 0, j = 0 ; i < count; i++)
    {
        if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') )
        {
            nakedcount++;
            j++;
        }
    }

    char text[nakedcount];

    //take out non pertinent characters
    for( int i = 0, j = 0; i < count; i++)
    {
        if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
        {
            text[j] = word[i];
            j++;
        }
    }

    // transpose string to check against it's reverse
    int comp = nakedcount;
    int halfcount = comp / 2;
    char straight[nakedcount];

    for(int i = 0; i< nakedcount ; i++)
    {
        straight[i] = text[comp-1];
        comp --;
    }
    // check to see if transposed string equals direct string
    for(int i = 0; i < halfcount; i++ )
    {
        if(straight[i] != text[i])
        {
            printf("This is not a palindrome. \n");
            return 0;
        }
    }
    // anything that makes it this far passes the test
    printf("Well, go hang a salami I'm a lasagna hog! Youve Got a Certified Palindrome! \n");
}