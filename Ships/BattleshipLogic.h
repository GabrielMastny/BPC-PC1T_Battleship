#pragma once

const int AIRCRAFT_LENGHT = 5;
const int BATTLESHIP_LENGHT = 4;
const int CORVETTE_LENGHT = 2;
const int DESTROYER_LENGHT = 3;

void InitGrids(char gridP1[10][10], char gridP2[10][10], char gridP1Blind[10][10], char gridP2Blind[10][10], char gridP1Play[10][10], char gridP2Play[10][10]);

void PlaceShips(char grid[10][10], int AShipPos[AIRCRAFT_LENGHT][2], int BShipPos[BATTLESHIP_LENGHT][2], int CShipPos[CORVETTE_LENGHT][2], int DShipPos[DESTROYER_LENGHT][2]);

void PlaceCPUShips(char grid[10][10], int AShipPos[AIRCRAFT_LENGHT][2], int BShipPos[BATTLESHIP_LENGHT][2], int CShipPos[CORVETTE_LENGHT][2], int DShipPos[DESTROYER_LENGHT][2]);

bool PlayerTurn(char gridBase[10][10], char ownPlayGrid[10][10], char blindGridOfOponent[10][10], char oponentsPlayGrid[10][10], int* pointsP1);

bool CPUTurn(int* probab, int posa[AIRCRAFT_LENGHT][2], int posb[BATTLESHIP_LENGHT][2], int posc[CORVETTE_LENGHT][2], int posd[DESTROYER_LENGHT][2], int diff, char oponentsGridPlay[10][10], char oponentsGridBase[10][10], char oponetsGridBlind[10][10], int* points);
