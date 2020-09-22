/**
* @file main.c
* @brief Description
* @date 2018-1-1
* @author name of author
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "debug.h"
#include "memory.h"

#include "args.h"
#include "help.h"
#include "readfile.h"
#include "tratadir.h"
#include "discrete.h"

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

int main(int argc, char *argv[])
{
	clock_t begin = clock();
	struct gengetopt_args_info args_info;
	if (cmdline_parser(argc, argv, &args_info) != 0)
	{
		exit(1);
	}

	if (args_info.help_given)
	{
		help();
		exit(0);
	}
	else if (args_info.file_given || args_info.dir_given)
	{
		if ((args_info.compact_given && args_info.discrete_given) ||  (args_info.compact_given && args_info.search_given) ){
			printf("ERROR: Compact is not compatible with discrete or search!\n");
			exit(0);
		}else 
		if (args_info.file_given)
		{
			if (args_info.file_given && args_info.compact_given)
			{
				if (args_info.mode_given)
				{
					if (args_info.mode_arg == 1)
					{
						count_bytes_compact(args_info.file_arg);
					}
					else if (args_info.mode_arg == 2)
					{
						count_bytes_compact_bi(args_info.file_arg);
					}
					else
					{
						printf("ERROR: invalid value ‘%d’ for -m/--mode\n", args_info.mode_arg);
					}
				}
				else
				{
					count_bytes_compact(args_info.file_arg);
				}
			}
			else if (args_info.file_given && args_info.discrete_given)
			{
				if (args_info.mode_given)
				{
					if (args_info.mode_arg == 1)
					{
						discrete(args_info.file_arg,args_info.discrete_arg);
					}
					else if (args_info.mode_arg == 2)
					{
						discrete_bi(args_info.file_arg,args_info.discrete_arg);
					}
					else
					{
						printf("ERROR: invalid value ‘%d’ for -m/--mode\n", args_info.mode_arg);
					}
				}
				else
				{
					discrete(args_info.file_arg,args_info.discrete_arg);
				}
			}
			else
			{
				if (args_info.mode_given)
				{
					if (args_info.mode_arg == 1)
					{
						count_bytes(args_info.file_arg);
					}
					else if (args_info.mode_arg == 2)
					{
						count_bytes_bi(args_info.file_arg);
					}
					else
					{
						printf("ERROR: invalid value ‘%d’ for -m/--mode\n", args_info.mode_arg);
					}
				}
				else
				{
					count_bytes(args_info.file_arg);
				}
			}
		}
		if (args_info.dir_given)
		{
			if (args_info.dir_given && args_info.compact_given)
			{
				if (args_info.mode_given)
				{
					if (args_info.mode_arg == 1)
					{
						trata_dir_compact(args_info.dir_arg);
					}
					else if (args_info.mode_arg == 2)
					{
						trata_dir_compact_bi(args_info.dir_arg);
					}
					else
					{
						printf("ERROR: invalid value ‘%d’ for -m/--mode\n", args_info.mode_arg);
					}
				}
				else
				{
					trata_dir_compact(args_info.dir_arg);
				}
			}
			else
			{
				if (args_info.mode_given)
				{
					if (args_info.mode_arg == 1)
					{
						trata_dir(args_info.dir_arg);
					}
					else if (args_info.mode_arg == 2)
					{
						trata_dir_bi(args_info.dir_arg);
					}
					else
					{
						printf("ERROR: invalid value ‘%d’ for -m/--mode\n", args_info.mode_arg);
					}
				}
				else
				{
					trata_dir(args_info.dir_arg);
				}
			}
		}
	}

	clock_t end = clock();
	double time_spent = ((double)end - begin) / 1000000;
	if (args_info.time_given)
	{
		printf("Tempo: %f sec \n", time_spent);
	}
	cmdline_parser_free(&args_info);

	return 0;
}
