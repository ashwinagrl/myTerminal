#include "myheader.h"

void grep(char *pattern, char *filename)
{

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(0);
    }

    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        char *tf = strstr(line, pattern);

        if (tf != NULL)
        {
            for (int i = 0; i < strlen(line); i++)
            {
                if ((tf <= (line + i)) && ((line + i) < (tf + strlen(pattern))))
                {
                    printf("\033[0;31m%c\033[0m", *(line + i));
                }
                else
                {
                    printf("%c", *(line + i));
                }
            }
        }
        else
        {
        }
    }

    fclose(fp);
}
