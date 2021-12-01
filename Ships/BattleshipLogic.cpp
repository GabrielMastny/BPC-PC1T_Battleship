#include "BattleshipLogic.h"
#include "StringConsts.h"
#include <stdio.h>
#include <stdlib.h>
#include "Printing.h"



void InitGrids(char gridP1[10][10], char gridP2[10][10],char gridP1Blind[10][10], char gridP2Blind[10][10], char gridP1Play[10][10], char gridP2Play[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gridP2[i][j] = '.';
            gridP1[i][j] = '.';
            gridP1Blind[i][j] = '.';
            gridP2Blind[i][j] = '.';
            gridP1Play[i][j] = '.';
            gridP2Play[i][j] = '.';
        }
    }
}

bool GetOrientationAndCoordinatesForPlacement(int* x, int* y, bool* horizontal)
{
    char orin = ' ';

    printf(ORIENTATION_STR);

    scanf(" %c", &orin);
    getchar();

    if (orin == 'h') *horizontal = true;
    else if (orin == 'v') *horizontal = false;
    else
    {
        *x = -1;
        *y = -1;
        *horizontal = false;
        return false;
    }

    printf(COORDINATES_STR);

    scanf("%d %d", x, y);
    getchar();

    return ((*x >= 0 && *x < 10) && (*y >= 0 && *y < 10));
}

bool PositionCheck(int shipLength, int x, int y, bool horizontal)
{
    return horizontal ? !((y > 10 - shipLength) || y < 0 || x>9 || x < 0) :
        !((x > 10 - shipLength) || x < 0 || y>9 || y < 0);
}

void PlaceShipInsideGrid(char playerGrid[10][10], int shipPositionGrid[][2], char shipLetter, int shipLength, bool horizontal, int x, int y)
{
    int a = 0;
    if (horizontal)
    {

        for (int i = y; i < y + shipLength; i++)
        {
            playerGrid[x][i] = shipLetter;
            shipPositionGrid[a][0] = x;
            shipPositionGrid[a][1] = i;
            a++;
        }
    }
    else
    {
        for (int i = x; i < x + shipLength; i++)
        {
            playerGrid[i][y] = shipLetter;
            shipPositionGrid[a][0] = i;
            shipPositionGrid[a][1] = y;
            a++;
        }
    }
}

bool ColisionCheck(char grid[10][10], int x, int y, bool horizontal, int shipLength)
{
    if (horizontal)
    {
        for (int i = y; i < y + shipLength; i++)
        {
            if (grid[x][i] != '.')
            {
                return false;
            }
        }
    }
    else
    {
        for (int i = x; i < x + shipLength; i++)
        {
            if (grid[i][y] != '.')
            {
                return false;
            }
        }
    }
    return true;
}

void PlaceShip(char grid[10][10], int shipPos[][2], const char* shipsName, char shipLetter, int shipLength)
{
    system("cls");

    PrintGrid(grid, false);

    while (true)
    {
        printf(shipsName);

        printf("\n");

        bool horizontal;
        int x, y;
        if (GetOrientationAndCoordinatesForPlacement(&x, &y, &horizontal))
        {
            if (PositionCheck(AIRCRAFT_LENGHT, x, y, horizontal) &&
                ColisionCheck(grid, x, y, horizontal, shipLength))
            {
                PlaceShipInsideGrid(grid, shipPos, shipLetter, shipLength, horizontal, x, y);
                break;
            }
            else
            {
                printf("Can't place here. TRY AGAIN!\n");
                continue;
            }
        }
        else
        {
            PrintInvalidCoord();

            delay(60);
            continue;
        }


    }


}

bool ObtainCoordForShoot(char grid[10][10], int* x, int* y)
{
    printf(COORDINATES_STR);
    scanf("%d %d", x, y);
    getchar();

    char a = grid[*x][*y];

    if (*x > 9 || *x < 0 || *y>9 || y < 0 || grid[*x][*y] == 'H' || grid[*x][*y] == '*')
    {
        printf(INVALID_CORDINATES_ORIENTATION_STR);
        printf("\n");
        printf(TRY_AGAIN_STR);

        return false;
    }

    return true;
}

void PlaceShips(char grid[10][10], int AShipPos[AIRCRAFT_LENGHT][2], int BShipPos[BATTLESHIP_LENGHT][2], int CShipPos[CORVETTE_LENGHT][2], int DShipPos[DESTROYER_LENGHT][2])
{
    PlaceShip(grid, AShipPos, ASHIP_STR, 'A', AIRCRAFT_LENGHT);
    PlaceShip(grid, BShipPos, BSHIP_STR, 'B', BATTLESHIP_LENGHT);
    PlaceShip(grid, DShipPos, DSHIP_STR, 'D', DESTROYER_LENGHT);
    PlaceShip(grid, CShipPos, CSHIP_STR, 'C', CORVETTE_LENGHT);

    system("cls");

    PrintGrid(grid, true);
}

void PlaceCPUShip(char grid[10][10], int shipPos[][2], const char shipsName[20], char shipLetter, int shipLength)
{
    while (true)
    {
        bool horizontal = rand() % 2;
        int x = rand() % 10;
        int y = rand() % 10;

        if (PositionCheck(shipLength, x, y, horizontal) &&
            ColisionCheck(grid, x, y, horizontal, shipLength))
        {
            PlaceShipInsideGrid(grid, shipPos, shipLetter, shipLength, horizontal, x, y);
            break;
        }
        else continue;
    }
}

void PlaceCPUShips(char grid[10][10], int AShipPos[AIRCRAFT_LENGHT][2], int BShipPos[BATTLESHIP_LENGHT][2], int CShipPos[CORVETTE_LENGHT][2], int DShipPos[DESTROYER_LENGHT][2])
{
    PlaceCPUShip(grid, AShipPos, ASHIP_STR, 'A', AIRCRAFT_LENGHT);
    PlaceCPUShip(grid, BShipPos, BSHIP_STR, 'B', BATTLESHIP_LENGHT);
    PlaceCPUShip(grid, DShipPos, DSHIP_STR, 'D', DESTROYER_LENGHT);
    PlaceCPUShip(grid, CShipPos, CSHIP_STR, 'C', CORVETTE_LENGHT);
}

bool PlayerTurn(char gridBase[10][10], char ownPlayGrid[10][10], char blindGridOfOponent[10][10], char oponentsPlayGrid[10][10], int* pointsP1)
{
    system("cls");

    PrintGrid(blindGridOfOponent, false);

    printf("\n");

    PrintGrid(ownPlayGrid, false);

    int x, y;
    if (!ObtainCoordForShoot(blindGridOfOponent, &x, &y)) return false;

    if (gridBase[x][y] == 'A' || gridBase[x][y] == 'B' || gridBase[x][y] == 'C' || gridBase[x][y] == 'D')
    {
        blindGridOfOponent[x][y] = 'H';
        oponentsPlayGrid[x][y] = 'H';
        (*pointsP1)++;

        system("cls");

        PrintGrid(blindGridOfOponent, false);

        printf("\n");

        PrintGrid(ownPlayGrid, false);
    }
    else
    {
        blindGridOfOponent[x][y] = '*';
        oponentsPlayGrid[x][y] = '*';
    }

    return true;
}

bool CPUTurn(int* probab, int posa[AIRCRAFT_LENGHT][2], int posb[BATTLESHIP_LENGHT][2], int posc[CORVETTE_LENGHT][2], int posd[DESTROYER_LENGHT][2], int diff, char oponentsGridPlay[10][10], char oponentsGridBase[10][10], char oponetsGridBlind[10][10], int* points)
{
    int x, y, a = 0, b = 0, c = 0, d = 0;

    *probab = rand() % diff;
    if (*probab == diff - 3 && a < 5)
    {
        x = posa[a][0];
        y = posa[a][1];
        a++;
    }
    else if (*probab == diff - 2 && b < 4)
    {
        x = posb[b][0];
        y = posb[b][1];
        b++;
    }
    else if (*probab == diff - 5 && d < 3)
    {
        x = posd[d][0];
        y = posd[d][1];
        d++;
    }
    else if (*probab == diff - 6 && c < 2)
    {
        x = posc[c][0];
        y = posc[c][1];
        c++;
    }
    else
    {
        x = rand() % 10;
        y = rand() % 10;
    }


    if (x > 9 || x < 0 || y>9 || y < 0 || oponentsGridPlay[x][y] == 'H' || oponentsGridPlay[x][y] == '*')
    {
        return false;
    }
    else
    {
        if (oponentsGridBase[x][y] == 'A' || oponentsGridBase[x][y] == 'B' || oponentsGridBase[x][y] == 'C' || oponentsGridBase[x][y] == 'D')
        {
            if (oponentsGridPlay[x][y] != 'H')
            {
                oponentsGridPlay[x][y] = 'H';

                (*points)++;

                system("cls");

                PrintGrid(oponetsGridBlind, false);

                printf("\n");

                PrintGrid(oponentsGridPlay, false);
            }
        }
        else
        {
            oponentsGridPlay[x][y] = '*';
        }
    }

    return true;
}