#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include  <stdio.h>

int main(int argc, char *argv[], char *env[]);
int uz_sh(pid_t ch_pid, char *buffer, char *args[], char *argv);
int handle_execution(char *args[], char *env[], char *argv_0, char *buffer);
void tokenize_input(char *buffer, char *args[]);
char *uz_path(char *env[], char *args[]);

#endif
