#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[])
{
	int count=0;
	if(argc!=3)
	{
		cout<<"usage: Occurances <BigString> <SubString>\n";
		exit(EXIT_FAILURE);
	}	
	char *bigString=argv[1];
	char *subString=argv[2];
	int l;
	for(l=0;bigString[l]!='\0';l++);
	int length1=l;
	for(l=0;subString[l]!='\0';l++);
	int length2=l;
	if(length1<length2)
	{
		cout<<"\n Length of Big String can not be smaller than Sub String \n";
		exit(EXIT_FAILURE);		
	}
	for(int i=0;i<length1-length2+1;i++)
	{
		bool mismatch=false;
		for(int j=0,k=i;j<length2;j++,k++)
		{
			if(bigString[k]!=subString[j])
			{
				mismatch=true;
				break;
			}
		}
		if(!mismatch)
			count++;

	}
	cout<<"\n****************"<<count<<"times occurances found**********\n";	
	return EXIT_SUCCESS;

}
