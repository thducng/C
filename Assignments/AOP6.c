/* Afleveringsopgave 6 - Opgave 17 s. 331
   Skrevet af Thuan Duc Nguyen */
   
#include <stdio.h>
#include <math.h>

void scan_for_n(double *n_h, double *n_g);
double h_function(double x);
double g_function(double x);
double sum_function(double a, double b, double n, double (*f)(double));
double h_equation(double a, double b, double n);
double trap(double a, double b, double n, double (*f)(double));
  
int main(void){
  double a_h = -2, b_h = 2, a_g = 0, b_g = 3.14150, n_h = 0, n_g = 0, result_h, result_g;
  
  scan_for_n(&n_h, &n_g);
  result_h = trap(a_h, b_h, n_h, &h_function);
  result_g = trap(a_g, b_g, n_g, &g_function);
  
  printf("The approximate area under the functions h(x) and g(x) is: %.2lf and %.2lf \n", result_h,result_g);
  return 0;
}

/* Scans for n */
void scan_for_n(double *n_h, double *n_g){
  printf("Enter value of n for h(x), then g(x): \n");
  scanf("%lf %lf", n_h, n_g);
}

/* Function h(x) */
double h_function(double x){
  return sqrt(4 - pow(x,2));
}

/* Function g(x) */
double g_function(double x){
  return pow(x,2) * sin(x);
}

/* Equation for h */
double h_equation(double a, double b, double n){
  return (b - a)/ n;
}

/* Summation of functions (A part of trapezoidal rule) */
double sum_function(double a, double b, double n, double (*f)(double)){
  double sum = 0, h = h_equation(a,b,n), x = h;
  
  for(n ;n > 0; n--){
    sum = sum + f(a+x);
    x = x + h;
  }
  return 2*sum;
}

/* Trapezoidal rule function */
double trap(double a, double b, double n, double (*f)(double)){
  return (h_equation(a,b,n)/2) * (f(a) + f(b) + sum_function(a,b,n,f));
}