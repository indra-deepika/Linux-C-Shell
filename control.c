#include "headers.h"
/*void ctrl_c(int sig)
{

    int pid = getpid();
    int currgpid = getpgid(pid);

    if(shellpgid != currgpid)
    {
        kill(pid,SIGINT);
    }

    return;

}*/

/*void ctrl_z(int sig)
{
    int pid = getpid();
    int currgpid = getpgid(pid);


    if(shellpgid != currgpid)
        kill(pid,SIGTSTP);
    return;
}

void ctrl_d(int sig)
{
    printf("\n");
}*/

void ctrl_c(int sig)
{
    // printf("2\n");
    //error = 1;
    printf("\n");
    display();
    fflush(stdout);
}

void ctrl_z(int sig)
{
    // printf("3\n");
    // printf("3\n");
    printf("\n");
    display();
    fflush(stdout);
    
}