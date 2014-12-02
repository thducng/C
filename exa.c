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
#define WIN_POINT 3
#define DRAW_POINT 1

typedef struct match{
  char day_of_week[NAMEDAY_SIZE];
  unsigned int date_day;
  unsigned int date_month; 
  char time[TIME_SIZE];
  char h_team[TEAMNAME_SIZE];
  char a_team[TEAMNAME_SIZE];
  unsigned int h_goal;
  unsigned int a_goal;
  long long spectator;
}match;
typedef struct table{
  char team[TEAMNAME_SIZE];
  unsigned int matches;
  unsigned int wins;
  unsigned int draws;
  unsigned int loss;
  unsigned int goal_f;
  unsigned int goal_a;
  unsigned int goal_d;
  unsigned int points;
}table;
typedef struct round{
  match match[MAX_MATCH];
}round;

// Prototypes //
void read_copy_file(round *round);
void do_one_of_the_problems(round *round, table *table);
void do_all_problems(round *round, table *table);

// Prototypes for assignments //
void solve_problem_one(round *round);
void solve_problem_two(round *round);
void solve_problem_three(round *round);
void solve_problem_four(round *round);
void solve_problem_five(round *round, char *u, char *k1, char *k2);
void solve_problem_six(round *round, table *table);

// Prototypes for helping functions //
void print_match(unsigned int i, unsigned int j, round *round);
void print_all_matches(round *round);
void input_home_games_into_table(round *round, table *table, unsigned int i, unsigned int j, unsigned int k);
void input_away_games_into_table(round *round, table *table, unsigned int i, unsigned int j, unsigned int k);
void print_table(table *table);
void sort_table(table *table);
void swap_position(table *table, unsigned int j);

unsigned int main(unsigned int argc, char *argv[]){
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
  unsigned int i, j;
  long long k, l;

  superliga = fopen("superliga-2013-2014","r");
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      fscanf(superliga," %s %d / %d %s %s - %s %d - %d %lld . %lld", &round[i].match[j].day_of_week,
                                                                     &round[i].match[j].date_day,
                                                                     &round[i].match[j].date_month,
                                                                     &round[i].match[j].time,
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
  unsigned int i = 1;
  char u[NAMEDAY_SIZE] = {"Fre"},
       k1[TIME_SIZE] = {"18.05"},
       k2[TIME_SIZE] = {"19.05"};

  printf("\nEnter problem(1-6, 7 for all matches): ");
  scanf("%d",&i);
    
  switch(i){
    case 1:
      printf("\n--------------------Problem 1---------------------- \n\n");
      solve_problem_one(round);
      break;
    case 2:
      printf("\n--------------------Problem 2---------------------- \n\n");
      solve_problem_two(round);
      break;
    case 3:
      printf("\n--------------------Problem 3---------------------- \n\n");
      solve_problem_three(round);
      break;
    case 4:
      printf("\n--------------------Problem 4---------------------- \n\n");
      solve_problem_four(round);
      break;
    case 5:
      printf("Enter a weekday(Fre), and a timeframe(18.05 19.05): ");
      scanf("%s %s %s", u, k1, k2);
      //printf("\n--------------------Problem 5---------------------- \n\n");
      //solve_problem_five(round, u, k1, k2);  Kan muligvis løses ved at dele k1 op i to, og derefter lægges de to sammen.
      printf("Invalid \n %3s \n %5s \n %5s \n", u, k1, k2);
      break;
    case 6:
      printf("\n--------------------Problem 6---------------------- \n\n");
      solve_problem_six(round, table);
      break;
    case 7:
      printf("\n--------------------All Matches---------------------- \n\n");
      print_all_matches(round);
  }
}
void do_all_problems(round *round, table *table){
  char u[NAMEDAY_SIZE] = "Fre",
       k1[TIME_SIZE] = "18.05",
       k2[TIME_SIZE] = "19.05";
  
  printf("\n--------------------Problem 1---------------------- \n\n");
  solve_problem_one(round);
  printf("\n--------------------Problem 2---------------------- \n\n");
  solve_problem_two(round);
  printf("\n--------------------Problem 3---------------------- \n\n");
  solve_problem_three(round);
  printf("\n--------------------Problem 4---------------------- \n\n");
  solve_problem_four(round);
  printf("\n--------------------Problem 5---------------------- \n\n");
  solve_problem_five(round, u, k1, k2);
  printf("\n--------------------Problem 6---------------------- \n\n");
  solve_problem_six(round, table);
}

// Main body for solving the assignments //
void solve_problem_one(round *round){
  unsigned int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      if(round[i].match[j].h_goal + round[i].match[j].a_goal >= SEVEN)
        print_match(i, j, round);
    }
  }
}
void solve_problem_two(round *round){
  unsigned int i, j, temp_res = 0, res = 0, round_res = 0;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    for(j = 0; j < MAX_MATCH; j++){
      temp_res += round[i].match[j].h_goal + round[i].match[j].a_goal;
    }
    if(res < temp_res){
      res       = temp_res;
      round_res = i+1;
      temp_res  = 0;}
    else
      temp_res  = 0;
  }
 printf("Round %d with %d goals. \n", round_res, res);
}
void solve_problem_three(round *round){
  unsigned int i = 0, j = 0, k = 0, 
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
  unsigned int i = 0, j = 0, k = 0, team = 0; 
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
void solve_problem_five(round *round, char *u, char *k1, char *k2){
  unsigned int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
      for(j = 0; j < MAX_MATCH; j++){
        if(strcmp(u, round[i].match[j].day_of_week) == 0 && strcmp(k1, round[i].match[j].time) < 0 && strcmp(k2, round[i].match[j].time) > 0)
          print_match(i, j, round);
    }
  }
}
void solve_problem_six(round *round, table *table){
  unsigned int i = 0, j = 0, k = 0;
  char teams[NUMBER_OF_TEAMS][TEAMNAME_SIZE] = { "AGF" , "FCM" , "VFF" , "RFC" ,
                                                 "OB"  , "SDR" , "BIF" , "FCV" ,
                                                 "AAB" , "FCK" , "EFB" , "FCN" };
  
  for(k = 0, i = 0, j = 0; k < NUMBER_OF_TEAMS; k++){
    for(i = 0, j = 0; i < MAX_ROUND; i++){
      for(j = 0; j < MAX_MATCH; j++){
        if(strcmp(teams[k], round[i].match[j].h_team) == 0)
          input_home_games_into_table(round, table, i, j, k);
        if(strcmp(teams[k], round[i].match[j].a_team) == 0)
          input_away_games_into_table(round, table, i, j, k);
      }
    }
    strcpy(table[k].team, teams[k]);
    table[k].goal_d = (table[k].goal_f - table[k].goal_a);
  }
  sort_table(table);
  print_table(table);
}

// Helping functions //
void print_match(unsigned int i, unsigned int j, round *round){
  printf(" %.3s %#0.2d/%#0.2d %.5s  %3.3s - %3.3s %2d -%2d %6.lld \n", round[i].match[j].day_of_week,
                                                                         round[i].match[j].date_day,
                                                                         round[i].match[j].date_month,
                                                                         round[i].match[j].time,
                                                                         round[i].match[j].h_team,
                                                                         round[i].match[j].a_team,
                                                                         round[i].match[j].h_goal,
                                                                         round[i].match[j].a_goal,
                                                                         round[i].match[j].spectator);
}
void print_all_matches(round *round){
  unsigned int i, j;
  
  for(i = 0, j = 0; i < MAX_ROUND; i++){
    printf("---------------------Round %d-----------------------\n",i+1);
    for(j = 0; j < MAX_MATCH; j++){
      print_match(i, j, round);
    }
  }
}

// Helping functions for problem six //
void input_home_games_into_table(round *round, table *table, unsigned int i, unsigned int j, unsigned int k){
  table[k].matches += 1;
  table[k].goal_f += round[i].match[j].h_goal;
  table[k].goal_a += round[i].match[j].a_goal;
  if(round[i].match[j].h_goal > round[i].match[j].a_goal){
    table[k].points += WIN_POINT;
    table[k].wins += 1;}
  else if(round[i].match[j].h_goal == round[i].match[j].a_goal){
    table[k].points += DRAW_POINT;
    table[k].draws += 1;}
  else
    table[k].loss += 1;
}
void input_away_games_into_table(round *round, table *table, unsigned int i, unsigned int j, unsigned int k){
  table[k].matches += 1;
  table[k].goal_f += round[i].match[j].a_goal;
  table[k].goal_a += round[i].match[j].h_goal;
  if(round[i].match[j].h_goal < round[i].match[j].a_goal){
    table[k].points += WIN_POINT;
    table[k].wins += 1;}
  else if(round[i].match[j].h_goal == round[i].match[j].a_goal){
    table[k].points += DRAW_POINT;
    table[k].draws += 1;}
  else
    table[k].loss += 1;
}
void print_table(table *table){
  unsigned int i;
  
  printf("Nr.  Team    M    W    D    L    Gf   Ga   +/-    P \n\n");
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
void sort_table(table *table){
  unsigned int i = 0, j = 0;
  
  for(i = 0, j = 0; i < NUMBER_OF_TEAMS; i++){
    for(j = 0; j < NUMBER_OF_TEAMS; j++){
      if(table[j].points < table[j+1].points){
        swap_position(table, j);
      }
      else if(table[j].points == table[j+1].points){
        if(table[j].goal_d < table[j+1].goal_d){
          swap_position(table, j);
        }
        else if(table[j].goal_d == table[j+1].goal_d){
          if(table[j].goal_f < table[j+1].goal_f){
            swap_position(table, j);
          }
          else if(table[j].goal_f == table[j+1].goal_f){
            if(strcmp(table[j].team, table[j+1].team) > 0){
              swap_position(table, j);
            }
          }
        }
      }
    }
  }
}
void swap_position(table *table, unsigned int j){
  struct table temp[1];
  
  temp[0] = table[j];
  table[j] = table[j+1];
  table[j+1] = temp[0];
}











