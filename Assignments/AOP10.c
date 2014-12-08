#include <stdio.h>
#include <strings.h>
#define DECKSIZE 55
/* clubs > diamonds > hearts > spades
   2 .. 9, 10, knight, queen, king, ace 
   > joker */

/* suits = clubs,diamonds,hearts,spades,joker;
   value = 2,3,4,5,6,7,8,9,10,11,12,13,1,14
   
   Joker = suit joker & value 14 */
   
typedef struct deck{
  int suit[DECKSIZE];
  int value[DECKSIZE];
}deck;

deck cards_in_deck(deck *deck);
deck set_value(deck *deck, int i, int value1, int *value2);
void printfunc(deck deck);
void Value(deck deck, int i);
void Suit(deck deck, int i);


int main(void){
  deck deck;
  
  cards_in_deck(&deck);
  printfunc(deck);

  return 0;
}

deck cards_in_deck(deck *deck){
  int i, 
      clubs = 2, diamonds = 2, hearts = 2, spades = 2, joker = 15;
  
  for(i = 0; i < 55; ++i){
    if(clubs < 15){
      set_value(deck, i, 1, &clubs);}
    else if(diamonds < 15){
      set_value(deck, i, 2, &diamonds);}
    else if(hearts < 15){
      set_value(deck, i, 3, &hearts);}
    else if(spades < 15){
      set_value(deck, i, 4, &spades);}
    else{
      set_value(deck, i, 5, &joker);}
  }
}

deck set_value(deck *deck, int i, int value1, int *value2){
  deck->suit[i] = value1;
  deck->value[i] = *value2;
  if(value1 == 5)
    *value2 = 15;
  else
    *value2 = *value2 + 1;
}

void printfunc(deck deck){
  int i;
  for(i = 0; i < 55; ++i){
    Value(deck, i);
    Suit(deck, i);
  }
}

void Suit(deck deck, int i){
  if(deck.suit[i] == 1)
    printf("Clubs \n");
  else if(deck.suit[i] == 2)
    printf("Diamonds \n");
  else if(deck.suit[i] == 3)
    printf("Hearts \n");
  else if(deck.suit[i] == 4)
    printf("Spades \n");
}

void Value(deck deck, int i){
  if(deck.value[i] == 11)
    printf("Knight of ");
  else if(deck.value[i] == 12)
    printf("Queen  of ");
  else if(deck.value[i] == 13)
    printf("King   of ");
  else if(deck.value[i] == 14)
    printf("Ace    of ");
  else if(deck.value[i] == 15)
    printf("Joker\n");
  else
    printf("%2.0d     of ", deck.value[i])  ;
}