#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "readfile.h"
#include "memory.h"

/*
Marcelo Lima 2160866 
Ruben Oliveira 2192236
*/

int discrete_bi(char *filename, char *numbers)
{
    char *file = strtok(filename, ",");
    char *number = strtok(numbers, ",");
    unsigned short buf[1];
    size_t count = sizeof(buf);
    int sum = 0;
    while (file != NULL)
    {
        printf("File %s :\n", file);
        while (number != NULL)
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
                            if (atoi(number) == buf[i])
                            {
                                numb++;
                            }
                        }
                    }
                } while (read_res > 0);

                printf("Bi-Byte %05d: %d\n", atoi(number), numb);

                close(fd);

                sum = sum + numb;
            number = strtok(NULL, ",");
        }
        file = strtok(NULL, ",");
    }
    return 0;
}

int discrete(char *filename, char *numbers)
{
    char *file = strtok(filename, ",");
    char *number = strtok(numbers, ",");
    while (file != NULL)
    {
        printf("File %s :\n", file);
        while (number != NULL)
        {
           // int j = atoi(number);
            unsigned char buf[1];
            size_t count = sizeof(buf);
            int sum = 0;
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
                        if (atoi(number) == buf[i])
                        {
                            numb++;
                        }
                    }
                }
            } while (read_res > 0);

            printf("Byte %03d: %d\n", atoi(number), numb);

            close(fd);
            sum = sum + numb;
            number = strtok(NULL, ",");
        }
        file = strtok(NULL, ",");
    }
    return 0;
}