#include <stdio.h>
#include <stdlib.h>
void printPosition(int number)
{

	unsigned position;		
		/* Compute the position of the most significant set bit using the
		bsrl assembly instruction. */
		asm ("bsrl %1, %0" : "=r" (position) : "r" (number));
		printf("Bit Position(31-0) set from left is %d in number %d\n",position,number);
}
int main ()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{	
		if(a>b)
			printPosition(a);
		else
			printPosition(b);
	}
	return 0;

}

