#include "main.h"
/**
 * uz_sh - executes a command in a child process
 * @ch_pid: pid_t
 * @buffer: char *
 * @args: char *
 * @argv: char *
 * Return: -1 if failure 0 otherwise
 */
int uz_sh(pid_t ch_pid, char *buffer, char *args[], char *argv)
{
int status;
if (ch_pid == -1)
{
perror("Error in fork");
return (-1);
}
else if (ch_pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror(argv);
free(buffer);
exit(2);
}
}
else
{
wait(&status);
return (status / 256);
}
return (0);
}
