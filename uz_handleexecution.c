#include "main.h"
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
