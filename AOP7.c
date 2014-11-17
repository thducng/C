/* Afleveringsopgave 7 - Merging Arrays
   Skrevet af Thuan Duc Nguyen */
   
#include <stdio.h>
#include <stdlib.h>

double Merging(double *pf, double *ps, double *pr);
int el_cmp(void *ep1, void *ep2);
void Print_results(double *pf, double *ps, double *pr);

int main(void){
  double F_array[5] = {-10.5,-1.8,3.5,6.3,7.2},
         S_array[3] = {-1.8,3.1,6.3},
         R_array[6];

  Merging(F_array, S_array, R_array);
  Print_results(F_array, S_array, R_array);
  
  return 0;
}
/* Merging without duplicates*/
double Merging(double *pf, double *ps, double *pr){
  int a, b, c, d, e,f;
  
  for(a = 0; a < 3; ++a){
    *pr = *ps;
    ++pr;
    ++ps;
  }
  ps = ps - 3;
  
  /* Merge non-duplicates */
  for(c = 0; c < 5; ++c){
    for(d = 0; d < 3; ++d){
      if(*pf == *ps){e = 1; ps++;}
      else {*pr = *pf; ps++;}
    }
    ps = ps - 3;
    pf++;
    if (e == 1){ e = 0;}
    else {pr++;}
  }
}
/* Printing everything */
void Print_results(double *pf, double *ps, double *pr){
  int a, b, c, d;
  printf("------------------------------------\n");
  printf("Before Merging: \n");
  printf("------------------------------------\n");
  
  for(a = 0; a < 5; ++a){
    printf("F_array[%1d] = %.2lf \n",a,*(pf+a));}
  printf("\n");
    
  for(b = 0; b < 3; ++b){
    printf("S_array[%1d] = %.2lf \n",b,*(ps+b));}
    
  printf("------------------------------------\n");
  printf("After Merging: \n");
  printf("------------------------------------\n");
  
  for(c = 0; c < 6; ++c){
    printf("R_array[%1d] = %.2lf \n",c,*(pr+c));}
  
  /* Quick Sort */
  qsort(pr,6,sizeof(double),el_cmp);
  
  printf("------------------------------------\n");
  printf("After Sorting: \n");
  printf("------------------------------------\n");
  
  for(d = 0; d < 6; ++d){
    printf("R_array[%1d] = %.2lf \n",d,*(pr+d));
  }
}
/* Element compare for Quick Sort function */
int el_cmp(void *ep1, void *ep2){
  double *tp1 = (double*) ep1,
         *tp2 = (double*) ep2;
    
  if (*tp1 > *tp2){
    return 1;
  }
  else{
    return 0;
  }
}