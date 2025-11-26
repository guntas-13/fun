#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char buff[256];
    for (;;)
    {
        write(1, "\033[1;36mmyshell> $ \033[0m", 25);
        int handle = read(0, buff, 256);
        buff[handle - 1] = '\0'; // Replace newline with null terminator

        int pid = fork();
        if (pid == 0) // Child process
        {
            char *argv[] = {buff, NULL};
            execve(buff, argv, NULL);
            break; // If execve fails, exit child process
        }
        else // Parent process
        {
            wait(NULL); // Wait for child process to finish
        }
    }

    return 0;
}