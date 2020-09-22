#ifndef _TRATADIR_H_
#define _TRATADIR_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include "readfile.h"

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

DIR *d;
struct dirent *dir;

void trata_dir(char *directory);
void trata_dir_compact(char *directory);
void trata_dir_compact_bi(char *directory);
void trata_dir_bi(char *directory);

#endif