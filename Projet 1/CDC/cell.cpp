#include  <iostream>
#include "cell.h"

void Display(Cell* cell) 
{
    std::cout<< cell->line;
    std::cout<<'+'<<std::endl;
    std::cout<<cell->space;
    std::cout<<'|'<<std::endl;
    std::cout<< cell->line;s
    std::cout<<'+'<<std::endl;
    
}



