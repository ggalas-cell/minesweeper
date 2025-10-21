#include <iostream>
#include "grid.h"

void Initialyse(Grid* grid,int line, int column);
{
	grid-> line= lines;
	grid-> column= columns;
	grid-> cells=(cells**)malloc(sizeof(int*)*lines)
	
	for(int i=0,i<lines,i++)
	{
	    grid->cells[i] = (cell*)malloc(sizeof(cell)*columns)
	}
}
void Display(Grid* grid)
{
    for (int i=0,i<lines,i++)           // 9*9 easy 16*16 medium 30×16 hard et perso 
    {
        for (int j=0,j<columns,j++)
        {
            std::cout<<grid->cells[i][j].line;
        }
        std::cout<<'+'std::endl;
        std::cout<<lines;
        for(int j=0,j<columns,j++)
        {
            std::cout<<grid->cells[i][j].space
        }
        std::cout<<'|'std::endl; 
    }
    for(int i=0,i<columns,i++)
    {
        std::cout<<grid->cells[i][j].line;
        
    }
    
    
}


//void freegrid(Grid* grid)
//Cell l;
//Display(&l, l.line, l.space);