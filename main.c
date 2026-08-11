#include "main.h"
/**
 * main - runs the simple shell
 * @argc: int
 * @argv: char *
 * @env: char *
 * Return: 0 if success, otherwise -1
 */
int main(int argc, char *argv[], char *env[])
{
char *buffer = NULL;
char *args[64];
ssize_t line;
size_t bufsize = 0;
int exit_status = 0;
(void)argc;
while (1)
{
if (isatty(STDIN_FILENO))
printf("UZ$ ");
line = getline(&buffer, &bufsize, stdin);
if (line == -1)
{
free(buffer);
if (isatty(STDIN_FILENO))
putchar('\n');
return (exit_status);
}
tokenize_input(buffer, args);
if (args[0] != NULL)
{
if (check_builtins(args, buffer, env, exit_status) == 1)
continue;
exit_status = handle_execution(args, env, argv[0], buffer);
if (exit_status == -1)
{
free(buffer);
break;
}
}
}
return (exit_status);
}
