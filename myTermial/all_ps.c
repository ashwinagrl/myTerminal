#include "myheader.h"
int ops();
int opsa();
int opsd();
int opse();
int opsr();
void call_ps(char *inputarr1[])
{
    if((strcmp(inputarr1[0], "ps") == 0) && (inputarr1[1] == NULL))
    {
        ops();
    }
    if ((strcmp(inputarr1[0], "ps") == 0) && (inputarr1[1] != NULL))
    {
        if ((strcmp(inputarr1[1], "-a") == 0))
        {
            opsa();
        }
        if ((strcmp(inputarr1[1], "-d") == 0))
        {
            opsd();
        }
        if ((strcmp(inputarr1[1], "-e") == 0))
        {
            opse();
        }
        if ((strcmp(inputarr1[1], "-r") == 0))
        {
            opsr();
        }
    }
}