#pragma once


struct Cell
{
    char line;
	bool isMine;
	int isRevealed;
	int isFlag;
	int adjacentMineCount;
};

void Display(Cell* cell);
