/************************************************************************************
//FILENAME:ewcproject_7.c
//NAME: Edward Corbett
//DATE: 11/05/14
//PURPOSE: String manipulation - user will input sentence and the program
//will convert each word into pig latin and display the converted sentence back to the user
//user can exit proram loop with an input of the word "done"
//***********************************************************************************/
#include <stdio.h> //include contents of standart input/output header
#include <stdlib.h> //include function prototypes for conversions of numbers to text,
#include <string.h> //used to manipulate strings
#include <ctype.h> //used to classify and transform characters
char makeInput(char string[70]); //function to fill input array
char removePunct(char input[70], char noPunct[70]); //function to remove punctuation from input array
char convert2PigLatin(char noPunct[70], char pigLatin[0], char output[0]); //function to convert 
int main(void) //main function
{
    char pigLatin [0]; //initialize pig latin array
    pigLatin[0]=' '; //set array to blank space
    char output[0]; //initialize output array
    output[0] = ' '; //set array to blank space
    char input [70]; //initialize input array
    char noPunct[70];// initialize input array
    char quit [6] = {'d','o','n','e','\0'}; //initialize quit array to compare to input to quit
    makeInput(input); //fill input array with blank spaces
    makeInput(noPunct); //fill noPunct array with blank spaces
    FILE *fPtr; //Piglatin.txt file pointer
    
    if ((fPtr = fopen("Piglatin.txt", "w")) == NULL) //fopen opens file, displays message if cannot open
    {
        printf("Can not open file");
        system("PAUSE");
    }
    
    fprintf(fPtr, "%s", "Edward Corbett\n");//file headers
    fprintf(fPtr, "%s", "11/5/14\n");
    fprintf(fPtr, "%s", "CPS 135 Program 7\n");
    printf("\t\t\tString Manipulation Program\n");
    fprintf(fPtr, "%s", "String Manipulation Program\n");
    printf("\t\t\t---------------------------\n");
    fprintf(fPtr, "%s", "---------------------------\n");
    printf("\nThis program will accept sentences, up to 80 characters long.\n");
    printf("Each sentence will be changed to pig latin.");
    puts("");
    puts("");
    puts("");
    system("PAUSE");
    system("CLS");
    printf("Enter a sentence, or type \"done\" to quit:\n"); //get input 
    puts("");
    gets(input); //get input array
    if((strcmp(input, quit)!= 0)) //if user inputs "done" first time, program exits
    {
        do
        {
            fprintf(fPtr, "input: "); //display information in file
            fprintf(fPtr, input);
            fprintf(fPtr, "\n");
            removePunct(input, noPunct); //send input string to removePunct function
            convert2PigLatin(noPunct, pigLatin, output); //convert noPunct array to pigLatin in convert2PigLatin function
            puts(pigLatin); //display pigLatin array
            fprintf(fPtr, "pig latin conversion: ");  //display array in file    
            fprintf(fPtr, "%12s", pigLatin);
            fprintf(fPtr, "\n\n\n");
            puts("");
            printf("Enter a sentence, or type \"done\" to quit:\n"); //continue until user inputs "done"
            puts("");
            gets(input); 
            pigLatin[0] = '\0'; //erases pigLatin array to fill with new word
        }while((strcmp(input, quit)!= 0)); //exits if input is "done"
    }
    fprintf(fPtr, "\0"); // end file
    fclose(fPtr); //close file
    exit("0");  
}
char makeInput(char raceBoard[70]) //function to make array for game board
{      
     int i = 0; //column counter
     for(i = 0; i < 70; i++)
     {                      
            raceBoard[i] = ' '; //initialize each entry with blank space
     } 
}
char removePunct (char input[70], char noPunct[70])
{
    int i = 0;
    int noPunctIndex = 0;
    
    for(i = 0; i < strlen(input);)
    {
        if(ispunct(input[i])) //looks at character at i checks if punctuation
        {
            i++; //does not input to new array if punctuation
        }
        else
        {
            noPunct[noPunctIndex] = tolower(input[i]); //if character at i is not punctuation, convert to lowercase
            noPunctIndex++; //increase new input array 
            i++;
        }     
    }
    noPunct[noPunctIndex] = '\0'; //insert null at end of array 
}
char convert2PigLatin(char noPunct[70], char pigLatin[0], char output[0])
{
    char *strPtr; //points to each word in the string
    char subString[20]; //used to hold and convert each word 
    strPtr = strtok(noPunct, " "); //tokenize string noPunct by space

    do
    {
        do
        {  
            int i = 0;
            strcpy(subString, strPtr); //copy pointer into subString array
            subString[strlen(subString)+1] = '\0'; //insert null into subString array
            switch(subString[i]) //swtich statement based on position i in subString
            {
                case 'a':                       //special switch statement if first letter is vowel
                    strcat(subString, "-way ");
                    strcat(pigLatin, subString);
                    break;
                case 'e': 
                    strcat(subString, "-way ");
                    strcat(pigLatin, subString);
                    break;    
                case 'i': 
                    strcat(subString, "-way ");
                    strcat(pigLatin, subString);
                    break;
                case 'o': 
                    strcat(subString, "-way ");
                    strcat(pigLatin, subString);
                    break;
                case 'u': 
                    strcat(subString, "-way ");
                    strcat(pigLatin, subString);
                    break;
                case 'y': 
                    strcat(subString, "-way ");
                    strcat(pigLatin, subString);
                    break;
                default: 
                    strcat(subString, "  "); //append consonants to end of word if begins with consonant
                    subString[strlen(subString) - (i + 2)] = '-';
                    subString[strlen(subString)- (i + 1)] = subString[i];
                    subString[i] = ' '; 
                    i++;
                    break;
            }
            if(i == 1 && i < strlen(subString)) //continue if 2nd character is consonant
            {
                switch(subString[i])
                {
                case 'a': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'e': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;    
                case 'i': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'o': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'u': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'y': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                default: 
                    strcat(subString, " ");
                    subString[strlen(subString)-1] = subString[i];
                    subString[i] = ' '; 
                    i++;
                }
            if(i == 2 && i < strlen(subString)) //continue if 3rd character is consonant
            {
                switch(subString[i])
                {
                case 'a': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'e': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;    
                case 'i': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'o': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'u': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'y': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                default: 
                    strcat(subString, " ");
                    subString[strlen(subString)-1] = subString[i];
                    subString[i] = ' '; 
                    i++;
                }
            }   
            if(i == 3 && i < strlen(subString)) //continue if 4th character is consonant
            {
                switch(subString[i])
                {
                case 'a': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'e': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;    
                case 'i': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'o': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'u': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                case 'y': 
                    strcat(subString, "ay ");
                    strcat(pigLatin, subString);
                    break;
                default: 
                    strcat(subString, " ");
                    subString[strlen(subString)-1] = subString[i];
                    subString[i] = ' '; 
                    i++;
                }
            }break;   
        }break;      
    }while(noPunct != "done"); //stop if noPunct = "done"     
    strPtr = strtok(NULL, " "); //continue tokenizing until next blank space
    }while(strPtr != NULL); //stop when pointer = null
    strcat(pigLatin, "  "); //increase size of pigLatin array to insert null
    pigLatin[strlen(pigLatin) + 1] = '\0'; //insert null to end of pigLatin array

    if(isalpha(pigLatin[0])) // converts first character to uppercase
    {
    pigLatin[0] = toupper(pigLatin[0]);
    }
    else if(isalpha(pigLatin[1]))
    {
    pigLatin[1] = toupper(pigLatin[1]);
    }
    else if(isalpha(pigLatin[2]))
    {
    pigLatin[2] = toupper(pigLatin[2]);
    }
    else if(isalpha(pigLatin[3]))
    {
    pigLatin[3] = toupper(pigLatin[3]);
    }
    pigLatin[strlen(pigLatin)- 3] = '.'; //appends period to end of pigLatin string
}     
