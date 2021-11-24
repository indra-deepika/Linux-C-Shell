#include "headers.h"
void format(char *f, char *file)
{
 
  char form[10000] = "";
  struct stat st;

  stat(f, &st);

  if (stat(f, &st) < 0)
  {
    perror(" ");
    return;
  }

  if (S_ISDIR(st.st_mode))
    strcat(form, "d");
  else
    strcat(form, "-");
  if (st.st_mode & S_IRUSR)
    strcat(form, "r");
  else
    strcat(form, "-");
  if (st.st_mode & S_IWUSR)
    strcat(form, "w");
  else
    strcat(form, "-");
  if (st.st_mode & S_IXUSR)
    strcat(form, "x");
  else
    strcat(form, "-");
  if (st.st_mode & S_IRGRP)
    strcat(form, "r");
  else
    strcat(form, "-");
  if (st.st_mode & S_IWGRP)
    strcat(form, "w");
  else
    strcat(form, "-");
  if (st.st_mode & S_IXGRP)
    strcat(form, "x");
  else
    strcat(form, "-");
  if (st.st_mode & S_IROTH)
    strcat(form, "r");
  else
    strcat(form, "-");
  if (st.st_mode & S_IWOTH)
    strcat(form, "w");
  else
    strcat(form, "-");
  if (st.st_mode & S_IXOTH)
    strcat(form, "x");
  else
    strcat(form, "-");

  long int no;
  no = st.st_nlink;

  long int size;
  size = st.st_size;

  struct passwd *user;
  user = getpwuid(st.st_uid);
  char *user1 = user->pw_name;
  struct group *grp;
  grp = getgrgid(st.st_gid);
  char *grp1;
  grp1 = grp->gr_name;
  char t[25];
  strftime(t, 24, "%b %d %H:%M ", localtime(&st.st_mtime));

  printf("%s\t%ld\t%s\t%s\t%ld\t %s\t%s\n", form, no, user1, grp1, size, t, file);

  return;
}
void ls_(char *dir)
{
  struct dirent **namelist;
  int n, i = 0;
  //printf("   %s  \n",dir);
  n = scandir(dir, &namelist, NULL, alphasort);
  if (n < 0)
  {
    struct stat buffer;

    int exist = stat(dir, &buffer);
    if (exist == 0)
    {
      printf("%s\n", dir);
    }
    else
      perror("scandir");
  }
  char try[1000];
  while (i < n)
  {
    strcpy(try, namelist[i]->d_name);

    if (try[0] == '.')
    {
      i++;
      continue;
    }

    printf("%s \n", namelist[i]->d_name);
    i++;
  }
}
void ls_l(char *dir)
{
   //printf("%s\n",dir);
  struct dirent **namelist;
  int n, i = 0;
  n = scandir(dir, &namelist, NULL, alphasort);

  if (n < 0)
  {
    struct stat buffer;

    int exist = stat(dir, &buffer);
    if (exist == 0)
    {
      char dir1[10000] = "";
      strcat(dir1, ".");
      strcat(dir1, "/");
      strcat(dir1, dir);
      format(dir1, dir);
    }
    else
      perror("scandir");
  }

  else
  {
    char try[1000];
    int total = 0;
    struct stat fs;
    stat(namelist[i]->d_name, &fs);

    while (i < n)
    {
      total += fs.st_blocks;
      strcpy(try, namelist[i]->d_name);

      if (try[0] == '.')
      {
        i++;
        continue;
      }
      char dir1[10000] = "";
      getcwd(dir1, 10000);
      strcat(dir1, "/");
      strcat(dir1, dir);
      strcat(dir1, "/");
      strcat(dir1, namelist[i]->d_name);

      format(dir1, namelist[i]->d_name);
      i++;
    }
  }
}

void ls_a(char *dir)
{
  struct dirent **namelist;
  int n, i = 0;
  n = scandir(dir, &namelist, NULL, alphasort);
  if (n < 0)
    perror("scandir");
  else
  {
    //int i=0;
    while (i < n)
    {
      printf("%s  \n", namelist[i]->d_name);
      free(namelist[i]);
      i++;
    }
    free(namelist);
    printf("\n");
  }
  return;
}

void ls_al_la(char *dir)
{
  struct dirent **namelist;
  int n, i = 0;
  n = scandir(dir, &namelist, NULL, alphasort);

  if (n < 0)
    perror("scandir");

  else
  {
    char try[1000];
    int total = 0;
    struct stat fs;
    stat(namelist[i]->d_name, &fs);

    while (i < n)
    {

      char dir1[10000] = "";
      getcwd(dir1, 10000);
      strcat(dir1, "/");
      strcat(dir1, dir);
      strcat(dir1, "/");
      strcat(dir1, namelist[i]->d_name);

      format(dir1, namelist[i]->d_name);

      i++;
    }
  }
}

void ls(char *token[], int count)
{

 //printf("+++++++++++++++++++++++++++++++++++++++++");
  int loop = 1;
  char *name[1000];
  int dir_c = 0;

  int flag_l = 0;
  int flag_a = 0;
  int flag_al = 0;
  //int flag_tilda=0;

  if (count > 2)
  {

    while (token[loop] != NULL)
    {
      if (strcmp(token[loop], "-a") == 0)
        flag_a = 1;
      else if (strcmp(token[loop], "-l") == 0)
        flag_l = 1;
      else if (strcmp(token[loop], "-al") == 0 || strcmp(token[loop], "-la") == 0)
        flag_al = 1;
      else
      {
        if(strcmp(token[loop],"~")==0)
        {
        
         name[dir_c]=".";
         dir_c++;
        }
        else
        {
         name[dir_c]= token[loop];
         dir_c++;
        }
      }
      loop++;
    }
    //  /printf("%d FFFFFFF",dir_c);

    if(dir_c==0)
    {
      if((flag_a==1 && flag_l==1 )|| flag_al==1 )
            {
            ls_al_la(".");
            }
            else if(flag_l==1)
            {
             ls_l(".");
            }
            else if(flag_a==1)
            {
            ls_a(".");
            }
            else if((flag_a+flag_l+flag_al)==0 )
            {
                ls_(".");
            }
    }
    while(dir_c--)
    {

       if((flag_a==1 && flag_l==1 )|| flag_al==1 )
            {
            ls_al_la(name[dir_c]);
            }
            else if(flag_l==1)
            {
             ls_l(name[dir_c]);
            }
            else if(flag_a==1)
            {
            ls_a(name[dir_c]);
            }
            else if((flag_a+flag_l+flag_al)==0 )
            {
                ls_(name[dir_c]);
            }
    }

    
    
  }

  if (count == 1)
  {
    struct dirent **namelist;
    int n, i = 0;
    n = scandir(".", &namelist, NULL, alphasort);
    if (n < 0)
      perror("scandir");
    else
    {
      char try[1000];
      while (i < n)
      {
        strcpy(try, namelist[i]->d_name);

        if (try[0] == '.')
        {
          i++;
          continue;
        }

        printf("%s  \n", namelist[i]->d_name);
        free(namelist[i]);
        i++;
      }
      free(namelist);
    }
    return;
  }

   if (count == 2)
  {
    if (strcmp(token[1], "-a") == 0)
    {
      char dir[1000] = "";
      strcpy(dir, ".");

      ls_a(dir);
    }

    else if (strcmp(token[1], "-l") == 0)
    {
      char dir[1000] = "";
      strcpy(dir, ".");
      ls_l(dir);
    }
    else if (strcmp(token[1], "-la") == 0 | strcmp(token[1], "-al") == 0)
    {
      char dir[1000] = "";
      strcpy(dir, ".");
      ls_al_la(dir);
    }

    else if (strcmp(token[1], "~") == 0)
    {
      struct dirent **namelist;
      int n, i = 0;
      n = scandir(root_dir, &namelist, NULL, alphasort);
      char try[1000];
      while (i < n)
      {
        strcpy(try, namelist[i]->d_name);

        if (try[0] == '.')
        {
          i++;
          continue;
        }

        printf("%s \n", namelist[i]->d_name);
        i++;
      }
    }
    else
    {
      struct dirent **namelist;
      int n, i = 0;
      n = scandir(token[1], &namelist, NULL, alphasort);
      char try[1000];
      while (i < n)
      {
        strcpy(try, namelist[i]->d_name);

        if (try[0] == '.')
        {
          i++;
          continue;
        }

        printf("%s \n", namelist[i]->d_name);
        i++;
      }
    }
  }
}
