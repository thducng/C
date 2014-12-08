#include <stdio.h>
#include <string.h>
#define limit 100

void scan(char *input);
char add_ending(char *input, char *output);
void print(char *input, char *output);

int main(void){
  char input[][] = {"chair","diary","boss","circus","fly","dog","church","clue","dish"}
       output[limit];
  
  for(i = 0; strlen(A); ++i){
    add_ending(input, output);
    print(input, output);
  }
  
  return 0;
}

char add_ending(char *input, char *output){
  char a[3] = "ies",
       b[2] = "es",
       c[2] = "ch",
       d[2] = "sh",
       e[limit];
       
  strcpy(output, input);
  
  if(*strrchr(input, 'y') == 'y'){
    output[strlen(strrchr(input, 'y'))] = '\0';
    strcat(output, a);}
  else if(*strrchr(input, 's') == 's'){
    output[strlen(strrchr(input, 'y'))] = '\0';
    strcat(output, b);}
  else if(*strrchr(input, 'c') == *c){
    output[strlen(strrchr(input, 'y'))] = '\0';
    strcat(output, b);}
  else if(*strrchr(input, 's') == *d){
    output[strlen(strrchr(input, 'y'))] = '\0';
    strcat(output, b);}
  else
    strcat(output, "s");
}

void print(char *input, char *output){
  printf(" %s\n %s\n", input, output);
}


