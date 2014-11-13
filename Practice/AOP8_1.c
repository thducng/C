#include <stdio.h>
#include <string.h>
#define limit 10

void printfunc(char *ware, char *pro, char *quali, int a);
char distrifunc(char *input, char *pware, char *ppro, char *pquali, int *a);

int main(void){
  char input[limit],
       ware[limit], pro[limit], quali[limit];
  int a = 0;
 
  distrifunc(input, ware, pro, quali, &a);
  printfunc(ware, pro, quali, a);

  return 0;
}

void printfunc(char *ware, char *pro, char *quali, int a){
  if(a == 0){
    printf("Warehouse: %s\n", *ware);
    printf("Product: %s\n", *pro);
    printf("Qualifiers: %s\n",*quali);}
  else
    printf("Error");
}

char distrifunc(char *input, char *pware, char *ppro, char *pquali, int *a){
  int count, c, b = 0;
  
  for(count = 0, c = 0; count < limit && c < 2; ++count){
    if(*input >= 'A' && *input <= 'Z' && input-1 > '9' ){
      *pware = *input;
      ++input;
      ++pware;}
    else if(*input >= 'A' && *input <= 'Z'){
      *pquali = *input;
      ++input;
      ++pquali;}
    else if(*input >= '0' && *input <= '9' && b != 3){
      *ppro = *input;
      ++input;
      ++ppro;
      ++b;}
    else if(*input >= '0' && *input <= '9' && b == 3){
      *pquali = *input;
      ++c;}
    else
      *a = 1;
      count = limit;
  }
}