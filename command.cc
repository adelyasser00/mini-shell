/*
 * CS354: Shell project
 *
 * Template file.
 * You will need to add more code here to execute the command table.
 *
 * NOTE: You are responsible for fixing any bugs this code may have!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#include <time.h>

#include "command.h"


SimpleCommand::SimpleCommand() {
    // Creat available space for 5 arguments
    _numberOfAvailableArguments = 5;
    _numberOfArguments = 0;
    _arguments = (char **) malloc(_numberOfAvailableArguments * sizeof(char *));
}

void
SimpleCommand::insertArgument(char *argument) {
    if (_numberOfAvailableArguments == _numberOfArguments + 1) {
        // Double the available space
        _numberOfAvailableArguments *= 2;
        _arguments = (char **) realloc(_arguments,
                                       _numberOfAvailableArguments * sizeof(char *));
    }

    _arguments[_numberOfArguments] = argument;

    // Add NULL argument at the end
    _arguments[_numberOfArguments + 1] = NULL;

    _numberOfArguments++;
}

Command::Command() {
    // Create available space for one simple command
    _numberOfAvailableSimpleCommands = 1;
    _simpleCommands = (SimpleCommand **)
            malloc(_numberOfSimpleCommands * sizeof(SimpleCommand *));

    _numberOfSimpleCommands = 0;
    _outFile = 0;
    _inputFile = 0;
    _errFile = 0;
    _background = 0;
    _append = 0;
}

void
Command::insertSimpleCommand(SimpleCommand *simpleCommand) {
    if (_numberOfAvailableSimpleCommands == _numberOfSimpleCommands) {
        _numberOfAvailableSimpleCommands *= 2;
        _simpleCommands = (SimpleCommand **) realloc(_simpleCommands,
                                                     _numberOfAvailableSimpleCommands * sizeof(SimpleCommand *));
    }

    _simpleCommands[_numberOfSimpleCommands] = simpleCommand;
    _numberOfSimpleCommands++;
}

void
Command::clear() {
    for (int i = 0; i < _numberOfSimpleCommands; i++) {
        for (int j = 0; j < _simpleCommands[i]->_numberOfArguments; j++) {
            free(_simpleCommands[i]->_arguments[j]);
        }

        free(_simpleCommands[i]->_arguments);
        free(_simpleCommands[i]);
    }

    if (_outFile) {
        free(_outFile);
    }

    if (_inputFile) {
        free(_inputFile);
    }

    if (_errFile) {
        free(_errFile);
    }

    _numberOfSimpleCommands = 0;
    _outFile = 0;
    _inputFile = 0;
    _errFile = 0;
    _background = 0;
    _append = 0;
}

void
Command::print() {
    printf("\n\n");
    printf("              COMMAND TABLE                \n");
    printf("\n");
    printf("  #   Simple Commands\n");
    printf("  --- ----------------------------------------------------------\n");

    for (int i = 0; i < _numberOfSimpleCommands; i++) {
        printf("  %-3d ", i);
        for (int j = 0; j < _simpleCommands[i]->_numberOfArguments; j++) {
            printf("\"%s\" \t", _simpleCommands[i]->_arguments[j]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("  Output       Input        Error        Background\n");
    printf("  ------------ ------------ ------------ ------------\n");
    printf("  %-12s %-12s %-12s %-12s\n", _outFile ? _outFile : "default",
           _inputFile ? _inputFile : "default", _errFile ? _errFile : "default",
           _background ? "YES" : "NO");
    printf("\n\n");

}

void
PrintDebugging(int _numberOfSimpleCommands, SimpleCommand **_simpleCommands) {
    char *c;
    int a;
    printf("---number of simple commands %d---\n", _numberOfSimpleCommands);
    for (int i = 0; i < _numberOfSimpleCommands; i++) {
        printf("%d th command has %d argument\n", i, _simpleCommands[i]->_numberOfArguments);
        a = 0;
        c = _simpleCommands[i]->_arguments[a];
        while (c != NULL) {
            printf("argument-> %s\n", c);
            a++;
            c = _simpleCommands[i]->_arguments[a];
            printf("END OF WHILE-LOOP");
        }
        printf("END OF FOR-LOOP");
    }
    printf("---END OF DEBUGGING PRINT---");
}

void
handler(int sig){
    int pid= wait(NULL);
    int status;
    time_t tim = time(NULL);
    struct tm curr = *localtime(&tim);
    FILE *log = fopen("logfile","a");

        fprintf(log,"%02d-%02d-%02d %02d/%02d/%d\n",curr.tm_sec, curr.tm_min, curr.tm_hour, curr.tm_mday, curr.tm_mon+1, curr.tm_year+1900);
        fprintf(log,"------------------------------------------------------\n");
        fprintf(log ,"%d child process terminated\n", pid);
        printf("%d child process terminated\n", pid);
        fprintf(log,"------------------------------------------------------\n");
        signal(sig, handler);
        

    fclose(log);
    
    //printf("%d child process terminated\n", pid);
    // signal(sig,handler);
}

void
Command::execute() {
    signal(SIGINT, SIG_IGN);
    //signal(SIGCHLD,handler);
    //if exit typed, terminate whole program
    if (_numberOfSimpleCommands == 1 && _simpleCommands[0]->_numberOfArguments == 1 &&
        strcmp(_simpleCommands[0]->_arguments[0], "exit") == 0) {
        exit(0);
    }
    
    
    if (_numberOfSimpleCommands == 0) {
        prompt();
        return;
    }
        // handle cd differently
    if (_numberOfSimpleCommands==1 && _simpleCommands[0]->_numberOfArguments <= 2 && strcmp(_simpleCommands[0]->_arguments[0], "cd") == 0 ){
    printf("cd intercepted\n");
    if (_simpleCommands[0]->_numberOfArguments == 1){
    int ch = chdir(getenv("HOME"));
    }
    else 
    if (chdir(_simpleCommands[0]->_arguments[1]) == -1)
    printf("directory doesn't exist");

    print();
    clear();
    prompt();
    return;
    }
    // Don't do anything if there are no simple commands
    if (_numberOfSimpleCommands == 0) {
        prompt();
        return;
    }
    //printf("# of simple commands %d",_numberOfSimpleCommands);
    // Print contents of Command data structure
    print();
  // PrintDebugging(_numberOfSimpleCommands, _simpleCommands);

    //printf("# of simple commands %d",_numberOfSimpleCommands);
    if (_numberOfSimpleCommands >= 1) {
        // printf("yes # of commands > 1");
       // executePipedCommands();
        int defaultint = dup(0);
        int defaultout = dup(1);
        int defaulterr = dup(2);
        int inFd, outFd, errFd;

        if (_inputFile) {
            inFd = open(_inputFile, O_RDONLY);
            if (inFd < 0) {
                perror("error : create infile");
                exit(2);
            } else
                dup2(inFd, 0);

        } else
            inFd = dup(defaultint);

        if (_errFile) {
            errFd = creat(_errFile, 0666);
            if (errFd < 0) {
                perror("error : create errorfile");
                exit(2);
            } else
                dup2(errFd, 2);
        } else
            errFd = defaulterr;





        pid_t pid;
        for (int i = 0; i < _numberOfSimpleCommands; i++) {
            dup2(inFd,0);
            close(inFd);
//            if (i == 0) {
//                dup2(fdpipe[1], 1);
//                close(fdpipe[1]);
//                dup2(inFd, 0);
//                close(inFd);
//            } else
            if (i == _numberOfSimpleCommands - 1) {
                if (_outFile) {
                    if (_append == 1) {
                        outFd = open(_outFile, O_APPEND | O_WRONLY | O_CREAT, 0666);
                        if (outFd < 0) {
                            perror("error : bad acess to outfile or non existent");
                            exit(2);
                        } else
                            {
                                dup2(outFd, 1);
                                if (_appback == 1)
                                    dup2(outFd,2);
                            }
                    } else {
                        outFd = open(_outFile, O_TRUNC | O_CREAT | O_WRONLY, 0666);
                        if (outFd < 0) {
                            perror("error : bad acess to outfile or non existent\"");
                            exit(2);
                        } else
                            {
                                dup2(outFd, 1);
                                if (_appback == 1)
                                    dup2(outFd,2);
                            }
                    }
                } else {
                    outFd = dup(defaultout);
                }
//                dup2(outFd, 1);
//                close(outFd);
//                dup2(fdpipe[0], 0);
//                close(fdpipe[0]);
            } else {
                int fdpipe[2];
                //bytes written on PIPEDES[1] can be read from PIPEDES[0].
                if (pipe(fdpipe) == -1) {
                    perror("command : pipe");
                    exit(2);
                }
                inFd=fdpipe[0];
                outFd=fdpipe[1];
//                dup2(fdpipe[1], 1);
//                close(fdpipe[1]);
//                dup2(fdpipe[0], 0);
//                close(fdpipe[0]);
            }

            dup2(outFd,1);
            close(outFd);
             pid = fork();
            if (pid == -1) {
                perror("command: fork\n");
                exit(2);
            }

            if (pid == 0) {
//                close(defaultout);
//                close(defaulterr);
//                close(defaultint);
//                close(inFd);
//                close(fdpipe[0]);
//                close(fdpipe[1]);

                execvp(_simpleCommands[i]->_arguments[0], _simpleCommands[i]->_arguments);
                perror("piping error :");
            // signal(SIGCHLD,handler);
                exit(1);
            }
            
//            else {
//                waitpid(pid,0,0);
//            }

        signal(SIGCHLD,handler);

        }

        dup2(defaultint, 0);
        dup2(defaultout, 1);
        dup2(defaulterr, 2);

        // Close file descriptors that are not needed
        close(inFd);
        close(outFd);
        close(errFd);

        if (!_background) {
            waitpid(pid, 0,0);
        }
        signal(SIGCHLD,handler);

    }
    else {
       // executeSimpleCommand();
        int defaultin = dup(0);
        int defaultout = dup(1);
        int defaulterr = dup(2);
        int inFd, outFd, errFd;


//tested and verified, no create needed cuz you cant create the source DOESNT MAKE SENSE
        if (_inputFile) {
            inFd = open(_inputFile, O_RDONLY);
            if (inFd < 0) {
                perror("ls : create infile");
                exit(2);
            } else
                dup2(inFd, 0);

        }
//works perfectly fine if file already created or not , for overwrite and append
        if (_errFile) {
            errFd = creat(_errFile, 0666);
            if (errFd < 0) {
                perror("ls : create errorfile");
                exit(2);
            } else
                dup2(errFd, 2);
        }
        
        if(_outFile){
            if (_append == 1){
                outFd = open(_outFile,O_APPEND|O_WRONLY|O_CREAT,0666);
                if ( outFd < 0 ) {
                    perror( "ls : create outfile" );
                    exit( 2 );
                }
                else
                    {
                                dup2(outFd, 1);
                                if (_appback == 1)
                                    dup2(outFd,2);
                            }
            }
            else{
                outFd = open(_outFile,O_TRUNC | O_CREAT|O_WRONLY,0666);
                if ( outFd < 0 ) {
                    perror( "ls : create outfile" );
                    exit( 2 );
                }
                else
                    {
                                dup2(outFd, 1);
                                if (_appback == 1)
                                    dup2(outFd,2);
                            }
                            }
        }

        


        int pid = fork();
        if (pid == 0) {
            close(inFd);
            close(outFd);
            close(errFd);
            close(defaultin);
            close(defaultout);
            close(defaulterr);

            int status = execvp(_simpleCommands[0]->_arguments[0], _simpleCommands[0]->_arguments);
            perror("error :");
            // signal(SIGCHLD,handler);
            exit(2);
        }
        

        dup2(defaultin, 0);
        dup2(defaultout, 1);
        dup2(defaulterr, 2);

        close( outFd );
        close( defaultin );
        close( defaultout );
        close( defaulterr );
        // sleep(100000);
        if (!_background) {
            waitpid(pid, 0, 0);
        }
        signal(SIGCHLD,handler);
    }

    clear();

    // Print new prompt
    prompt();
}



// Shell implementation

void
Command::prompt() {
    char cwd[256];
    getcwd(cwd,256);
    printf("myshell>%s ",cwd);
    fflush(stdout);
}

Command Command::_currentCommand;
SimpleCommand *Command::_currentSimpleCommand;

int yyparse(void);

int
main() {
    Command::_currentCommand.prompt();
    yyparse();
    return 0;
}
