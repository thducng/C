/* Afleveringsopgave 9 - Palindromer
   Skrevet af Thuan Duc Nguyen */
#include <stdio.h>
#include <strings.h>
#define LIMIT 100

void get_word(char *input);
int is_palindrome_iter(char *input);
int is_palindrome_rec(char *input);
void flip_word(char *input, char *output);
void print_res(int res1, int res2, char *input);

int main(void){
  char input[LIMIT];
  int res1, res2;

  get_word(input);
  
  res1 = is_palindrome_iter(input);
  res2 = is_palindrome_rec(input);
  print_res(res1, res2, input);
  
  return 0;
}

/* Get a word without newline and random values */
void get_word(char *input){
  printf("Enter a word: ");
  fgets(input, LIMIT, stdin);
  strtok(input, "\n");
  input[strlen(input)] = '\0';
}

/* Iterative function to determine a palindrome */
int is_palindrome_iter(char *input){
  char output[LIMIT];
  int i;
  
  for(i = strlen(input); i > 1; --i){
    output[strlen(input)-i] = input[i-1];
  }  
  output[strlen(input)-1] = input[0];
  output[strlen(input)] = '\0';
  
  return strcmp(input, output);
}

/* Using recursive function(flip_word) to determine a palindrome*/
int is_palindrome_rec(char *input){
  char output[LIMIT];
  
  flip_word(input, output);
  output[strlen(input)-1] = input[0];
  output[strlen(input)] = '\0';
  
  return strcmp(input, output);
}

/* Recursive function to read input backwards */
void flip_word(char *input, char *output){
 if(strlen(input) > 1){
    flip_word(++input, output);
  }  
 output[strlen(input)-1] = input[0];
 output[strlen(input)] = '\0';
}

/* Print answer to the question! */
void print_res(int res1, int res2, char *input){
  printf("\nIs '%s' a Palindrome?\n", input);
  if(res1 == 0)
    printf("\nIterativ function says Yes!\n");
  else
    printf("\nIterativ function says No!\n");
  if(res2 == 0)
    printf("Rekursiv function says Yes!\n\n");
  else
    printf("Rekursiv function says No!\n\n");
}