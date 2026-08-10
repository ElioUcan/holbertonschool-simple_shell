#include "main.h"

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
char *args[] = {buffer, NULL};
pid_t ch_pid;

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
buffer[line - 1] = '\0';
if (buffer[0] == '\0')
continue;

ch_pid = fork();
if (ch_pid == -1)
{
perror("Error in fork");
}
else if (ch_pid == 0)
{
if (execve(buffer, args, NULL) == -1)
{
perror(argv[0]);
free(buffer);
exit(1);
}
}
else
{
wait(NULL);
}
}
}
