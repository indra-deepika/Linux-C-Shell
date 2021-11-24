# Running the Shell
 In order to run the shell run the following command.
  ``` 
  make
  ./a.out
  ```

# Functions Implenented 

- cd
- pwd
- ls
- history
- echo
- pinfo
- repeat
- piping
- redirection
- control
- fg 
- bg
- signal handling
- replay


# Files 

- main.c
   It contains the functions 
   - removeSubstr  -  deletes a subtring 
   - delete_pro - Stored background is removed after completiom
   - if_done - Cheks if any of the background process are running
   - display - displays the prompt
   - pwd - Prints the current working directoy
   - command - Checks what command is being given as an input and directs to the corresponding function.
 
- cd.c 
   Implements  basic functionality and the flags  “.”, “..”, “-” and “~"
- ls.c
   It contains the functions :
   - ls_l  - when only l flag is implemented
   - ls_a - when only a flag is implemented 
   - ls_al_la -  when l and a both flags are implemented
   - ls_ - when there is no flag
   - format - ls -l format is printed 

- echo.c
- pinfo.c
- repeat.c
- history.c
   It contains the functions :
   - st_hist - stores the commands given (maximum 20)
   - history - prints the history (maximum 10 )
- background.c
- foreground.c
- headers.h - Contains all the headers<br><br><br>
---------- PART 2 -------- <br><br>
- redirect.c
    It contains the functions:
    - check_redirection - If redirection exits then it handles it , >> - gets appended , >  - gets overwritten
- piping.c
    It contains functions:
    - check_piping - checks if the commands has any pipes
    - piping - if pipes exists then it handles the command
- fg.c
    It contains the functions :
    - fg - Brings the running or stopped background job corresponding to job number to the foreground, and changes its state to running

- bg.c
   It contains the function :
   - bg -  Changes the state of a stopped background job to running (in the background)
- jobs.c
   It contains the function :
   - a_jobs - This command prints a list of all currently running background processes spawned by the shell in alphabetical order of the command name, along with their job number , process ID and their state, which can either be running or stopped .
   - jobs - handles the case when there are flags in the command .If the flag specified is -r, then prints only the running processes else if the flag is -s then prints the stopped processes only.
- sig.c
      It contains the functions:
      - sig - Takes the job number (assigned by your shell) of a running job and sends the signal corresponding to signal number to that process.
- control.c 
    It contains the function :
    - ctrl_z: Pushes any currently running foreground job into the background, and change its state from running to stopped when ctrl Z  is executed.
    - ctrl_c: Interrupts any currently running foreground job, by sending it the SIGINT signal when Ctrl C is executed.
    - ctrl_d: Logs you  of the shell when ctrl D is executed.
- replay.c
   It contains the function:
   - replay : Executes a particular command in fixed time interval for a certain period.
