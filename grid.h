
#pragma once
#include "cell.h"
struct Grid
{
	int column;
	int line;
	Cell** cells;
};

void Initialyse(Grid* grid,int column, int line);
void Display(Grid* grid);
void freegrid(Grid* grid)


    