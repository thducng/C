// get date/time

#include <stdio.h>
#include <time.h>

int string_to_integer(char *s);

int main(void){
  char date[256], input[256];
  int a, date_m = 0, date_d = 0, time_h = 0, time_m = 0;
  
  get_date_time(input, date, &date_m, &date_d, &time_h, &time_m);
  
  if(strcmp(input, "string") == 0)
    printf("Program is %d, date and time in string is: %s", a, date);
  else if(strcmp(input, "integer") == 0)
    printf("Program is %d, date and time in integer is: %d/%d %d:%d",
            date_d, date_m, time_h, time_m);
  else
    printf("Error bitch!\n");
  
  return 0;
}

int get_date_time(char i, char *date, int *dm, int *dd, int *th, int *tm){
  time_t rawtime;
  struct tm *timeinfo
  
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  
  if(strcmp(i,"string") == 0){
    strcpy(date,asctime(timeinfo));
    return 1;
  }
  else if(strcmp(i,"integer")){
    strcpy(date,asctime(timeinfo));
    string_to_integer(&dm, &dd, &th, &tm);
    return 1;
  }
  else
    return 0;
}


int string_to_integer(char *s, int *dm, int *dd, int *th, int *tm){
  char *day_of_week, *date_month;
  
  day_of_week = strtok(s, " ");
  date_month = strtok(s, " ");
  date_day = strtok(s, " ");
  time_hour = strtok(s, ":");
  time_min = strtok(s, ":");

  if(strcmp(date_month, "Jan"))
    
    
}












