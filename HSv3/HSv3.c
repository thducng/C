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
void commandlist(int command);

void win_stats();
void class_win_stats(int classnum);
void best_class();
void worst_class();
void played_class();
void myelo();
void class_win_stats1(int class, int runs);
void print_top3(int top1, double  p1, int top2, double p2, int top3, double p3);
void print_top3a(int top1, int p1, int top2, int p2, int top3, int p3);

int main(void){
  int stop = FALSE;
  system("cls");
  
  while(stop == FALSE){
    pre_stats();
    user_dialog(&stop); 
  }
  return 0;
}

// Main Funcs //

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
    winp = 0;
    printf(   ": -------------------------------- :\n");
    printf(   ": Matches: %4d                    :\n"
              ": Runs:    %4d                    :\n"
              ": Wins:    %4d                    :\n"
              ": Loss:    %4d                    :\n"
              ": Win Percentage: %.2lf %%           :\n", win_c+lost_c, runs, win_c, lost_c, winp);
    printf( ":__________________________________: \n");}
  else{
    printf(   ": -------------------------------- :\n");
    printf(   ": Matches: %4d                    :\n"
              ": Runs:    %4d                    :\n"
              ": Wins:    %4d                    :\n"
              ": Loss:    %4d                    :\n"
              ": Win Percentage: %.2lf %%          :\n", win_c+lost_c, runs, win_c, lost_c, winp);
    printf( ":__________________________________: \n");
  }
}
void user_dialog(int *stop){
  int i = 0, classnum = 0;
  char choice[100];
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
    commandlist(classnum);
  }
}

// Admins //

void commandlist(int command){
  switch(command){
    case 1: case 2: case 3: case 4: case 5:
    case 6: case 7: case 8: case 9:
      print_run(command);
      break;
    case 10:
      recover_run();
      break;
    case 11:
      print_all();
      break;
    case 12:
      win_stats();
      break;
    case 13:
      best_class();
      break;
    case 14:
      worst_class();
      break;
    case 15:
      played_class();
      break;
    case 16:
      myelo();
      break;
    case 21: case 22: case 23: case 24: case 25:
    case 26: case 27: case 28: case 29:
      class_win_stats(command);  
      break;
  }
}
int class_number(char *class){
  int class_num = 0;
  
  if(strcmp(class, "druidwin") == 0)
    class_num = 21;
  else if(strcmp(class, "hunterwin") == 0)
    class_num = 22;
  else if(strcmp(class, "magewin") == 0)
    class_num = 23;
  else if(strcmp(class, "paladinwin") == 0)
    class_num = 24;
  else if(strcmp(class, "priestwin") == 0)
    class_num = 25;
  else if(strcmp(class, "roguewin") == 0)
    class_num = 26;
  else if(strcmp(class, "shamanwin") == 0)
    class_num = 27;
  else if(strcmp(class, "warlockwin") == 0)
    class_num = 28;
  else if(strcmp(class, "warriorwin") == 0)
    class_num = 29;
  else if(strcmp(class, "druid") == 0)
    class_num = 1;
  else if(strcmp(class, "hunter") == 0)
    class_num = 2;
  else if(strcmp(class, "mage") == 0)
    class_num = 3;
  else if(strcmp(class, "paladin") == 0)
    class_num = 4;
  else if(strcmp(class, "priest") == 0)
    class_num = 5;
  else if(strcmp(class, "rogue") == 0)
    class_num = 6;
  else if(strcmp(class, "shaman") == 0)
    class_num = 7;
  else if(strcmp(class, "warlock") == 0)
    class_num = 8;
  else if(strcmp(class, "warrior") == 0)
    class_num = 9;
  else if(strcmp(class, "recover") == 0)
    class_num = 10;
  else if(strcmp(class, "all") == 0)
    class_num = 11;
  else if(strcmp(class, "allwin") == 0)
    class_num = 12;
  else if(strcmp(class, "bclass") == 0)
    class_num = 13;
  else if(strcmp(class, "wclass") == 0)
    class_num = 14;
  else if(strcmp(class, "pclass") == 0)
    class_num = 15;
  else if(strcmp(class, "myelo") == 0)
    class_num = 16;
  else
    class_num = 0;
    
  return class_num;
}

// Dialog //

void new_arena(){
  int a = 0, win = 0, lost = 0, i = 0, choice = 0;
  char class[10];
  
  printf( "\n __________________________________ \n"
            ": Class then Win then Loss         :\n"
            ": -------------------------------- :\n"
            ": druid 12 2                       :\n"
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

// Commands //

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
void win_stats(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  int onew = 0, twow = 0, threew = 0, fourw = 0, fivew = 0, sixw = 0, sevenw = 0, 
      eightw = 0, ninew = 0, tenw = 0, elevenw = 0, twelvew = 0;

  file = fopen("Stats.txt", "r");    
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){    
    if(delete == FALSE){
      switch(win){
        case 1:
          onew++;
          break;
        case 2:
          twow++;
          break;
        case 3:
          threew++;
          break;
        case 4:
          fourw++;
          break;
        case 5:
          fivew++;
          break;
        case 6:
          sixw++;
          break;
        case 7:
          sevenw++;
          break;
        case 8:
          eightw++;
          break;
        case 9:
          ninew++;
          break;
        case 10:
          tenw++;
          break;
        case 11:
          elevenw++;
          break;
        case 12:
          twelvew++;
          break;
      }
      i++;
    }
  }
  fclose(file);
  printf( "\n __________________________________ \n");
  printf(": Win rates from all %4.d Runs     :\n"
         ": -------------------------------- :\n"
         ": 1  Win Runs        %3.d Times     :\n"
         ": 2  Win Runs        %3.d Times     :\n"
         ": 3  Win Runs        %3.d Times     :\n"
         ": 4  Win Runs        %3.d Times     :\n"
         ": 5  Win Runs        %3.d Times     :\n"
         ": 6  Win Runs        %3.d Times     :\n"
         ": 7  Win Runs        %3.d Times     :\n"
         ": 8  Win Runs        %3.d Times     :\n"
         ": 9  Win Runs        %3.d Times     :\n"
         ": 10 Win Runs        %3.d Times     :\n"
         ": 11 Win Runs        %3.d Times     :\n"
         ": 12 Win Runs        %3.d Times     :\n"
         ":__________________________________:\n",
         i, onew, twow, threew, fourw, fivew, sixw,
         sevenw, eightw, ninew, tenw, elevenw, twelvew);
}
void class_win_stats(int classnum){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0;
  double  winp = 0.00;
  int onew = 0, twow = 0, threew = 0, fourw = 0, fivew = 0, sixw = 0, sevenw = 0, 
      eightw = 0, ninew = 0, tenw = 0, elevenw = 0, twelvew = 0;

  file = fopen("Stats.txt","r");
  
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){    
    if(delete == FALSE && class == (classnum - 20)){
      switch(win){
        case 1:
          onew++;
          break;
        case 2:
          twow++;
          break;
        case 3:
          threew++;
          break;
        case 4:
          fourw++;
          break;
        case 5:
          fivew++;
          break;
        case 6:
          sixw++;
          break;
        case 7:
          sevenw++;
          break;
        case 8:
          eightw++;
          break;
        case 9:
          ninew++;
          break;
        case 10:
          tenw++;
          break;
        case 11:
          elevenw++;
          break;
        case 12:
          twelvew++;
          break;
      }
      i++;
    }
  }
  fclose(file);
  printf( "\n __________________________________ \n");
  class_win_stats1(classnum-20, i);
  printf(": -------------------------------- :\n");
  printf(": 1  Win Runs        %3.d Times     :\n"
         ": 2  Win Runs        %3.d Times     :\n"
         ": 3  Win Runs        %3.d Times     :\n"
         ": 4  Win Runs        %3.d Times     :\n"
         ": 5  Win Runs        %3.d Times     :\n"
         ": 6  Win Runs        %3.d Times     :\n"
         ": 7  Win Runs        %3.d Times     :\n"
         ": 8  Win Runs        %3.d Times     :\n"
         ": 9  Win Runs        %3.d Times     :\n"
         ": 10 Win Runs        %3.d Times     :\n"
         ": 11 Win Runs        %3.d Times     :\n"
         ": 12 Win Runs        %3.d Times     :\n"
         ":__________________________________:\n",
         onew, twow, threew, fourw, fivew, sixw,
         sevenw, eightw, ninew, tenw, elevenw, twelvew);
}
void best_class(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  double win_c = 0, lost_c = 0, runs = 0, temp_points = 0;
  int top1 = 0, top2 = 0, top3 = 0, top4 = 0, top5 = 0;
  double p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
  double  winp = 0.00;
  
  for(i = 0; i < 9; i++){
    file = fopen("Stats.txt", "r");
    while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      if(delete == FALSE && class == i+1){
        runs++;
        temp_points += win;
      }
    }
    fclose(file);
    p5 = temp_points/runs;
    if(p1 < p5){
      p1 = p5;
      top1 = i+1;
    }
    else if(p2 < p5){
      p2 = p5;
      top2 = i+1;
    }
    else if(p3 < p5){
      p3 = p5;
      top3 = i+1;
    }
    temp_points = 0;
    runs = 0;
  }
  printf( "\n __________________________________ \n");
  printf(": Best Three Played Classes        :\n"
         ": -------------------------------- :\n");
  print_top3(top1, p1, top2, p2, top3, p3);
  printf( ":__________________________________:\n");
}
void worst_class(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  double win_c = 0, lost_c = 0, runs = 0, temp_points = 0;
  int top1 = 0, top2 = 0, top3 = 0, top4 = 0, top5 = 0;
  double p1 = 100, p2 = 100, p3 = 100, p4 = 100, p5 = 100;
  double  winp = 0.00;
  
  for(i = 0; i < 9; i++){
    file = fopen("Stats.txt", "r");
    while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      if(delete == FALSE && class == i+1){
        runs++;
        temp_points += win;
      }
    }
    fclose(file);
    p5 = temp_points/runs;
    if(p1 > p5){
      p1 = p5;
      top1 = i+1;
    }
    else if(p2 > p5){
      p2 = p5;
      top2 = i+1;
    }
    else if(p3 > p5){
      p3 = p5;
      top3 = i+1;
    }
    temp_points = 0;
    runs = 0;
  }
  printf( "\n __________________________________ \n");
  printf(": Worst Three Played Classes       :\n"
         ": -------------------------------- :\n");
  print_top3(top1, p1, top2, p2, top3, p3);
  printf( ":__________________________________:\n");  
  
}
void played_class(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0, temp_points = 0;
  int top1 = 0, top2 = 0, top3 = 0, top4 = 0, top5 = 0;
  double p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
  double  winp = 0.00;
  
  for(i = 0; i < 9; i++){
    file = fopen("Stats.txt", "r");
    while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){  
      if(delete == FALSE && class == i+1){
        runs++;
      }
    }
    fclose(file);
    if(p1 > runs){
      if(p2 > runs){
        if(p3 > runs){
          runs = 0;}
        else{
          p3 = runs;
          top3 = i+1;
        }}
      else{
        p2 = runs;
        top2 = i+1;
      }}
    else{
      p1 = runs;
      top1 = i+1;
    }
    runs = 0;
  }
  printf( "\n __________________________________ \n");
  printf(": Three Most Played Classes        :\n"
         ": -------------------------------- :\n");
  print_top3a(top1, p1, top2, p2, top3, p3);
  printf( ":__________________________________:\n");
}  
void myelo(){
  FILE *file;
  int class = 0, win = 0, lost = 0, i = 0, delete = FALSE;
  int win_c = 0, lost_c = 0, runs = 0, elo = 1500, melo = 0;
  double  winp = 0.00, calc = 0.00;
  
  file = fopen("Stats.txt", "r");
  
  while(fscanf(file, "%d %d %d %d", &class, &win, &lost, &delete) != EOF){    
    if(delete == FALSE){
      calc = (win - lost) * 10;
    }
    if(elo < 1400){
      if(calc > 35){
        elo += 35;
      }
      else if(calc < -5){
        elo += -5;
      }
      else
        elo += calc;
    }
    else if(elo >= 1400 && elo < 1500){
      if(calc > 25){
        elo += 25;
      }
      else if(calc < -10){
        elo += -10;
      }
      else
        elo += calc;
    }
    else if(elo >= 1500 && elo < 1600){
      if(calc > 20){
        elo += 20;
      }
      else if(calc < -10){
        elo += -10;
      }
      else
        elo += calc;
    }
    else if(elo >= 1600 && elo < 1700){
      if(calc > 15){
        elo += 15;
      }
      else if(calc < -5){
        elo += -5;
      }
      else
        elo += calc;
    }
    else if(elo >= 1700 && elo < 1800){
      if(calc > 10){
        elo += 10;
      }
      else if(calc < -5){
        elo += -5;
      }
      else
        elo += calc;
    }
    else if(elo >= 1800){
      if(calc > 7){
        elo += 7;
      }
      else if(calc < -10){
        elo += -10;
      }
      else
        elo += calc;
    }
    if(win >= 7)
      elo += 1;
    if(win >= 9)
      elo += 2;
    if(win >= 11)
      elo += 3;
    if(win == 12)
      elo += 4;
    calc = 0;
    if(melo < elo){
      melo = elo;
    }
  }
  
  printf("\n __________________________________ \n");
  printf(": Elo calculated by me!            :\n"
         ": -------------------------------- :\n");
  printf(": Your Current Elo   ~~   %4d     :\n", elo);
  printf(": -------------------------------- :\n"
         ": Your Maximum Elo   ~~   %4d     :\n", melo);
  printf(":__________________________________:\n"); 
  
  fclose(file);
}

// Helpings //

void add_run(int class, int win, int lost){
  FILE *file;

  file = fopen("Stats.txt", "a");

  fprintf(file, " %d %d %d %d", class, win, lost, 0);
  
  fclose(file);
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
void class_win_stats1(int class, int runs){
  switch(class){
    case 1:
      printf(": Druid               %3.d Runs     :\n",runs);
      break;
    case 2:
      printf(": Hunter              %3.d Runs     :\n",runs);
      break;
    case 3:
      printf(": Mage                %3.d Runs     :\n",runs);
      break;
    case 4:
      printf(": Paladin             %3.d Runs     :\n",runs);
      break;
    case 5: 
      printf(": Priest              %3.d Runs     :\n",runs);
      break;
    case 6:
      printf(": Rogue               %3.d Runs     :\n",runs);
      break;
    case 7:
      printf(": Shaman              %3.d Runs     :\n",runs);
      break;
    case 8:
      printf(": Warlock             %3.d Runs     :\n",runs);
      break;
    case 9:
      printf(": Warrior             %3.d Runs     :\n",runs);
      break;
  }
}
void print_top3(int top1, double  p1, int top2, double p2, int top3, double p3){
  switch(top1){
    case 1:
      printf(": Druid    Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 2:
      printf(": Hunter   Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 3:
      printf(": Mage     Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 4:
      printf(": Paladin  Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 5:
      printf(": Priest   Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 6:
      printf(": Rogue    Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 7:
      printf(": Shaman   Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 8:
      printf(": Warlock  Nr. 1 with %2.2lf points  :\n", p1);
      break;
    case 9:
      printf(": Warrior  Nr. 1 with %2.2lf points  :\n", p1);
      break;
  }
    switch(top2){
    case 1:
      printf(": Druid    Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 2:
      printf(": Hunter   Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 3:
      printf(": Mage     Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 4:
      printf(": Paladin  Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 5:
      printf(": Priest   Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 6:
      printf(": Rogue    Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 7:
      printf(": Shaman   Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 8:
      printf(": Warlock  Nr. 2 with %2.2lf points  :\n", p2);
      break;
    case 9:
      printf(": Warrior  Nr. 2 with %2.2lf points  :\n", p2);
      break;
  } 
    switch(top3){
    case 1:
      printf(": Druid    Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 2:
      printf(": Hunter   Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 3:
      printf(": Mage     Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 4:
      printf(": Paladin  Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 5:
      printf(": Priest   Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 6:
      printf(": Rogue    Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 7:
      printf(": Shaman   Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 8:
      printf(": Warlock  Nr. 3 with %2.2lf points  :\n", p3);
      break;
    case 9:
      printf(": Warrior  Nr. 3 with %2.2lf points  :\n", p3);
      break;
  } 
}
void print_top3a(int top1, int p1, int top2, int p2, int top3, int p3){
  switch(top1){
    case 1:
      printf(": Druid    Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 2:
      printf(": Hunter   Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 3:
      printf(": Mage     Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 4:
      printf(": Paladin  Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 5:
      printf(": Priest   Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 6:
      printf(": Rogue    Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 7:
      printf(": Shaman   Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 8:
      printf(": Warlock  Nr. 1  with  %2.2d runs    :\n", p1);
      break;
    case 9:
      printf(": Warrior  Nr. 1  with  %2.2d runs    :\n", p1);
      break;
  }
    switch(top2){
    case 1:
      printf(": Druid    Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 2:
      printf(": Hunter   Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 3:
      printf(": Mage     Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 4:
      printf(": Paladin  Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 5:
      printf(": Priest   Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 6:
      printf(": Rogue    Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 7:
      printf(": Shaman   Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 8:
      printf(": Warlock  Nr. 2  with  %2.2d runs    :\n", p2);
      break;
    case 9:
      printf(": Warrior  Nr. 2  with  %2.2d runs    :\n", p2);
      break;
  } 
    switch(top3){
    case 1:
      printf(": Druid    Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 2:
      printf(": Hunter   Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 3:
      printf(": Mage     Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 4:
      printf(": Paladin  Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 5:
      printf(": Priest   Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 6:
      printf(": Rogue    Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 7:
      printf(": Shaman   Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 8:
      printf(": Warlock  Nr. 3  with  %2.2d runs    :\n", p3);
      break;
    case 9:
      printf(": Warrior  Nr. 3  with  %2.2d runs    :\n", p3);
      break;
  }   
}











