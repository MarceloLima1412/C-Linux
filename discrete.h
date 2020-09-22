#ifndef _DISCRETE_H_
#define _DISCRETE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

ssize_t read_res;

int discrete(char *filename, char *numbers);
int discrete_bi(char *filename, char *numbers);


#endif