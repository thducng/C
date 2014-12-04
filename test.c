/* atoi example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <string.h>
#define THOUSAND 1000

int main ()
{
  char s[256];
  scanf("%s",s);
  printf("%s,%d\n",s,spec_string_to_integer(s));

  return 0;
}

int spec_string_to_integer(char *spec_s){
  int thousands_int, hundreds_int;
  char *thousands_s, *hundreds_s;
  char *dot = ".";
  
  if(strchr(spec_s,'.') != 0){
    thousands_s = strtok(spec_s, dot);
    hundreds_s = strtok(NULL, " ");
    
    thousands_int = atoi(thousands_s);
    hundreds_int = atoi(hundreds_s);
    
    return (atoi(thousands_s)*THOUSAND)+atoi(hundreds_s);}
  else
    return atoi(spec_s);
}