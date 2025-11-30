#pragma once
#include "cell.h"
struct Grid
{
	int columns;
	int difficulty;
	int lines;
	int totalmines;
	int minesplaced;
	int randomline;
	int randomcell;
	char userEntryGame;
	int userEntryRow;
	int userEntryCol;
	int demine;
	Cell** cells;
};

void Initialise(Grid* grid);
void Display(Grid* grid);
void Freegrid(Grid* grid);
void CalculateMines(Grid*grid);
void playgame(Grid*grid);
void PlayAgain(Grid* grid);
