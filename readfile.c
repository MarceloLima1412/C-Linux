#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "readfile.h"
#include "memory.h"

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

int count_bytes_bi(char *filename)
{
	char *file = strtok(filename, ",");
	unsigned short buf[1];
	size_t count = sizeof(buf);
	int sum = 0;
	while(file != NULL)
	{
		printf("File %s :\n", file);
		for (unsigned short j = 0; j <= 65535; j++)
		{
			int numb = 0;
			int fd = open(file, O_RDONLY);
			if (fd == -1)
			{
				printf("------------------\n");
				printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
				printf("------------------\n");
				return 0;
			}
			do
			{
				read_res = read(fd, buf, count);

				if (read_res == -1)
				{
					printf("------------------\n");
					printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
					printf("------------------\n");
					return 0;
				}
				if (read_res > 0)
				{
					for (int i = 0; i < read_res; i = i + 2)
					{
						if (j == buf[i])
						{
							numb++;
						}
					}
				}
			} while (read_res > 0);
			if(numb >0){
			printf("Bi-Byte %05d: %d\n", j, numb);
			}
			close(fd);

			sum = sum + numb;
		}
		printf("Sum:%d\n", sum);
		file = strtok(NULL, ",");
	}
	return 0;
}

int count_bytes(char *filename)
{
	char *file = strtok(filename, ",");
	while (file != NULL)
	{
		unsigned char buf[1];
		size_t count = sizeof(buf);
		int sum = 0;
		printf("File %s :\n", file);
		for (unsigned short j = 0; j < 256; j++)
		{
			int numb = 0;
			int fd = open(file, O_RDONLY);
			if (fd == -1)
			{
				printf("------------------\n");
				printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
				printf("------------------\n");
				return 0;
			}
			do
			{
				read_res = read(fd, buf, count);

				if (read_res == -1)
				{
					printf("------------------\n");
					printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
					printf("------------------\n");
					return 0;
				}
				if (read_res > 0)
				{
					for (int i = 0; i < read_res; i++)
					{
						if (j == buf[i])
						{
							numb++;
						}
					}
				}
			} while (read_res > 0);
			if(numb >0){
			printf("Byte %03d: %d\n", j, numb);
			}
			close(fd);

			sum = sum + numb;
		}
		printf("Sum:%d\n", sum);
		file = strtok(NULL, ",");
	}
	return 0;
}

int count_bytes_compact(char *filename)
{
	unsigned char buf[1];
	size_t count = sizeof(buf);
	int sum = 0;

	char *file = strtok(filename, ",");
	while (file != NULL)
	{
		printf("File %s :", file);
		for (unsigned int j = 0; j < 256; j++)
		{
			int numb = 0;
			int fd = open(file, O_RDONLY);
			if (fd == -1)
			{
				printf("------------------\n");
				printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
				printf("------------------\n");
				return 0;
			}
			do
			{
				read_res = read(fd, buf, count);

				if (read_res == -1)
				{
					printf("------------------\n");
					printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
					printf("------------------\n");
					return 0;
				}
				if (read_res > 0)
				{
					for (int i = 0; i < read_res; i++)
					{
						if (j == buf[i])
						{
							numb++;
						}
					}
				}
			} while (read_res > 0);

			printf("%d", numb);

			close(fd);

			sum = sum + numb;
		}
		printf(":%d\n", sum);
		file = strtok(NULL, ",");
	}
	return 0;
}

int count_bytes_compact_bi(char *filename)
{
	unsigned short buf[1];
	size_t count = sizeof(buf);
	int sum = 0;
	char *file = strtok(filename, ",");
	while (file != NULL)
	{
		for (unsigned int j = 0; j < 256; j++)
		{
			int numb = 0;
			int fd = open(file, O_RDONLY);
			if (fd == -1)
			{
				printf("------------------\n");
				printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
				printf("------------------\n");
				return 0;
			}
			do
			{
				read_res = read(fd, buf, count);

				if (read_res == -1)
				{
					printf("------------------\n");
					printf("ERROR:'%s': CANNOT PROCESS FILE\n", file);
					printf("------------------\n");
					return 0;
				}
				if (read_res > 0)
				{
					for (int i = 0; i < read_res; i++)
					{
						if (j == buf[i])
						{
							numb++;
						}
					}
				}
			} while (read_res > 0);

			printf("%d", numb);

			close(fd);

			sum = sum + numb;
		}
		printf(":%d\n", sum);
		file = strtok(NULL, ",");
	}
	return 0;
}