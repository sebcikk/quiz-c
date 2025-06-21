#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "../include/files.h"
#include "../include/questions.h"

int main(int argc, char** argv){
  char* path = "data/questions.txt"; // default
  int base = 20;

  srand(time(NULL));
                                     
  if(argc >= 2) {
    path = argv[1];
  }
  if(argc >=3 ) {
    base = atoi(argv[2]);
  }

  printf("USING DATABASE: %s\n\n", path);

  int lines_count;
  char** lines = get_lines(path, &lines_count);

  Question* questions = get_questions(lines, lines_count);
  int questions_count = get_questions_count(lines, lines_count);

  if(base > questions_count) {
    printf("Not enough questions available. Base set to %d\n\n", questions_count);
    base = questions_count;
  }

  free_lines(lines, lines_count);

  int score = 0;
  int* rand_indexes = malloc(questions_count * sizeof(int));

  for(int i = 0; i < questions_count; i++) rand_indexes[i] = i;

  for(int i = questions_count - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int tmp = rand_indexes[i];
    rand_indexes[i] = rand_indexes[j];
    rand_indexes[j] = tmp;
  }

  for(int i = 0; i < base; i++) {
    int j = rand_indexes[i];

    char choice;
    print_question(questions, j);

    printf("Choice: ");
    scanf(" %c", &choice);

    if(toupper(choice) == questions[j].correct){
      printf("Correct answer!\n\n");
      score++;
    }
    else {
      printf("Incorrect. Correct answer is %c\n\n", questions[j].correct);
    }
  }

  free(rand_indexes);

  free_questions(questions, questions_count);

  printf("\nQuiz finished! Score: %d/%d (%.2f%%)\n",
      score,
      base,
      (float) score / base * 100 );

  return 0;
}
