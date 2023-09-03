#include"myheader.h"

void grepc (char* pattern,char* filename) {
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
    int no=0;
    while (fgets(line, 1024 , fp) != NULL) {
        char* tf = strstr(line,pattern);
        if (tf != NULL) {
            no++;
        }
         else {
          
        }
    }
    printf("%d\n",no);
    
    fclose(fp);
}
