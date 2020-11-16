#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    short cont = 0;
    //char string[10] = "-23234";
    //int contr = isNumber(string);
    //printf("Condition %d \n", contr);

    int r =0;

    int i = 0;
    while(i!=10)
    {
        r++;
        if(r==20)
        {
            break;
        }

        printf("%d \n", i);
        if(i==7)
        {
            i = 4;
            continue;
        }
        

        i++;
    }

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