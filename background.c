#include "headers.h"
int comparator(const void* p, const void* q)
{
    return strcmp(((struct jobs*)p)->name,
                  ((struct jobs*)q)->name);
}

pid_t pid;
void background(char *token[], int count)
{ 
  pid = fork();
  setpgid(0, 0);
   token[count-1]=NULL;
  if (pid < 0)
    perror("Error:\n");
  else if (pid == 0)
  {
  
    int z = execvp(token[0], token);  

    if (z < 0)
      perror("Error:\n");
 
   exit(0);
   
  }
  else 
  {
    int k;  
    pid_t pi = waitpid(-1,&k,WNOHANG);

    
       strcpy(jb[ac_jb].name, token[0]);
       jb[ac_jb].pid =  pid;
       jbno++;
      jb[ac_jb].no=  jbno;
      ac_jb++;
       printf("[%d] %d  %s\n",jbno,pid, token[0]);

         qsort(jb, ac_jb, sizeof(struct jobs), comparator);
  }

  return;
}