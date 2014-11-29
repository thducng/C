// Aalborg Universitet - Imperativ Programmering - Eksamensopgave //
// Thuan Duc Nguyen - tnguy14@student.aau.dk                      //
// Software - A405c                                               //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ROUND 33
#define MAX_MATCH 6
#define NAMEDAY_SIZE 3
#define TIME_SIZE 5
#define TEAMNAME_SIZE 10
#define THOUSAND 1000
#define SEVEN 7

typedef struct match{
  char day_of_week[NAMEDAY_SIZE];
  int date_day;
  int date_month; 
  int time_hour;
  int time_min;
  char h_team[TEAMNAME_SIZE];
  char a_team[TEAMNAME_SIZE];
  int h_goal;
  int a_goal;
  long long spectator;
}match;
typedef struct round{
  match match[MAX_MATCH];
}round;

void read_copy_file(round *round);
void do_one_of_the_problems(round *round);
void do_all_problems(round *round);
void solve_problem_one(round *round);
void solve_problem_two(round *round);
void solve_problem_three(round *round);
void solve_problem_four(round *round);
void solve_problem_five(round *round, char *k1, char *k2, char *u);
void solve_problem_six(round *round);
void print_match(int i, int j, round *round);
void printfunc(round *round);

int main(int argc, char *argv[]){
  struct round round[MAX_ROUND];
  
  read_copy_file(round);
  
  if(argc != 1)
    do_all_problems(round);
  else
    do_one_of_the_problems(round);
    
  return 0;
}

// Read file, and copy data //
void read_copy_file(round *round){
  FILE *superliga;
  int i, j;
  long long k, l;

  superliga = fopen("superliga-2013-2014","r");
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      fscanf(superliga," %s %d / %d %d . %d %s - %s %d - %d %lld . %lld", &round[i].match[j].day_of_week,
                                                                          &round[i].match[j].date_day,
                                                                          &round[i].match[j].date_month,
                                                                          &round[i].match[j].time_hour,
                                                                          &round[i].match[j].time_min,
                                                                          &round[i].match[j].h_team,
                                                                          &round[i].match[j].a_team,
                                                                          &round[i].match[j].h_goal,
                                                                          &round[i].match[j].a_goal,
                                                                          &k, &l);
      round[i].match[j].spectator = (k*THOUSAND)+l;
    }
  }
  fclose(superliga);
}

// Determine dialogue with user //
void do_one_of_the_problems(round *round){
  int i = 0;
  char u[NAMEDAY_SIZE], k1[TIME_SIZE], k2[TEAMNAME_SIZE];
  
  while(i != 10){
  printf("\nEnter problem(1-6, 10 for exit): ");
  scanf("%d",&i);
  
    switch(i){
      case 1:
        solve_problem_one(round);
        break;
      case 2:
        solve_problem_two(round);
        break;
      case 3:
        solve_problem_three(round);
      case 4:
        solve_problem_four(round);
      case 5:
        printf("Enter a weekday(e. g. Fre) and a timeframe(18.00 19.00): ");
        scanf(" %s %s %s", &u, &k1, &k2 );
        solve_problem_five(round, k1, k2, u);
      case 6:
        solve_problem_six(round);
    }
  }
}
void do_all_problems(round *round){
  char u[3] = {"Fre"}, k1[TIME_SIZE] = {"18.05"}, k2[TIME_SIZE] = {"19.05"};
  
  printf("\nProblem 1: \n");
  solve_problem_one(round);
  printf("\nProblem 2: \n");
  solve_problem_two(round);
  printf("\nProblem 3: \n");
  solve_problem_three(round);
  printf("\nProblem 4: \n");
  solve_problem_four(round);
  printf("\nProblem 5: \n");
  solve_problem_five(round, k1, k2, u);
  printf("\nProblem 6: \n");
  solve_problem_six(round);
}

// Main body for solving the assignments //
void solve_problem_one(round *round){
  int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      if(round[i].match[j].h_goal + round[i].match[j].a_goal >= SEVEN)
        print_match(i, j, round);
    }
  }
}
void solve_problem_two(round *round){
  int i, j, temp_res = 0, res = 0, round_res = 0;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      temp_res += round[i].match[j].h_goal + round[i].match[j].a_goal;
    }
    if(res < temp_res){
      res       = temp_res;
      round_res = i;
      temp_res  = 0;}
    else
      temp_res  = 0;
  }
 printf("Round %d with %d goals. \n", round_res, res);
}
void solve_problem_three(round *round){
  int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      
    }
  }
}
void solve_problem_four(round *round){







}
void solve_problem_five(round *round, char *k1, char *k2, char *u){
  int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
      for(j = 0; j < MAX_MATCH; j++){
        if(round[i].match[j].day_of_week == u){
          if(round[i].match[j].time_hour >= k1 && round[i].match[j].time_hour =< k2){
            print_match(i, j, round);
          }
        }
      }
    }
}
void solve_problem_six(round *round){





}

// Helping functions for solving or printing //
void print_match(int i, int j, round *round){
  printf(" %3s %#02d/%#02d %#02d.%#02d %3s - %3s %2d - %d %6lld \n", round[i].match[j].day_of_week,
                                                                         round[i].match[j].date_day,
                                                                         round[i].match[j].date_month,
                                                                         round[i].match[j].time_hour,
                                                                         round[i].match[j].time_min,
                                                                         round[i].match[j].h_team,
                                                                         round[i].match[j].a_team,
                                                                         round[i].match[j].h_goal,
                                                                         round[i].match[j].a_goal,
                                                                         round[i].match[j].spectator);
}
void printfunc(round *round){
  int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      print_match(i, j, round);
    }
  }
}











