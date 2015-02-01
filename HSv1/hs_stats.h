// HEADER FILE FOR HS_STAT.C //

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