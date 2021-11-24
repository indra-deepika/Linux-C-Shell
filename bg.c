#include "headers.h"

void bg(char *token[])
{
    int no=atoi(token[1]);
    int flag=0;

    if(token[2]!=NULL)
    printf("Error : Incorrect number of arguments");
   else
      {
  
   for(int i=0;i<ac_jb; i++)
   {
        if(jb[no].no==i)
        {
        kill(jb[no].pid,SIGCONT);
        flag = 1;
        }
   }
   if(flag == 0)
   printf("Error: Wrong job number");
   }
   
}
