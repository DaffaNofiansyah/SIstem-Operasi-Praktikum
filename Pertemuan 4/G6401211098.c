#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();
    if (child == 0)
    {
        while (1)
        {
            puts("start");
            sleep(1);
        }
    }
    else
    {
        sleep(4);
        kill(child, SIGSTOP);
        sleep(3);
        kill(child, SIGCONT);
        sleep(2);
        kill(child, SIGTERM);
    }
    return 0;
}