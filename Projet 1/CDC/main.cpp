#pragma once
#include <iostream>
#include "grid.h"


int main()
{
	Grid g;
	Initialise(&g);
	CalculateMines(&g);
	Display(&g);
	playgame(&g);
	Freegrid(&g);
	return 0;
}

//struc inclusion:
//main.cpp-> grid.h->cell.h
//grid.cpp->grid.h->cell.h
//cell.cpp->cell.h
