#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    short cont = 0;
    char string[10] = "23234d";
    //int contr = isNumber(string);
    int test = 10/4;
    printf("Condition %d \n", test);
}

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