#include <stdio.h>
#include <math.h>

double f_x(double x);
double f_c(int n, double h, double a);
double h_T(double a, double b, int n);
double trap(double a, double b, int n, double h, double (*f_x)(double), double (*f_c)(int, double, double));

int main(void){
  double a = 0, b = 3.14150, h, result;
  int n = 128;
  
  h = h_T(a,b,n);
  result = trap(a,b,n,h,&f_x,&f_c);
  printf("The approximate area under the function is: %.2lf \n", result);
  return 0;
}

double f_x(double x){
  return pow(x,2) * sin(x);
}

double f_c(int n, double h, double a){
  double sum = 0;
  double h1 = h; 
  
  for(n;n > 0; n--){
  sum = sum + pow(a+h1,2) * sin(a+h1);
  h1 = h1 + h;
  }
  
  return 2*sum;
}

double h_T(double a, double b, int n){
  return (b - a)/ n;
}

double trap(double a, double b, int n, double h, double (*f_x)(double), double (*f_c)(int, double, double)){
  return (h/2)*((f_x(a)) + (f_x(b)) + (f_c(n,h,a)));
}