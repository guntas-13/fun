#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buff[256];
    char *argv[64];
    extern char **environ;
    
    for (;;)
    {
        write(1, "\033[1;36mmyshell> $ \033[0m", 23);
        int handle = read(0, buff, 256);
        if (handle <= 0) break;
        
        if (handle > 0 && buff[handle - 1] == '\n')
            buff[handle - 1] = '\0';

        if (buff[0] == '\0') continue;
        if (strcmp(buff, "exit") == 0) break;

        int argc = 0;
        char *token = strtok(buff, " ");
        while (token != NULL && argc < 63)
        {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        if (argc == 0) continue;

        int pid = fork();
        if (pid == 0) // Child process
        {
            if (argv[0][0] != '/') execvp(argv[0], argv);
            else execve(argv[0], argv, environ);
            write(2, "Command not found\n", 18);
            exit(1);
        }
        else // Parent process
        {
            wait(NULL);
        }
    }

    return 0;
}