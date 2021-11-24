#include "headers.h"

void yellow() {
  printf("\033[0;32m");
}
/*void ctrl_c(int sig)
{

    int pid = getpid();
    int currgpid = getpgid(pid);

    if(shellpgid != currgpid)
    {
        kill(pid,SIGINT);
    }

    return;

}
void ctrl_z(int sig)
{
    int pid = getpid();
    int currgpid = getpgid(pid);


    if(shellpgid != currgpid)
        kill(pid,SIGTSTP);
   return;
}

void ctrl_d()
{
    exit(0);
}*/


void removeSubstr(char *string, char *sub)
{
  char *match;
  int len = strlen(sub);
  while ((match = strstr(string, sub)))
  {
    *match = '\0';
    strcat(string, match + len);
  }
}


void delete_pro( int pid , int i)
{
 // printf("%d %d %d", pid , i,jbno);

  for(int j=i+1; j<jbno;j++)
  {
      jb[j-1]= jb[j];;
  }
  ac_jb--;
   //display();
   return;
}


void if_done()
{

  int x;
  pid_t pid = waitpid(-1, &x, WNOHANG);
  

  for(int i=0; i< ac_jb ; i++)
  {

    int in_loop=0;
    int exit = WEXITSTATUS(x);

    if(jb[i].pid == pid)
    {
      in_loop=1;
      
      if (x==0)
      fprintf(stderr,"\n%s with PID %d exited normally\n", jb[i].name, pid);
      else 
      fprintf(stderr,"\n%s with PID %d failed to exit normally\n",jb[i].name, pid);


      delete_pro(pid,i);
     
    }
  }

}

void pwd()
{
  char dir1[10000] = "";
  getcwd(dir1, 10000);
  printf("%s\n", dir1);
}

char root_dir[10000];
void display()
{
  char prompt[20000]="";

  struct utsname uname_pointer;
  uname(&uname_pointer);

  char sysname[10000];
  strcpy(sysname, uname_pointer.sysname);

  char username[10000];
  cuserid(username);
  

  strcat(prompt, "<");
  strcat(prompt, username);
  strcat(prompt, "@");
  strcat(prompt, sysname);
  strcat(prompt, ":");
  strcat(prompt, "~");


  char dir[200000];
  getcwd(dir, 200000);

  removeSubstr(dir, root_dir);

  strcat(prompt, dir);
  strcat(prompt, ">");
  printf("%s ", prompt);
  
  return;
}



void command(char *inp)
{ 
   
  size_t size = 1000;
  char temp[10000] = "";
  strcpy(temp, inp);
  // red();
  // printf("check 0 %s\n",temp);
  // reset();
  char *token2[100],*token[100];
  char *rest = temp;

  int count = 0;

  while ((token2[count] = strtok_r(rest, " \t", &rest)))
  {
    count++;
  }
 
  if( check_piping(inp)==1)
  return;
  
  check_redirection(inp,token2,count);
  
  count=0;
  char *rest2=inp;
  while ((token[count] = strtok_r(rest2, " \t", &rest2)))
  {
    count++;
  }
  
  if (strcmp(token[0], "cd") == 0)
  {
    cd(token[1], count);
  }
  else if (strcmp(token[0], "echo") == 0)
  {

    echo(token);
  }
  else if (strcmp(token[0], "ls") == 0)
  {
    // printf("------------------------------------------------------------ %s, %s, %s",token[0],token[1],token[2]);
    ls(token, count);
  }
  else if (strcmp(token[0], "pwd") == 0)
  {
    pwd();
  }
  else if (strcmp(token[0], "repeat") == 0)
  {
    repeat(token, count);
  }
  else if (strcmp(token[0], "pinfo") == 0)
  { 
    int pid;
    if(token[1]==NULL)
    {
      pid = 0;
    }
    else
    pid = atoi(token[1]);


    pinfo(pid);
  }
  else if(strcmp(token[0], "history") == 0)
  {
    if(token[1]==NULL)
    history(10);
    else 
    history(atoi(token[1]));
  }
  else if(strcmp(token[0], "jobs") == 0)
  {
    if(token[1]!=NULL)
    jobs(token);
    else
    a_jobs(token);
  }
   else if(strcmp(token[0], "sig") == 0)
  {
    sig(token);
  }
   else if(strcmp(token[0], "fg") == 0)
  {
    fg(token);
  }
   else if(strcmp(token[0], "bg") == 0)
  {
    bg(token);
  }
   else if(strcmp(token[0], "replay") == 0)
  {
    replay(token,count);
  }
  else
  {
    //printf(" --here--");
    int i = 0, set = 0;
    while (i < count)
    {
      if (strcmp(token[i],"&")==0)
      {
        set = 1;
        background(token, count);
      }
      i++;
    }
    if (set == 0)
    {
        
      foreground(token, count);
    }
  }
  

}

int main()
{  
  his=0;

  shellpid = getpid();
	shellpgid = getpgid(shellpid);

  signal(SIGCHLD,if_done);
  signal(SIGINT, ctrl_c);
  signal(SIGTSTP, ctrl_z);
  //signal(SIGKILL, ctrl_d);
  
  jbno=0;

  getcwd(root_dir, 10000);
  strcpy(store_prev, root_dir);

 while(1>0)
 {

  display();
  size_t size = 1000;
  char *str;
  char temporary[100];
  if(getline(&str, &size, stdin)<0)
  { printf("\n");
  return 0;
  }
  int length = (int)strlen(str);
  str[length - 1] = '\0';
  strcpy(temporary,str);
  char *token;
  char *rest = str; 

  
  while ((token = strtok_r(rest, ";", &rest)))
  {
    st_hist(temporary,his);
    if(his<20)
    his++;
    else
    his=19;

     int stdo = dup(1), stdi = dup(0);
     command(token);
      dup2(stdo, STDOUT_FILENO);
      close(stdo);
      dup2(stdi, STDIN_FILENO);
     close(stdi);
  }
 }
  //display();
}
