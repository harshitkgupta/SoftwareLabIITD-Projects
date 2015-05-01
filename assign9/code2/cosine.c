#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846
double cosx(double angle)
{
	double rada=PI*(angle)/180;
	
    return cos(rada);
}
int main()
{
	double a,b;
	while(scanf("%lf %lf",&a,&b)==2)
	{
		printf("Cosine of a= %lf \nCosine of b= %lf \n",cosx(a),cosx(b));
	}	
	return 0;		
}