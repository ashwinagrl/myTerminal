#include "myheader.h"

int ops()
{
    char tyym[600];
    char tyy[600];
    char tt_path[300];
    char othbuf[2000];
    DIR *dir;
    FILE *file;
    struct dirent *entry;
    char path[1024], buf[1024], cmd[1024];
    int pid;

    dir = opendir("/proc");
    if (!dir)
    {
        printf("Failed to open directory");
        return 0;
    }
    printf("%7s%4s%14s%4s\n", "PID", "TTY", "TIME", "CMD");

    int fd = open("/proc/self/fd/0", O_RDONLY);
    strcpy(tyym, ttyname(fd));
    while ((entry = readdir(dir)) != NULL)
    {

        if (sscanf(entry->d_name, "%d", &pid) != 1)
        {
            continue;
        }
        sprintf(tt_path, "/proc/%d/fd/0", pid);
        fd = open(tt_path, O_RDONLY);
        if (ttyname(fd) != NULL)
        {
            strcpy(tyy, ttyname(fd));
            if ((strcmp(tyym, tyy)) == 0)
            {
                char final[200];
                int ii = 0;
                while (tyy[ii + 5] != '\0')
                {
                    final[ii] = tyy[ii + 5];
                    ii++;
                }
                final[ii] = '\0';
                snprintf(tt_path, 300, "/proc/%d/stat", pid);
                file = fopen(tt_path, "r");
                if (!file)
                {
                    printf("Error: Could not open file\n");
                    return 0;
                }
                fgets(othbuf, sizeof(othbuf), file);
                fclose(file);
                char *toke = strtok(othbuf, " ");
                for (int it = 1; it < 14; it++)
                {
                    toke = strtok(NULL, " ");
                }
                long utime = atol(toke);
                toke = strtok(NULL, " ");
                long stime = atol(toke);
                long tot_time = (utime + stime) / sysconf(_SC_CLK_TCK);
                snprintf(tt_path, 300, "/proc/%d/exe", pid);

                ssize_t len1 = readlink(tt_path, othbuf, sizeof(othbuf) - 1);
                if (len1 != -1)
                {
                    othbuf[len1] = '\0';
                }
                char timefin[400];
                sprintf(timefin, "%02lu:%02lu:%02lu", (tot_time / 3600) % 3600, (tot_time / 60) % 60, tot_time / 60);
                printf("%7d %s%12s", pid, final, timefin);
                ii = strlen(othbuf);
                int b = 0;
                while (othbuf[ii - 1] != '/')
                {
                    b++;
                    ii--;
                }
                printf(" ");
                for (int ii = 0; ii < b; ii++)
                {
                    printf("%c", othbuf[strlen(othbuf) - b + ii]);
                }
                printf("\n");
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}