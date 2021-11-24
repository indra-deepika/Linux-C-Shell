#include "headers.h"

void sig(char *token[])
{
     if(token[3]!= NULL)
     {
         red();
         printf("Error:Incorrect number of arguments\n");
         reset();
     }
     else
     {
        int no= atoi(token[1]);
        int signum = atoi(token[2]);

        int flag=0;

        for(int i=0; i<=ac_jb; i++)
        {
            if(jb[i].no==no)
            {
                flag=1;
                kill(jb[i].pid,signum);
            }
        }

        if(flag==0)
        {
            red();
            printf("Error: No such job number\n");
            reset();
        }
     }

}