#include <stdlib.h> 
#include <iostream>
#include "grid.h"
#include <ctime>

void Initialise(Grid* grid)
{
    // 9*9 easy 16*16 medium 30×16 hard et perso 
    std::cout << "Choissez le niveau de difficulte ((1)Easy/(2)Medium/(3)Hard/(4)Custom) :";
    std::cin >> grid->difficulty;
    switch (grid->difficulty) //difficulty
    {
    case(1):        //easy 9*9
        grid->lines = 9;
        grid->columns = 9;
        grid->totalmines = 10;
        break;      // medium 16*16
    case(2):
        grid->lines = 16;
        grid->columns = 16;
        grid->totalmines = 40;
        break;
    case(3):        //hard 30*16
        grid->lines = 30;
        grid->columns = 16;
        grid->totalmines = 99;
        break;
    case(4):        //Custom
        std::cout << "Longeur ?";
        std::cin >> grid->lines;
        std::cout << "Largeur ?";
        std::cin >> grid->columns;
        std::cout << "Nombre de mines ?";
        std::cin>> grid->totalmines;
        break;
    default:        //medium par défaut
    std::cout<<"Difficulté invalide, mode medium selectionnee."<<std::endl;
    grid->lines = 16;
    grid->columns = 16;
    grid->totalmines = 40;
    }
    grid->cells = (Cell**)malloc(sizeof(Cell*) * grid->lines);  //alloué tableau 2D
    if (grid->cells == nullptr)
        exit(1);

    for(int i=0;i<grid->lines;i++)
    {
        grid->cells[i]=(Cell*)malloc(sizeof(Cell)*grid->columns);
        if(grid->cells[i] == nullptr)
        {
            exit(1);
        }
        for(int j=0;j<grid->columns;j++)        //Initialisé chaque cellule
        {
            grid->cells[i][j].isMine = 0;
            grid->cells[i][j].isRevealed = 0;
            grid->cells[i][j].isFlag = 0;
            grid->cells[i][j].adjacentMineCount = 0;
        }
    }

    grid->userEntryRow = 0;     // guess du joueur (par rangé)
    grid->userEntryCol = 0;     //guess du joueur (par collone)
}

void Display(Grid* grid)
{
    system("cls");
    std::cout << "   ";
    for (int i = 0; i < grid->columns; i++)     //affiche nombre pour chque colonne
    {
        if (i<10)
        {
            std::cout << "  " << i << " ";
        }
        if (i >= 10)
        {
            std::cout << " " << i << " ";
        }
    }
    std::cout << "" << std::endl;
    for (int i = 0; i < grid->lines;i++)           //affiche grille
    {
         std::cout << "   ";
        for (int j = 0; j < grid->columns; j++)
        {
            std::cout << "+---";
        }
        std::cout << "+"<<std::endl;
        if (i < 10)
        {
            std::cout << i << "  ";
        }
        else
        {
            std::cout << i << " ";
        }
        for (int j = 0; j < grid->columns; j++)  
        {
            
            if(grid->cells[i][j].isFlag == 1)
            {
                std::cout<<"| F ";
            }
            else if(grid->cells[i][j].isRevealed == 1)  
            {
                std::cout<<"| * ";
            }
            else if(grid->cells[i][j].isMine == 1)       //pour debug
            {
                std::cout<<"| : ";
            }
            else
            {
                std::cout<<"|   ";
            }
        }
        std::cout << "|  "<<std::endl;

    }
    
    std::cout << "   ";
    for (int i = 0; i < grid->columns; i++)     //dernière ligne du tableaux
    {
        std::cout <<"+---";
    }
    std::cout << "+" << std::endl;
}

void CalculateMines(Grid* grid)     // intégration des mines dans le tableaux 2D
{
    srand(time(0));
    grid->minesplaced = 0;
    while (grid->minesplaced < grid->totalmines)
    {
        int randomline = rand() % grid->lines;
        int randomcell = rand() % grid->columns;

        if (grid->cells[randomline][randomcell].isMine == false)
        {
            grid->cells[randomline][randomcell].isMine = true;
            grid->minesplaced++;
        }

    }
    std::cout << "Mines :" << grid->minesplaced << std::endl;           // pour debug et verifier si le totale des mines sont bien posé  
    std::cout << "Mines total :" << grid->totalmines << std::endl;      //totale de mines
}

void Freegrid(Grid* grid)       // désallouement
{
    for (int i = 0;i < grid->lines; i++)
    {
        free(grid->cells[i]);
    }
    free(grid->cells);
}
// void isAdjacentMine(Grid* grid)      //
// {
//     for(int i=0;<grid->lines;i++)
//     {
//         for(int j=0;j<grid->columns;j++)
//         {
            
//         }
//     }
// }

void playgame(Grid* grid)       //gameplay
{
    std::cout << "Pour jouez ecrivez les coordonnees de la case a deminee." << std::endl;
    std::cout << "Quelle case voulez vous deminer ?" << std::endl;
    do
    {
        std::cout<<"Commande (d: deminer, f: drapeau)";         //Commande
        std::cin>>grid->userEntryGame;
        if(grid->userEntryGame=='d')      //deminer
        {
            std::cout << "ligne-> ";
            std::cin >> grid->userEntryRow;
            std::cout << "Colonne-> ";
            std::cin >> grid->userEntryCol;
            if(grid->cells[grid->userEntryRow][grid->userEntryCol].isFlag==1)
            {
                std::cout<<"Case marque veuillez enlever le drapeau d'abord !"<<std::endl;
            }
        }
        else if(grid-> userEntryGame=='f')     //flag
        {
            std::cout << "ligne-> ";
            std::cin >> grid->userEntryRow;
            std::cout << "Colonne-> ";
            std::cin >> grid->userEntryCol;
            if(grid->cells[grid->userEntryRow][grid->userEntryCol].isFlag==1)
            {
                grid->cells[grid->userEntryRow][grid->userEntryCol].isFlag=0;
            }
            grid->cells[grid->userEntryRow][grid->userEntryCol].isFlag=1;
        }
        else        //erreur
        {
            std::cout<<"Commande invalide !"<<std::endl;
        }
        
        for(int i=0;i<grid->lines;i++)                          // win temporaire
        {
            for(int j=0;j<grid->columns;j++)    
            {    
                if(grid->cells[grid->userEntryRow][grid->userEntryCol].isMine== grid->cells[grid->userEntryRow][grid->userEntryCol].isFlag)
                {
                    std::cout<<"Vous avez gagnez !!!"<<std::endl;    
            }   }
        }
        if (grid->cells[grid->userEntryRow][grid->userEntryCol].isMine == true)     //game over
        {
            grid->cells[grid->userEntryRow][grid->userEntryCol].isRevealed = 1;
            std::cout << "\n\n///   GAME OVER   ///" << std::endl;
            for(int i=0;i<grid->lines;i++)
            {
                for(int j=0;j<grid->columns;j++)
                {
                    if(grid->cells[i][j].isMine==1)
                    {
                        grid->cells[i][j].isRevealed = 1;
                    }
                }
            }
            Display(grid);
            PlayAgain(grid);
        }    
    } while (grid->cells[grid->userEntryRow][grid->userEntryCol].isRevealed != 1);
}

void PlayAgain(Grid* grid)
{
    char input;
    std::cout << "Voulez vous rejouer ?( Y / N )";
    std::cin >> input;
    switch (input)
    {
    case 'y':
        playgame(grid);
        break;
    case 'n':
        exit(1);
        break;
    default:
        std::cout << "Erreur caractère non valid...\n";
        std::cout << "Veuillez saisir un autre caractère.";
        switch (input);
    }
}
