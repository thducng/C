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

// Structure "MATCH" and "ROUND" is for the file data, "TABLE" is for the sixth assignment //
typedef struct MATCH{
  char day_of_week[NAMEDAY_SIZE];
  int date_day;
  int date_month; 
  char time[TIME_SIZE];
  char h_team[TEAMNAME_SIZE];
  char a_team[TEAMNAME_SIZE];
  int h_goal;
  int a_goal;
  long long spectator;
}MATCH;
typedef struct ROUND{
  MATCH match[MAX_MATCH_PER_ROUND];
}ROUND;
typedef struct TABLE{
  char team[TEAMNAME_SIZE];
  int matches;
  int wins;
  int draws;
  int loss;
  int goal_f;
  int goal_a;
  int goal_d;
  int points;
}TABLE;

// Prototypes for pre-solving functions //
void read_copy_file(ROUND *round);
void do_one_of_the_problems(ROUND *round);
void do_all_problems(ROUND *round);

// Prototypes for all assignments //
void solve_problem_one(ROUND *round);
void solve_problem_two(ROUND *round);
void solve_problem_three(ROUND *round);
void solve_problem_four(ROUND *round);
void solve_problem_five(ROUND *round, char *u, char *k1, char *k2);
void solve_problem_six(ROUND *round);

// Prototypes for all the helping functions //
void print_match(int i, int j, ROUND *round);
void print_all_matches(ROUND *round);
int spec_string_to_integer(char *spec_s);
void print_matches(MATCH *matches, int k);
int goal_cmp(const void *match1, const void* match2);
void input_home_games_into_table(ROUND *round, TABLE *table, int i, int j, int k);
void input_away_games_into_table(ROUND *round, TABLE *table, int i, int j, int k);
void print_table(TABLE *table);
int point_goal_name_cmp(const void *team1, const void *team2);

// Mainly for determine whether to have the user dialogue or not //
int main(int argc, char *argv[]){
  struct ROUND round[MAX_ROUND_PER_SEASON];
  
  read_copy_file(round);
  
  if(argc > 1 && strcmp(argv[1],"--print") == 0)
    do_all_problems(round);
  else
    do_one_of_the_problems(round);
    
  return 0;
}

// Read given file and copy data into the program //
void read_copy_file(ROUND *round){
  FILE *superliga;
  int i, j;
  char spec_in_string[256];

  superliga = fopen("superliga-2013-2014","r");
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      fscanf(superliga," %s %d / %d %s %s - %s %d - %d %s", &round[i].match[j].day_of_week,
                                                            &round[i].match[j].date_day,
                                                            &round[i].match[j].date_month,
                                                            &round[i].match[j].time,
                                                            &round[i].match[j].h_team,
                                                            &round[i].match[j].a_team,
                                                            &round[i].match[j].h_goal,
                                                            &round[i].match[j].a_goal,
                                                            &spec_in_string);
                                                                     
      round[i].match[j].spectator = spec_string_to_integer(spec_in_string);
    }
  }
  fclose(superliga);
}

// Solve one problem of the users wish, or do all of them //
void do_one_of_the_problems(ROUND *round){
  int i = 0;
  char u[NAMEDAY_SIZE], k1[TIME_SIZE], k2[TIME_SIZE];
  
  printf("\n __________________________\n"
           ": Select an option:        :\n"
           ": Assignment from: 1 to 6  :\n"
           ": Print All Assignment: 7  :\n"
           ": Print All Matches: 8     :\n"
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
      printf("\nEnter a weekday(Fre), and a timeframe(18.05 19.05): ");
      scanf("%s %s %s", u, k1, k2);
      printf("\n--------------------Problem 5---------------------- \n\n"
             "All matches for %s between the time %s and %s \n\n",u, k1, k2);
      solve_problem_five(round, u, k1, k2);
      break;
    case 6:
      printf("\n--------------------Problem 6---------------------- \n\n");
      solve_problem_six(round);
      break;
    case 7:
      printf("\n------------------All Assignments-------------------- \n\n");
      do_all_problems(round);
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
void do_all_problems(ROUND *round){
  char u[NAMEDAY_SIZE] = "Fre",
       k1[TIME_SIZE] = "18.05",
       k2[TIME_SIZE] = "19.05"; // Pre-set values for problem five //
       
  printf("\n------------------All Assignments-------------------- \n\n");
  printf("\n--------------------Problem 1---------------------- \n\n");
  solve_problem_one(round);
  printf("\n--------------------Problem 2---------------------- \n\n");
  solve_problem_two(round);
  printf("\n--------------------Problem 3---------------------- \n\n");
  solve_problem_three(round);
  printf("\n--------------------Problem 4---------------------- \n\n");
  solve_problem_four(round);
  printf("\n--------------------Problem 5---------------------- \n\n"
         "All matches for %s between the time %s and %s \n\n",u, k1, k2);
  solve_problem_five(round, u, k1, k2);
  printf("\n--------------------Problem 6---------------------- \n\n");
  solve_problem_six(round);
}

// Main function for solving the assignments //
void solve_problem_one(ROUND *round){
  int i = 0, j = 0;
  
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      if(round[i].match[j].h_goal + round[i].match[j].a_goal >= SEVEN)
        print_match(i, j, round);
    }
  }
}
void solve_problem_two(ROUND *round){
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
void solve_problem_three(ROUND *round){
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
void solve_problem_four(ROUND *round){
  int i = 0, j = 0, k = 0, team = 0; 
  long long temp_spec = 0, least_specs = 0;
  
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
    if(least_specs > temp_spec){
      least_specs  = temp_spec;
      team      = k;
      temp_spec = 0;}
    else if(least_specs == 0)
      least_specs  = temp_spec;
    else
      temp_spec = 0;
  }
  printf("Team %s, had %lld spectators at all home games.\n"
         "Which makes it the team with least spectators.\n", teams[team], least_specs);
}
void solve_problem_five(ROUND *round, char *u, char *k1, char *k2){
  int i = 0, j = 0, k = 0;
  struct MATCH matches[MAX_MATCH_PER_ROUND*MAX_ROUND_PER_SEASON];
  
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      if(strcmp(u, round[i].match[j].day_of_week) == 0 &&
         strcmp(k1, round[i].match[j].time) <= 0 && 
         strcmp(k2, round[i].match[j].time) >= 0){
         
        matches[k] = round[i].match[j];
        k++;
      }
    }
  }
  if(k != 0){
    qsort(matches, k, sizeof(MATCH), goal_cmp);
    print_matches(matches, k);}
  else
    printf("No matches at this time\n\n");
}
void solve_problem_six(ROUND *round){
  int i = 0, j = 0, k = 0;
  struct TABLE table[MAX_MATCH_PER_ROUND*MAX_ROUND_PER_SEASON];
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
  qsort(table,NUMBER_OF_TEAMS,sizeof(TABLE),point_goal_name_cmp);
  print_table(table);
}

// Helping functions or extra functions //
void print_match(int i, int j, ROUND *round){
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
void print_all_matches(ROUND *round){
  int i = 0, j = 0;
 
  for(i = 0, j = 0; i < MAX_ROUND_PER_SEASON; i++){
    printf("---------------------Round %d-----------------------\n",i+1);
    for(j = 0; j < MAX_MATCH_PER_ROUND; j++){
      print_match(i, j, round);
    }
  }
}
int spec_string_to_integer(char *spec_s){
  char *thousands_s, *hundreds_s;
  char *dot = ".";
  
  if(strchr(spec_s,'.') != 0){
    thousands_s = strtok(spec_s, dot);
    hundreds_s  = strtok(NULL, " ");
    
    return (atoi(thousands_s)*THOUSAND)+atoi(hundreds_s);}
  else
    return atoi(spec_s);
}

// Helping functions for only problem five //
void print_matches(MATCH *matches, int k){
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
int goal_cmp(const void *match1, const void* match2){
  int match1_int = (((MATCH *)match1)->h_goal + ((MATCH *)match1)->a_goal),
      match2_int = (((MATCH *)match2)->h_goal + ((MATCH *)match2)->a_goal);

  return match2_int - match1_int;
}

// Helping functions for only problem six //
void input_home_games_into_table(ROUND *round, TABLE *table, int i, int j, int k){
  table[k].matches  += 1;
  table[k].goal_f   += round[i].match[j].h_goal;
  table[k].goal_a   += round[i].match[j].a_goal;
  if(round[i].match[j].h_goal > round[i].match[j].a_goal){
    table[k].points += WIN_POINT;
    table[k].wins   += 1;}
  else if(round[i].match[j].h_goal == round[i].match[j].a_goal){
    table[k].points += DRAW_POINT;
    table[k].draws  += 1;}
  else
    table[k].loss   += 1;
}
void input_away_games_into_table(ROUND *round, TABLE *table, int i, int j, int k){
  table[k].matches  += 1;
  table[k].goal_f   += round[i].match[j].a_goal;
  table[k].goal_a   += round[i].match[j].h_goal;
  if(round[i].match[j].h_goal < round[i].match[j].a_goal){
    table[k].points += WIN_POINT;
    table[k].wins   += 1;}
  else if(round[i].match[j].h_goal == round[i].match[j].a_goal){
    table[k].points += DRAW_POINT;
    table[k].draws  += 1;}
  else
    table[k].loss   += 1;
}
void print_table(TABLE *table){
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
int point_goal_name_cmp(const void *team1, const void *team2){
  int point_cmp      = ((TABLE *)team2)->points - ((TABLE *)team1)->points,
      goal_diff_cmp  = ((TABLE *)team2)->goal_d - ((TABLE *)team1)->goal_d,
      goal_total_cmp = ((TABLE *)team2)->goal_f - ((TABLE *)team1)->goal_f;
  
  if(point_cmp != 0)
    return point_cmp;
  else if(goal_diff_cmp != 0)
    return goal_diff_cmp;
  else if(goal_total_cmp != 0)
    return goal_total_cmp;
  else
    return strcmp(((TABLE *)team1)->team,((TABLE *)team2)->team);  
}