#include <stdio.h>

int main(void){
  /* Define variables */
  int m=0,n=0,k,small,large,c,sum=0;
  
  /* Prompt input */
  printf("Enter the range of numbers n(largest) and m(smallest), and a number k\n");
  scanf("%d %d %d",&m,&n,&k);
  
  /* Which number is bigger n or m */
  if(n <= m){
    printf("The result is 0\n");
    }
  else{
  /* The loop */
    printf("These are numbers that are divisors for both %d and %d\n",m,n);
    for(c=m;c < n+1; c++){
      if(c%k==0){
      printf("%d \n",c);
      sum += c;
      }
    }
  /* Print sum */
  printf("The sum of the divisors of both %d and %d is %d \n",m,n,sum);
  }
  return 0;
}