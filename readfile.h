#ifndef _READFILE_H_
#define _READFILE_H_

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

int count_bytes(char *filename);
int count_bytes_compact(char *filename);
int count_bytes_bi(char *filename);
int count_bytes_compact_bi(char *filename);

#endif