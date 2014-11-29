#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>



int main (void){
char a[10], b[10], c[10];
int d, e, f, g=0;
long long q, j=0;
int h, i=0;
FILE *file;
char x[10],z[10];

file = fopen("superliga.txt","r");

  while (fscanf(file," %s %d / %d %d . %d %s - %s %d - %d %lld . %lld", &a, &d, &e, &f, &g, &b, &c, &h, &i,&q, &j) != EOF){

    printf(" %3s %2d %2d %2d %2d %3s %3s %2d %2d %3lld.%lld \n", a, d, e, f, g, b, c, h, i,q, j);
  }
}