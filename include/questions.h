#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct { 
  char* content;
  int answers_count;
  char** answers;
  char correct;
} Question;

int get_questions_count(char** lines, int lines_count);

Question* get_questions(char** lines, int lines_count);

void print_question(Question* questions, int i);

void free_questions(Question* questions, int questions_count);

#endif
