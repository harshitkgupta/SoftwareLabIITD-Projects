#include<iostream>
#include"spiral.hpp"
using namespace std;

int main()
{
	int N; 
	cout<<"Enter the size of square matrix   ";
	cin>>N;
	if(N%2==0)
	{
		cout<<"\nSize of square matrix should be odd \n";
		cout<<"Again Enter the size of square matrix   ";
		cin>>N;
	}
        int **arr =new int*[N];

	/* read elements of a matrix */
	for(int i=0;i<N;i++)
		arr[i]=new int[N];

	cout<<"\n Enter the elements of Square matrix \n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}	                  
 	/*print spiral matrix in reverse order*/
    	printSpiralMatrix(arr,N);
    	return 0;
}
