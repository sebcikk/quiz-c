#ifndef FILES_H
#define FILES_H

#include <stdio.h>
char** get_lines(char* path, int* lines_count_out);

char* read_line(FILE* file);

void free_lines(char** lines, int lines_count);

#endif
