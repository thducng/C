// HS Statistics    //
// Thuan Duc Nguyen //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUMBER_OF_CLASSES 9
#define MAX_ARENA_WIN 12
#define MAX_ARENA_LOSS 3
// /D/Uni/P1/C/HS/Arena/arena_stats.txt
// /D/Uni/P1/C/HS/Ranked/ranked_stats.txt

typedef struct ARENA{
  char class[10];
  int total_match;
  int win_match;
  int lost_match;
  int max_win;
}ARENA;

void user_dialogue();
void arena_option();
void ranked_option();

void resume_arena();
void start_new_arena();
void view_arena_stat();
void view_aclass_stat();

void new_ranked_match();
void view_last_match();
void view_ranked_stat();
void view_rclass_stat();

void read_arena_file(char *choice);
void read_ranked_file();
void read_class_file();

int main(int argc, char *argv[]){
  
  if(argc == 1)
    user_dialogue();
  else if(argc > 1 && strcmp(argv[1], "Arena"))
    arena_option();
  else if(argc > 1 && strcmp(argv[1], "Ranked"))
    ranked_option();
}

// User dialogue //
void user_dialogue(){
  int i = 0;
  
  printf("\n_______________________\n"
          ": What you want to do?  :\n"
          ": Arena    -> 1         :\n"
          ": Ranked   -> 2         :\n"
          ":_______________________:\n\n");

  scanf("%d",&i);
  
  switch(i){
    case 1:
      arena_option();
      break;
    case 2:
      ranked_option();
      break;
    default:
      printf("Dumb fuck, cant even 1 or 2 -.-'\n");
  }
}
void arena_option(){
  int i = 0;
  
  printf("\n_______________________\n"
          ": What you want to do?  :\n"
          ": Resume Arena    -> 1  :\n"
          ": Start New Arena -> 2  :\n"
          ": View Arena Stat -> 3  :\n"
          ": View Class Stat -> 4  :\n"
          ": Back            -> 5  :\n"
          ":_______________________:\n\n");
  
  scanf("%d",&i);
  
  switch(i){
    case 1:
      resume_arena();
      break;
    case 2:
      start_new_arena();
      break;
    case 3:
      view_arena_stat();
      break;
    case 4:
      view_aclass_stat();
      break;
    default:
      user_dialogue();
      break;
  }
}
void ranked_option(){
  int i = 0;
  
  printf("\n_______________________\n"
          ": What you want to do?  :\n"
          ": New Ranked Match -> 1 :\n"
          ": View Last Match  -> 2 :\n"
          ": View Ranked Stat -> 3 :\n"
          ": View Class Stat  -> 4 :\n"
          ": Back             -> 5 :\n"
          ":_______________________:\n\n");

  scanf("%d",&i);
  
  switch(i){
    case 1:
      new_ranked_match();
      break;
    case 2:
      view_last_match();
      break;
    case 3:
      view_ranked_stat();
      break;
    case 4:
      view_rclass_stat();
      break;
    default:
      user_dialogue();
      break;
  }
}

// Arena Options //
void resume_arena(){


}
void start_new_arena(){
  char *class[10], outcome[2];
  int win = 0, loss = 0, match = 1;
  
  printf("Enter class(Paladin): ");
  scanf("%s", class);
  
  while(loss != MAX_ARENA_LOSS || win != MAX_ARENA_WIN){
    printf("Match %d outcome is(W or L): ", match);
    scanf("%s", outcome);
    
    if(!strcmp(outcome, "W")){
      match++;
      win++;}
    else if(!strcmp(outcome, "L")){
      match++;
      loss++;}
    else if(!strcmp(outcome, "P")){
      }
    else
      printf("Did you just draw??\n");
  }
}
void view_arena_stat(){
  char *view_a_stat = "view_a_stat";
  read_arena_file(view_a_stat);

}
void view_aclass_stat(){


}

// Ranked Options //
void new_ranked_match(){


}
void view_last_match(){


}
void view_ranked_stat(){

}
void view_rclass_stat(){

}

// File Handling Functions //
void read_arena_file(char *choice){
 FILE *v_a_stat,
      *v_c_stat;
 int i = 0, j = 0;
 
 struct ARENA arena[256];

  if(!strcmp(choice, "view_a_stat")){
    v_a_stat = fopen("/D/Uni/P1/C/HS/Arena/arena_stats.txt", "r");
    for(i = 0; i < 5 ; i++){
      fscanf(v_a_stat, " %s %d %d - %d %d", arena[i].class,
                                            arena[i].total_match,
                                            arena[i].win_match,
                                            arena[i].lost_match,
                                            arena[i].max_win);
    }
    for(j = 0; j < i; j++)
      printf("%s %d   %d-%d   %d\n", arena[j].class,
                                           arena[j].total_match,
                                           arena[j].win_match,
                                           arena[j].lost_match,
                                           arena[j].max_win);
  }
}
void read_ranked_file(){

}
void read_class_file(){

}
void write_arena_file(char *class, int w, int l, int m, int p){
  FILE *w_a_stat;
  FILE *w_c_stat;
  int m_w = 0;
  
  if(p == 0)
    fprintf("%-10s %4d %4d-%-4d %2d", class, m, w, l, m_w);

}
void write_ranked_file(){


}
void write_class_file(){


}

void class_file_identifier(char *class, ){
  if(strcmp(class, "Druid"))
}








