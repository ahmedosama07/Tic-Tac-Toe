#include <stdio.h>
#include <string.h>

#define ROW1(PLAYER) arr[0]==PLAYER&&arr[1]==PLAYER&&arr[2]==PLAYER
#define ROW2(PLAYER) arr[3]==PLAYER&&arr[4]==PLAYER&&arr[5]==PLAYER
#define ROW3(PLAYER) arr[6]==PLAYER&&arr[7]==PLAYER&&arr[8]==PLAYER
#define COL1(PLAYER) arr[0]==PLAYER&&arr[3]==PLAYER&&arr[6]==PLAYER
#define COL2(PLAYER) arr[1]==PLAYER&&arr[4]==PLAYER&&arr[7]==PLAYER
#define COL3(PLAYER) arr[2]==PLAYER&&arr[5]==PLAYER&&arr[8]==PLAYER
#define DIAGONAL1(PLAYER) arr[0]==PLAYER&&arr[4]==PLAYER&&arr[8]==PLAYER
#define DIAGONAL2(PLAYER) arr[2]==PLAYER&&arr[4]==PLAYER&&arr[6]==PLAYER

#define WINNING(PLAYER) (ROW1(PLAYER))||(ROW2(PLAYER))||(ROW3(PLAYER))||(COL1(PLAYER))||(COL2(PLAYER))||(COL3(PLAYER))||(DIAGONAL1(PLAYER))||(DIAGONAL2(PLAYER))
int main()
{
    char choice1;
    char choice2;
    int p1;
    int p2;
    int i = 0;
    int j = 0;;
    int position;
    int move = 1;
    int x = 0;
    int y = 0;
    int count = 0;
    int c = 1;
    int d = 0;
    int k = 0;
    int flag = 1;
    int arr[8];

    for(i = 0; i < 9; i++)
    {
        arr[i] = 3;
    }

    printf("_________\n");
    printf("|  |  |  |\n");
    printf("|__|__|__|\n");
    printf("|  |  |  |\n");
    printf("|__|__|__|\n");
    printf("|  |  |  |\n");
    printf("|__|__|__|\n");

    while(flag == 1)
    {
        printf("Player1 choose X or O: ");
        scanf("%c", &choice1);

        if((tolower(choice1) == 'x') || (tolower(choice1) == 'o'))
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            printf("Invalid\n");
        }
    }

    if(tolower(choice1) == 'x')
    {
        choice1 = 'X';
        choice2 = 'O';
    }
    else
    {
        choice1 = 'O';
        choice2 = 'X';
    }

    printf("Player1: %c || Player2: %c\n", choice1, choice2);

    if(tolower(choice1) == 'x')
    {
        p1 = 1;
        p2 = 0;
    }
    else
    {
        p1 = 0;
        p2 = 1;
    }

    while(move < 3)
    {
        count = 0;
        if(move == 1)
        {
            printf("Player1 position: ");
            scanf("%d", &position);

            if(arr[position] == 3)
            {
                arr[position] = p1;
                k = 0;
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 3; j++)
                    {
                        if(arr[k] == 3)
                        {
                            printf("\t-");
                        }
                        else if(arr[k] == 1)
                        {
                            printf("\tX");
                        }
                        else if(arr[k] == 0)
                        {
                            printf("\t0");
                        }

                        k++;
                    }
                    printf("\n");
                }

                if(WINNING(p1))
                {
                    printf("Player1 wins\n");
                    x = 1;
                    printf("Thanks for playing\n");
                    move = 3;
                    break;
                }
                else
                {
                    move = 2;
                }
            }
            else
            {
                printf("Place is not empty");
                move = 1;
            }
        }

            for(i = 0; i < 9; i++)
            {
                if(arr[i] == 3)
                {
                    count++;
                }
            }

            if(count == 0)
            {
                move = 3;
                break;
            }

            if(move = 2)
            {
                printf("Player2 position: ");
                scanf("%d", &position);

            if(arr[position] == 3)
            {
                arr[position] = p2;
                k = 0;
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 3; j++)
                    {
                        if(arr[k] == 3)
                        {
                            printf("\t-");
                        }
                        else if(arr[k] == 1)
                        {
                            printf("\tX");
                        }
                        else if(arr[k] == 0)
                        {
                            printf("\t0");
                        }

                        k++;
                    }
                    printf("\n");
                }

                if(WINNING(p2))
                {
                    printf("Player2 wins\n");
                    y = 1;
                    printf("Thanks for playing\n");
                    move = 3;
                    break;
                }
                else
                {
                    move = 1;
                }
            }
            else
            {
                printf("Place is not empty");
                move = 2;
            }
        }
    }

    if((x != 1) && (y != 1))
    {
        printf("Draw\n");
        printf("Thanks for playing\n");
    }
    return 0;
}
