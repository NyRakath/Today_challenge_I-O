// C program that does not suspend when
// Ctrl+Z is pressed
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
  
// Signal Handler for SIGTSTP
void sighandler(int sig_num)
{
    /** Reset handler to catch SIGTSTP next time */
    
    signal(SIGQUIT, sighandler);
    signal(SIGINT, sighandler);
    signal(SIGTSTP, sighandler);
}
  
int main()
{
    /** Set the SIGTSTP (Ctrl-Z) signal handler 
     * to sigHandler */
    signal(SIGTSTP, sighandler);
    // signal(SIGINT, sighandler);  
    while(1)
    {
    }
    return 0;
    
}