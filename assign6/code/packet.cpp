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

int BalancedPartition ( int a[] , int n ){

    int sum = 0;
    for( int i = 0 ; i < n ; i++)
        sum += a[i];

    int *s = new int[sum+1];

    s[0] = 1;
    for(int i = 1 ; i < sum+1 ; i++)    s[i] = 0;

    int diff = INT_MAX , ans=0;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = sum ; j >= a[i] ; j--)
        {
            s[j] = s[j] | s[j-a[i]];
            if( s[j] == 1 )
            {
                if( diff > abs( sum/2 - j) )
                {
                    diff = abs( sum/2 - j );
                    ans = j;
                }

            }
        }
    }
	return ans;
}
long ncr(int n,int k)
{
	if(n<k)
		return 0;
	if(n==k)
		return 1;
	long res=1;	
	for(int i=n;i>=n-k+1;i--)
		res*=i;
	for(int i=k;i>=1;i--)
		res/=i;
	return res;
}
int main()
{

	int n,k;
	cin>>n>>k;
	int *x=new int[n];
	int odd=0,even=0,sum=0;

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
	cout<<"no of triplets  "<<out<<endl;
	int *comb=new int [k];
	int cmb;
	int unfair=INT_MAX;
	int pi=0;
	cout<<"set of size "<<k<<"    and   unfairness"<<endl;
	 for(int i=0; i<(1<<n); i++) 
	{	int c=0;
                for (int j=0; j<32; j++) 
			if ( i & (1<<j)) c++;
		pi=0;
                if (c == k) {			
                        for (int j=0;j<32; j++)
			{	
				
				if (i & (1<<j)) 
				{	cout<< x[j];
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
	cout<<"min unfairness  "<<unfair;
	cout<<"\nset with min unfairness ";
	for (int j=0;j<32; j++)
	{	
		
		if (cmb & (1<<j)) 
		{	
			cout<< x[j]<<" ";
		
					
		}
	}
	int first=BalancedPartition(x,n);
	cout<<"\nfisrt partion has sum "<<first<<"\nsecond partition has sum "<<sum-first;
	int *s=new int [n];
	 for(int i=0; i<(1<<n); i++) 
	{	
			int fsum=0;
                	int pi=-1;	
                        for (int j=0;j<n; j++)
			{	
				
				if (i & (1<<j)) 
				{	
					fsum+=x[j];
					
				}
			}
			if(fsum==first)
			{
			cout<<"\nFirst Set ";
			for (int j=0;j<n; j++)
			{				
				if (i & (1<<j)) 
				{	cout<< x[j]<<" ";
										
				}				
			}
			cout<<"\nSecond Set";
                	for (int j=0;j<n; j++)
			{				
				if (~i & (1<<j)) 
				{	cout<< x[j]<<" " ;
										
				}				
			}
			cout<<endl;	
			break;
			}
	
        }
	return 0;


}
