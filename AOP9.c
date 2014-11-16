#include <stdio.h>
#include <strings.h>
#define limit 10
char irativ(char *input, char *output);

int main(void){
  char input[limit], output[limit];
  
  printf("Enter nine character: ");
  scanf("%s", input);
  
  irativ(input, output);
  
  return 0;
}

char irativ(char *input, char *output){
  int i;
  
  for(i = strlen(input); i >= 1; --i){
    output[strlen(input)-i] = input[i];
  }  
  output[limit] = '\0';
  printf(" %s\n", output);
  if(input == output)
    printf(" %s\n", output);
}