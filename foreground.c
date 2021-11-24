#include "headers.h"
void foreground(char *token[], int count)
{
  
  pid_t pid;
   setpgid(0, 0);
  pid = fork();

  if (pid < 0)
    perror("Error: \n");

  if (pid == 0)
  {
    int z = execvp(token[0], token);
    if (z < 0)
      perror("Error:\n");

    exit(0);
  }
  else
  {
    int status;
    waitpid(pid, &status, WUNTRACED);
    if(WIFSTOPPED(status)){
                int flag=0;
                for(int i=0; i<ac_jb; i++)
                {
                  if(jb[i].pid==pid)
                  flag =1;
                }

               if(flag ==0)
               {
                strcpy(jb[ac_jb].name,token[0]);
                jb[ac_jb].pid = pid;
                jbno++;
                jb[ac_jb].no = jbno;
                ac_jb++;
                  qsort(jb, ac_jb, sizeof(struct jobs), comparator);
               }
            }
  }  
  return;

}