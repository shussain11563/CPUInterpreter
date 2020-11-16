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

int jumpAt(char* currLine)
{
    char tempCommand[10]; 
    char linePointer[5]; 
    sscanf(currLine, "%s %s", tempCommand, linePointer);
    int lineJump = atoi(linePointer);
    return lineJump;

}


//find command read register 
//may not work with negative numbers
int isNumber(char* stringReg)
{
    int condition = 1;
    int i = 0;
    while(!(stringReg[i]=='\0'))
    {
        if(stringReg[i]=='-' || stringReg[i]=='+')
        {
            continue;
        }
        if(!(isdigit(stringReg[i])))
        {
            condition = 0;
            return condition;
        }
        i++;
    }
    return condition;
}

int jumpCondition(char* currLine, int* registers, int currentLineInstruction, int* success)
{
    char tempCommand[10]; 
    char linePointer[5];
    char readFirst[10]; 
    char readSec[10];
    int x;
    int y;
    sscanf(currLine, "%s %s %s %s", tempCommand, linePointer, readFirst, readSec);  

    int jumpAt = atoi(linePointer);

    //grab first register value
    if(isNumber(readFirst)==1)
    {
        x = atoi(readFirst);
    }
    else
    {
        int index = registerIndex(readFirst);
        x = registers[index];
    }

    //grab second register
    if(isNumber(readSec)==1)
    {
        y = atoi(readSec);
    }
    else
    {
        y = registers[registerIndex(readSec)];
    }

  
    if(strcmp("je", tempCommand)==0)
    {
        if(x==y)
        {
            *success = 1;
            return jumpAt;
        }
    }
    else if(strcmp("jne", tempCommand)==0)
    {
        if(x!=y)
        {
            *success = 1;
            return jumpAt;
        }
    }
    else if(strcmp("jg", tempCommand)==0)
    {
        if(x>y)
        {
            *success = 1;
            return jumpAt;
        }
    }
    else if(strcmp("jge", tempCommand)==0)
    {
        if(x>=y)
        {
            *success = 1;
            return jumpAt;
        }
    }
    else if(strcmp("jl", tempCommand)==0)
    {
        if(x<y)
        {
            *success = 1;
            return jumpAt;
        }
    }
    else if(strcmp("jle", tempCommand)==0)
    {
        if(x<=y)
        {
            *success = 1;
            return jumpAt;
        }
    }
    
    return currentLineInstruction;
      
}

//FILE IO
void ioInstructions(char* currLine, int* registers)
{
    char tempCommand[10]; 
    char readRegister[4]; 
    sscanf(currLine, "%s %s", tempCommand, readRegister);
    if(strcmp("read", tempCommand)==0)
    {
        int readValue = 0;
        scanf("%d", &readValue);
        registers[registerIndex(readRegister)] = readValue;
    }
    else if(strcmp("print", tempCommand)==0)
    {
        if(isNumber(readRegister)==1)
        {
            printf("%d\n", atoi(readRegister));
        }
        else
        {
            printf("%d\n", registers[registerIndex(readRegister)]);
        }
        
    }
}

//arithmetic only supports multiply
void arithmeticInstructions(char* currLine, int* registers)
{
    //arithmetic only supports multiply
    char tempCommand[10]; 
    char readFirst[10]; 
    char readSec[10];
    int x;
    int y;
    sscanf(currLine, "%s %s %s", tempCommand, readFirst, readSec);

    //grab first register value
    if(isNumber(readFirst)==1)
    {
        x = atoi(readFirst);
    }
    else
    {
        int index = registerIndex(readFirst);
        x = registers[index];
    }

    //grab second register
    y = registers[registerIndex(readSec)];

    if(strcmp("add", tempCommand)==0)
    {
        y = y + x;
    }
    else if(strcmp("sub", tempCommand)==0)
    {
        y = y - x;
    }
    else if(strcmp("mul", tempCommand)==0)
    {
        y = y * x;
    }
    else if(strcmp("div", tempCommand)==0)
    {
        y = x/y;
    }
    else if(strcmp("mov", tempCommand)==0)
    {
        y = x;
    }

    //copy and paste this into if statements above instead
    registers[registerIndex(readSec)] = y;

   // CHECK DIVIDE ALGO

}



///remember -g flag in make
int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    int registers[4] = {0,0,0,0};

    //char instructionC[6]; 
    char currLine[50]; 
    char currCommand[10]; 
//EXPERIMENT CODE
    char instructionPointer[100][50];

    for(int i = 0; i < 100; i++)
    {
        fgets(instructionPointer[i], 50, fp);
    }

    int instructLinePtr = 0;

    while(instructLinePtr!=100)
    {
        strcpy(currLine ,instructionPointer[instructLinePtr]);
        parseCommand(currLine, currCommand);
        
        
        if(strcmp("read", currCommand)==0 || strcmp("print", currCommand)==0)
        {
            ioInstructions(currLine, registers);
        }
        else if(strcmp("add", currCommand)==0 || strcmp("sub", currCommand)==0 || strcmp("mul", currCommand)==0 || strcmp("div", currCommand)==0 )
        {
            arithmeticInstructions(currLine, registers);
        }
        else if(strcmp("mov", currCommand)==0)
        {
            arithmeticInstructions(currLine, registers);
        }
        else if(strcmp("jmp", currCommand)==0)
        {
            instructLinePtr = jumpAt(currLine);
            continue;
        }
        else if(strcmp("je", currCommand)==0 || strcmp("jne", currCommand)==0 || strcmp("jg", currCommand)==0 || strcmp("jge", currCommand)==0 || strcmp("jl", currCommand)==0 || strcmp("jle", currCommand)==0)
        {
            int temp = instructLinePtr;
            int isSuccess = 0;
            instructLinePtr = jumpCondition(currLine, registers, instructLinePtr, &isSuccess);

            //NOT SURE ABOUT POINTER PASS BY REFERENCE FOR ISSUCCESS
            if(isSuccess==1)
            {
                continue;
            }
        }
        //else if(strlen(currLine)==0)
        //{
            //instructLinePtr++;
            //continue;
        //}
        

            //printf("Current line is")
        
        
        
        instructLinePtr++;

    }

    

    //g
    //call an array (hashcode similar)

    //fscanf(fp,"%s", instructionC);
    //change size
    //sscanf("")
    fclose(fp);
}
