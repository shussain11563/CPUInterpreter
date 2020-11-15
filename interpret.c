#include <stdio.h>
#include <stdlib.h>


//parse Command from string
void parseCommand(char* currLine, char* currCommand)
{
    sscanf(currLine, "%s", currCommand);
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
    signed short int registers[4] = {0,0,0,0}
    //signed short int ax = 0;
    //signed short int bx = 0;
    //signed short int cx = 0;
    //signed short int dx = 0;

    //char instructionC[6]; 
    char currLine[50]; 
    char currCommand[10]; 

    while(fgets(currLine, 50, fp)!=EOF)
    {
        parseCommand(currLine, currCommand);
        printf("%s\n", currCommand);
    }

    //if(strcmp("read", ))
    

    //g
    //call an array (hashcode similar)

    //fscanf(fp,"%s", instructionC);
    //change size
    //sscanf("")


    //printf("%s \n" , instructionC);
    


    fclose(fp);
}
