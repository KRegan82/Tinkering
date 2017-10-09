#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// declare global variables
int deck[7][6];


// declare functions
void print_deck();
char prompt_player1();
char prompt_player2();
void drop_piece(char drop, int p);
int checkwin ();

int main(void)
{
    //initialize deck array
    for(int i = 0; i < 7; i++)
    {
        for(int j=0; j < 6; j++)
        {
        deck[i][j] = 0;
        }
    }

    print_deck();
    int check = checkwin();

    while(check < 1)
    {

        for(int i = 0, j = 0; j < 1; i ++)
        {
            char move = prompt_player1();

            if((move == 'a' && deck[0][0] > 0 ) || ( move == 'b' && deck[1][0]) || (move == 'c' && deck[2][0]) || (move == 'd' && deck[3][0]) || (move == 'e' && deck[4][0]) ||
                (move == 'f' && deck[5][0]) || (move == 'g' && deck[6][0]))
            {
            printf("\nThat column is already full dingleberry.\n\n");
            }
            else
            {
                drop_piece(move,1);
                print_deck();
                check = checkwin();
                if(check == 1)
                {
                    printf("Player %i Wins!\n",check);
                    return 0;
                }
                j++;
            }
        }

        for(int i = 0, j = 0; j < 1; i ++)
        {
            char move = prompt_player2();

            if((move == 'a' && deck[0][0] > 0 ) || ( move == 'b' && deck[1][0]) || (move == 'c' && deck[2][0]) || (move == 'd' && deck[3][0]) || (move == 'e' && deck[4][0]) ||
                (move == 'f' && deck[5][0]) || (move == 'f' && deck[6][0]))
            {
            printf("\nThat column is already full dingleberry.\n\n");
            }

            else
            {
                drop_piece(move,2);
                print_deck();
                check = checkwin();
                if(check ==2)
                {
                    printf("Player %i Wins!\n", check);
                    return 0;
                }
                j++;
            }
        }
    }
}
// simply prints the value in the state of the current deck
void print_deck()
{
    printf("\n[a][b][c][d][e][f][g]\n\n");
    printf("[%i][%i][%i][%i][%i][%i][%i]\n",deck[0][0],deck[1][0],deck[2][0],deck[3][0],deck[4][0],deck[5][0],deck[6][0]);
    printf("[%i][%i][%i][%i][%i][%i][%i]\n",deck[0][1],deck[1][1],deck[2][1],deck[3][1],deck[4][1],deck[5][1],deck[6][1]);
    printf("[%i][%i][%i][%i][%i][%i][%i]\n",deck[0][2],deck[1][2],deck[2][2],deck[3][2],deck[4][2],deck[5][2],deck[6][2]);
    printf("[%i][%i][%i][%i][%i][%i][%i]\n",deck[0][3],deck[1][3],deck[2][3],deck[3][3],deck[4][3],deck[5][3],deck[6][3]);
    printf("[%i][%i][%i][%i][%i][%i][%i]\n",deck[0][4],deck[1][4],deck[2][4],deck[3][4],deck[4][4],deck[5][4],deck[6][4]);
    printf("[%i][%i][%i][%i][%i][%i][%i]\n\n",deck[0][5],deck[1][5],deck[2][5],deck[3][5],deck[4][5],deck[5][5],deck[6][5]);
}

//prompts player 1 to enter column they choose to place their piece
char prompt_player1()
{

    char placement = 'z';
    do
    {
    printf("Player 1\n");
    printf("Select a column to place your next piece a-g: ");
    placement = get_char();
    }
    while (placement != 'a' && placement != 'b' && placement != 'c' &&  placement != 'd' && placement != 'e' && placement != 'f' && placement != 'g' &&
           placement != 'A' && placement != 'B' && placement != 'C' &&  placement != 'D' && placement != 'E' && placement != 'F' && placement != 'G');
    return tolower(placement);

}
//prompts player 2 to enter column they choose to place their piece
char prompt_player2()
{
    printf("Player 2\n");
    printf("Select a column to place your next piece a-g: ");
    char placement1 = get_char();
    return tolower(placement1);
}
// places piece in appropriate column on top of any already placed pieces
void drop_piece(char drop, int p)
{
    if((drop >= 'a' && drop <= 'g') || (drop >= 'A' && drop <= 'G'))
    {
        if(drop == 'a' || drop == 'A')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[0][i] == 0)
                {
                    deck[0][i] = p;
                    j++;
                }

            }

        }

        if(drop == 'b' || drop == 'B')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[1][i] == 0)
                {
                    deck[1][i] = p;
                    j++;
                }

            }

        }

        if(drop == 'c' || drop == 'C')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[2][i] == 0)
                {
                    deck[2][i] = p;
                    j++;
                }

            }

        }
        if(drop == 'd' || drop == 'D')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[3][i] == 0)
                {
                    deck[3][i] = p;
                    j++;
                }

            }

        }

        if(drop == 'e' || drop == 'E')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[4][i] == 0)
                {
                    deck[4][i] = p;
                    j++;
                }

            }

        }

        if(drop == 'f' || drop == 'f')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[5][i] == 0)
                {
                    deck[5][i] = p;
                    j++;
                }

            }

        }
        if(drop == 'g' || drop == 'G')
        {
            for(int i = 5, j = 0; j == 0 ; i--)
            {
                if(deck[6][i] == 0)
                {
                    deck[6][i] = p;
                    j++;
                }

            }

        }

    }

}
// checks to see if there is a winning score on the deck
int checkwin()
{
    int who_wins =0;

    for(int i = 0; i < 7; i++) // test all vertical possiblilities
    {
        for (int j =0 ; j < 3 ; j ++)
        {
            if( (deck[i][j] == 0) || (deck[i][j+1] == 0) || (deck[i][j+2] == 0) || (deck[i][j+3] ==0))
            {
                who_wins = 0;

            }
            else
            {
                int test_sum = (deck[i][j] + deck[i][j+1] + deck[i][j+2] + deck[i][j+3]);
                if (test_sum ==4)
                {
                    who_wins = 1;
                    return who_wins;

                }
                else if( test_sum == 8)
                {
                    who_wins = 2;
                    return who_wins;
                }
            }
        }
    }
    // check for all horizontal wins
    for (int i = 0 ; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if((deck[i][j] == 0 ) || (deck[i+1][j] ==0 ) || (deck[i+2][j] == 0 ) || (deck[i+3][j] == 0 ))
            {
                who_wins = 0;
            }
            else
            {
                int test_sum = (deck[i][j] + deck[i+1][j] + deck[i+2][j] + deck[i+3][j]);
                if(test_sum == 4)
                {
                    who_wins = 1;
                    return who_wins;
                }
                else if (test_sum == 8)
                {
                    who_wins = 2;
                    return who_wins;
                }
            }
        }
    }
    // check for all up-diagonal wins e.g. ////
    for(int i = 0; i < 4 ; i++)
    {
        for(int j = 3; j < 6 ; j++)
        {
            if((deck[i][j] == 0) || (deck[i+1][j-1] == 0) || (deck[i+2][j-2] == 0 ) || (deck[i+3][j-3] == 0))
            {
                who_wins = 0;
            }
            else
            {
                int test_sum = (deck[i][j] + deck[i+1][j-1] + deck[i+2][j-2] + deck[i+3][j-3]);
                if(test_sum == 4)
                {
                    who_wins = 1;
                    return who_wins;
                }
                else if(test_sum == 8)
                {
                    who_wins = 2;
                    return who_wins;
                }
            }
        }
    }
    //check for down-diagonal wins e.g. '\\\\'
    for (int i = 0; i < 4 ; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if((deck[i][j] == 0) || (deck[i+1][j+1] == 0) || (deck[i+2][j+2] == 0) || (deck[i+3][j+3] == 0))
            {
                who_wins = 0;
            }
            else
            {
                int test_sum = (deck[i][j] + deck[i+1][j+1] + deck[i+2][j+2] + deck[i+3][j+3]);
                if(test_sum == 4)
                {
                    who_wins = 1;
                    return who_wins;
                }
                else if(test_sum == 8)
                {
                    who_wins = 2;
                    return who_wins;
                }
            }
        }
    }

    // if nothing hits then return 0
    return 0;
}