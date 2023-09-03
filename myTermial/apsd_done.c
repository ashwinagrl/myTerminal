#include"myheader.h"


int opsd()
{
    char tyym[600];
    char tyy[600]; 
     char tt_path [300];
     char othbuf[2000];
    DIR* dir;
    FILE* file;
    struct dirent *entry;
    char path[1024], buf[1024], cmd[1024];
    int pid;
   
    dir = opendir("/proc");
    if(!dir)
    {
        printf("Failed to open directory");
        return 0;
    }
    printf("%7s%4s%21s%4s\n","PID","TTY","TIME","CMD");
      
       int fd = open("/proc/self/fd/0", O_RDONLY);

        strcpy(tyym,ttyname(fd));

    while((entry=readdir(dir)) != NULL)
    {

        if(sscanf(entry->d_name, "%d", &pid) != 1)
        {
            continue;
        }
        sprintf(tt_path,"/proc/%d/stat",pid);
        file = fopen(tt_path, "r");
           fgets(othbuf, sizeof(othbuf),file);
            fclose(file);
            char*toke1 = strtok(othbuf, " ");
            for(int it=1;it<6;it++)
            {
                toke1 = strtok(NULL, " ");
            }
            long ssid = atol(toke1);
            if(ssid == pid){
                continue;
            }

        sprintf(tt_path,"/proc/%d/fd/0",pid);
         fd = open(tt_path, O_RDONLY);
         printf("%7d",pid);

         if(ttyname(fd) != NULL)
         {
        strcpy(tyy,ttyname(fd));
        char final[200];
            int ii=0;
            while(tyy[ii+5] != '\0')
            {
                final[ii] = tyy[ii+5];
                ii++;
            }
            final[ii]='\0';
            printf(" %-9s",final);
            
         } 
         else{
            printf(" %-9c",'?');
         }   
            snprintf(tt_path,300,"/proc/%d/stat",pid);
            file=fopen(tt_path, "r");
            if(!file)
            {
                printf("Error: Could not open file\n");
                return 0;
            }
            fgets(othbuf, sizeof(othbuf),file);
            fclose(file);
            char*toke = strtok(othbuf, " ");
            for(int it=1;it<14;it++)
            {
                toke = strtok(NULL, " ");
            }
            long utime = atol(toke);
            toke = strtok(NULL, " ");
            long stime = atol(toke);
            long tot_time = utime + stime;
            printf("%16ld",tot_time/ sysconf(_SC_CLK_TCK));
            snprintf(tt_path,300, "/proc/%d/exe", pid);
            

            char flag;
            int i;
            sprintf(tt_path,"/proc/%d/stat",pid);
            file = fopen(tt_path, "r");
            fscanf(file, "%d%s", &i, cmd);
            cmd[strlen(cmd)-1]='\0';
            printf(" %s\n",cmd+1);
            
    }
  
    return 0;
}