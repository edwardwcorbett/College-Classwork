/************************************************************************************
//FILENAME:ewcproject_4.c
//NAME: Edward Corbett
//DATE: 10/05/14
//PURPOSE: Land Mines - User will move through a game board one coloumn at a time 
//selecting which row to choose depending on current location.  Each row will contain
//a land mine which ends the game if the user picks that spot.  
//***********************************************************************************/
#include <stdio.h> //include contents of standart input/output header
#include <stdlib.h> //include function prototypes for conversions of numbers to text,
#include <time.h>   //include time
#define ROW 4 //set value of 4 wherever there is "ROW"
#define COL 5 //set value of 5 wherever there is "COL"
int instructions(); //function to display instructions
char makeGame(char gameBoard[ROW][COL]); //function to make game board array
char makeMines(char mines[ROW][COL]); //function to make array to hold land mines
char fillArray(char mines[ROW][COL]);//function to fill land mines array with mines
char printGame(char gameBoard[ROW][COL]); //function to print game board array
char printMines(char fillMines[ROW][COL]);//functino to print land mine array
char userFirst(char gameBoard[ROW][COL], char mines [ROW][COL]); //function to determine user's first move
char userMoves(char gameBoard[ROW][COL], char mines[ROW][COL]); //function to determine user's moves 2-5
char convertArray(char gameboard[ROW][COL], char mines[ROW][COL]); //function to transfer location of mines to game board
int main(void) //main function
{    
    srand(time(NULL)); //declare random generator based on time
    char gameBoard[ROW][COL]; //declare game board array
    makeGame(gameBoard); //function to make game board array 
    char mines[ROW][COL]; //declare land mines array
    makeMines(mines); //function to make land mines array
    fillArray(mines); //function to fill land mines array with mines
    instructions(); //call instructions function to print instructions  
    system("PAUSE");
    userFirst(gameBoard, mines); //call to function to determine user's first move

    userMoves(gameBoard, mines); //call to function to determine and display user's moves 2-5
    system("CLS"); //clear screen
    convertArray(gameBoard, mines); //call to function to convert mines location from mines array to game board array
    printGame(gameBoard); //display gameboard with mines 
    puts("");
    printf("You win, you missed all the mines.");//user wins if they reach the end of the field
    puts("");
    puts("");
    system("\tPAUSE");
}
char makeGame(char gameBoard[ROW][COL]) //function to make array for game board
{      
     int i = 0; //row counter
     int j = 0; //column counter
     for(i = 0; i < ROW; i++)
     {             
        for(j = 0; j < COL; j++)  
        {            
            gameBoard[i][j] = ' ' ; //initialize each entry with blank space
        }
     } 
}
char makeMines(char mines[ROW][COL]) //function to make array for land mines array
{     
     int i = 0;
     int j = 0;
     for(i = 0; i < ROW; i++)
     {     
        for(j = 0; j < COL; j++)  
        {   
            mines[i][j] = ' ' ;    
        } 
     }  
}
char fillArray(char mines[ROW][COL]) //function to fill land mines array with mines (M)
{
     int i = 0;
     int j = 0;
     for(i = 0; i < ROW; i++) //each row has 1 mine
     {                     
        int xMark = rand() % 4 + 1;    //random number generator to choose which column M is placed     
        switch (xMark) //switch statement placing M in appropriate column
        {
            case 1:
                mines[i][1] = 'M';  
                break;
            case 2:
                mines[i][2] = 'M';
                break;
            case 3:
                mines[i][3] = 'M';
                break;
            case 4:
                mines[i][4] = 'M';
                break;
        }   
     }    
}      
char printGame(char gameBoard[ROW][COL]) //function to display gameboard array
{    
    int i = 0;
    int j = 0;
    for(i = 0; i < ROW; i++)
    {     
        puts("");
        printf(" ---------------------");    
        puts("");   
        for(j = 0; j < COL; j++)
        { 
            printf(" | ");
            printf("%c", gameBoard[i][j]);
        }
        printf(" |");
    }   puts("");
        printf(" ---------------------"); 
}
char printMines(char mines[ROW][COL]) //function to display mines array
{
    int i = 0;
    int j = 0;
    for(i = 0; i < ROW; i++)
    {  
        puts("");     
        printf(" ---------------------");    
        puts(""); 
        for(j = 0; j < COL; j++)
        { 
            printf(" | ");
            printf("%c", mines[i][j]);
        }
        printf(" |");
    }   puts("");
        printf(" ---------------------");
}
char userFirst(char gameBoard[ROW][COL], char mines[ROW][COL]) //function to begin game, user's first move
{
    int move;
    int spot;
    system("CLS");
    printGame(gameBoard); //display gameboard
    do 
    {
    printf("\n\nChoose which row you wish to start out at: 1, 2, 3, or 4. \n\n"); //user must choose valid row
    scanf("%d", &move);
    }while (move != 1 && move != 2 && move != 3 && move != 4);
      
    switch(move) //switch statement placing X in appropriate row based on user input
    {
        case 1:
                gameBoard[0][0] = 'X';
                break;
        case 2:                 
                gameBoard[1][0] = 'X';
                break;
        case 3:               
                gameBoard[2][0] = 'X';
                break;
        case 4:              
                gameBoard[3][0] = 'X';
                break;       
    }         
}  
char userMoves(char gameBoard[ROW][COL], char mines[ROW][COL]) //function to determine moves 2-5
{   
    int j;
    int row;
    int move;
    system("CLS");
    printGame(gameBoard);
    for(j = 0; j < COL -1; j++) //for loop for each turn on each column
    {
        if(gameBoard[0][j] == 'X') //if statements to determine current position of X
        {   
            row = 1;
        }
        if(gameBoard[1][j] == 'X')
        {   
            row = 2;
        }
        if(gameBoard[2][j] == 'X')
        {
            row = 3;
        }
        if(gameBoard[3][j] == 'X')
        {
            row = 4;
        }     
    int columnNext = j + 2; 
    int move1 = row - 1; //variables based on possible next moves depend on row
    int move2 = row;
    int move3 = row + 1;
    int h = j + 1;
    printf("\n\nYou are moving into column");
    printf(" %d", columnNext);
    do
    {
    if (move1 >= 1 && move3 <= 4) //if statements to accept only moves that are allowed by game
    {
        do
        {
        printf("\n\nYour choice of rows are: rows "); //user has 3 choices in rows 2 or 3
        printf(" %d,", move1);
        printf(" %d,", move2);
        printf(" or");
        printf(" %d\n\n", move3);
        scanf("%d", &move);
        }
        while (move != move1 && move != move2 && move != move3);
    }
    else if(move1 < 1)
    {   
        do
        { 
        printf("\n\nYour choice of rows are: rows "); //only allow user to move into row 1 or 2 from row 1
        printf(" %d or", move2);
        printf(" %d\n\n", move3);
        scanf("%d", &move);
        }
        while (move != move2 && move != move3);
    }
    else if (move3 > 4)
    {   
        do
        {
        printf("\n\nYour choice of rows are: rows "); //only allow user to move into row 3 or 4 from row 4
        printf(" %d", move1);
        printf(" or");
        printf(" %d\n\n", move2);   
        scanf("%d", &move);         
        }
        while (move != move1 && move != move2);
    }
    }
    while(move != 1 && move != 2 && move !=3 && move !=4);
    switch(move) //switch statement to either place X in row or check if the spot has a mine (M)
    {
        case 1:
            if(mines[0][h] != 'M') //checks array with mines to position input by user in gameboard
            {              
                gameBoard[0][h] = 'X'; // if array position in mines is empty, gameboard position is set with X
                break;
            }
            else if(mines[0][h] == 'M') // if position in mines array has a mine (M) game over 
            {
                system("CLS");
                convertArray(gameBoard, mines); //transfer mines position onto gameboard
                printGame(gameBoard);  //display new gameboard with mines 
                puts("");               
                printf("You lose, row 1 had a mine.");
                puts("");
                puts("");                
                system("PAUSE");
                exit("0");
                break;
            }
        case 2:
            if(mines[1][h] != 'M') //checks array with mines to position input by user in gameboard
            {              
                gameBoard[1][h] = 'X';  // if array position in mines is empty, gameboard position is set with X
                break;
            }
            else if(mines[1][h] == 'M') // if position in mines array has a mine (M) game over 
            {
                system("CLS");
                convertArray(gameBoard, mines); //transfer mines position onto gameboard
                printGame(gameBoard); //display new gameboard with mines
                puts("");                          
                printf("You lose, row 2 had a mine.");
                puts("");
                puts("");                
                system("PAUSE");
                exit("0");
                break;
            }
        case 3:
             if(mines[2][h] != 'M')//checks array with mines to position input by user in gameboard
            {              
                gameBoard[2][h] = 'X';  // if array position in mines is empty, gameboard position is set with X
            }
            else if(mines[2][h] == 'M')// if position in mines array has a mine (M) game over 
            {
                system("CLS");
                convertArray(gameBoard, mines); //transfer mines position onto gameboard
                printGame(gameBoard); //display new gameboard with mines
                puts("");             
                printf("You lose, row 3 had a mine.");
                puts("");
                puts("");                
                system("PAUSE");
                exit("0");
                break;
            }
            break;
        case 4:
            if(mines[3][h] != 'M') //checks array with mines to position input by user in gameboard
            {              
                gameBoard[3][h] = 'X';  // if array position in mines is empty, gameboard position is set with X
                break;
            }
            else if(mines[3][h] == 'M') // if position in mines array has a mine (M) game over 
            {
                system("CLS");
                convertArray(gameBoard, mines); //transfer mines position onto gameboard
                printGame(gameBoard); //display new gameboard with mines
                puts("");
                printf("You lose, row 4 had a mine.");
                puts("");
                puts("");                
                system("PAUSE");
                exit("0");
                break;
            }  
    }
    system("CLS");
    printGame(gameBoard); //display gameboard if user has not hit any mines in turn
    }
}
char convertArray(char gameBoard[ROW][COL], char mines[ROW][COL]) //function transfer position of mines in mines array to gameboard 
{
    int i;
    int j;
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            if ( mines[i][j] == 'M') //if statment to check if position has a mine
            {
                gameBoard[i][j] = 'M'; //if there is a mine, match position on gameboard
            }
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
