
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

#include "command.h"

SimpleCommand::SimpleCommand()
{
    // Creat available space for 5 arguments
    _numberOfAvailableArguments = 5;
    _numberOfArguments = 0;
    _arguments = (char **) malloc( _numberOfAvailableArguments * sizeof( char * ) );
}

void
SimpleCommand::insertArgument( char * argument )
{
    if ( _numberOfAvailableArguments == _numberOfArguments  + 1 ) {
        // Double the available space
        _numberOfAvailableArguments *= 2;
        _arguments = (char **) realloc( _arguments,
                                        _numberOfAvailableArguments * sizeof( char * ) );
    }

    _arguments[ _numberOfArguments ] = argument;

    // Add NULL argument at the end
    _arguments[ _numberOfArguments + 1] = NULL;

    _numberOfArguments++;
}

Command::Command()
{
    // Create available space for one simple command
    _numberOfAvailableSimpleCommands = 1;
    _simpleCommands = (SimpleCommand **)
            malloc( _numberOfSimpleCommands * sizeof( SimpleCommand * ) );

    _numberOfSimpleCommands = 0;
    _outFile = 0;
    _inputFile = 0;
    _errFile = 0;
    _background = 0;
    _append = 0;
}

void
Command::insertSimpleCommand( SimpleCommand * simpleCommand )
{
    if ( _numberOfAvailableSimpleCommands == _numberOfSimpleCommands ) {
        _numberOfAvailableSimpleCommands *= 2;
        _simpleCommands = (SimpleCommand **) realloc( _simpleCommands,
                                                      _numberOfAvailableSimpleCommands * sizeof( SimpleCommand * ) );
    }

    _simpleCommands[ _numberOfSimpleCommands ] = simpleCommand;
    _numberOfSimpleCommands++;
}

void
Command:: clear()
{
    for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
        for ( int j = 0; j < _simpleCommands[ i ]->_numberOfArguments; j ++ ) {
            free ( _simpleCommands[ i ]->_arguments[ j ] );
        }

        free ( _simpleCommands[ i ]->_arguments );
        free ( _simpleCommands[ i ] );
    }

    if ( _outFile ) {
        free( _outFile );
    }

    if ( _inputFile ) {
        free( _inputFile );
    }

    if ( _errFile ) {
        free( _errFile );
    }

    _numberOfSimpleCommands = 0;
    _outFile = 0;
    _inputFile = 0;
    _errFile = 0;
    _background = 0;
    _append = 0;
}

void
Command::print()
{
    printf("\n\n");
    printf("              COMMAND TABLE                \n");
    printf("\n");
    printf("  #   Simple Commands\n");
    printf("  --- ----------------------------------------------------------\n");

    for ( int i = 0; i < _numberOfSimpleCommands; i++ ) {
        printf("  %-3d ", i );
        for ( int j = 0; j < _simpleCommands[i]->_numberOfArguments; j++ ) {
            printf("\"%s\" \t", _simpleCommands[i]->_arguments[ j ] );
        }
    }

    printf( "\n\n" );
    printf( "  Output       Input        Error        Background\n" );
    printf( "  ------------ ------------ ------------ ------------\n" );
    printf( "  %-12s %-12s %-12s %-12s\n", _outFile?_outFile:"default",
            _inputFile?_inputFile:"default", _errFile?_errFile:"default",
            _background?"YES":"NO");
    printf( "\n\n" );

}

void
Command::execute() {
    // Don't do anything if there are no simple commands
    if (_numberOfSimpleCommands == 0) {
        prompt();
        return;
    }

    printf("hey there\n");
    // Print contents of Command data structure
    print();

    int defaultin = dup(0);
    int defaultout = dup(1);
    int defaulterr = dup(2);
    int inFd, outFd, errFd;

    if (_inputFile) {
        inFd = open(_inputFile, O_RDONLY);
        if (inFd < 0) {
            perror("ls : create infile");
            exit(2);
        } else
            dup2(inFd, 0);

    }
//problem wih appending to already existing output file
    if (_outFile) {
        if (_append == 1) {
            outFd = open(_outFile, O_APPEND | O_WRONLY);
            if (outFd < 0) {
                perror("ls : create outfile");
                exit(2);
            } else {
                dup2(outFd, 1);
            }
        } else {
            outFd = open(_outFile, O_CREAT | O_WRONLY,0777);
            if (outFd < 0) {
                perror("ls : create outfile");
                exit(2);
            }
        }

        if (_errFile) {
            errFd = creat(_errFile, 0666);
            if (errFd < 0) {
                perror("ls : create errorfile");
                exit(2);
            } else
                dup2(errFd, 2);
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
            exit(2);
            printf("im in baby process");
        }

        dup2(defaultin, 0);
        dup2(defaultout, 1);
        dup2(defaulterr, 2);

        if (!_background) {
            waitpid(pid, 0, 0);
        }
        // Clear to prepare for next command
        clear();
        printf("im the mainprocess\n");



        // Print new prompt
        prompt();
    }
}

// Shell implementation

void
Command::prompt()
{
    printf("myshell>");
    fflush(stdout);
}

Command Command::_currentCommand;
SimpleCommand * Command::_currentSimpleCommand;

int yyparse(void);

int
main()
{
    Command::_currentCommand.prompt();
    yyparse();
    return 0;
}

