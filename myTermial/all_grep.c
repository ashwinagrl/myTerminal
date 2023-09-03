#include "myheader.h"
void grep(char *, char *);
void grepc(char *, char *);
void grepn(char *, char *);
void grepv(char *, char *);
void grepi(char *, char *);
void call_grep(char *inputarr1[])
{
    if ((strcmp(inputarr1[0], "grep") == 0) && (inputarr1[1] != NULL) && (inputarr1[2] != NULL))
    {
        if (*(inputarr1[1]) != '-')
        {

            grep(inputarr1[1], inputarr1[2]);
        }
        if ((strcmp(inputarr1[1], "-c") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
        {
            grepc(inputarr1[2], inputarr1[3]);
        }
        if ((strcmp(inputarr1[1], "-n") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
        {
            grepn(inputarr1[2], inputarr1[3]);
        }
        if ((strcmp(inputarr1[1], "-v") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
        {
            grepv(inputarr1[2], inputarr1[3]);
        }
        if ((strcmp(inputarr1[1], "-i") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
        {
            grepi(inputarr1[2], inputarr1[3]);
        }
    }
}