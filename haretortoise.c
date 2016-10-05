/************************************************************************************
//FILENAME:ewcproject_6.c
//NAME: Edward Corbett
//DATE: 10/05/14
//PURPOSE: The race - a randomized race between a tortoise (T) and hare (H)
//both tortoise and hare will move based on a random number generated each turn 
//the game is over when either the tortoise or hare reaches the end
//***********************************************************************************/
#include <stdio.h> //include contents of standart input/output header
#include <stdlib.h> //include function prototypes for conversions of numbers to text,
#include <time.h>   //include time
#include <windows.h>
#define COL 71 //set value of 71 wherever there is "COL"
int instructions(); //function to display instructions
char makeGame(char gameBoard[COL]); //function to make game board array
char printGame(char gameBoard[COL]); //function to print game board array
char printGame2(char gameBoard[COL]);
char biteCheck(char gameBoard1[COL], char gameBoard2[COL]); //function to transfer location of mines to game board
char tortoiseMove(char tortoiseBoard[COL]);
char hareMove(char hareBoard[COL]);


int main(void) //main function
{    
    srand(time(NULL)); //declare random generator based on time
    char tortoiseBoard[COL]; //declare game board array
    makeGame(tortoiseBoard); //function to make game board array 
    char hareBoard[COL]; //declare land mines array
    makeGame(hareBoard); //function to make land mines array
    tortoiseBoard[1]= 'T';
    hareBoard[1]= 'H';
    printGame(tortoiseBoard); //display gameboard with mines
    printGame2(hareBoard);     
    printf("\nTortoise VS Hare");
    puts("");
    system("\nPAUSE");
        
    while(tortoiseBoard[70] != 'T' && hareBoard[70] != 'H')
    {
           system("CLS");        
           printGame(tortoiseBoard); //display gameboard with mines
           printGame2(hareBoard); 
           tortoiseMove(tortoiseBoard);
           hareMove(hareBoard);
           biteCheck(tortoiseBoard, hareBoard);
           Sleep(210);
           system("CLS");
    }    
    
    printGame(tortoiseBoard); //display gameboard with mines
    printGame(hareBoard); 
    if(tortoiseBoard[70] == 'T' && hareBoard[70] == 'H')
    {
        system("CLS");        
        printGame(tortoiseBoard); //display gameboard with mines
        printGame2(hareBoard); 
        printf("\nIt's a TIE!");
    }
    
    else if (tortoiseBoard[70] == 'T')
    {
        system("CLS");        
        printGame(tortoiseBoard); //display gameboard with mines
        printGame2(hareBoard);        
        printf("\nThe TORTOISE wins!");
    }
    
    else if (hareBoard[70] == 'H')
    {
        system("CLS");        
        printGame(tortoiseBoard); //display gameboard with mines
        printGame2(hareBoard);     
        printf("\nThe HARE wins!");
    }
    system("PAUSE");
}

char makeGame(char raceBoard[COL]) //function to make array for game board
{      
     int i = 0; //column counter
     for(i = 0; i < COL; i++)
     {                      
            raceBoard[i]= ' ' ; //initialize each entry with blank space
     } 
}
char tortoiseMove(char tortoiseBoard[COL]) //function to fill land mines array with mines (M)
{
     int positionT;
     int i;
     int moveT = rand() % 9 + 1;    //random number generator to choose which column 'T' is placed 
     for(i = 0; i < COL; i++) //for loop for each turn on each column     
     {
           if (tortoiseBoard[i] == 'T')
           {
                positionT = i;
           }
     }
     if (moveT >= 1 && moveT <= 5)
     {  
        i = positionT + 3;
     }
     else if (moveT >= 6 && moveT <= 8)
     {  
        i = positionT + 1;
     }
     else if (moveT == 9 || moveT == 10)
     {  
        i = positionT - 6;
     } 
     if (i < 0)
     {
            i = 0;
     }
     if (i > 70)
     {
            i = 70;
     }
     makeGame(tortoiseBoard); //function to make game board array 
     tortoiseBoard[i] = 'T';       
}       
char hareMove(char hareBoard[COL]) //function to fill land mines array with mines (M)
{
     int positionH;
     int i;
     int moveH = rand() % 9 + 1;    //random number generator to choose which column 'T' is placed 
     for(i = 1; i < COL; i++) //for loop for each turn on each column     
     {
           if (hareBoard[i] == 'H')
           {
                positionH = i;
           }
     }
     if (moveH >= 1 && moveH <= 2)
     {  
        i = positionH;
     }
     if (moveH >= 3 && moveH <= 4)
     {  
        i = positionH + 9;
     }
     if (moveH >= 5 && moveH <= 7)
     {  
        i = positionH + 1;
     } 
     if (moveH == 8)
     {  
        i = positionH - 12;
     }
     if (moveH == 9 || moveH == 10)
     {
            i = positionH - 2;
     }
     if (i < 0)
     {
            i = 0;
     }
     if (i > 70)
     {
            i = 70;
     }
     makeGame(hareBoard); //function to make game board array 
     hareBoard[i] = 'H';       
}      
char printGame(char gameBoard[COL]) //function to display gameboard array
{    
    int i = 0;
    int j = 0;
    for(i = 0; i < 1; i++)
    {     
        puts("");
        printf("-----------------------------------------------------------------------");    
        puts("");   
        for(j = 0; j < COL; j++)
        { 
            printf("%c", gameBoard[j]);
        }
    }   puts("");
        printf("-----------------------------------------------------------------------"); 
}
char printGame2(char gameBoard[COL]) //function to display gameboard array
{    
    int i = 0;
    int j = 0;
    for(i = 0; i < 1; i++)
    {     

        puts("");   
        for(j = 0; j < COL; j++)
        { 
            printf("%c", gameBoard[j]);
        }
    }   puts("");
        printf("-----------------------------------------------------------------------"); 
}
char biteCheck(char gameBoard1[COL], char gameBoard2[COL]) //function transfer position of mines in mines array to gameboard 
{
    int j;
       
        for(j = 0; j < COL; j++)
        {
            if ( gameBoard1[j] == 'T' && gameBoard2[j] == 'H') //if statment to check if position has a mine
            {
                system("CLS");
                printGame(gameBoard1); //display gameboard with mines
                printGame2(gameBoard2); 
                printf("\nOUCH"); //if there is a mine, match position on gameboard
                puts("");
                system("PAUSE");
            }
        }
}    
int instructions() //instructions function
{
    printf("Welcome to Land Mines.\n");
    printf("The goal of this game is to safely cross a minefield.\n");
    printf("The field has four rows and five columns.\n");
    printf("There are four mines hidden in the field.\n");
    printf("You start by choosing any of the first four cells.\n");
    printf("In every turn, you move to the next column on the right.\n");
    printf("You must choose a cell that touches yours, either a side or\n");
    printf("corner <you can move horizontal or diagonal>.\n");
    printf("There are no land mines in the first column, and there is\n");
    printf("always at least one safe route across.\n");
    printf("After each turn, your progress will be displayed.\n");
    printf("The game ends when you either reach the other side or step\n");
    printf("on a mine.  The mines will be displayed after the game ends.\n");
} 
