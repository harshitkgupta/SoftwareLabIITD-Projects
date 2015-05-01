#include<stdio.h>
#include"regex.h"    
int main()
{
	char regexp[40];
	char text[40];
	printf("\nEnter the Regular Expression  ");
	fgets(regexp,40,stdin);
	printf("\nEnter the text to be matched  ");
	fgets(text,40,stdin);
	
	if(matchhere(regexp,text))
	{
		printf("-------------Match found---------------\n");
	}
	else
	{
		printf("-------------Match not found-----------\n");
	}
	
	return 0;
}
