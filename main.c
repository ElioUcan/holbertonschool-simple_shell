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
if (ch_pid == -1)
{
perror("Error in fork");
return (-1);
}
else if (ch_pid == 0)
{
if (execve(buffer, args, NULL) == -1)
{
perror(argv);
free(buffer);
exit(1);
}
}
else
{
wait(NULL);
return (0);
}
return (0);
}


/**
 * main - runs the simple shell
 * @argc: int
 * @argv: char *
 * Return: 0 if success, otherwise -1
 */
int main(int argc, char *argv[])
{
char *buffer = NULL;
char *args[2];
ssize_t line;
size_t bufsize = 0;
pid_t ch_pid;
int gb;

if (argc == 1)
{
while (1)
{
if (isatty(STDIN_FILENO))
printf("UZ$ ");

line = getline(&buffer, &bufsize, stdin);

if (line == -1)
{
free(buffer);
putchar('\n');
return (0);
}
args[0] = buffer;
args[1] = NULL;
buffer[line - 1] = '\0';
if (buffer[0] == '\0')
continue;

ch_pid = fork();
gb = uz_sh(ch_pid, buffer, args, argv[0]);
if (gb == -1)
return (0);
}
}
return (0);
}
