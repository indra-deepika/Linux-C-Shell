#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/utsname.h>

char root_dir[10000];
char store_prev[10000];
int jbno,ac_jb;
char hist[20][100];

struct jobs{
    char name[1000];
    pid_t pid;
    int no;
};
 
struct jobs jb[100000];

void display();
void pinfo (int k);
void pwd();
void cd(char *inp, int count );
//void echo();
int check_piping(char *inp);
void piping(char *inp);
void red();
void reset();
void sig(char *token[]);
void jobs(char *token[]);
void a_jobs(char *token[]);
void bg(char *token[]);
void fg(char *token[]);
void ls();
void repeat(char *token[], int count);
void ls(char *token[], int count);
void command(char *inp);
void background(char *token[], int count);
void foreground(char *token[], int count);
void cuserid(char username[]);
void st_hist(char *token, int his);
void history(int count);
void ctrl_c(int sig);
void ctrl_z(int sig);
void ctrl_d(int sig);
void fg(char *token[]);
void replay(char *token[],int k);
int comparator(const void* p, const void* q);


void echo(char *token[]);
void  check_redirection(char *new_cmd,char *token[],int num_args);
void delete_pro( int pid , int i);



int his;
int shellpid;
int shellpgid;
int stdo;
int stdi;
#endif