#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include  <stdio.h>

int main(int argc, char *argv[]);
void uz_sh(pid_t ch_pid, char *buffer, char *args[], char *argv);


#endif
