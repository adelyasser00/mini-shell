# MINI-SHELL
### Developed by 6848 Adel Yasser and 6207 Hayam Hiba


#### Overview
mini-shell program on ubuntu using lex, yacc and c code.
mini-shell is designed to operate just like the normal linux shell and run all the commands entered.


#### Prerequisites
<bold>This application was desgined to run on Linux based systems.</bold>
You can either use ubuntu linux OS or you could install wsl on a windows OS machine.

to run the <bold>makefile</bold>, please install make on your system using 
sudo apt install make.
make sure to also install any g++ compiler of your liking for the makefile

#### Instructions
Right-click in the project directory and open it in terminal.
enter the command <bold>make</bold>
once its done, run the command <bold>"./shell"</bold>

<italic><bold>You have successfully opened the mini-shell!</bold></italic>

Please insert any command you'd like just like the original shell terminal.
interrupt signals like ctrl+c and exit are also implemented.
you could also change directory from inside the mini-shell using the <bold>cd</bold> command.


#### Code

###### Lex: shell.l
our lexical analyzer shell.l contains a dictionary of all the expressions that are tokenizable with their respective mapping to the yacc file

###### Yacc: shell.y
our yacc compiler shell.y contains all the appropriate tokenizations for every expression that can be input to the terminal.
This is handled accordingly by setting all the appropriate variables and calling the respective functions developed in the command.cc file.

###### C: command.cc and command.h
First, the command.h header file contains all the structures for each command and each simple command when they will be used in the command.cc c file
Then, the command.cc handles the processing for each command inserted whether it is 0 commands or more including any piped commands.
A for loop is implemented to appropriately set all the input and output redirections accordingly. especially during the execution of the last simple command.
calling a background operation using & will result in the parent function not waiting for its previous command to finish executing.

#### Makefile
The makefile when run creates all the necessary lex and yacc processing files as well as the <bold>shell</bold> we run.