// Aalborg Universitet - Imperativ Programmering - Eksamensopgave //
// Thuan Duc Nguyen - tnguy14@student.aau.dk                      //
// Software - A405c                                               //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ROUND_PER_SEASON 33
#define MAX_MATCH_PER_ROUND 6
#define NAMEDAY_SIZE 4
#define TIME_SIZE 6
#define NUMBER_OF_TEAMS 12
#define TEAMNAME_SIZE 4
#define THOUSAND 1000
#define SEVEN 7
#define WIN_POINT 3
#define DRAW_POINT 1

// Structure "match" and "round" is for the file data, "table" is for the sixth assignment //
typedef struct match{
  char day_of_week[NAMEDAY_SIZE];
  int date_day;
  int date_month; 
  char time[TIME_SIZE];
  char h_team[TEAMNAME_SIZE];
  char a_team[TEAMNAME_SIZE];
  int h_goal;
  int a_goal;
  long long spectator;
}match;
typedef struct round{
  match match[MAX_MATCH_PER_ROUND];
}round;
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

// Prototypes for pre-solving functions //
void read_copy_file(round *round);
void do_one_of_the_problems(round *round, table *table);
void do_all_problems(round *round, table *table);

// Prototypes for all assignments //
void solve_problem_one(round *round);
void solve_problem_two(round *round);
void solve_problem_three(round *round);
void solve_problem_four(round *round);
void solve_problem_five(round *round, char *u, char *k1, char *k2);
void solve_problem_six(round *round, table *table);

// Prototypes for all the helping functions //
void print_match(int i, int j, round *round);
void print_all_matches(round *round);
void sort_matches(match *matches, int k);
void print_matches(match *matches, int k);
void swap_position_matches(match *matches, int j);
void input_home_games_into_table(round *round, table *table, int i, int j, int k);
void input_away_games_into_table(round *round, table *table, int i, int j, int k);
void print_table(table *table);
void sort_table(table *table);
void swap_position_table(table *table, int j);

// Mainly for determine whether to have the user dialogue or not //
int main(int argc, char *argv[]){
  struct round round[MAX_ROUND_PER_SEASON];
  struct table table[NUMBER_OF_TEAMS];
  
  read_copy_file(round);
  
  if(argc > 1 && strcmp(argv[1],"--print") == 0)
    do_all_problems(round, table);
  else
    do_one_of_the_problems(round, table);
    
  return 0;
}

// Read given file and copy data into the program //
void read_copy_file(round *round){
  FILE *superliga;
  int i, j;
  long long k, l;

  superliga = fopen("superliga-2013-2014","r");
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
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

// Solve one problem of the users wish, or do all of them //
void do_one_of_the_problems(round *round, table *table){
  int i = 0;
  char u[NAMEDAY_SIZE], k1[TIME_SIZE], k2[TIME_SIZE];
  
  printf("\n __________________________\n"
           ": Select an assignment:    :\n"
           ": Assignment from 1 to 6   :\n"
           ": Print All Assignment 7   :\n"
           ": Print All Matches 8      :\n"
           ":__________________________:\n\n");
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
      printf("\n--------------------Problem 5---------------------- \n\n"
             "All matches for %s between the time %s and %s \n\n",u, k1, k2);
      solve_problem_five(round, u, k1, k2);
      break;
    case 6:
      printf("\n--------------------Problem 6---------------------- \n\n");
      solve_problem_six(round, table);
      break;
    case 7:
      printf("\n----------------All Assignments---------------------- \n\n");
      do_all_problems(round, table);
      break;
    case 8:
      printf("\n--------------------All Matches---------------------- \n\n");
      print_all_matches(round);
      break;
    default:
      printf("Invalid Choice\n\n");
      break;
  }
}
void do_all_problems(round *round, table *table){
  char u[NAMEDAY_SIZE] = "Fre",
       k1[TIME_SIZE] = "18.05",
       k2[TIME_SIZE] = "19.05"; // Pre-set values for problem five //
  
  printf("\n--------------------Problem 1---------------------- \n\n");
  solve_problem_one(round);
  printf("\n--------------------Problem 2---------------------- \n\n");
  solve_problem_two(round);
  printf("\n--------------------Problem 3---------------------- \n\n");
  solve_problem_three(round);
  printf("\n--------------------Problem 4---------------------- \n\n");
  solve_problem_four(round);
  printf("\n--------------------Problem 5---------------------- \n\n"
         " All matches for %s between the time %s and %s \n\n", u, k1, k2);
  solve_problem_five(round, u, k1, k2);
  printf("\n--------------------Problem 6---------------------- \n\n");
  solve_problem_six(round, table);
}

// Main function for solving the assignments //
void solve_problem_one(round *round){
  int i = 0, j = 0;
  
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      if(round[i].match[j].h_goal + round[i].match[j].a_goal >= SEVEN)
        print_match(i, j, round);
    }
  }
}
void solve_problem_two(round *round){
  int i = 0, j = 0, 
      temp_res = 0, res = 0, round_res = 0;
  
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
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
  int i = 0, j = 0, k = 0, 
      h_win = 0, a_win = 0;
  
  char teams[NUMBER_OF_TEAMS][TEAMNAME_SIZE] = { "AGF" , "FCM" , "VFF" , "RFC" ,
                                                 "OB"  , "SDR" , "BIF" , "FCV" ,
                                                 "AAB" , "FCK" , "EFB" , "FCN" };
  
  for(k = 0, i = 0, j = 0; k < NUMBER_OF_TEAMS; k++){
    for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
      for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
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
    for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
      for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
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
  int i = 0, j = 0, k = 0;
  struct match matches[MAX_MATCH_PER_ROUND*MAX_ROUND_PER_SEASON];
  
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      if(strcmp(u, round[i].match[j].day_of_week) == 0 && strcmp(k1, round[i].match[j].time) <= 0 && strcmp(k2, round[i].match[j].time) >= 0){
        matches[k] = round[i].match[j];
        k++;
      }
    }
  }
  if(k != 0){
    sort_matches(matches, k);
    print_matches(matches, k);}
  else
    printf("No matches at this time\n\n");
}
void solve_problem_six(round *round, table *table){
  int i = 0, j = 0, k = 0;
  char teams[NUMBER_OF_TEAMS][TEAMNAME_SIZE] = { "AGF" , "FCM" , "VFF" , "RFC" ,
                                                 "OB"  , "SDR" , "BIF" , "FCV" ,
                                                 "AAB" , "FCK" , "EFB" , "FCN" };
  
  for(k = 0, i = 0, j = 0; k < NUMBER_OF_TEAMS; k++){
    for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
      for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
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

// Helping functions or extra functions //
void print_match(int i, int j, round *round){
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
  int i = 0, j = 0;
  
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    printf("---------------------Round %d-----------------------\n",i+1);
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      print_match(i, j, round);
    }
  }
}

// Helping functions for only problem five //
void sort_matches(match *matches, int k){
  int i = 0, j = 0;
  
  for(i = 0, j = 0; i < k; i++){
    for(j = 0; j < k; j++){
      if((matches[j].h_goal+matches[j].a_goal) < (matches[j+1].h_goal+matches[j+1].a_goal))
        swap_position_matches(matches, j);
    }
  }
}
void print_matches(match *matches, int k){
  int i = 0;
  
  for(i = 0; i < k; i++){
    printf(" %.3s %#0.2d/%#0.2d %.5s  %3.3s - %3.3s %2d -%2d %6.lld \n", matches[i].day_of_week,
                                                                         matches[i].date_day,
                                                                         matches[i].date_month,
                                                                         matches[i].time,
                                                                         matches[i].h_team,
                                                                         matches[i].a_team,
                                                                         matches[i].h_goal,
                                                                         matches[i].a_goal,
                                                                         matches[i].spectator);
  }
}
void swap_position_matches(match *matches, int j){
  struct match temp[1];
  
  temp[0] = matches[j];
  matches[j] = matches[j+1];
  matches[j+1] = temp[0];
}

// Helping functions for only problem six //
void input_home_games_into_table(round *round, table *table, int i, int j, int k){
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
void input_away_games_into_table(round *round, table *table, int i, int j, int k){
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
  int i = 0;
  
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
  int i = 0, j = 0;
  
  for(i = 0, j = 0; i < NUMBER_OF_TEAMS; i++){
    for(j = 0; j < NUMBER_OF_TEAMS; j++){
      if(table[j].points < table[j+1].points){
        swap_position_table(table, j);
      }
      else if(table[j].points == table[j+1].points){
        if(table[j].goal_d < table[j+1].goal_d){
          swap_position_table(table, j);
        }
        else if(table[j].goal_d == table[j+1].goal_d){
          if(table[j].goal_f < table[j+1].goal_f){
            swap_position_table(table, j);
          }
          else if(table[j].goal_f == table[j+1].goal_f){
            if(strcmp(table[j].team, table[j+1].team) > 0){
              swap_position_table(table, j);
            }
          }
        }
      }
    }
  }
}
void swap_position_table(table *table, int j){
  struct table temp[1];
  
  temp[0] = table[j];
  table[j] = table[j+1];
  table[j+1] = temp[0];
}











