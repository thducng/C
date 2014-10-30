#include <stdio.h> 
#include <math.h>

double scan_data(char *operator, double *operand);
double do_next_op(char operator, double operand, double *akkumulator, double *q);
void print_result(char operator, double operand, double akkumulator, double q);

int main(void){
  double operand, akkumulator = 0.0, q = 1;
  char operator;
  
  printf("\nStart value is 0.0\n");
  printf("Enter operation and a value:\n");
  
  while(q > 0){
  scan_data(&operator, &operand);
  do_next_op(operator, operand, &akkumulator, &q);
  print_result(operator, operand, akkumulator, q);
  }
}

double scan_data(char *operator, double *operand){
  scanf(" %c %lf", operator, operand);
}

double do_next_op(char operator, double operand, double *akkumulator, double *q){
  if(operator != 'q'){
    if(operator == '+'){*akkumulator = *akkumulator + operand;}
    if(operator == '-'){*akkumulator = *akkumulator - operand;}
    if(operator == '*'){*akkumulator = *akkumulator * operand;}
    if(operator == '/'){*akkumulator = *akkumulator / operand;}
    if(operator == '^'){*akkumulator = pow(*akkumulator, operand);}
    if(operator == 'q'){*q = 0;}}
}

void print_result(char operator, double operand, double akkumulator, double q){
  if(operator != 'q'){
    printf("result so far is %lf\n", akkumulator);}
  else
    printf("final result is %lf\n\n", akkumulator);
}