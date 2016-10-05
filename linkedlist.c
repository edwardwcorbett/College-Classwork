/************************************************************************************
//FILENAME:ewcproject_10.c
//NAME: Edward Corbett
//DATE: 11/30/14
//PURPOSE: Display menu and provide option #2 with two options to input to linked.txt 
//or to load an existing linked.txt and add to linked list.  Option #5 is available
//to print the values from the linked list.
//***********************************************************************************/
#include <stdio.h> //include contents of standart input/output header
#include <stdlib.h> //include function prototypes for conversions of numbers to text,
#include <string.h> //used to manipulate strings
#include <ctype.h> //used to classify and transform characters
#include <stdbool.h> //boolean type and values
typedef struct list *ptr; //create list pointer
typedef struct list //create node type for list
{
    int data;
    ptr next;
} node;
struct node* add2List(int c,ptr *H); //function to add contents to linked list
struct node* insertFirst(ptr *H, int c); //function to add int as first item in list
struct node* insertAfter(ptr *H, int c); //function to insert int after first node in linked list
struct node* insertBefore(ptr *H, int c);//function to insert int before first node in linked list
void printList(ptr (*H));//function to print list
int menuOption (char a[2], char b[2], char c[2], char d[2], char e[10], char f[10], char g[2], char z[2], char j[2], char k[2], char l[2], char m[2], int h, FILE *i, char fileIn[10], ptr *H); //menu funciton
int validate (char invalid[6], char valid[6], int number);//function to validate input as only int with + or -
int print2File(char input[10], FILE *b); //function to print char array to file
int main(void)//function to display instructions
{        
  FILE *fPtr; //linked.txt file pointer   
  ptr H = NULL; //linked list first node "Head"
  char menu[10]; //array to hold input for menu choice
  char load2[2] = {'2', '\0'}; //array used to compare to enter option 2 from menu
  char load5[2] = {'5', '\0'};//array used to compare to enter option 5 from menu
  char input[10]; //array to hold input to load into file
  char valid[10]; //array to convert int number to array
  char fileIn[10]; //array to hold data from file
  char exitMenu[2]={'q','\0'}; //array used to compare to exit main menu
  char exitMenu2[2]={'Q', '\0'};  //array used to compare to exit main menu
  char exitLoad[2] = {'x', '\0'}; //array used to compare to exit option 2 from menu
  char option[2]; //array to hold N or E value
  char exitOp1[2]={'N','\0'}; //arrays used to compare to option array
  char exitOp2[2]={'n','\0'};
  char exitOp3[2]={'E','\0'};
  char exitOp4[2]={'e','\0'};
  int number; //used to convert input array to number
  printf("\t\tLinked List Program  \n"); 
  printf("\t\t-------------------- \n\n");  
  printf("This program puts numbers in a Linked List in ascending order.\n"); //program details
  printf("It allows the user to load the list from an existing file,\n");
  printf("create a new file and enter numbers into it, or to enter.\n");  
  printf("numbers one at a time from the keyboard. Numbers can then be\n");
  printf("added to or removed from the list until the user decides they\n");
  printf("are finished at which time the list can be printed and the\n");
  printf("ordered numbers can be written to the file \"ordered.txt\".\n");
  puts("");
  system("PAUSE");  
  do
  { 
    system("CLS");
    printf("1. Empty the list.\n"); //menu options  
    printf("2. Load the list from the \"linked.txt\" file.\n"); //game instructions
    printf("3. Add a number to the list\n");
    printf("4. Remove a number from the list.\n");  
    printf("5. Print the list\n");
    printf("6. Write the list to the \"ordered.txt\" file.\n");
    printf("Q. Quit the program.\n");
    printf("?  ");
    gets(menu);
    menu[1]='\0';//second position set to null     
    menuOption(menu, load2, load5, exitLoad, input, valid, exitMenu, option, exitOp1, exitOp2, exitOp3, exitOp4, number, fPtr, fileIn, &H);
  }while((strcmp(menu, exitMenu)!=0) && (strcmp(menu, exitMenu2)!=0)); //while menu input is not "q" or "Q"
}
int menuOption(char menu[2], char load2[2], char load5[2], char exitLoad[2], char input[10], char valid[10], char exitMenu[2], char option[2], char exitOp1[2], char exitOp2[2], char exitOp3[2], char exitOp4[2], int number, FILE *fPtr, char fileIn[10], ptr *H)
{
    if(strcmp(menu,load2)==0) //option 2
    {   
            do
            {
                system("CLS");
                printf("\nDo you want to create and/or enter data into the \"list.txt\" file or");
                printf("\ndo you want to use an existing file with number already in it?");
                printf("\n\nPlease enter an 'N' for new file or an 'E' for existing file.\n");  
                gets(option);
                option[1]='\0';
                    if(option[0] == 'N' || option [0] == 'n') //writes input to file in new linked.txt
                    {
                        system("CLS");
                        input[0]=' '; //clear input array
                        if ((fPtr = fopen("linked.txt", "w")) == NULL) //fopen opens file, displays message if cannot open
                        {
                            printf("Can not open file");
                            system("PAUSE");
                        }
                        printf("\nEnter a series of numbers up to 5 digits long, do not");
                        printf("\ninclude a sign.  Type an \"x\" at anytime to quit:\n\n");
                        while (input[0]!='x')
                        {
                            printf("?  ");  
                            gets(input); //get line of input
                            input[strlen(input)+1] = '\0';//insert null at end of array
                            validate(input, valid, number);
                            if (strcmp(valid,input)==0)//compare number array to input array
                            {   
                                print2File(input,fPtr);//put validated input array into file
                            }
                        }
                        fprintf(fPtr, "\0"); // end file
                        fclose(fPtr); //close file
                    }
                    //if option E or e is selected, nothing is put into file
            }while((strcmp(option,exitOp1)!=0) && (strcmp(option,exitOp2)!=0) && (strcmp(option,exitOp3)!=0) && (strcmp(option,exitOp4)!=0));       
    }
    if((strcmp(menu,load5)==0) && (strcmp(option,exitOp3)==0))//if the user chooses option 5 after selecting option E or e in option 2
    {
        if ((fPtr = fopen("linked.txt", "r")) == NULL) //fopen opens file, displays message if cannot open
        {
            printf("Can not open file");
            system("PAUSE");
        }
        while(fgets(fileIn, 10, fPtr) != NULL)
        {
 
          fileIn[strlen(fileIn)-1]='\0';  // insert null 
          validate(fileIn, valid, number); //validate fileIn and put into valid array    
          if(strcmp(valid, fileIn)==0)//if the valid array and fileIn array match, add the number to Linked List
            {
                if(fileIn[strlen(fileIn)-1]=='-')//if last character of input is - 
                {
                    number=(atoi(fileIn) * -1); //add - to end of array
                    add2List(number, &(*H));//insert null at new end
                }            
                else
                {    
                    number=atoi(fileIn);
                    add2List(number, &(*H));   //send into function with number and address of head node  
                }
            }
            
        }
        printList(&(*H));
        puts("");
        puts("");
        system("PAUSE");
        fclose(fPtr);
    }
    else if((strcmp(menu,load5)==0) && (strcmp(option,exitOp4)==0))//if the user chooses option 5 after selecting option E or e in option 2 
    {
        if ((fPtr = fopen("linked.txt", "r")) == NULL) //fopen opens file, displays message if cannot open
        {
            printf("Can not open file");
            system("PAUSE");
        }
        while(fgets(fileIn, 10, fPtr) != NULL)
        {

          fileIn[strlen(fileIn)-1]='\0'; // insert null 
          validate(fileIn, valid, number); //validate fileIn and put into valid array   
          if(strcmp(valid, fileIn)==0)//if the valid array and fileIn array match, add the number to Linked List
            {
                if(fileIn[strlen(fileIn)-1]=='-')//if last character of input is - 
                {
                    number=(atoi(fileIn) * -1); //add - to end of array
                    add2List(number, &(*H));//insert null at new end
                }            
                else
                {    
                    number=atoi(fileIn);
                    add2List(number, &(*H));   //send into function with number and address of head node  
                }
            }
        }
        printList(&(*H));
        puts("");
        puts("");
        system("PAUSE");
        fclose(fPtr);
    }
    else if(strcmp(menu,load5)==0 && option[0]=='N' )//if the user chooses option 5 after selecting option N or n in option 2 
    {
        if ((fPtr = fopen("linked.txt", "r")) == NULL) //fopen opens file, displays message if cannot open
        {
            printf("Can not open file");
            system("PAUSE");
        }
        while(fgets(fileIn, 10, fPtr) != NULL)
        {

          fileIn[strlen(fileIn)-1]='\0'; // insert null 
          validate(fileIn, valid, number); //validate fileIn and put into valid array   
          if(strcmp(valid, fileIn)==0)//if the valid array and fileIn array match, add the number to Linked List
            {
                if(fileIn[strlen(fileIn)-1]=='-')//if last character of input is - 
                {
                    number=(atoi(fileIn) * -1); //add - to end of array
                    add2List(number, &(*H));//insert null at new end
                }            
                else
                {    
                    number=atoi(fileIn);
                    add2List(number, &(*H));   //send into function with number and address of head node  
                }
            }
        }
        printList(&(*H));
        puts("");
        puts("");
        system("PAUSE");
        fclose(fPtr);
    }
    else if(strcmp(menu,load5)==0 && option[0]=='n' )//if the user chooses option 5 after selecting option N or n in option 2 
    {
        if ((fPtr = fopen("linked.txt", "r")) == NULL) //fopen opens file, displays message if cannot open
        {
            printf("Can not open file");
            system("PAUSE");
        }
        while(fgets(fileIn, 10, fPtr) != NULL)
        {

          fileIn[strlen(fileIn)-1]='\0'; // insert null 
          validate(fileIn, valid, number); //validate fileIn and put into valid array   
          if(strcmp(valid, fileIn)==0)//if the valid array and fileIn array match, add the number to Linked List
            {
                if(fileIn[strlen(fileIn)-1]=='-')//if last character of input is - 
                {
                    number=(atoi(fileIn) * -1); //add - to end of array
                    add2List(number, &(*H));//insert null at new end
                }            
                else
                {    
                    number=atoi(fileIn);
                    add2List(number, &(*H));   //send into function with number and address of head node  
                }
            }
        }
        printList(&(*H));
        puts("");
        puts("");
        system("PAUSE");
        fclose(fPtr);
    }
    else if(strcmp(menu,load5)==0) //if user has not loaded the list or input to a new list, the list will be empty
    {

        printList(&(*H));
        puts("");
        puts("");
        system("PAUSE");
    }
}
int validate(char invalid[10], char valid[10], int number) //validate input 
{
            if(invalid[0]=='-') //check input for - at beginning
            {
                
                valid[0]='-'; //create new array with only digits to compare to input
                int i;
                for(i = 1; i < (strlen(invalid)+1);)//examine input array 
                {  
                    int numCheck = isdigit(invalid[i]); //check if character is digit
                    if(numCheck > 0)
                    {
                        valid[i]=invalid[i];//match value in compare array 
                    }
                    else
                    {
                        valid[i]='\0';//insert null at first nondigit character
                    }
                    i++;
                }
            }
            if(invalid[0]=='+')//check input for + at beginning
            {
                valid[0]='+'; //create new array with only digits to compare to input
                int i;
                for(i = 1; i < (strlen(invalid)+1);)//examine input array 
                {  
                    int numCheck = isdigit(invalid[i]); //check if character is digit
                    if(numCheck > 0)
                    {
                        valid[i]=invalid[i]; //match value in compare array 
                    }
                    else
                    {
  
                        valid[i]='\0';//insert null at first nondigit character 
                    }
                    i++;
                }
            }
            if(invalid[0]!='+' && invalid[0]!='-') //if input begins with digit
            {
                number = atoi(invalid); //convert character array to integer
                itoa(number,valid,10);//convert integer(previous character array) to character array
                valid[strlen(valid)]='\0';//insert null at end of array 
            }
            if(invalid[strlen(invalid)-1]=='-')//if last character of input is - 
            {
                strcat(valid, "-"); //add - to end of array
                valid[strlen(valid)]='\0';//insert null at new end
            }
            if(invalid[strlen(invalid)-1]=='+')//if last character is +
            {
                strcat(valid, "+"); //add + to end array           
                valid[strlen(valid)]='\0';//insert null at new end
            }       
}
int print2File(char input[10], FILE *fPtr) //print to file 
{
    fprintf(fPtr, "%s\n", input); //display information in file if input matches integer only array (w/ + or - optional)   
}
struct node* add2List(int c, ptr *H) //add int to list using pointer to address of head node
{
     if(!(*H))//while the head node is NULL
     {
        (*H) = malloc(sizeof(**H)); //allocate node 
        insertFirst(&(*H), c);//insert node as first and only in list
     }
     else if(c > (*H)->data) //if int c is greater than the data in the first node
     {
        insertAfter(&(*H), c); //insert somewhere after first in list
     }
     else if(c <= (*H)->data) //if int c is less than data in first node
     {
        insertBefore(&(*H), c); //insert before first node, making it the first node
     }
}  
struct node* insertFirst(ptr *H, int c)//insert node as first in list
{
    ptr newnode;//local node
    newnode = malloc(sizeof(**H));
    newnode->data = c;//int c is data for new node
    newnode->next = NULL;
    (*H)=newnode;//make first node new node
}
struct node* insertBefore(ptr *H, int c)//insert before first node, pointing to first node
{
    ptr newnode;//local node
    newnode = malloc(sizeof(**H)); //allocate new node
    newnode->data = c;
    newnode->next = NULL;
    newnode->next = (*H); //point new node to current first node address
    (*H)=newnode; //make address of first node equal to address of new node
}
struct node* insertAfter(ptr *H, int c)
{
    ptr newnode; //local node
    ptr traverse; //local node
    traverse = malloc(sizeof(**H));  //allocate node to travel through list
    traverse = (*H); //assign address of first node to traverse
    newnode = malloc(sizeof(**H)); //allocate new node
    newnode->data = c;
    newnode->next = NULL;
    while(c > traverse->data) //while c is greater than data in traverse node
    {
        if(c>traverse->data && !traverse->next) //if c is greater than data in traverse and traverse next is NULL
        {
                traverse->next=newnode; //traverse points to new node
                newnode->next=NULL;//new node next is null
                break;
        }
        if(c>traverse->data && c<=(traverse->next)->data) //if c is greater than the data in traverse data and less than or equal 
        {                                                  //to data in the next node of traverse
            newnode->next=traverse->next;//new node next is what traverse next node is
            traverse->next=newnode; //traverse points to new node
            traverse=traverse->next;// set traverse to next node in list
        }
        if(c>traverse->data && c>(traverse->next)->data) //if c is greater than traverse node and traverse next node data
        {
            traverse=traverse->next;//set traverse to next node in list
        }
    }
}
void printList(ptr *H) //print link list
{
    system("CLS");
    printf("\n\nThe values in the Linked List are:\n\n\n");
    printf("  Item #\t Value\n");
    printf("  ------\t -----\n");
    int i = 1;
    while (*H)//while node is not null
    {   
        printf(" %5d\t\t %5d \n",i, (*H)->data);
        (*H)=(*H)->next; //traverse through list
        i++;
    }
}
