#include "main.h"
/**
 * check_builtins - checks if the command is a built-in and executes it
 * @args: char *
 * @buffer: char *
 * @env: char *
 * @exit_status: int
 * Return: 1 if a built-in was executed, 0 otherwise
 */
int check_builtins(char *args[], char *buffer, char *env[], int exit_status)
{
int i;
if (strcmp(args[0], "exit") == 0)
{
free(buffer);
exit(exit_status);
}
if (strcmp(args[0], "env") == 0)
{
for (i = 0; env[i] != NULL; i++)
{
printf("%s\n", env[i]);
}
return (1);
}
return (0);
}
