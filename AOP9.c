#include <stdio.h>
#include <strings.h>
#define limit 10
char iterativ(char *input, char *output);
char rekursiv(char *input, char*output);

int main(void){
  char input[limit] = "hallo",
       output[strlen(input)];
  
 /* iterativ(input, output); */
  rekursiv(input, output);
  
  
  return 0;
}

char iterativ(char *input, char *output){
  int i;
  
  for(i = strlen(input); i >= 1; --i){
    output[strlen(input)-i] = input[i];
  }  
  output[limit] = '\0';
  printf(" %s\n", output);
  if(input == output)
    printf(" %s\n", output);
}

char rekursiv(char *input, char *output){
 if(strlen(input) >= 1){
    strcpy(output, &input[strlen(input)]);
    printf(" %s", output);
    rekursiv(input - 1, output + 1);  
    printf(" %s", output);
  }
}