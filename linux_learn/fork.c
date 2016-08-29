#include<stdio.h> 
#include <unistd.h>
int main()
{
    int i;
    int pid = 0;
    int CurrentProcess;
    {
        for(i = 0; i < 4; i++)
        {
            CurrentProcess = fork();
            if(!CurrentProcess)
            {
                /// double the child process
                fork();
            }
        }
        printf("In the child process :\n");
        return 0;
    }
}
