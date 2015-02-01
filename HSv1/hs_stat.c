// HS Statistics    //
// Thuan Duc Nguyen //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_ARENA_WIN 12
#define MAX_ARENA_LOSS 3
#define TRUE 1
#define FALSE 0


void user_dialogue();
void new_arena();
void view_stat();
void view_late();
void view_m_win();
void reset();
void add_run(int class, int win, int lost);
void print_run(int class_num);
void print_class(int i);


int main(int argc, char *argv[]){
  int stop = FALSE;
  
  while(stop == FALSE){
    user_dialogue(&stop);
  }
  
  return 0;
}

// Main //
void user_dialogue(int *stop){
  int i = 0;
  
  printf( "\n __________________________________ \n"
            ": What you want to do?             :\n"
            ": -------------------------------- :\n"
            ": New Arena                -> 1    :\n"
            ": View Statistics          -> 2    :\n"
            ": View Latest              -> 3    :\n"
            ": View Most Wins           -> 4    :\n"
            ": Quit                     -> 5    :\n"
            ": RESET ALL STATS!!!!      -> 66   :\n"
            ":__________________________________:\n\n");

  scanf("%d",&i);
  system("cls");
  
  switch(i){
    case 1:
      new_arena();
      break;
    case 2:
      view_stat();
      break;
    case 3:
      view_late();
      break;
    case 4:
      view_m_win();
      break;
    case 66:
      reset();
      break;
    default:
      *stop = TRUE;
      break;
  }
}

// Main Functions //
void new_arena(){
  int a = 0, win = 0, lost = 0, i = 0, choice = 0;
  char class[10];
  
  printf( "\n __________________________________ \n"
            ": Class then Win then Loss         :\n"
            ": -------------------------------- :\n"
            ": Druid 12 2                       :\n"
            ":__________________________________:\n\n");
  scanf("%s %d %d", &class, &win, &lost);
  system("cls");
            
  a = class_number(&class);
  if(a && win == MAX_ARENA_WIN && lost < MAX_ARENA_LOSS)
    add_run(a, win, =lost);
    printf( "\n __________________________________ \n"
              ": Run added successfully!          :\n"
              ":__________________________________:\n");
  else if(a && win < MAX_ARENA_WIN && lost == MAX_ARENA_LOSS)
    add_run(a, win, lost);
    printf( "\n __________________________________ \n"
              ": Run added successfully!          :\n"
              ":__________________________________:\n");
  else
    printf( "\n __________________________________ \n"
              ": Wrong inputs(Name, wins or loss) :\n"
              ":__________________________________:\n");
}
void view_stat(){
  int i = 0, stop = FALSE;
  while(stop == FALSE){
    printf( "\n __________________________________ \n"
              ": Choose class or all?             :\n"
              ": -------------------------------- :\n"
              ": All Classes              -> 0    :\n"
              ": Druid                    -> 1    :\n"
              ": Hunter                   -> 2    :\n"
              ": Mage                     -> 3    :\n"
              ": Paladin                  -> 4    :\n"
              ": Priest                   -> 5    :\n"
              ": Rogue                    -> 6    :\n"
              ": Shaman                   -> 7    :\n"
              ": Warlock                  -> 8    :\n"
              ": Warrior                  -> 9    :\n"
              ": Back                     -> 10   :\n"
              ":__________________________________:\n\n");

    scanf("%d",&i);
    system("cls");
    if(i < 10)
      print_run(i);
    else
      stop = TRUE;
  }
}
void view_late(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0;
  
  file = fopen("Stats.txt", "r");
  
  while(fscanf(file, "%d %d %d", &class, &win, &lost) != EOF){
    i++;
  }
  printf( "\n __________________________________ \n"
            ": Latest Arena Run  Nr. %d         :\n"
            ":__________________________________:\n"
            ":                                  :\n\n", i);
  print_class(class);
  printf(": Wins - %d   Loss - %d\n\n"
         ":__________________________________:\n\n",win, lost);
  fclose(file);
}
void view_m_win(){
  FILE *file;
  int class = 0, win = 0, lost = 0;
  int most_win = 0;
  
  file = fopen("Stats.txt", "r");
  
  while(fscanf(file, "%d %d %d", &class, &win, &lost) != EOF){
    if(most_win == 0){
      most_win = win;
    }
    else if(most_win < win){
      most_win = win;
    }
  }
  fclose(file);
  file = fopen("Stats.txt", "r");
  printf( "\n __________________________________ \n"
          ": Most wins is %d                  :\n"
          ":__________________________________:\n\n", most_win);
  while(fscanf(file, "%d %d %d", &class, &win, &lost) != EOF){
    if(win == most_win){
      print_class(class);
      printf(": Wins - %d   Loss - %d\n", win, lost);
    }
  }
  printf("\n:__________________________________:\n\n");
 fclose(file);
}
void reset(){
  if(remove("Stats.txt") == 0)
    printf( "\n __________________________________ \n"
              ": All runs reset successfully      :\n"
              ":__________________________________:\n");
  else{
    printf( "\n __________________________________ \n"
              ": Unable to reset                  :\n"
              ":__________________________________:\n");
  }
}

// Helping Functions //
int class_number(char *class){
  int class_num = 0;
  
  if(strcmp(class, "Druid") == 0)
    class_num = 1;
  else if(strcmp(class, "Hunter") == 0)
    class_num = 2;
  else if(strcmp(class, "Mage") == 0)
    class_num = 3;
  else if(strcmp(class, "Paladin") == 0)
    class_num = 4;
  else if(strcmp(class, "Priest") == 0)
    class_num = 5;
  else if(strcmp(class, "Rogue") == 0)
    class_num = 6;
  else if(strcmp(class, "Shaman") == 0)
    class_num = 7;
  else if(strcmp(class, "Warlock") == 0)
    class_num = 8;
  else if(strcmp(class, "Warrior") == 0)
    class_num = 9;
  else
    class_num = 0;
    
  return class_num;
}
void add_run(int class, int win, int lost){
  FILE *file;

  file = fopen("Stats.txt", "a");

  fprintf(file, " %d %d %d ", class, win, lost);
  
  fclose(file);
}
void print_run(int class_num){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0;
  int win_c = 0, lost_c = 0;
  double  winp = 0.00;
  
  file = fopen("Stats.txt", "r");
  
  if(class_num != 0){
    printf( "\n __________________________________ \n");
    print_class(class_num);
    printf( "\n:__________________________________: \n");
    while(fscanf(file, "%d %d %d", &class, &win, &lost) != EOF){
      if(class == class_num){
        win_c += win;
        lost_c += lost;
        printf(" %d : Wins - %4d   Loss - %4d\n", i+1, win, lost);
        i++;
      }
    }
    winp = ((double)win_c/((double)win_c+(double)lost_c))*100;
    if(win_c+lost_c == 0){
      winp = 0;}
    printf( "\n __________________________________ \n");
    printf("    Matches: %4d\n"
           "    Wins:    %4d\n"
           "    Loss:    %4d\n"
           "    Win Percentage: %.2lf %%", win_c+lost_c, win_c, lost_c, winp);
    printf( "\n __________________________________ \n\n");
  }
  else{
    printf( "\n __________________________________ \n");
    printf( " All Arena Runs");
    printf( "\n __________________________________ \n");
    while(fscanf(file, "%d %d %d", &class, &win, &lost) != EOF){    
      win_c += win;
      lost_c += lost;
      print_class(class);
      printf(": Wins - %4d   Loss - %d\n",win, lost);
    }
    winp = ((double)win_c/((double)win_c+(double)lost_c))*100;
    if(win_c+lost_c == 0){
      winp = 0;}
    printf( "\n __________________________________ \n");
    printf("    Matches: %4d\n"
           "    Wins:    %4d\n"
           "    Loss:    %4d\n"
           "    Win Percentage: %.2lf %%", win_c+lost_c, win_c, lost_c, winp);
    printf( "\n __________________________________ \n\n");
  }
  fclose(file);
}
void print_class(int i){
  switch(i){
    case 1:
      printf(" Druid   ");
      break;
    case 2:
      printf(" Hunter  ");
      break;
    case 3:
      printf(" Mage    ");
      break;
    case 4:
      printf(" Paladin ");
      break;
    case 5:
      printf(" Priest  ");
      break;
    case 6:
      printf(" Rogue   ");
      break;
    case 7:
      printf(" Shaman  ");
      break;
    case 8:
      printf(" Warlock ");
      break;
    case 9:
      printf(" Warrior ");
      break;
  }
}

  

