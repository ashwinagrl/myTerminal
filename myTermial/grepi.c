#define _GNU_SOURCE
#include"myheader.h"

void grepi (char* pattern,char* filename) {
   /* char pattern[100];
    char filename[100];
    gets(pattern);
    gets(filename); */

   // printf("%s    %s\n",pattern,filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(0);
    }
    
    char line[1024];
    while (fgets(line, 1024 , fp) != NULL) {
        char* tf = strcasestr(line,pattern);

        if (tf != NULL) {
            for(int i=0;i<strlen(line);i++)
           { 
            if((tf<=(line+i))&&((line+i)<(tf+strlen(pattern))))
            {
            printf("\033[0;31m%c\033[0m", *(line+i));
            }
            else{
                printf("%c",*(line+i));
            }
        }
        }
         else {
          
        }
    }
    
    fclose(fp);
}
