/* Afleveringsopgave 8 - Opgave 1 side 488
   Skrevet af Thuan Duc Nguyen */

#include <stdio.h>
#include <string.h>
#define limit 100

char scaninput(char *procode);
char *seperation(char *procode, char *ware, char *pro, char *quali);
void printfunc(char *procode, char *ware, char *pro, char *quali);

int main(void){
  char procode[limit],
       ware[limit], pro[limit], quali[limit];
  
  while(*procode != 'q'){
    scaninput(procode);
    seperation(procode, ware, pro, quali);
    printfunc(procode, ware, pro, quali);
  } 
  
  return 0;
}

char scaninput(char *procode){
  printf("Enter Product Code or q: ");
  fgets(procode, limit, stdin);
}

char *seperation(char *procode, char *ware, char *pro, char *quali){
  strncpy(ware, &procode[0], 3);
  ware[3] = '\0';
  
  strncpy(pro, &procode[3], 4);
  pro[4] = '\0';
  
  strncpy(quali, &procode[7], 3);
  quali[3] = '\0';
}

void printfunc(char *procode, char *ware, char *pro, char *quali){
  if(*procode != 'q'){
    printf("\nWarehouse: %s\n", ware);
    printf("Product: %s\n", pro);
    printf("Qualifiers: %s\n\n", quali);}
}