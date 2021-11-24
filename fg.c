
#include "headers.h"
void fg(char *token[])
{

    //printf("Entered");
    if (token[2] != NULL)
    {
        red();
        printf("Error: Incorrect no of arguments\n");
        reset();
    }
    else
    {
        int flag = 0;
        int no = atoi(token[1]);

        for (int i = 0; i < ac_jb; i++)
        {
            //printf("%d %s %d\n",jb[i].no,jb[i].name,jb[i].pid);

            if (jb[i].no == no)
            {
                signal(SIGTTIN, SIG_IGN); //input ingore
                signal(SIGTTOU, SIG_IGN); 
                tcsetpgrp(STDIN_FILENO, jb[i].pid);// fpreground proceess grp id , we change to fg pid
                
                kill(jb[i].pid, SIGCONT);// we are conyinuing the proxcess if halted
                delete_pro(jb[i].pid, jb[i].no); // DELETING THE PROCESS FROM THE BACKGROUND PROC ARRAY
                int status;
                waitpid(jb[i].pid, &status, WUNTRACED);// till terminate  wait

                if (WIFSTOPPED(status))// if stopeed by ctrlz
                { 
                        strcpy(jb[ac_jb].name,token[0]);
                        jb[ac_jb].pid = atoi(token[1]);
                        //jb[countpid].flag = 1;
                        jbno++;
                        jb[ac_jb].no = jbno;
                        ac_jb++;
                        qsort(jb, ac_jb, sizeof(struct jobs), comparator);

                }
                // waitpid(-1, NULL, WUNTRACED);   // WAITING FOR THAT PROCESS TO FINISH EXECUTION
                tcsetpgrp(STDIN_FILENO, getpgrp()); // perent process  change 
                signal(SIGTTIN, SIG_DFL);
                signal(SIGTTOU, SIG_DFL);
                flag = 1;
            }
        }

        if (flag == 0)
        {
            red();
            printf("Error : Incorrect job number\n");
            reset();
        }
    }
}