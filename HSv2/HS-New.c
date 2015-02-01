#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_ARENA_WIN 12
#define MAX_ARENA_LOSS 3
#define TRUE 1
#define FALSE 0

void user_dialog(int *stop);
void pre_stats();

void new_arena();
void delete_arena();
void view_late();
void view_m_win();
void recover_run();

void add_run(int class, int win, int lost);
void print_run(int class_num);
void print_class(int i);
int class_number(char *class);
void print_all();
void print_class1(int class, int win, int lost);

int main(void){
  int stop = FALSE;
  system("cls");
  
  while(stop == FALSE){
    pre_stats();
    user_dialog(&stop); 
  }
  return 0;
}

void pre_stats(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  
  file = fopen("Stats.txt", "r");
  
  printf( "\n __________________________________ \n");
  printf(   ": Statistics                       :\n");
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){    
    if(delete == FALSE){
      win_c += win;
      lost_c += lost;
      runs++;
    }
  }
  winp = ((double)win_c/((double)win_c+(double)lost_c))*100;
  
  if(win_c+lost_c == 0){
    winp = 0;}
    
  printf(   ": -------------------------------- :\n");
  printf(   ": Matches: %4d                    :\n"
            ": Runs:    %4d                    :\n"
            ": Wins:    %4d                    :\n"
            ": Loss:    %4d                    :\n"
            ": Win Percentage: %.2lf %%          :\n", win_c+lost_c, runs, win_c, lost_c, winp);
  printf( ":__________________________________: \n");
}
void user_dialog(int *stop){
  int i = 0, classnum = 0;
  char choice[10];
  char *choicep = choice;
  
  printf( "\n __________________________________ \n"
            ": Command list below:              :\n"
            ": -------------------------------- :\n"
            ": New Arena                -> 1    :\n"
            ": Delete Arena             -> 2    :\n"
            ": View Latest              -> 3    :\n"
            ": View Most Wins           -> 4    :\n"
            ": Quit                     -> 5    :\n"
            ": -------------------------------- :\n"
            ": Enter class name to get specific :\n"
            ": class statistics or 'all'        :\n"
            ": 'Hunter' or 'Warrior' or 'Mage'  :\n"
            ":__________________________________:\n\n");

  scanf("%s",&choice);
  system("cls");
  
  if(strcmp(choicep, "1") == 0 || strcmp(choicep, "2") == 0 || strcmp(choicep, "3") == 0 ||
     strcmp(choicep, "4") == 0 || strcmp(choicep, "5") == 0){
    i = atoi(choicep);   
    switch(i){
      case 1:
        new_arena();
        break;
      case 2:
        delete_arena();
        break;
      case 3:
        view_late();
        break;
      case 4:
        view_m_win();
        break;
      default:
        *stop = TRUE;
        break;
    }
  }
  else{
    classnum = class_number(choice);
  
    if(classnum > 0 && classnum != 10 && classnum != 11){
      print_run(classnum);
    }
    else if(classnum == 10){
      recover_run();
    }
    else if(classnum == 11){
      print_all();
    }
  }
}

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
            
  a = class_number(class);
  if(a && win == MAX_ARENA_WIN && lost < MAX_ARENA_LOSS){
    add_run(a, win, lost);
    printf( "\n __________________________________ \n"
              ": Run added successfully!          :\n"
              ":__________________________________:\n");}
  else if(a && win < MAX_ARENA_WIN && lost == MAX_ARENA_LOSS){
    add_run(a, win, lost);
    printf( "\n __________________________________ \n"
              ": Run added successfully!          :\n"
              ":__________________________________:\n");}
  else
    printf( "\n __________________________________ \n"
              ": Wrong inputs(Name, wins or loss) :\n"
              ":__________________________________:\n");
}
void view_late(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  
  file = fopen("Stats.txt", "r");
  
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){
    if(delete == FALSE)
      i++;
  }
  printf( "\n __________________________________ \n"
            ": Latest Arena Run  Nr. %d         :\n"
            ": -------------------------------- :\n", i);
  print_class(class);
  printf( "\n: -------------------------------- :\n");
  printf(": Wins - %d   Loss - %d              :\n"
           ":__________________________________:\n\n",win, lost);
  fclose(file);
}
void view_m_win(){
  FILE *file;
  int class = 0, win = 0, lost = 0, delete = FALSE;
  int most_win = 0;
  
  file = fopen("Stats.txt", "r");
  
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){
    if(delete == FALSE){
      if(most_win == 0){
        most_win = win;
      }
      else if(most_win < win){
        most_win = win;
      }
    }
  }
  fclose(file);
  file = fopen("Stats.txt", "r");
  printf( "\n __________________________________ \n"
            ": Most wins is %2.d                  :\n"
            ": -------------------------------- :\n", most_win);
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){
    if(delete == FALSE){
      if(win == most_win){
        switch(class){
          case 1:
            printf(": Druid      Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 2:
            printf(": Hunter     Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 3:
            printf(": Mage       Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 4:
            printf(": Paladin    Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 5:
            printf(": Priest     Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 6:
            printf(": Rogue      Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 7:
            printf(": Shaman     Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 8:
            printf(": Warlock    Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
          case 9:
            printf(": Warrior    Wins - %2.d   Loss - %d  :\n",win, lost);
            break;
        }
      }
    }
  }
  printf( ":__________________________________:\n\n");
 fclose(file);
}
void delete_arena(){
  FILE *file1, *file2;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE, choice = 0;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  
  file1 = fopen("Stats.txt", "r");
  file2 = fopen("Stats1.txt","w");
  
  printf( "\n __________________________________\n"
            ": Pick the run you want deleted or :\n"
            ": 0 for back to main screen        :\n");
  printf(   ": -------------------------------- :\n"
            ":                                  :\n");
  while(fscanf(file1, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
    if(delete == FALSE){
        printf(": %#02d ~ Wins - %4d   Loss - %4d   :\n", i+1, win, lost);
        i++;
    }
  }
  printf( ":__________________________________:\n\n");
  fclose(file1);
  file1 = fopen("Stats.txt", "r");
  scanf("%d", &choice);
  i = 1;
  system("cls");
  if(choice != 0){
    while(fscanf(file1, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      if(delete == FALSE){
        if(i == choice)
          fprintf(file2, " %d %d %d %d", class, win, lost, 1);
        else{
          fprintf(file2, " %d %d %d %d", class, win, lost, delete);}
        i++;
      }
      else
        fprintf(file2, " %d %d %d %d", class, win, lost, delete);
    }
    fclose(file1);
    fclose(file2);
    file1 = fopen("Stats.txt", "w");
    file2 = fopen("Stats1.txt","r");
    
    while(fscanf(file2, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      fprintf(file1, " %d %d %d %d", class, win, lost, delete);
    }
    fclose(file1);
    fclose(file2);
    
    if(remove("Stats1.txt") == 0)
      printf( "\n __________________________________ \n"
                ": Deleted                          :\n"
                ":__________________________________:\n\n");
    else{
      printf( "\n __________________________________ \n"
                ": Unable to delete                 :\n"
                ":__________________________________:\n\n");
    }
  }
}
void recover_run(){
  FILE *file1, *file2;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE, choice = 0;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  char command[10];
  
  file1 = fopen("Stats.txt", "r");
  while(fscanf(file1, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
    if(delete == TRUE){
        i++;
    }
  }
  fclose(file1);
      
  if(i == 0){
    printf( "\n __________________________________\n"
              ": Nothing to recover               :\n"
              ":__________________________________:\n");
  }
  else{
    file1 = fopen("Stats.txt", "r");
    file2 = fopen("Stats1.txt","w");
    i = 0;
    printf( "\n __________________________________\n"
              ": Select run to recover            :\n");
    printf(   ": -------------------------------- :\n"
              ":                                  :\n");
    while(fscanf(file1, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      if(delete == TRUE){
          printf(": %#02d ~ Wins - %4d   Loss - %4d   :\n", i+1, win, lost);
          i++;
      }
    }
    printf( ":__________________________________:\n\n");
    fclose(file1);
    file1 = fopen("Stats.txt", "r");
    scanf("%s", &command);
    i = 1;
    if(strcmp(command, "all") == 0){
      system("cls");
      while(fscanf(file1, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
        if(delete == TRUE){
          fprintf(file2, " %d %d %d %d", class, win, lost, 0);
        }
        else
          fprintf(file2, " %d %d %d %d", class, win, lost, delete);
      }
      fclose(file1);
      fclose(file2);
    }
    else{
      choice = atoi(command);
      system("cls");
      if(choice != 0){
        while(fscanf(file1, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
          if(delete == TRUE){
            if(i == choice)
              fprintf(file2, " %d %d %d %d", class, win, lost, 0);
            else{
              fprintf(file2, " %d %d %d %d", class, win, lost, delete);}
            i++;
          }
          else
            fprintf(file2, " %d %d %d %d", class, win, lost, delete);
        }
        fclose(file1);
        fclose(file2);
      }
    }
    file1 = fopen("Stats.txt", "w");
    file2 = fopen("Stats1.txt","r");
    while(fscanf(file2, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      fprintf(file1, " %d %d %d %d", class, win, lost, delete);
    }
    fclose(file1);
    fclose(file2);
    
    if(remove("Stats1.txt") == 0)
      printf( "\n __________________________________ \n"
                ": Recovered                        :\n"
                ":__________________________________:\n\n");
    else{
      printf( "\n __________________________________ \n"
                ": Unable to recover                :\n"
                ":__________________________________:\n\n");
    }
  }
}

void add_run(int class, int win, int lost){
  FILE *file;

  file = fopen("Stats.txt", "a");

  fprintf(file, " %d %d %d %d", class, win, lost, 0);
  
  fclose(file);
}
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
  else if(strcmp(class, "recover") == 0)
    class_num = 10;
  else if(strcmp(class, "all") == 0)
    class_num = 11;
  else
    class_num = 0;
    
  return class_num;
}
void print_run(int class_num){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  
  file = fopen("Stats.txt", "r");
  
  printf( "\n __________________________________ \n");
  print_class(class_num);
  printf( "\n: -------------------------------- :\n");
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
    if(class == class_num && delete == FALSE){
      win_c += win;
      lost_c += lost;
      printf(": %d ~ Wins - %4d   Loss - %4d    :\n", i+1, win, lost);

      runs++;
      i++;
    }
  }
  winp = ((double)win_c/((double)win_c+(double)lost_c))*100;
  if(win_c+lost_c == 0){
    winp = 0;}
  printf( ": -------------------------------- :\n");
  printf(   ": Matches: %4d                    :\n"
            ": Runs:    %4d                    :\n"
            ": Wins:    %4d                    :\n"
            ": Loss:    %4d                    :\n"
            ": Win Percentage: %.2lf %%          :\n", win_c+lost_c, runs, win_c, lost_c, winp);
  printf( ":__________________________________: \n\n");

  fclose(file);
}
void print_class(int i){
  switch(i){
    case 1:
      printf(": Druid                            :");
      break;
    case 2:
      printf(": Hunter                           :");
      break;
    case 3:
      printf(": Mage                             :");
      break;
    case 4:
      printf(": Paladin                          :");
      break;
    case 5:
      printf(": Priest                           :");
      break;
    case 6:
      printf(": Rogue                            :");
      break;
    case 7:
      printf(": Shaman                           :");
      break;
    case 8:
      printf(": Warlock                          :");
      break;
    case 9:
      printf(": Warrior                          :");
      break;
  }
}
void print_all(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  
  file = fopen("Stats.txt", "r");

  printf( "\n __________________________________ \n");
  printf(": All Arena Runs                   :\n");
  printf( ": -------------------------------- :\n");
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
    if(delete == FALSE){
      win_c += win;
      lost_c += lost;
      print_class1(class, win, lost);
      runs++;
      i++;
    }
  }
  winp = ((double)win_c/((double)win_c+(double)lost_c))*100;
  if(win_c+lost_c == 0){
    winp = 0;}
  printf( ": -------------------------------- :\n");
  printf(   ": Matches: %4d                    :\n"
            ": Runs:    %4d                    :\n"
            ": Wins:    %4d                    :\n"
            ": Loss:    %4d                    :\n"
            ": Win Percentage: %.2lf %%          :\n", win_c+lost_c, runs, win_c, lost_c, winp);
  printf( ":__________________________________: \n\n");

  fclose(file);
}
void print_class1(int class, int win, int lost){
  switch(class){
    case 1:
      printf(": Druid      Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 2:
      printf(": Hunter     Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 3:
      printf(": Mage       Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 4:
      printf(": Paladin    Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 5:
      printf(": Priest     Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 6:
      printf(": Rogue      Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 7:
      printf(": Shaman     Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 8:
      printf(": Warlock    Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
    case 9:
      printf(": Warrior    Wins - %2.d   Loss - %d  :\n",win, lost);
      break;
  }
}