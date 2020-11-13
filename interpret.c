#include <stdio.h>
#include <stdlib.h>

///remember -g flag in make
int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");

    //fscanf
    //change to ints
    
    //REGISTERS
    signed short int ax = 0;
    signed short int bx = 0;
    signed short int cx = 0;
    signed short int dx = 0;

    char instruction[6]; 

    //call an array (hashcode similar)

    if(fscanf("%s", &instruction)!=EOF)
    {
        printf("%s \n" , &instruction);
    }


    fclose(fp);
}
