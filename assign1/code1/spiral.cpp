#include<iostream>
#include"spiral.hpp"
using namespace std;

void printSpiralMatrix(int **arr,int N)
{ 
	int levl;
        int c = N/2;
    	int x,y;
	int flag=1;
    	x = y = c;
        
    	// Printing inwards to outwards. Works only for odd sized 2D array with one element in center
    	for(levl=1; c+levl<=N; levl++)
    	{

		for(; y>=c-levl ; y--)               // go left
		{  
           		cout << arr[x][y] << " ";

			if (x == 0 && y == 0)   // we are done
          		{ 
				 flag=0;
				break;
			}
		}       
		if(flag==0)
		break;
        	for(x++,y++; x<=c+levl && x < N; x++)    // go down
            		cout << arr[x][y] << " ";

        	for(x--,y++; y<=c+levl && y < N; y++) // go right
            		cout << arr[x][y] << " ";

       		 for(x--,y--; x>=c-levl ;x--)     // go up
            		cout << arr[x][y] << " ";

       		 x++;
        	y--;

	}
	cout<<endl;
}
