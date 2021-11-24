#include "headers.h"
void red()
{
    printf("\033[1;31m");
}

// void yellow {
//   printf("\033[1;33m");
// }

void reset()
{
    printf("\033[0m");
}
void jobs(char *token[])
{
    if (strcmp(token[1], "-s") == 0)
    {
        for (int index = 0; index < ac_jb; index++)
        {

            pid_t pid = jb[index].pid;

            char file_temp[10000];

            sprintf(file_temp, "/proc/%d/stat", pid);

            int f = open(file_temp, O_RDONLY);
            if (f < 0)
                perror("Error: no such process exists\n");

            FILE *fi;
            fi = fopen(file_temp, "r");

            if (fi == NULL)
                return;

            size_t size = 10000;
            char *str;

            char status[1000];

            int i = 1;
            char token[10000];

            while (fscanf(fi, "%s", token) == 1)
            {
                if (i == 3)
                    strcpy(status, token);

                i++;
            }

            fclose(fi);
            red();
            if (strcmp(status, "T") == 0)
                printf("[%d] Stopped %s  [%d]\n", jb[index].no, jb[index].name, jb[index].pid);
            reset();
        }
    }

    else if (strcmp(token[1], "-r") == 0)
    {
        for (int index = 0; index < ac_jb; index++)
        {

            pid_t pid = jb[index].pid;

            char file_temp[10000];

            sprintf(file_temp, "/proc/%d/stat", pid);

            int f = open(file_temp, O_RDONLY);
            if (f < 0)
                perror("Error: no such process exists\n");

            FILE *fi;
            fi = fopen(file_temp, "r");

            if (fi == NULL)
                return;

            size_t size = 10000;
            char *str;

            char status[1000];

            int i = 1;
            char token[10000];

            while (fscanf(fi, "%s", token) == 1)
            {
                if (i == 3)
                    strcpy(status, token);

                i++;
            }

            fclose(fi);
            red();
            if (strcmp(status, "T") != 0)
                printf("[%d] Running %s  [%d]\n", jb[index].no, jb[index].name, jb[index].pid);
            reset();
        }
    }
}
void a_jobs(char *tokaen[])
{

    for (int index = 0; index < ac_jb; index++)
    {

        pid_t pid = jb[index].pid;

        char file_temp[10000];

        sprintf(file_temp, "/proc/%d/stat", pid);

        int f = open(file_temp, O_RDONLY);
        if (f < 0)
            perror("Error: no such process exists\n");

        FILE *fi;
        fi = fopen(file_temp, "r");

        if (fi == NULL)
            return;

        size_t size = 10000;
        char *str;

        char status[1000];

        int i = 1;
        char token[10000];

        while (fscanf(fi, "%s", token) == 1)
        {
            if (i == 3)
                strcpy(status, token);

            i++;
        }

        fclose(fi);
        red();
        if (strcmp(status, "T") != 0)
            printf("[%d] Running %s  [%d]\n", jb[index].no, jb[index].name, jb[index].pid);
        if (strcmp(status, "T") == 0)
            printf("[%d] Stopped %s  [%d]\n", jb[index].no, jb[index].name, jb[index].pid);

        reset();
    }
}