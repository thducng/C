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
#define NUMBER_OF_TEAMS 12
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
typedef struct table{
  char team[TEAMNAME_SIZE];
  int matches;
  int wins;
  int draws;
  int loss;
  int goal_f;
  int goal_a;
  int goal_d;
  int points;
}table;
typedef struct round{
  match match[MAX_MATCH];
}round;


void read_copy_file(round *round);
void do_one_of_the_problems(round *round, table *table);
void do_all_problems(round *round, table *table);
void solve_problem_one(round *round);
void solve_problem_two(round *round);
void solve_problem_three(round *round);
void solve_problem_four(round *round);
void solve_problem_five(round *round);
void solve_problem_six(round *round, table *table);
void print_match(int i, int j, round *round);
void printfunc(round *round);
void input_stats_to_table(table *table, int i, int j, int k, int *m, int *gf, int *ga, int *p, int *w, int *d, int *l);
int point_cmp(const void *A, const void *B);
void print_table(table *table);

int main(int argc, char *argv[]){
  struct round round[MAX_ROUND];
  struct table table[NUMBER_OF_TEAMS];
  
  read_copy_file(round);
  
  if(argc != 1)
    do_all_problems(round, table);
  else
    do_one_of_the_problems(round, table);
    
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
void do_one_of_the_problems(round *round, table *table){
  int i = 0;
  
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
        solve_problem_five(round);
      case 6:
        solve_problem_six(round, table);
    }
  }
}
void do_all_problems(round *round, table *table){
  printf("\nProblem 1: \n");
  solve_problem_one(round);
  printf("\nProblem 2: \n");
  solve_problem_two(round);
  printf("\nProblem 3: \n");
  solve_problem_three(round);
  printf("\nProblem 4: \n");
  solve_problem_four(round);
  printf("\nProblem 5: \n");
  solve_problem_five(round);
  printf("\nProblem 6: \n");
  solve_problem_six(round, table);
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
  int i = 0, j = 0, k = 0, 
      h_win = 0, a_win = 0;
  
  char teams[NUMBER_OF_TEAMS][TEAMNAME_SIZE] = { "AGF" , "FCM" , "VFF" , "RFC" ,
                                                 "OB"  , "SDR" , "BIF" , "FCV" ,
                                                 "AAB" , "FCK" , "EFB" , "FCN" };
  
  for(k = 0, i = 0, j = 0; k < NUMBER_OF_TEAMS; k++){
    for(i = 0, j = 0; i < MAX_ROUND; i++){
      for(j = 0; j < MAX_MATCH; j++){
        if(strcmp(teams[k],round[i].match[j].h_team) == 0){
          if(round[i].match[j].h_goal > round[i].match[j].a_goal)
            h_win++;
        }
        if(strcmp(teams[k],round[i].match[j].a_team) == 0){
          if(round[i].match[j].h_goal < round[i].match[j].a_goal)
            a_win++;
        }
      }
    }
    if(a_win > h_win){
      printf("Team %3s, has won %d away games and %d home games. \n", teams[k], a_win, h_win);
      h_win = 0;
      a_win = 0;}
    else{
      h_win = 0;
      a_win = 0;}
  }
}
void solve_problem_four(round *round){
  int i = 0, j = 0, k = 0, team = 0; 
  long long temp_spec = 0, few_spec = 0;
  
  char teams[NUMBER_OF_TEAMS][TEAMNAME_SIZE] = { "AGF" , "FCM" , "VFF" , "RFC" ,
                                                 "OB"  , "SDR" , "BIF" , "FCV" ,
                                                 "AAB" , "FCK" , "EFB" , "FCN" };
  
  for(k = 0, i = 0, j = 0; k < NUMBER_OF_TEAMS; k++){
    for(i = 0, j = 0; i < MAX_ROUND; i++){
      for(j = 0; j < MAX_MATCH; j++){
        if(strcmp(teams[k],round[i].match[j].h_team) == 0){
          temp_spec += round[i].match[j].spectator;
        }
      }
    }
    if(few_spec > temp_spec){
      few_spec = temp_spec;
      team = k;
      temp_spec = 0;}
    else if(few_spec == 0)
      few_spec = temp_spec;
    else
      temp_spec = 0;
  }
  printf("Team %s, had %lld spectators at all home games.\n"
         "Which makes it the team with least spectators.\n", teams[team], few_spec);
}
void solve_problem_five(round *round){




}
void solve_problem_six(round *round, table *table){
  int i = 0, j = 0, k = 0;
  int m = 0, w = 0, d = 0, l = 0, gf = 0, ga = 0, gd = 0, p = 0;
  char teams[NUMBER_OF_TEAMS][TEAMNAME_SIZE] = { "AGF" , "FCM" , "VFF" , "RFC" ,
                                                 "OB"  , "SDR" , "BIF" , "FCV" ,
                                                 "AAB" , "FCK" , "EFB" , "FCN" };
  
  for(k = 0, i = 0, j = 0; k < NUMBER_OF_TEAMS; k++){
    for(i = 0, j = 0; i < MAX_ROUND; i++){
      for(j = 0; j < MAX_MATCH; j++){
        if(strcmp(teams[k], round[i].match[j].h_team) == 0){
           m++;
           gf += round[i].match[j].h_goal;
           ga += round[i].match[j].a_goal;
           if(round[i].match[j].h_goal > round[i].match[j].a_goal){
             p += 3;
             w++;}
           else if(round[i].match[j].h_goal == round[i].match[j].a_goal){
             p += 1;
             d++;}
           else
             l++;
        }
        if(strcmp(teams[k], round[i].match[j].a_team) == 0){
          m++;
          gf += round[i].match[j].a_goal;
          ga += round[i].match[j].h_goal;
          if(round[i].match[j].h_goal < round[i].match[j].a_goal){
            p += 3;
            w++;}
          else if(round[i].match[j].h_goal == round[i].match[j].a_goal){
            p += 1;
            d++;}
          else
            l++;
        }
      }
    }
    strcpy(table[k].team, teams[k]);
    input_stats_to_table(table, i, j, k, &m, &gf, &ga, &p, &w, &d, &l);
  }
  //qsort((void *)&table, NUMBER_OF_TEAMS, sizeof(table), &point_cmp);
  print_table(table);
}

// Helping functions //
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
void input_stats_to_table(table *table, int i, int j, int k, int *m, int *gf, int *ga, int *p, int *w, int *d, int *l){
  table[k].matches = *m;
  table[k].wins = *w;
  table[k].draws = *d;
  table[k].loss = *l;
  table[k].goal_f = *gf;
  table[k].goal_a = *ga;
  table[k].goal_d = *gf-*ga;
  table[k].points = *p;
  *m = 0, *gf = 0, *ga = 0, *p = 0, *w = 0, *d = 0, *l = 0;
}
int point_cmp(const void *A, const void *B){
  const table *a = A, *b = B;

  if(a->points < b->points){
    return -1;}
  else if(a->points > b->points)
    return 1;
  else if(a->points == b->points){
    if(a->goal_d < b->goal_d)
      return -1;
    else if(a->goal_d > b->goal_d)
      return 1;
    else if(a->goal_d == b->goal_d){
      if(a->goal_f < b->goal_f)
        return -1;
      else if(a->goal_f < b->goal_f)
        return 1;
      else if(a->goal_f == b->goal_f){
        if(strcmp(a->team, b->team) < 0)
          return 1;
        else if(strcmp(a->team, b->team) > 0)
          return -1;
        else return 0;
      }
      else return 0;
    }
    else return 0;
  }
  else return 0;
}
void print_table(table *table){
  int i;
  
  printf("Nr.  Team    M    W    D    L    Gf   Ga   +/-   P \n\n");
  for(i = 0; i < NUMBER_OF_TEAMS; i++){
    printf("%#02d    %3s   %2d   %2d   %2d   %2d    %2d   %2d   %3d   %2d\n", i+1,
                                                                              table[i].team,
                                                                              table[i].matches,
                                                                              table[i].wins,
                                                                              table[i].draws,
                                                                              table[i].loss,
                                                                              table[i].goal_f,
                                                                              table[i].goal_a,
                                                                              table[i].goal_d,
                                                                              table[i].points);
  }
}





