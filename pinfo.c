#include "headers.h"
void pinfo(int k)
{
    pid_t pid = k;
   // printf("%d",k);

    if (k == 0)
    {
        pid = getpid();
    }
    char file_temp[10000];

    //printf("%d",pid);

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
    //getline(&str, &size, fi);

    char status[1000];
    unsigned long long int vir_mem;
    unsigned long long int  exec;
    unsigned long long int pgrp;
    unsigned long long int tpgid;

    int f_b = 0;

    int i = 1;
    char token[10000];
    //token = strtok(str, " ");

    while (fscanf(fi,"%s",token)==1)
    {
        //token = strtok(NULL, " ");

        if (i == 3)
           strcpy(status, token);
        if (i == 5)
        {
          pgrp = atoi(token);
        }
        if (i == 8)
        {  
         tpgid =atoi(token);
        }
        if (i == 23)
        {
           vir_mem =atoi(token);
            break;
        }
        

        i++;
    }

     fclose(fi);
     
   

    if(pgrp == tpgid)
    f_b = 1;


    char fi2[10000];
    sprintf(fi2, "/proc/%d/exe", pid);

    char ca[10000];
    readlink(fi2, ca, 10000);

    if (f_b == 1)
        printf("%d ---- pid\n%s+ ---- status\n%llu ---- memory\n%s ---- executable path\n" ,pid,status, vir_mem, ca);
    else
        printf("%d ---- pid\n%s ---- status\n%llu ---- memory\n%s ---- executable path\n",pid,status, vir_mem, ca);
}