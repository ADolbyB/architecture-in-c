/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Using FIFO files to communicate between processes in C:
 * This example will demonstrate how to execute other programs
 * inside this program.
 * 
 * execl(): 'l' stands for 'list' as in a list of command line arguments
 * execlp(): 'l' for 'list' and 'p' for '$PATH' variable to avoid using absolute paths every time.
 * execlpe(): takes a list argument and an environment argument.
 * execvp(): 'v' stands for 'vector', meaning it takes a vector (array) as an argument instead of a list.
 * execvpe(): 'e' stands for 'environment' (can define your own environment)
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define WINDOWS 0                                                       // OS Type Activation
#define LINUX 1
#define VP 1                                                            // Subfunction Activation

#if WINDOWS
    #include <process.h>                                                // Only for Windows OS
#elif LINUX
    #include <unistd.h>                                                 // Only for Linux
#endif


int main(int argc, char *argv[])
{
    char *command[] = {"ping", "google.com", NULL};
    char *env[] = {"TEST=environment variable", NULL};                  // 'e' environment declaration

    printf("\n\n");

    #if WINDOWS
        char *env[] = {"TEST=environment variable", NULL};              // 'e' environment declaration
        #if L
            _execl("C:\\Windows\\System32\\ping.exe", "C:\\Windows\\System32\\ping.exe", "google.com", NULL);
        #elif LP
            _execlp("ping", "ping", "google.com", NULL);                // execlp() uses the $PATH
        #elif LPE
            _execlpe("ping", "ping", "google.com", NULL, env);          // execlpe() takes list arg & env arg.
        #elif VP
            _execvp("ping", command);                                   // execvp() takes path arg & env arg. 
        #elif VPE
            _execvpe("ping", command, env);                             // execvpe() takes vector/array arg & env arg.
        #endif
    #elif LINUX
        #if L
            execl("/usr/bin/ping", "/usr/bin/ping", "google.com", NULL);
        #elif LP
            execlp("ping", "ping", "google.com", NULL);                 // execlp() uses the $PATH
        #elif VP
            execvp("ping", command);                                    // execvp() takes vector/array arg & $PATH arg.
        #endif
    #endif

    int err = errno;                                                    // Saves error in case of crash.
    printf("Ping Process is Finished...\n\n");

    return 0;
}