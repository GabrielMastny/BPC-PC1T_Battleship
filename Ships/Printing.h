#include <time.h>


const int SPACING_SMALL = 10;
const int SPACING_BIG = 30;

void delay(clock_t a);

void WriteCharacterInARow(char ch, int count);
void PrintWelcomePage();
void PrintOptionsPage();
void PrintAboutPage();
void PrintPlayerPage();
void PrintDifficultyPage();
void PrintGrid(char grid[10][10], bool animation);
void PrintInvalidCoord();
void PlayersTurnMessage(int points, const char* player);
void WinMessage(const char* player);
void PrintRulesPage();

