#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/questions.h"

int get_questions_count(char** lines, int lines_count){
  int q_count = 0;
  int i = 0;

  while (i < lines_count) {
    if (i + 1 >= lines_count) break; // sprawdzenie czy nie wychodzimy
                                     // poza tablicę

    int ans_count = atoi(lines[i+1]);  // ilość odpowiedzi

    if (i + ans_count + 2 >= lines_count) break; // sprawdzenie czy istnieje 
                                                 // nastepne pytanie
    q_count++; // zliczamy pełny blok pytania

    i += ans_count + 3; // skok do nastpenego pytania
                        // 1 linia pytanie 
                        // + 1 linia liczba odpowiedzi 
                        // + ans_count linii odpowiedzi 
                        // + 1 linia poprawna odpowiedź
  }

  return q_count;
}

Question* get_questions(char** lines, int lines_count) {
  int questions_count = get_questions_count(lines, lines_count);
  Question* questions = malloc(questions_count * sizeof(Question));

  int i = 0;
  for(int j = 0; j < questions_count; j++) {
    Question q;
    q.content = strdup(lines[i++]);
    q.answers_count = atoi(lines[i++]);
    q.answers = malloc(q.answers_count * sizeof(char*));

    for(int k = 0; k < q.answers_count; k++) q.answers[k] = strdup(lines[i++]);

    q.correct = 'A' + atoi(lines[i++]);

    questions[j] = q;
  }

  return questions;
}

void print_question(Question* questions, int i) {
  printf("%s\n", questions[i].content);

  for(int j = 0; j < questions[i].answers_count; j++) 
      printf("%c. %s\n", 'A'+j, questions[i].answers[j]);
}

void free_questions(Question* questions, int questions_count) {
  for(int i = 0; i < questions_count; i++) {
    for(int j = 0; j < questions[i].answers_count; j++) 
      free(questions[i].answers[j]);

    free(questions[i].answers);
  }
  free(questions);
}
