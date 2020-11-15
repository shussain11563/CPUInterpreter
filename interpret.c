#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//parse Command from string
void parseCommand(char* currLine, char* currCommand)
{
    sscanf(currLine, "%s", currCommand);
}

int registerIndex(char* stringReg)
{
   return stringReg[0] - 97;
}

//find command read register 
int isNumber(char* stringReg)
{
    int condition = 1;
    int i = 0;
    while(!(stringReg[i]=='\0'))
    {
        printf("%c \n",stringReg[i]);
        if(!(isdigit(stringReg[i])))
        {
            condition = 0;
            return condition;
        }
        i++;
    }
    return condition;
}

//FILE IO
void ioInstructions(char* currLine, int* registers)
{
    char tempCommand[10]; 
    char readRegister[4]; 
    sscanf(currLine, "%s %s", tempCommand, readRegister);
    int index = registerIndex(readRegister);
    if(strcmp("read", tempCommand)==0)
    {
        int readValue = 0;
        scanf("%d", &readValue);
        registers[index] = readValue;
    }
    else if(strcmp("print", tempCommand)==0)
    {
        printf("%d\n", registers[index]);
    }
}

//arithmetic only supports multiply
void arithmetic(char* currLine, int* registers)
{
    //arithmetic only supports multiply
    char tempCommand[10]; 
    char readFirst[10]; 
    char readSecond[10];
    int valueOfFirst;
    int valueOfSec;
    sscanf(currLine, "%s %s %s", tempCommand, readFirst, readSec);

    //grab first register value
    if(isNumber(readFirst)==1)
    {
        valueOfFirst = atoi(readFirst);
    }
    else
    {
        int index = registerIndex(readFirst);
        valueOfFirst = registers[index];
    }

    //grab second register
    valueOfSec = registers[registerIndex(readSec)];

    if(strcmp("add", tempCommand)==0)
    {
        
    }
    else if(strcmp("sub", tempCommand)==0)
    {

    }
    else if(strcmp("mul", tempCommand)==0)
    {

    }
    else if(strcmp("div", tempCommand)==0)
    {

    }

}

///remember -g flag in make
int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");

    //signed short int registers[4];
    //fscanf
    //change to ints
    //create instruction pointer for each line and store in array for jumps
    //REGISTERS
    char instructionPointer[100][50];
    //signed short int registers[4] = {0,0,0,0};
    int registers[4] = {0,0,0,0};
    //signed short int ax = 0;
    //signed short int bx = 0;
    //signed short int cx = 0;
    //signed short int dx = 0;

    //char instructionC[6]; 
    char currLine[50]; 
    char currCommand[10]; 
    int instructLinePtr = -1;
    //n-1

//deal with spaces

    while(fgets(currLine, 50, fp)!=NULL)
    {
        instructLinePtr++;
        
        parseCommand(currLine, currCommand);
        
        
        if(strcmp("read", currCommand)==0 || strcmp("print", currCommand)==0)
        {
            ioInstructions(currLine, registers);
        }
        else if(strcmp("mult", currCommand))
        {

        }
        //{

        //}
        

        


    }

    

    //g
    //call an array (hashcode similar)

    //fscanf(fp,"%s", instructionC);
    //change size
    //sscanf("")


    //printf("%s \n" , instructionC);
    


    fclose(fp);
}