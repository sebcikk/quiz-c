#include "../include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_lines(char* path, int* lines_count_out) {
  FILE* file = fopen(path, "r");

  if(file == NULL){ printf("ERR: File \"%s\" not found.", path); exit(-1); }

  int capacity = 6;

  char** lines = malloc(capacity * sizeof(char*));

  if(lines == NULL){
    printf("ERR: malloc failed\n");
    exit(-1);
  } 

  char* line;

  int lines_count = 0;
  while((line = read_line(file)) != NULL){
    if(lines_count >= capacity) {
      capacity *= 2;

      char** tmp = realloc(lines, capacity * sizeof(char*));

      if(tmp == NULL){
        for(int i = 0; i < lines_count; i++) free(lines[i]);
        free(lines);
        free(line);
        fclose(file);
        printf("ERR: realloc failed\n");
        exit(-1);
      } 
      lines = tmp;
    }

    lines[lines_count++] = line;
 }

  fclose(file);
  *lines_count_out = lines_count;
  return lines;
}

char* read_line(FILE* file) {
  int buffer_size = 128;
  int len = 0;

  char* buffer = malloc(buffer_size);
  if(buffer == NULL) return NULL; // malloc niemożliwy

  while(fgets(buffer + len, buffer_size - len, file) != NULL) { 
              // buffer + len to przesunięcie wskaźnika o odczytane znaki
              // buffer_size - len to ukrócenie rozmiaru o odczytane znaki
    len += strlen(buffer + len);
    if(len > 0 && buffer[len - 1] == '\n'){
      buffer[len - 1] = '\0';
      return buffer; // sukces
    }

    int new_size = buffer_size * 2;
    char* tmp = realloc(buffer, new_size);

    if(tmp == NULL){
      free(buffer);
      return NULL; // realloc niemożliwy
    }

    buffer = tmp;
    buffer_size = new_size;
  }

  if(len > 0) return buffer; // prawdopodobnie ostatnia linia w pliku

  free(buffer);

  return NULL; // gdy pusty plik
}

void free_lines(char** lines, int lines_count) {
  for(int i = 0; i < lines_count; i++) free(lines[i]);
  free(lines);
}
