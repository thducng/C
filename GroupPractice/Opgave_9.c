/* Write a program that takes the length and width of a rectangular
   yard and the length and width of a rectangular house situated in
   yard. Your program should compute the time required to cut the
   grass at the rate of two aquare feet a second. */

#include <stdio.h>
#define TWO 2

int main(void)
{
  double lengthyard,widthyard,lengthhouse,widthhouse;
  double yard,house,areal,tid;

  printf("Indtast havens længde derefter bredde i feet \n");
  scanf("%lf %lf",&lengthyard,&widthyard);

  printf("Indtast husets længde derefter bredde i feet \n");
  scanf("%lf %lf",&lengthhouse,&widthhouse);

  yard = lengthyard * widthyard;
  house = lengthhouse * widthhouse;
  areal = yard - house;

  tid = areal / TWO;

  printf("Det tager %8.4f sekunder at slaa graesset paa arealet %8.4f kvadrat feet\n",tid,areal);

  return 0;
}
