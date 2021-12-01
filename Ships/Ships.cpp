
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>

#include "StringConsts.h"
#include "Printing.h"
#include "BattleshipLogic.h"



enum pages
{
    welcome,
    options,
    players,
    difficulty

};

enum OptionPageOptions
{
    play = 49,
    rules = 50,
    author = 51,
    appExit = 52,
    playerCount

};

enum Difficulty
{
    amateur = 49,
    profi = 50,
    legend = 51
};

enum PlayerCount
{
    p1vscpu = 49,
    p1vsp2 = 50
};

int main()
{
    pages page = welcome;
    Difficulty diffOption = amateur;
    int pointsP1 = 0, pointsP2 = 0;
    int p1posa[AIRCRAFT_LENGHT][2], p1posb[BATTLESHIP_LENGHT][2], p1posd[DESTROYER_LENGHT][2], p1posc[CORVETTE_LENGHT][2];
    int p2posa[AIRCRAFT_LENGHT][2], p2posb[BATTLESHIP_LENGHT][2], p2posd[DESTROYER_LENGHT][2], p2posc[CORVETTE_LENGHT][2];
    int probab, diff = -1;
    char gridP1[10][10], gridP1Play[10][10], gridP1Blind[10][10], gridP2[10][10], gridP2Play[10][10], gridP2Blind[10][10], orin[2], tempstr[10], ch;

    PrintWelcomePage();

    delay(1500);
    system("cls");

    page = options;

    while (true) // options loop
    {
        PrintOptionsPage();

        OptionPageOptions ch = (OptionPageOptions)getch();

        if (ch == play)
        {
            page = players;

            while (true) // player 
            {
                if (page != players) break;

                PrintPlayerPage();

                PlayerCount players = (PlayerCount)getch();

                if (players == p1vscpu)
                {
                    pointsP1 = 0;

                    while (true)
                    {

                        PrintDifficultyPage();

                        diffOption = (Difficulty)getch();

                        switch (diffOption)
                        {
                            case amateur: diff = 9;
                                break;
                            case profi: diff = 8;
                                break;
                            case legend: diff = 6;
                                break;
                            default: continue;
                        }
                        break;
                    }

                    InitGrids(gridP1, gridP2, gridP1Blind, gridP2Blind, gridP1Play, gridP2Play);

                    PlaceShips(gridP1, p1posa, p1posb, p1posc, p1posd);

                    system("cls");

                    srand(time(NULL));

                    PlaceCPUShips(gridP2, p2posa, p2posb, p2posc, p2posd);

                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 10; j++)
                            gridP1Play[i][j] = gridP1[i][j];
                    }

                    while (true)
                    {
                        while (!PlayerTurn(gridP2, gridP1Play, gridP1Blind, gridP2Play, &pointsP1));

                        if (pointsP1 == 14)
                        {
                            system("cls");
                            WriteCharacterInARow('\n', SPACING_SMALL);
                            WriteCharacterInARow(' ', SPACING_BIG);

                            for each (char var in CPU_WIN_STR)
                            {
                                printf("%c", var);
                                delay(60);
                            }

                            delay(240);
                            printf("\n");
                            printf(PRESS_ANY_STR);
                            getchar();

                            page = options;

                            break;
                        }

                        while (!CPUTurn(&probab, p2posa, p2posb, p2posc, p2posd, diff, gridP1Play, gridP1, gridP1Blind, &pointsP2));

                        if (pointsP2 == 14)
                        {
                            system("cls");
                            WriteCharacterInARow('\n', SPACING_SMALL);
                            WriteCharacterInARow(' ', SPACING_BIG);

                            for each (char var in CPU_LOST_STR)
                            {
                                printf("%c", var);
                                delay(60);
                            }

                            delay(240);
                            printf("\n");
                            printf(PRESS_ANY_STR);
                            getchar();

                            page = options;

                            break;
                        }
                    }
                }
                else if (players == p1vsp2)
                {
                    pointsP1 = 0;

                    pointsP1 = 0;

                    InitGrids(gridP1, gridP2, gridP1Blind, gridP2Blind, gridP1Play, gridP2Play);

                    PlayersTurnMessage(pointsP1, PLAYER1_STR);

                    PlaceShips(gridP1, p1posa, p1posb, p1posc, p1posd);

                    PlayersTurnMessage(pointsP1, PLAYER2_STR);

                    PlaceShips(gridP2, p2posa, p2posb, p2posc, p2posd);

                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 10; j++)
                        {
                            gridP1Play[i][j] = gridP1[i][j];
                            gridP2Play[i][j] = gridP2[i][j];
                        }


                    }

                    

                    while (true)
                    {
                        PlayersTurnMessage(pointsP1, PLAYER1_STR);

                        while (!PlayerTurn(gridP2, gridP1Play, gridP1Blind, gridP2Play, &pointsP1));

                        if (pointsP1 == 14)
                        {
                            WinMessage(PLAYER1_STR);

                            page = options;

                            break;
                        }

                        PlayersTurnMessage(pointsP2, PLAYER2_STR);

                        while (!PlayerTurn(gridP1, gridP2Play, gridP2Blind, gridP1Play, &pointsP2));

                        if (pointsP2 == 14)
                        {
                            WinMessage(PLAYER2_STR);

                            page = options;

                            break;
                        }
                    }

                    
                    
                }
            }
        }
        else if (ch == rules)
        {
        PrintRulesPage();
            continue;
        }
        else if (ch == author)
        {
            PrintAboutPage();
        }
        else if (ch == appExit) break;
    }
    
    
    return 0;
}
