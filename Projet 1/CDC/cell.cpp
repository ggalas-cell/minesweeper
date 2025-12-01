#include  <iostream>
#include "cell.h"

void DisplayCell(Cell* cell)
{
    cell->line= '+---';
    std::cout << cell->line;
}
