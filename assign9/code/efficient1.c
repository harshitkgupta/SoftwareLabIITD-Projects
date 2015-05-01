#include<stdio.h>
void gcd( int a, int b ) {
    int result ;
    /* Compute Greatest Common Divisor using Euclid's Algorithm */
    __asm__ __volatile__ ( "movl %1, %%eax;"
                          "movl %2, %%ebx;"
                          "CONTD: cmpl $0, %%ebx;"
                          "je DONE;"
                          "xorl %%edx, %%edx;"
                          "idivl %%ebx;"
                          "movl %%ebx, %%eax;"
                          "movl %%edx, %%ebx;"
                          "jmp CONTD;"
                          "DONE: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
    );
    printf("GCD OF %d and %d is %d \n",a,b,result); 
}
void lcm(int a,int b)
{
    int result ;
    __asm__ __volatile__ ( "movl %1, %%eax;"
                          "movl %2, %%ebx;"
                          "CONTD1: cmpl $0, %%ebx;"
                          "je DONE1;"
                          "xorl %%edx, %%edx;"
                          "idivl %%ebx;"
                          "movl %%ebx, %%eax;"
                          "movl %%edx, %%ebx;"
                          "jmp CONTD1;"
                          "DONE1: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
    );
    printf("LCM of %d and %d is %d \n",a,b,(a)*(b)/result);
}
int main()
{
  int a,b;
  while(scanf("%d %d",&a,&b)==2)
  { 
  #ifdef VALUE1
    gcd(a,b);
  #endif
  #ifdef VALUE0
    lcm(a,b);
  #endif
  } 
  return 0;
} 
