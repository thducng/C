// get date/time

#include <stdio.h>
#include <string.h>
#include <time.h>

int get_date_time(int *dm, int *dd, int *wd, int *th, int *tm);

int main(void){
  int a = 1, date_m = 0, date_d = 0, weekday = 0, time_h = 0, time_m = 0;

  printf("hej\n");
  get_date_time(&date_m, &date_d, &weekday, &time_h, &time_m);

  if(a == 1)
    printf("Current date and time in integer is: \n%#02d/%#02d %d %#02d:%#02d\n",
           date_d, date_m, weekday, time_h, time_m);
  else
    printf("Couldn't get time\n");
  
  return 0;
}

int get_date_time(int *dm, int *dd, int *wd, int *th, int *tm){
  char *date_month, *date_day, *weekday, *time_hour, *time_min, *s;
  time_t rawtime;
  struct tm *timeinfo;
  
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strcpy(s,asctime(timeinfo));

  weekday = strtok(s, " ");
  date_month = strtok(NULL, " ");
  date_day = strtok(NULL, " ");
  time_hour = strtok(NULL, ":");
  time_min = strtok(NULL, ":");
  
  if(strcmp(weekday, "Mon") == 0)
    *wd = 0;
  else if(strcmp(weekday, "Tue") == 0)
    *wd = 1;
  else if(strcmp(weekday, "Wed") == 0)
    *wd = 2;
  else if(strcmp(weekday, "Thu") == 0)
    *wd = 3;
  else if(strcmp(weekday, "Fri") == 0)
    *wd = 4;
  else if(strcmp(weekday, "Sat") == 0)
    *wd = 5;
  else if(strcmp(weekday, "Sun") == 0)
    *wd = 6;
  else
    return 0;
  
  if(strcmp(date_month, "Jan") == 0)
    *dm = 1;
  else if(strcmp(date_month, "Feb") == 0)
    *dm = 2;
  else if(strcmp(date_month, "Mar") == 0)
    *dm = 3;
  else if(strcmp(date_month, "Apr") == 0)
    *dm = 4;
  else if(strcmp(date_month, "May") == 0)
    *dm = 5;
  else if(strcmp(date_month, "Jun") == 0)
    *dm = 6;
  else if(strcmp(date_month, "Jul") == 0)
    *dm = 7;
  else if(strcmp(date_month, "Aug") == 0)
    *dm = 8;
  else if(strcmp(date_month, "Sep") == 0)
    *dm = 9;
  else if(strcmp(date_month, "Oct") == 0)
    *dm = 10;
  else if(strcmp(date_month, "Nov") == 0)
    *dm = 11;
  else if(strcmp(date_month, "Dec") == 0)
    *dm = 12;
  else
    return 0;
  
  *dd = atoi(date_day);
  *th = atoi(time_hour);
  *tm = atoi(time_min);
  
  return 1;
}












