#include <stdio.h>
#include <string.h>
#define limit 100

void printfunc(char *ware, char *pro, char *quali);
char *seperation(char *input, char *pware, char *ppro, char *pquali);

int main(void){
  char input[limit],
       ware[limit], pro[limit], quali[limit];
 
  seperation(input, ware, pro, quali);
  printfunc(ware, pro, quali);

  return 0;
}

void printfunc(char *ware, char *pro, char *quali){
  printf("Warehouse: %s\n", ware);
  printf("Product: %s\n", pro);
  printf("Qualifiers: %s\n",quali);
}

char *seperation(char *input, char *pware, char *ppro, char *pquali){
  int count, b = 0;
  strcpy(input, "ATL1203S14");
  
  for(count = 0; count < limit; ++count){
    if(*input >= 'A' && *input <= 'Z' && *(input-1) > '9' && *(input+1) > '9'){
      strncpy(pware, input, 3);
      pware[3] = '\0';
      input = input + 3;}
    else if(*input >= '0' && *input <= '9' && b != 1){
      strncpy(ppro, input, 4);
      ppro[4] = '\0';
      ++b;
      input = input + 4;}
    else{
      strncpy(pquali, input, 3);
      pquali[3] = '\0';
      count = count + limit;}
  }
}