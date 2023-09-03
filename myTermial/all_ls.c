#include "myheader.h"
char *getpermission(mode_t a, char *permission)
{
    (S_ISDIR(a)) ? strcpy(permission, "d") : strcpy(permission, "-");
    ((a & S_IRUSR) ? strcat(permission, "r") : strcat(permission, "-"));
    ((a & S_IWUSR) ? strcat(permission, "w") : strcat(permission, "-"));
    ((a & S_IXUSR) ? strcat(permission, "x") : strcat(permission, "-"));
    ((a & S_IRGRP) ? strcat(permission, "r") : strcat(permission, "-"));
    ((a & S_IWGRP) ? strcat(permission, "w") : strcat(permission, "-"));
    ((a & S_IXGRP) ? strcat(permission, "x") : strcat(permission, "-"));
    ((a & S_IROTH) ? strcat(permission, "r") : strcat(permission, "-"));
    ((a & S_IWOTH) ? strcat(permission, "w") : strcat(permission, "-"));
    ((a & S_IXOTH) ? strcat(permission, "x") : strcat(permission, "-"));
    return permission;
}
int gethumred_char(int a)
{
    int t = 0;
    while (a > 1024)
    {
        a = a / 1024;
        t++;
    }
    return t;
}
int gethumred_int(int a)
{
    double b = a;
    while (b > 1024)
    {
        b = b / 1024;
    }
    while (a > 1024)
    {
        a = a / 1024;
    }
    double c = (double)a;
    if (b > a)
    {
        return a + 1;
    }
    else
    {
        return a;
    }
}
void call_ls(char *s1, char *s2, char *s3)
{
    char permission[20];
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char pathname[900];
    getcwd(pathname, sizeof(pathname));
    struct dirent *content;
    struct stat filearr[200];
    char *filename[200];

    if ((strcmp(s1, "ls") == 0) && (s2 == NULL))
    {
        // DIR *opendir(const char *name);
        DIR *current = opendir(pathname);

        int kno = 0;
        while ((content = readdir(current)) != NULL)
        {
            if (((strcmp(content->d_name, "..") != 0) && (strcmp(content->d_name, ".") != 0)))
            {
                printf("%s  ", content->d_name);
                kno++;
            }
        }
        printf("\n");
    }
    if ((strcmp(s1, "ls") == 0) && (s2 != NULL) && (s3 == NULL))
    {
        if ((strcmp(s2, "-a") == 0))
        {
            // DIR *opendir(const char *name);
            DIR *current = opendir(pathname);

            int kno = 0;
            while ((content = readdir(current)) != NULL)
            {
                // if(((strcmp(content->d_name,"..") != 0) && (strcmp(content->d_name,".") != 0 )))
                //{
                printf("%s  ", content->d_name);
                kno++;
                //}
            }
        }
        if ((strcmp(s2, "-l") == 0))
        {
            // DIR *opendir(const char *name);
            DIR *current = opendir(pathname);

            int kno = 0;
            while ((content = readdir(current)) != NULL)
            {
                if (((strcmp(content->d_name, "..") != 0) && (strcmp(content->d_name, ".") != 0)))
                {
                    filename[kno] = content->d_name;
                    stat(content->d_name, &filearr[kno]);
                    kno++;
                }
            }
            for (int i = 0; i < kno; i++)
            {

                printf("%s", getpermission(filearr[i].st_mode, permission));
                printf("%2lu", filearr[i].st_nlink);
                struct passwd *user = getpwuid(filearr[i].st_uid);
                struct passwd *group = getpwuid(filearr[i].st_gid);
                time_t time = filearr[i].st_mtime;
                struct tm *localTime = localtime(&time);
                int month = localTime->tm_mon;
                int mday = localTime->tm_mday;
                int hour = localTime->tm_hour;
                int minute = localTime->tm_min;
                printf("%*s %*s %*ld %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 15, filearr[i].st_size, 10, months[month], mday, hour, minute, filename[i]);
                printf("\n");
            }
        }
        if ((strcmp(s2, "-s") == 0))
        {
            DIR *current = opendir(pathname);

            int kno = 0;
            long int blocksz;
            while ((content = readdir(current)) != NULL)
            {
                if (((strcmp(content->d_name, "..") != 0) && (strcmp(content->d_name, ".") != 0)))
                {
                    filename[kno] = content->d_name;
                    stat(content->d_name, &filearr[kno]);
                    kno++;
                }
            }
            if (kno >= 1)
            {
                blocksz = filearr[0].st_blksize;
            }
            int total = 0;
            for (int i = 0; i < kno; i++)
            {
                if (((filearr[i].st_size) % 4096) == 0)
                {
                    total = total + 4 * (filearr[i].st_size / blocksz);
                }
                else
                {
                    total = total + 4 * (filearr[i].st_size / blocksz + 1);
                }
            }

            printf("total %d\n", total);

            for (int i = 0; i < kno; i++)
            {
                if (((filearr[i].st_size) % 4096) == 0)
                {
                    printf("%5ld  %s", 4 * (filearr[i].st_size / 4096), filename[i]);
                    printf("\n");
                }
                else
                {
                    printf("%5ld  %s", 4 * ((filearr[i].st_size / 4096) + 1), filename[i]);
                    printf("\n");
                }
            }
        }
        if ((strcmp(s2, "-r") == 0))
        {
            // DIR *opendir(const char *name);
            DIR *current = opendir(pathname);

            int kno = 0;
            while ((content = readdir(current)) != NULL)
            {
                if (((strcmp(content->d_name, "..") != 0) && (strcmp(content->d_name, ".") != 0)))
                {
                    filename[kno] = content->d_name;
                    stat(content->d_name, &filearr[kno]);
                    kno++;
                }
            }
            for (int i = kno - 1; i >= 0; i--)
            {
                printf("%s", getpermission(filearr[i].st_mode, permission));
                printf("%2lu", filearr[i].st_nlink);
                struct passwd *user = getpwuid(filearr[i].st_uid);
                struct passwd *group = getpwuid(filearr[i].st_gid);
                time_t time = filearr[i].st_mtime;
                struct tm *localTime = localtime(&time);
                int month = localTime->tm_mon;
                int mday = localTime->tm_mday;
                int hour = localTime->tm_hour;
                int minute = localTime->tm_min;
                printf("%*s %*s %*ld %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 15, filearr[i].st_size, 10, months[month], mday, hour, minute, filename[i]);
                printf("\n");
            }
        }
        if ((strcmp(s2, "-lh") == 0))
        {
            // DIR *opendir(const char *name);
            DIR *current = opendir(pathname);

            int kno = 0;
            while ((content = readdir(current)) != NULL)
            {
                if (((strcmp(content->d_name, "..") != 0) && (strcmp(content->d_name, ".") != 0)))
                {
                    filename[kno] = content->d_name;
                    stat(content->d_name, &filearr[kno]);
                    kno++;
                }
            }
            for (int i = 0; i < kno; i++)
            {
                printf("%s", getpermission(filearr[i].st_mode, permission));
                printf("%2lu", filearr[i].st_nlink);
                struct passwd *user = getpwuid(filearr[i].st_uid);
                struct passwd *group = getpwuid(filearr[i].st_gid);
                time_t time = filearr[i].st_mtime;
                struct tm *localTime = localtime(&time);
                int month = localTime->tm_mon;
                int mday = localTime->tm_mday;
                int hour = localTime->tm_hour;
                int minute = localTime->tm_min;
                switch (gethumred_char(filearr[i].st_size))
                {
                case 0:
                    printf("%*s %*s %*d %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 15, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                case 1:
                    printf("%*s %*s %*dK %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                case 2:
                    printf("%*s %*s %*dM %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                case 3:
                    printf("%*s %*s %*dG %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");
                    break;
                case 4:
                    printf("%*s %*s %*dT %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                }
            }
        }
        if ((strcmp(s2, "-lhS") == 0))
        {
            // DIR *opendir(const char *name);
            DIR *current = opendir(pathname);

            int kno = 0;
            while ((content = readdir(current)) != NULL)
            {
                if (((strcmp(content->d_name, "..") != 0) && (strcmp(content->d_name, ".") != 0)))
                {
                    filename[kno] = content->d_name;
                    stat(content->d_name, &filearr[kno]);
                    kno++;
                }
            }
            for (int i = 0; i < kno; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (filearr[j].st_size < filearr[i].st_size)
                    {
                        struct stat temp;
                        temp = filearr[i];
                        filearr[i] = filearr[j];
                        filearr[j] = temp;
                    }
                }
            }
            for (int i = 0; i < kno; i++)
            {
                printf("%s", getpermission(filearr[i].st_mode, permission));
                printf("%2lu", filearr[i].st_nlink);
                struct passwd *user = getpwuid(filearr[i].st_uid);
                struct passwd *group = getpwuid(filearr[i].st_gid);
                time_t time = filearr[i].st_mtime;
                struct tm *localTime = localtime(&time);
                int month = localTime->tm_mon;
                int mday = localTime->tm_mday;
                int hour = localTime->tm_hour;
                int minute = localTime->tm_min;
                switch (gethumred_char(filearr[i].st_size))
                {
                case 0:
                    printf("%*s %*s %*d %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 15, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                case 1:
                    printf("%*s %*s %*dK %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                case 2:
                    printf("%*s %*s %*dM %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                case 3:
                    printf("%*s %*s %*dG %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");
                    break;
                case 4:
                    printf("%*s %*s %*dT %*s %02d %02d:%02d %s\n", 10, user->pw_name, 10, group->pw_name, 14, gethumred_int(filearr[i].st_size), 10, months[month], mday, hour, minute, filename[i]);
                    printf("\n");

                    break;
                }
            }
        }
    }
}