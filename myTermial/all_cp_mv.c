#include"myheader.h"
void ols(char *, char *);
void olsv(char *, char *);
void olsn(char *, char *);
void olsi(char *, char *);
void olsb(char *, char *);
void omvv(char *, char *);
void call_cp_mv(char* inputarr1[])
{
if((strcmp(inputarr1[0],"cp") == 0)&&(inputarr1[1] != NULL)&&(inputarr1[2] != NULL))
{
if (*(inputarr1[1]) != '-')
{
    
    ols(inputarr1[1], inputarr1[2]);
}
if((strcmp(inputarr1[1],"-v") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsv(inputarr1[2], inputarr1[3]);
}
if((strcmp(inputarr1[1],"-n") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsn(inputarr1[2], inputarr1[3]);
}
if((strcmp(inputarr1[1],"-i") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsi(inputarr1[2], inputarr1[3]);
}
if((strcmp(inputarr1[1],"-b") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsb(inputarr1[2], inputarr1[3]);
}
}



if((strcmp(inputarr1[0],"mv") == 0)&&(inputarr1[1] != NULL)&&(inputarr1[2] != NULL))
{
if (*(inputarr1[1]) != '-')
{
    
    ols(inputarr1[1], inputarr1[2]);
	remove(inputarr1[1]);
}
if((strcmp(inputarr1[1],"-v") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    omvv(inputarr1[2], inputarr1[3]);
    remove(inputarr1[1]);
}
if((strcmp(inputarr1[1],"-n") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsn(inputarr1[2], inputarr1[3]);
    remove(inputarr1[1]);
}
if((strcmp(inputarr1[1],"-i") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsi(inputarr1[2], inputarr1[3]);
    remove(inputarr1[1]);
}
if((strcmp(inputarr1[1],"-b") == 0) && (inputarr1[2] != NULL) && (inputarr1[3] != NULL))
{
    olsb(inputarr1[2], inputarr1[3]);
    remove(inputarr1[1]);
}
}
}
