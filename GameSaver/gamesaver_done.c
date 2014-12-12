// Odds Statistic Saver //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_CHAR 20

typedef struct GAME{
  char hteam[MAX_CHAR];
  char ateam[MAX_CHAR];
  int wdl; // 1 0 2 //
  double odds;
  double bet;
  char result; // W or L //
  double profit;
  int done;
}GAME;


// PROTOYPES //
int read_file(int d, GAME *dgame, GAME *ugame);
void user_dialogue(GAME *dgame, GAME *ugame);
void check_profit(GAME *dgame, int *done);
void highest_profit(GAME *dgame, int *done);
void show_list(GAME *dgame, int *done);
void show_undone_list(GAME *ugame, int *count);
void add_game(GAME *ugame, int *count);
void add_result(GAME *ugame, int *count);
int done_cmp(const void *game1, const void *game2);
void show_loss(GAME *dgame, int *done);
void show_wins(GAME *dgame, int *done);
void show_all_list(GAME *dgame, int *done);

int main(void){
  GAME dgame[256];
  GAME ugame[256];
  
  user_dialogue(dgame, ugame);
  
  return 0;
}

// FUNCTIONS //

int read_file(int d, GAME *dgame, GAME *ugame){
  int i = 0, j = 0, count = 0;
  FILE *file;
  file = fopen("statistic_odds.txt", "r");
  
  if(d == 1){
    while(fscanf(file, "%s vs %s %d %lf %lf %c %lf %d", &dgame[i].hteam,
                                                        &dgame[i].ateam,
                                                        &dgame[i].wdl,
                                                        &dgame[i].odds,
                                                        &dgame[i].bet,
                                                        &dgame[i].result,
                                                        &dgame[i].profit,
                                                        &dgame[i].done) != EOF){
      if(dgame[i].done == 1){
        i++;
        count++;}
    }
    fclose(file);
    return count;
  }
  else{
    while(fscanf(file, "%s vs %s %d %lf %lf %c %lf %d", &ugame[i].hteam,
                                                        &ugame[i].ateam,
                                                        &ugame[i].wdl,
                                                        &ugame[i].odds,
                                                        &ugame[i].bet,
                                                        &ugame[i].result,
                                                        &ugame[i].profit,
                                                        &ugame[i].done) != EOF){

      i++;
      count++;
    }
    fclose(file);
    return count;
  }
}

void user_dialogue(GAME *dgame, GAME *ugame){
  int j = 1, choice = 0, done, count;
  
  while(j){
    done = read_file(1, dgame, ugame);
    count = read_file(0, dgame, ugame);
    
    printf("\n_____________________________\n"
            ": Check profit     -   1      :\n"
            ": Highest profit   -   2      :\n"
            ": Show done list   -   3      :\n"
            ": Show undone list -   4      :\n"
            ": Add Game         -   5      :\n"
            ": Add Result       -   6      :\n"
            ": Quit             -   q      :\n"
            ":_____________________________:\n\n");
            
    if(scanf("%d", &choice) == 1){
      printf("\n");
      switch(choice){
        case 1:
          check_profit(dgame, &done);
          break;
        case 2:
          highest_profit(dgame, &done);
          break;
        case 3:
          show_list(dgame, &done);
          break;
        case 4:
          show_undone_list(ugame, &count);
          break;
        case 5:
          add_game(ugame, &count);
          break;
        case 6:
          add_result(ugame, &count);
          break;
        default:
          printf("Thanks!\n");
          j = 0;
          break;
      }
    }
    else
      j = 0;
  }
}
void highest_profit(GAME *dgame, int *done){
  int i = 0, j = 0, 
      temp_high = 0, high = 0;
  
  for(i = 0; i < *done; i++){
    if(dgame[high].profit < dgame[i].profit){
      high = i;}

  }
  printf("\n ___________________________________________________________________________\n");
  printf(": Home Team  vs  Away Team  1x2  Odds          Bet      Result       Profit :\n");
  printf(": ------------------------------------------------------------------------- :\n");
  for(i = 0; i < *done; i++){
    if(i == high)
      printf(": %-10s vs %10s %3d   %2.2lf  %10.2lf DKK %5.5c  %+10.2lf DKK :\n",  dgame[i].hteam,
                                                                                   dgame[i].ateam,
                                                                                   dgame[i].wdl,
                                                                                   dgame[i].odds,
                                                                                   dgame[i].bet,
                                                                                   dgame[i].result,
                                                                                   dgame[i].profit);

  }
  printf(":___________________________________________________________________________:\n");
}
void check_profit(GAME *dgame, int *done){
  int i = 0, j = 0;
  double profit = 0;
  
  while(j < *done){
    if(dgame[i].done == 1){
      profit += dgame[i].profit;
      j++;
      i++;
    }
    else
      i++;
  }
  printf("\n _____________________________________\n"
          ": Current profit is: %+10.2lf DKK   :\n"
          ": After %4d bets                     :\n"
          ":_____________________________________:\n\n", profit, *done);

}
void show_list(GAME *dgame, int *done){
  int choice;
  printf("\n_____________________________\n"
          ": Show wins list   -   1      :\n"
          ": Show loss list   -   2      :\n"
          ": Show all list    -   3      :\n"
          ": Back             -   4      :\n"
          ":_____________________________:\n\n");
  scanf("%d", &choice);
  
  switch(choice){
    case 1:
      show_wins(dgame, done);
      break;
    case 2:
      show_loss(dgame, done);
      break;
    case 3:
      show_all_list(dgame, done);
      break;
  }
}
void show_undone_list(GAME *ugame, int *count){
  int i = 0, j = 0;
  printf("\n _____________________________________________________________________________\n");
  printf(": Home Team  vs  Away Team  1x2    Odds          Bet      Result       Profit :\n");
  printf(": --------------------------------------------------------------------------- :\n");
  for(i = 0; i < *count; i++){
    if(ugame[i].done == 0 && ugame[i].result == 'N' && ugame[i].profit == 0.00){
      printf(": %-10s vs %10s %3d   %4.2lf  %10.2lf DKK %5.5c  %+10.2lf DKK :\n",  ugame[i].hteam,
                                                                                   ugame[i].ateam,
                                                                                   ugame[i].wdl,
                                                                                   ugame[i].odds,
                                                                                   ugame[i].bet,
                                                                                   ugame[i].result,
                                                                                   ugame[i].profit);
      j++;
    }
  }
  if(j < 1){
    printf(": No pending games                                                            :\n");}
    
  printf(":_____________________________________________________________________________:\n");
}
void add_game(GAME *ugame, int *count){
  int j = 1, i = *count, new_games = 0;
  char choice[2] = {"d"};
  FILE *file;
  
  printf("\n______________________________________\n"
          ": Team_Name, use '_' instead of space. :\n"
          ": Team_Name, keep it max 10 characters.:\n"
          ": Separate home_team and away_team     :\n"
          ": with vs XXXXX vs XXXXX.              :\n"
          ":______________________________________:\n\n");
          
  while(j > 0){
    printf("\n______________________________________\n"
            ": Write 'home_team vs away_team'.      :\n"
            ":______________________________________:\n\n");
    scanf("%s vs %s", ugame[i].hteam,
                      ugame[i].ateam);
    
    if(strlen(ugame[i].hteam) <= 10 && strlen(ugame[i].ateam) <= 10){
      printf("\n______________________________________\n"
              ": Write '1, 0 or 2'.                   :\n"
              ":______________________________________:\n\n");
      scanf("%d",&ugame[i].wdl);
        
      printf("\n______________________________________\n"
              ": Write 'Odds'.                        :\n"
              ":______________________________________:\n\n");
      scanf("%lf", &ugame[i].odds);
      
      printf("\n______________________________________\n"
              ": Write 'Bet'.                        :\n"
              ":______________________________________:\n\n");
      scanf("%lf", &ugame[i].bet);
      
      strcpy(&ugame[i].result, "N");
      ugame[i].done = 0;
                       
      printf("\n______________________________________\n"
              ": Add another game, d for delete? (y/n):\n"
              ":______________________________________:\n\n");
      scanf("%s", &choice);}
    
    if(strcmp(choice, "y") == 0){
      new_games++;
      i++;}
    else if(strcmp(choice, "n") == 0){
      new_games++;
      j = 0;
      i++;}
    else{
      printf("\n______________________________________\n"
              ": Add a game? (y/n)                    :\n"
              ":______________________________________:\n\n");
      scanf("%s", &choice);
      if(strcmp(choice, "n") == 0)
        j = 0;
    }  
  }
  if(new_games > 0){
    qsort(ugame, i, sizeof(GAME), done_cmp);
    remove("statistic_odds.txt");
    file = fopen("statistic_odds.txt", "wb");
    if(!file){
      printf("Error\n");}
    else{
      for(j = 0; j < i; j++){
        fprintf(file, "%s vs %s %d %lf %lf %c %lf %d \n",  ugame[j].hteam,
                                                           ugame[j].ateam,
                                                           ugame[j].wdl,
                                                           ugame[j].odds,
                                                           ugame[j].bet,
                                                           ugame[j].result,
                                                           ugame[j].profit,
                                                           ugame[j].done);}
    }
    fclose(file);
  }
}
void add_result(GAME *ugame, int *count){
  int i = 0, j = 0, choice = 0, p = 1, dones = 0;
  char mbquit[2];
  
  while(p == 1){
    printf("\n ____________________________________________________________________________\n");
    printf(": Choose one of the following games to add a result to, q for quit:          :\n");
    printf(": -------------------------------------------------------------------------- :\n");
    printf(": Nr  Home Team  vs  Away Team  1x2  Odds       Bet      Result       Profit :\n");
    printf(": -------------------------------------------------------------------------- :\n");
    for(i = 0; i < *count; i++){
      if(ugame[i].done == 0 && ugame[i].result == 'N' && ugame[i].profit == 0.00){
        printf(": %#02d  %-10s vs %10s %3d   %2.2lf %8.2lf DKK %5.5c  %+10.2lf DKK :\n", i,
                                                                                       ugame[i].hteam,
                                                                                       ugame[i].ateam,
                                                                                       ugame[i].wdl,
                                                                                       ugame[i].odds,
                                                                                       ugame[i].bet,
                                                                                       ugame[i].result,
                                                                                       ugame[i].profit);
        j++;
      }
    }
    if(j < 1){
      printf(": No pending games                                                           :\n");
      printf(":____________________________________________________________________________:\n");}
    else{
      printf(":____________________________________________________________________________:\n\n");
      scanf("%s", &mbquit);
      
      if(strcmp(mbquit, "q") == 0){
        p = 0;
        printf("hej\n");}
      else{
        choice = atoi(mbquit);
      
        printf("\n______________________________________\n"
                ": Write 'W or L or N for miss click'.  :\n"
                ":______________________________________:\n\n");
                
        scanf("%s", &ugame[choice].result);
        
        
        if(strcmp(&ugame[choice].result, "W") == 0){
          ugame[choice].profit = ugame[choice].bet * ugame[choice].odds;
          ugame[choice].done = 1;
          dones++;
          
          printf("\n __________________________________________\n"
                  ": Congratulation you won %+10.2lf DKK    :\n"
                  ":__________________________________________:\n\n", ugame[choice].profit);}
                  
        else if(strcmp(&ugame[choice].result, "L") == 0){
          ugame[choice].profit = 0 - ugame[choice].bet;
          ugame[choice].done = 1;
          dones++;
        
          printf("\n __________________________________________\n"
                  ": To bad, you lost %+10.2lf DKK          :\n"
                  ":__________________________________________:\n\n", ugame[choice].profit);}
                     
      }
    }
  }
 if(dones > 0){
  qsort(ugame, *count, sizeof(GAME), done_cmp);
  FILE *file;
  remove("statistic_odds.txt");
  file = fopen("statistic_odds.txt", "wb");
    if(!file){
      printf("Error\n");}
    else{
      for(j = 0; j < *count; j++){
        fprintf(file, "%s vs %s %d %lf %lf %c %lf %d \n",  ugame[j].hteam,
                                                           ugame[j].ateam,
                                                           ugame[j].wdl,
                                                           ugame[j].odds,
                                                           ugame[j].bet,
                                                           ugame[j].result,
                                                           ugame[j].profit,
                                                           ugame[j].done);}
    }
    fclose(file);
  }
}

int done_cmp(const void *game1, const void *game2){
  int done_or_not  = ((GAME *)game2)->done - ((GAME *)game1)->done;
  
  return done_or_not;
}
void show_all_list(GAME *dgame, int *done){
  int i = 0, j = 0;
  printf("\n ___________________________________________________________________________\n");
  printf(": Home Team  vs  Away Team  1x2  Odds          Bet      Result       Profit :\n");
  printf(": ------------------------------------------------------------------------- :\n");
  for(i = 0; i < *done; i++){
    if(dgame[i].done == 1)
      printf(": %-10s vs %10s %3d   %2.2lf  %10.2lf DKK %5.5c  %+10.2lf DKK :\n",  dgame[i].hteam,
                                                                                   dgame[i].ateam,
                                                                                   dgame[i].wdl,
                                                                                   dgame[i].odds,
                                                                                   dgame[i].bet,
                                                                                   dgame[i].result,
                                                                                   dgame[i].profit);

  }
  printf(":___________________________________________________________________________:\n");
}
void show_wins(GAME *dgame, int *done){
  int i = 0, j = 0;
  printf("\n ___________________________________________________________________________\n");
  printf(": Home Team  vs  Away Team  1x2  Odds          Bet      Result       Profit :\n");
  printf(": ------------------------------------------------------------------------- :\n");
  for(i = 0; i < *done; i++){
    if(dgame[i].done == 1 && strcmp(&dgame[i].result, "W") == 0)
      printf(": %-10s vs %10s %3d   %2.2lf  %10.2lf DKK %5.5c  %+10.2lf DKK :\n",  dgame[i].hteam,
                                                                                   dgame[i].ateam,
                                                                                   dgame[i].wdl,
                                                                                   dgame[i].odds,
                                                                                   dgame[i].bet,
                                                                                   dgame[i].result,
                                                                                   dgame[i].profit);

  }
  printf(":___________________________________________________________________________:\n");
}
void show_loss(GAME *dgame, int *done){
  int i = 0, j = 0;
  printf("\n ___________________________________________________________________________\n");
  printf(": Home Team  vs  Away Team  1x2  Odds          Bet      Result       Profit :\n");
  printf(": ------------------------------------------------------------------------- :\n");
  for(i = 0; i < *done; i++){
    if(dgame[i].done == 1 && strcmp(&dgame[i].result, "L") == 0)
      printf(": %-10s vs %10s %3d   %2.2lf  %10.2lf DKK %5.5c  %+10.2lf DKK :\n",  dgame[i].hteam,
                                                                                   dgame[i].ateam,
                                                                                   dgame[i].wdl,
                                                                                   dgame[i].odds,
                                                                                   dgame[i].bet,
                                                                                   dgame[i].result,
                                                                                   dgame[i].profit);

  }
  printf(":___________________________________________________________________________:\n");
}











