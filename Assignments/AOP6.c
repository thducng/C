/* Afleveringsopgave 6 - Opgave 17 s. 331
   Skrevet af Thuan Duc Nguyen */
   
#include <stdio.h>
#include <math.h>

double f(double x);
double sum_of_f(double a, double n, double h);
double h_equation(double a, double b, double n);
double trap(double a, double b, double n, double h, double (*f)(double), double (*sum_of_f)(double, double, double));

/* Kommentarer som ikke kunne skrives i kommentarfeltet med indrykningerne(IKKE EN DEL AF PROGRAMMET!)
  
  Ville det være bedre at skrive funktionen på linje 10 og 57 således?:
  double trap(double a, double b, double n, double h,
              double (*f)(double),
              double (*sum_of_f)(double, double, double)); 
  
  Tænkte at det ville se mere overskueligt ud, men var ikke sikker.
  Jeg havde også overvejet at anvende funktionen f(double x) ved linje 47, således det ser sådan ud:

  sum = sum + f(a+x);

  Men så skal jeg nede ved linje 58, skrive en aktuel parameter som jeg ikke kunne tænke mig frem til. 
  Ville bare spørge om du havde et tip, eller om det overhovedet er muligt :)
  
  */

int main(void){
  double a = -2, b = 2, n = 128, h, result;
  
  h = h_equation(a, b, n);
  result = trap(a, b, n, h, &f, &sum_of_f);
  printf("The approximate area under the function is: %.2lf \n", result);
  
  return 0;
}

double f(double x){
  return sqrt(4 - pow(x,2));
}

double sum_of_f(double a, double n, double h){
  double sum = 0, x = h;
  
  for(n ;n > 0; n--){
    sum = sum + sqrt(4 - pow((a+x),2));
    x = x + h;
  }
  return 2*sum;
}

double h_equation(double a, double b, double n){
  return (b - a)/ n;
}

double trap(double a, double b, double n, double h, double (*f)(double), double (*sum_of_f)(double, double, double)){
  return(h/2) * ((f(a)) + (f(b)) + (sum_of_f(a,n,h)));
}