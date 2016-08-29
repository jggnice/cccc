#include<stdio.h> 
#include <unistd.h>
int main()
{
    int pid = 0;
    int CurrentProcess;
    /// The variable will be copied for each process.
    pid++;
    CurrentProcess = fork();
    pid++;
    CurrentProcess = fork();
    pid++;
    ///  The following will sequently run twice.
    /// The variable will be copied for each process.
    {
        CurrentProcess = fork();
        ///  The following will sequently run twice.
        /*
        if(!CurrentProcess)
        {
           printf("In the child process :\n");
           pid = getpid();
           printf("%d\n", pid);
        }
        else
        {
           printf("In the current process :\n");
           pid = getpid();
           printf("%d\n", pid);
        }
        */
         printf("%d\n", ++pid);
        return 0;
    }
}
