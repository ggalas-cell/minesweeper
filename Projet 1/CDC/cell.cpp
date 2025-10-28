#include  <iostream>
#include "cell.h"

void Display(Cell* cell)
{
    cell->line= "+---";
    std::cout << cell->line;
}
