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
