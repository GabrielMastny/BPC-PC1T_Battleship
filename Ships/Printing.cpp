#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include "StringConsts.h"
#include "Printing.h"

void WriteCharacterInARow(char ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", ch);
    }
}

void PrintGrid(char grid[10][10], bool animation)
{
    for (int i = 0; i < 10; i++)
    {
        WriteCharacterInARow(' ', SPACING_BIG);
        if (i == 0)
        {
            printf("  ");

            for (int j = 0; j < 10; j++)
                printf("%d ", j);

            printf("\n");

            WriteCharacterInARow(' ', SPACING_BIG);
        }
        printf("%d ", i);
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", grid[i][j]);
            if (animation) delay(60);
        }

        printf("\n");

        if (animation) delay(60);
    }
}


#pragma region Welcome page

void PrintWelcomePage()
{
    WriteCharacterInARow('\n', SPACING_SMALL);

    WriteCharacterInARow(' ', SPACING_BIG);

    for each (char var in LECTURE_STR)
    {
        printf("%c", var);
        delay(60);
    }

    printf("\n");
    WriteCharacterInARow(' ', SPACING_BIG);

    for each (char var in GAME_NAME_STR)
    {
        printf("%c", var);
        delay(60);
    }

    printf("\n");

    WriteCharacterInARow(' ', SPACING_BIG);
}

#pragma endregion

#pragma region Options page

void PrintOptionOne_Play()
{
    printf("1.");
    printf(PLAY_STR);
    printf(" ");
    printf(GAME_NAME_STR);
    printf("\n");
}

void PrintOptionTwo_Rules()
{
    printf("2.");
    printf(RULES_STR);
    printf("\n");
}

void PrintOptionThree_Author()
{
    printf("3.");
    printf(ABOUT_STR);
    printf("\n");
}

void PrintOptionFour_Exit()
{
    printf("4.");
    printf(EXIT_STR);
    printf("\n");
}

void PrintOptionsPage()
{
    system("cls");

    WriteCharacterInARow('\n', SPACING_SMALL);

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintOptionOne_Play();

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintOptionTwo_Rules();

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintOptionThree_Author();

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintOptionFour_Exit();
}

#pragma endregion

#pragma region Rules page

void PrintRulesPage()
{
    system("cls");

    WriteCharacterInARow('\n', SPACING_SMALL/2);
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("1st rule: You do not talk about Fight Club.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("2nd rule: You do not talk about Fight Club.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("3rd rule: If someone yells \"Stop!\", goes limp, taps out, the fight is over.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("4th rule: Only two guys to a fight.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("5th rule: One fight at a time.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("6th rule: No shirts, no shoes.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("7th rule: Fights will go on as long as they have to.\n");
    WriteCharacterInARow(' ', SPACING_BIG / 2);
    printf("8th rule: If this is your first night at Fight Club, you have to fight.\n\n");
    WriteCharacterInARow(' ', SPACING_BIG);
    printf(PRESS_ANY_STR);
    getchar();

}

#pragma endregion


#pragma region About page

void PrintAboutPage()
{
    system("cls");
    WriteCharacterInARow('\n', SPACING_SMALL);
    WriteCharacterInARow(' ', SPACING_BIG);
    printf(LECTURE_STR);
    printf(" ");
    printf(GAME_NAME_STR);
    printf(" v.0.0.0.1");
    printf("\n");
    WriteCharacterInARow(' ', SPACING_BIG);
    printf("%c", (char)184);
    printf("xmastn02\n\n");
    WriteCharacterInARow(' ', SPACING_BIG);
    printf("Press ENTER to continue!");
    getchar();
}

#pragma endregion

#pragma region playerCount

void Print_1v1()
{
    printf("2.");
    printf(PLAYER1_STR);
    printf(" ");
    printf(VERSUS_STR);
    printf(" ");
    printf(PLAYER2_STR);
    printf("\n");
}

void Print_1vCPU()
{
    printf("1.");
    printf(PLAYER1_STR);
    printf(" ");
    printf(VERSUS_STR);
    printf(" ");
    printf(CPU_STR);
    printf("\n");
}

void PrintPlayerPage()
{
    system("cls");

    WriteCharacterInARow('\n', SPACING_SMALL);

    WriteCharacterInARow(' ', SPACING_BIG);

    Print_1vCPU();

    WriteCharacterInARow(' ', SPACING_BIG);

    Print_1v1();
}
#pragma endregion

#pragma region Difficulty page

void PrintAmateurDiff()
{
    printf("1.");
    printf(DIFF_AMATEUR_STR);
    printf("\n");
}

void PrintProDiff()
{
    printf("2.");
    printf(DIFF_PRO_STR);
    printf("\n");
}

void PrintLegendDiff()
{
    printf("3.");
    printf(DIFF_LEGEND_STR);
    printf("\n");
}

void PrintDifficultyPage()
{
    system("cls");

    WriteCharacterInARow('\n', SPACING_SMALL);

    WriteCharacterInARow(' ', SPACING_BIG);

    printf(SELECT_DIFF_STR);

    printf("\n");

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintAmateurDiff();

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintProDiff();

    WriteCharacterInARow(' ', SPACING_BIG);

    PrintLegendDiff();
}

#pragma endregion

void delay(clock_t a)
{
    clock_t start;
    start = clock();
    while (clock() - start < a)
    {

    }
}

void PrintInvalidCoord()
{
    printf(INVALID_CORDINATES_ORIENTATION_STR);
    printf("\n");
    printf(TRY_AGAIN_STR);
    printf("\n");
}

void PlayersTurnMessage(int points, const char* player)
{
    system("cls");
    WriteCharacterInARow('\n', SPACING_SMALL);
    WriteCharacterInARow(' ', SPACING_BIG);

    while(*player != '\0')
    {
        printf("%c", *player);
        delay(60);
        player++;
    }

    for each (char var in PLAYERS_TURN_STR)
    {
        printf("%c", var);
        delay(60);
    }

    printf("\n");
    WriteCharacterInARow(' ', SPACING_BIG);

    if (points > 0)
    {
        printf(POINTS_STR);
        printf("%d", points);
    }

    printf("\n");

    delay(240);
    WriteCharacterInARow(' ', SPACING_BIG);
    printf(PRESS_ANY_STR);
    getchar();
}

void WinMessage(const char* player)
{
    system("cls");
    WriteCharacterInARow('\n', SPACING_SMALL);
    WriteCharacterInARow(' ', SPACING_BIG);

    while (*player != '\0')
    {
        printf("%c", *player);
        delay(60);
        player++;
    }

    printf(" ");
    delay(60);

    for each (char var in Wins_STR)
    {
        printf("%c", var);
        delay(60);
    }

    delay(240);
    printf("\n\n");
    WriteCharacterInARow(' ', SPACING_BIG);
    printf(PRESS_ANY_STR);
    getchar();
}
