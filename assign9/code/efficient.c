#include<stdio.h>
/* Compute Greatest Common Divisor using Euclid's Algorithm */
#define GCD(a,b) {              \
		int m=a;\
		int n=b;\
		while(m!=n) \
		{           \
			if(m>n)\
				m=m-n;\
			else   \
				n=n-m; \
		}                 \
		printf("GCD OF %d and %d is %d \n",a,b,m); \ 	
}

#define LCM(a,b) {		\
	int m=a;\
	int n=b;\
	while(m!=n)\
	{\
		if(m>n)\
			m=m-n;\
		else\
			n=n-m;	\
	}\	
	printf("LCM of %d and %d is %d \n",a,b,(a)*(b)/m); \ 
}
void gcd(int a,int b)
{
	GCD(a,b);
}	
void lcm(int a,int b)
{
	LCM(a,b);
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



		
