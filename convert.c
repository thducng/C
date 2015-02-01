#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_ARENA_WIN 12
#define MAX_ARENA_LOSS 3
#define TRUE 1
#define FALSE 0

int main(void){
  FILE *file1, *file2;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0;
  double  winp = 0.00;
  
  file1 = fopen("Stats.txt", "r");
  file2 = fopen("Stats1.txt", "w");
  
  while(fscanf(file1, "%d %d %d", &class, &win, &lost) != EOF){
    fprintf(file2, " %d %d %d %d", class, win, lost, 0);
  }
  fclose(file1);
  fclose(file2);
  
  file1 = fopen("Stats.txt", "w");
  file2 = fopen("Stats1.txt", "r");
  
  while(fscanf(file2, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
    fprintf(file1, " %d %d %d %d", class, win, lost, delete);
  }
  fclose(file1);
  fclose(file2);
  
  if(remove("Stats1.txt") == 0)
    printf( "\n __________________________________ \n"
              ": Succes                           :\n"
              ":__________________________________:\n\n");
  else{
    printf( "\n __________________________________ \n"
              ": Succes                           :\n"
              ":__________________________________:\n\n");
  }
}