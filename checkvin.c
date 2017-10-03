#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // declare and initiate starting vars
    string startvin;
    int vinNum[17];
    int weight[17] = {8,7,6,5,4,3,2,10,0,9,8,7,6,5,4,3,2};
    int product = 0;

    //prompt for and receive vin number
    printf("Enter Vehicle Identification Number: ");
    startvin = get_string();
    printf("\n");
    //checks to assure that there are 17 characters entered
    if(strlen(startvin) != 17)
    {
            printf("Try again, needs 17 alphanumeric characters. \n");
            return 0;
    }

    char pos9 = startvin[8];
    //checks to assure values are alphanumeric
    for (int i = 0; i < 17; i++ )
    {
        if ((startvin[i] >= 'a' && startvin[i] <= 'z') || (startvin[i] >= 'A' && startvin[i] <= 'z') || (startvin[i] >= '0' && startvin[i] <= '9'));

        else
        {
            printf("Values must be alphanumeric.\n");
            return 0;
        }
    }
    string vin = startvin;

    // drop down all upper cases to lower case
    for (int i = 0; i < 17; i++)
    {
        if((vin[i] >= 'A') && (vin[i] <= 'Z'))
        {
            vin[i] = vin[i] + 32;
        }
    }
    //enter each value of the string into an int array as the proper transliteration
    for (int i = 0; i < 17; i++)
    {
        if((vin[i] == 'q') || ( vin[i] == 'o') || (vin[i] == 'i'))
        {
            printf("VIN contains invalid characters.\n");
            return 0;
        }
        else if ((vin[i] == '1') || (vin[i] == 'a') || (vin[i] == 'j' ))
        {
            vinNum[i] = 1;
        }
        else if((vin[i] == '2') || (vin[i] == 'b') || (vin[i] == 'k') || (vin[i] == 's'))
        {
            vinNum[i] = 2;
        }
        else if((vin[i] == '3') || (vin[i] == 'c') || (vin[i] == 'l') || (vin[i] == 't'))
        {
            vinNum[i] = 3;
        }
        else if((vin[i] == '4') || (vin[i] == 'd') || (vin[i] == 'm') || (vin[i] == 'u'))
        {
            vinNum[i] = 4;
        }
        else if ((vin[i] == '5') || (vin[i] == 'e') || (vin[i] == 'n' ) || (vin[i] == 'v'))
        {
            vinNum[i] = 5;
        }
        else if((vin[i] == '6') || (vin[i] == 'f') || (vin[i] == 'w'))
        {
            vinNum[i] = 6;
        }
        else if((vin[i] == '7') || (vin[i] == 'g') || (vin[i] == 'p') || (vin[i] == 'x'))
        {
            vinNum[i] = 7;
        }
        else if((vin[i] == '8') || (vin[i] == 'h') || (vin[i] == 'y'))
        {
            vinNum[i] = 8;
        }
        else if((vin[i] == '9') || (vin[i] == 'r') || (vin[i] == 'z'))
        {
            vinNum[i] = 9;
        }
        else if(vin[i] == '0')
        {
            vinNum[i] = 0;
        }


    }
    //weight the transliterated values and add them all to a single product
    for( int i = 0; i < 17 ; i++)
    {
        product = product + (vinNum[i] * weight[i]);
    }
    int mod = product % 11;
    if (pos9 == 'x')
    {
        vinNum[8] = 10;
    }
    if( vinNum[8] == mod)
    {
        printf("This is a valid VIN check Digit. \n");
    }
    else
    {
        printf("This VIN check digit doesn't work. \n");
    }

}