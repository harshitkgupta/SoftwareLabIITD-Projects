#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b)
{

	int p=*(const int *)a;
	int q=*(const int *)b;
	return p-q;
}
int max(int a,int b)
{
	return a>b?a:b;
}
void BalancedPartition(int W,int wt[],int val[],int n,int taken[])
{
	
	int O[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0||w==0)
				O[i][w]=0;
			else if(wt[i-1]>w)
				O[i][w]=O[i-1][w];
			else
				O[i][w]=max(O[i-1][w],val[i-1]+O[i-1][W-wt[i-1]]);
			//cout<<O[i][w]<<" ";
		}
		//cout<<endl;
	}
	int  i=n;
    int j=W;
    while( i>0 && j>0 )
    {            
        while( O[i][j]==O[i-1][j]  && i>0)
        {	
            taken[i-1]=0;
            i=i-1; 
        }    
        if( i >0)
        {     
            taken[i-1]=1;
            j=j-wt[i-1];
            i=i-1;
        }
    }        
	

}

long ncr(int n,int k)
{
	if(n<k)
		return 0;
	int comb[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
				comb[i][j]=1;
			else
				comb[i][j]=comb[i-1][j-1]+comb[i-1][j];

		} 
	}	
	return comb[n][k];

}
int main()
{

	int n,k;
	cout<<"Enter Value of n and k  ";
	cin>>n>>k;
	int *x=new int[n];
	int odd=0,even=0,sum=0;
	cout<<"Enter no of items in packets ";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		//cout<<x[i];
		if(x[i]%2==0)
			even++;
		else
			odd++;
		sum+=x[i];
	}
	//cout<<odd<<even<<endl;
	//cout<<ncr(even,3)<<ncr(even,2)<<ncr(odd,1)<<endl;
	long out=ncr(even,3)+ncr(even,1)*ncr(odd,2);	
	 for(int i=0; i<(1<<n); i++) 
	{	int c=0;
		int s=0;
                for (int j=0; j<32; j++) 
			if ( i & (1<<j))
			{ c++;
				s+=x[j];
			}
                if (c == 3 && (s%2)==0) 
                {		
				cout<<"Sum= "<<s<<" set = ";
                for (int j=0;j<32; j++)
				{	
				
				if (i & (1<<j)) 
				{	cout<< x[j]<<" ";					
				}
				
				}
			cout<<endl;
		}
		
	}		
	cout<<"no of triplets  "<<out<<endl;
	int *comb=new int [k];
	int cmb;
	int unfair=INT_MAX;
	int pi=0;
	cout<<"\nset of size "<<k<<"    and   unfairness"<<endl;
	 for(int i=0; i<(1<<n); i++) 
	{	int c=0;
                for (int j=0; j<32; j++) 
			if ( i & (1<<j)) c++;
		pi=0;
                if (c == k) {			
                        for (int j=0;j<32; j++)
			{	
				
				if (i & (1<<j)) 
				{	cout<< x[j]<<" ";
					comb[pi]=x[j];
					pi++;
				}
				
			}
				long un=0;
				for(int a=0;a<k;a++)
				{	
					
					for(int b=a+1;b<k;b++)
					{	int u=comb[a]-comb[b];
						u=u>0?u:-1*u;
						
						un+=u;
					}
				}
				if(un<unfair)
				{	cmb=i;
					unfair=un;
				}
				cout<<"      "<<un;
                        cout<<endl;
                
		}
        }
	cout<<"\nmin unfairness  "<<unfair;
	cout<<"\nset with min unfairness ";
	for (int j=0;j<32; j++)
	{	
		
		if (cmb & (1<<j)) 
		{	
			cout<< x[j]<<" ";
		
					
		}
	}
	int taken[n];
	//cout<<sum/2;
	BalancedPartition(sum/2,x,x,n,taken);
	
	int first=0;
	int second=0;
	cout<<"\n \nElements of first set  ";
	 for(int i=0; i<n; i++) 
	{	
			if(taken[i]==1)
			{	cout<<x[i]<<"  ";
				first+=x[i];}
    }
    cout<<"\n Elements of second set ";
	 for(int i=0; i<n; i++) 
	{	
			if(taken[i]==0)
			{	cout<<x[i]<<"  ";
				second+=x[i];
			}
    }
    cout<<"\nfisrt partion has sum "<<first<<"\nsecond partition has sum "<<second<<endl;
    int diff=first-second;
    diff=(diff>=0?diff:-1*diff);
    cout<<"\n Min Diff between two partitions "<<diff<<endl<<endl;
	return 0;


}
