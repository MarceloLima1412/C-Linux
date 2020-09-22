#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "tratadir.h"
#include "memory.h"

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

void trata_dir(char *directory)
{
    d = opendir(directory);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            count_bytes(dir->d_name);
        }
        closedir(d);
    }
}

void trata_dir_compact(char *directory)
{
    d = opendir(directory);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            count_bytes_compact(dir->d_name);
        }
        closedir(d);
    }
}

void trata_dir_bi(char *directory)
{
    d = opendir(directory);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            count_bytes_bi(dir->d_name);
        }
        closedir(d);
    }
}

void trata_dir_compact_bi(char *directory)
{
    d = opendir(directory);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            count_bytes_compact_bi(dir->d_name);
        }
        closedir(d);
    }
}