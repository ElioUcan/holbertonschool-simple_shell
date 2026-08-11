#include "main.h"
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
