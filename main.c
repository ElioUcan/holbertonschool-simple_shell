#include "main.h"

/**
 * uz_path - gives the PATH
 * @env: char *
 * @args: char *
 * Return: char
 */

char *uz_path(char *env[], char *args[])
{
char *path_copy;
char *dir_token;
char *path_comp;
int i = 0;
while (env[i])
{
if (strncmp(env[i], "PATH=", 5) == 0)
{
path_copy = strdup(env[i] + 5);
dir_token = strtok(path_copy, ":");

while (dir_token != NULL)
{
path_comp = malloc(sizeof(char) * (strlen(dir_token) + strlen(args[0]) + 2));
if (path_comp == NULL)
return (NULL);

strcpy(path_comp, dir_token);
strcat(path_comp, "/");
strcat(path_comp, args[0]);

if (access(path_comp, X_OK) == 0)
{
free(path_copy);
return (path_comp);
}
free(path_comp);
dir_token = strtok(NULL, ":");
}
free(path_copy);
break;
}
i++;
}
return (NULL);
}

/**
 * tokenize_input - tokenizes the input
 * @buffer: char *
 * @args: char*
 */
void tokenize_input(char *buffer, char *args[])
{
int i = 0;
args[0] = strtok(buffer, " \n\t");
while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " \n\t");
}
}


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
if (execve(args[0], args, NULL) == -1)
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
 * handle_execution - resolves PATH and makes fork
 * @args: char *
 * @env: char *
 * @argv_0:  char *
 * @buffer:  char *
 * Return: 0 if good -1 if bad
 */
int handle_execution(char *args[], char *env[], char *argv_0, char *buffer)
{
char *path_result = NULL;
pid_t ch_pid;
int gb, i = 0, has_slash = 0;
while (args[0][i])
{
if (args[0][i] == '/')
has_slash = 1;
i++;
}
if (has_slash == 0)
{
path_result = uz_path(env, args);
if (path_result == NULL)
{
fprintf(stderr, "%s: 1: %s: not found\n", argv_0, args[0]);
return (127);
}
args[0] = path_result;
}
else if (access(args[0], X_OK) != 0)
{
fprintf(stderr, "%s: 1: %s: not found\n", argv_0, args[0]);
return (127);
}
ch_pid = fork();
gb = uz_sh(ch_pid, buffer, args, argv_0);
if (path_result != NULL)
free(path_result);
return (gb);
}

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
if (strcmp(args[0], "exit") == 0)
{
free(buffer);
exit(exit_status);
}
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
