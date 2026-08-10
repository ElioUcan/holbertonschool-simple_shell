#include "main.h"

/**
 * uz_sh - executes a command in a child process
 * @ch_pid: pid_t
 * @buffer: char *
 * @args: char *
 * @argv: char *
 * Return: void
 */
void uz_sh(pid_t ch_pid, char *buffer, char *args[], char *argv)
{
if (ch_pid == -1)
{
perror("Error in fork");
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
}
}


/**
 * main - prints a hello world message
 * @argc: int
 * @argv: char *
 * Return: 0 if success, otherwise -1
 */
int main(int argc, char *argv[])
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t line;
char *args[2];
pid_t ch_pid;


if (argc == 1)
{
while (1)
{
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
uz_sh(ch_pid, buffer, args, argv[0]);
}
}
return (0);
}
