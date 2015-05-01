#include<stdio.h>
void printPosition(int a)
{
	int i,j=0;
	for( i=0;i<32;i++)
		if(a & (1<<i))
		{
			j=i;
		}
	printf("Bit Position(31-0) set from left is %d in number %d\n",j,a);			
}
int main()
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