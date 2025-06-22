# QUIZ-C
made by sebcikk

## Running the program
./quiz [QUESTIONS_BASE] [PATH_TO_DATABASE]  

### Default settings  
To run with default settings simply run ./quiz  
QUESTIONS_BASE = 20  
PATH_TO_DATABASE = /data/questions.txt  

## Data Format
The input data should follow this format:  
    Question text (one line)  
    Number of answers (an integer)  
    Answer options (each answer on its own line)  
    Index of the correct answer (zero-based)  

### EXAMPLE
How many bytes does an int occupy in memory? // question 1  
4                                            // number of answers  
2                                            // answer A (i: 0)  
4                                            // answer B (i: 1)  
6                                            // answer C (i: 2)  
8                                            // answer D (i: 3)  
1                                            // correct answer  
Is C a statically typed language?            // question 2  
2                                            // number of answers  
True                                         // answer A (i: 0)  
False                                        // answer B (i: 1)  
0                                            // correct answer  

etc.  
