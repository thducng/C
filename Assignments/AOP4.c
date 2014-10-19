/* Afleveringsopgave 4 - solveQuadraticEquation
   Skrevet af Thuan Duc Nguyen                  */
   
#include <stdio.h>
#include <math.h>

double calc_disc(double a, double b, double c){
  /* Define local variables */
  double discriminant;
  
  /* Calculate the discriminant */
  discriminant = b * b - 4 * a * c;
  
  return discriminant;
}

double calc_1root(double a, double b){
  /* Define local variables */
  double root1;
  
  /* Calculate the only root */
  root1 = -b/(2*a);
  
  return root1;
}

double calc_2root1(double a, double b, double c){
  /* Define local variables */
  double root1;
  
  /* Calculate 1 of the two roots */
  root1 = (-b + sqrt(calc_disc(a,b,c)))/(2*a);
  
  return root1;
}

double calc_2root2(double a, double b, double c){
 /* Define local variables */
  double root2;
  
  /* Calculate 1 of the two roots */
  root2 = (-b - sqrt(calc_disc(a,b,c)))/(2*a);
  
  return root2;
}

void print_solution(double a, double b, double c){
  /* Print the discriminant */
  printf("\nThe discriminant is: %.2f\n\n",calc_disc(a,b,c));
  
  /* Print solution */
  if(calc_disc(a,b,c) < 0)
    printf("  No solution:\n  No root\n\n");
  else if(calc_disc(a,b,c) == 0)
    printf("  One solution:\n  Root: %.2f\n\n",
           calc_1root(a,b));
  else
    printf("  Two solutions:\n  First root: %.2f\n  Second root: %.2f\n\n",
           calc_2root1(a,b,c),
           calc_2root2(a,b,c));
}

int main(void) {
  /* Define variables */
  double a,b,c;

  /* Prompt input */
  printf("\nEnter the values a, b and c: ");
  scanf("%lf %lf %lf",&a,&b,&c);
  
  /* Print output */
  print_solution(a,b,c);

  return 0;
}