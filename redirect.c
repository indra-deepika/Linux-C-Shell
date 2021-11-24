#include "headers.h"

void  check_redirection(char *new_cmd,char *token[],int num_args)
{
    int left=-1,left_num=0,right=num_args,right_num=0,append=0;
   for(int i=0; i<num_args; i++)
   {
       if(strcmp(token[i],"<")==0)
       {
           left = i;
           left_num++;
       }
       else if(strcmp(token[i],">")==0)              
       {
           right = i;
           right_num++;
       }
       else if(strcmp(token[i],">>")==0)              
       {
           right = i;
           right_num++;
           append=1;
       }
   }
   
   if(left>0)
   strcpy(token[left],"");
   
   int fd;
   if(right<num_args-1)
   {
   if(append==0)    
   fd = open(token[right+1],O_WRONLY|O_CREAT|O_TRUNC,0644);
   else
   fd = open(token[right+1],O_WRONLY|O_CREAT|O_APPEND,0644);


           if (dup2(fd, STDOUT_FILENO) < 0)
        {
            perror("Unable to duplicate file descriptor.");
            return ;
        }
        close(fd);
   }

   for(int i=right;i<num_args;i++)
   {
       strcpy(token[i]," ");
   }

    strcpy(new_cmd,"");

    for(int i=0; i< num_args; i++)
    {
       strcat(new_cmd,token[i]);
       strcat(new_cmd," ");
    }
}