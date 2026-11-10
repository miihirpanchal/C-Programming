#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// int main()
//{
//     srand(time(NULL));//srand takes seed as input and is defined in stdlib.h
//     printf("The Random Number Between 1 & 100 is %d\n", rand() % 100);
//     return 0;
// }

int RandomNumberGenerator()
{
    return rand() % 3;
}
int main()
{
    char name[20];
    int ComputerChoise, PlayerChoise;
    int PlayerScore = 0, ComputerScore = 0;
    int i = 1;

    // Initiallize Random number.
    srand(time(NULL));

    printf("Enter The Name Of The Player\n");
    scanf("%19s", name);
    printf("\nWELLCOME %s! \n", name);
    printf("The Rock, Paper & Scissors Game Begins\n");
    while (i <= 3)
    {
        printf("\n------- ROUND %d--------\n", i);
        printf("You Can Choose Your Option from....\n");
        printf("0. ROCK\n");
        printf("1. PAPER\n");
        printf("2. SCISSOR\n");

        printf("Enter Your Choise :");
        if (scanf("%d", &PlayerChoise) != 1)
        {
            printf("INVALID INPUT! Try Again.\n");
            return 1;
        }
        if (PlayerChoise < 0 || PlayerChoise > 2)
        {
            printf("INVALID INPUT! Try Again.\n");
            continue;
        }

        printf("\n%s chose: \n", name);

        switch (PlayerChoise)
        {
        case 0:
            printf("Rock\n");
            break;

        case 1:
            printf("Paper\n");
            break;

        case 2:
            printf("Scissor\n");
            break;
        }

        ComputerChoise = RandomNumberGenerator();

        printf("Computer Chose : \n");
        switch (ComputerChoise)
        {
        case 0:
            printf("Rock\n");
            break;

        case 1:
            printf("Paper\n");
            break;

        case 2:
            printf("Scissor\n");
            break;
        }

        if (PlayerChoise == ComputerChoise)
        {
            printf("Its a draw!!\n");
        }

        else if ((PlayerChoise == 0 && ComputerChoise == 2) || (PlayerChoise == 1 && ComputerChoise == 0) ||
                 (PlayerChoise == 2 && ComputerChoise == 1))
        {
            printf("%s wins this round!\n", name);
            PlayerScore++;
        }
        else
        {
            printf("Computer wins this round!\n");
            ComputerScore++;
        }
        i++;
    }
    printf("\n--------FINAl SCOREBOARD-------\n");
    printf("%s : %d\n", name, PlayerScore);
    printf("Computer : %d\n", ComputerScore);

    if (PlayerScore > ComputerScore)
    {
        printf("CONGRATULATIONS %s! You Won\n", name);
    }
    else if (ComputerScore > PlayerScore)
    {
        printf("Computer won the game");
    }
    else
    {
        printf("The game is draw!!");
    }
    return 0;
}