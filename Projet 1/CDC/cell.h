#pragma once


struct Cell
{
	const char* line = "+---";
	const char* space = "|   ";
};

void Display(Cell* cell, const char* line,const char* space);
