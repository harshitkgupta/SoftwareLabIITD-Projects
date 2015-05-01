//============================================================================
// Name        : parallel_occurrences.cpp
// Author      : Harshit Kumar Gupta
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : NumOfOccurances in C++, Ansi-style
//============================================================================

/**
 *writing a program (called NumOfOccurrences)
*to find how many times a substring s2 occurs in a bigger string s1
*/

/**
\dot
digraph G {
main -> pthread_create -> counting_thread_fun -> count_occurrence;

pthrad_create->error;
main ->error;
}
\enddot
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>
#include<ctime>
using namespace std;
/**
 *\brief counting_thread_fun is the  function invoked by each thread
 *\param[in] thread_data is data passed to thread in form of structure
 */
void* counting_thread_fun(void * thread_data);

/**
 *\brief error function print error message on error stream
 *\param[in] msg is error message
 */
void error(string msg);

/**
 * \brief main function provides facility to process command line argument
 * \param[in] argc is the number of count of command line argument passed.
 * \param [in] argv is array to pointer of characters to store arguments.
 */
int main(int argc,char *argv[]);

/** COUNTING_THREAD_DATA is structure for passing data from main thread to child threads**/
typedef struct
{
	char * bigString;///< Pointer to Bigger String for finding Occurrences
	char * subString;///< Pointer Small String for finding Occurrences in Bigger Occurrences
	int bigStringLength;///< Length of Bigger String
	int subStringLength;///<Length of Smaller String
}COUNTING_THREAD_DATA;


pthread_mutex_t counting_mutex=PTHREAD_MUTEX_INITIALIZER;///<Mutex variable for synchronizing operation on count

pthread_mutex_t writing_mutex=PTHREAD_MUTEX_INITIALIZER;///<Mutex variable for writing output

static int match_count=0;///Static variable count

int NO_OF_THREADS=1;///No of thread which are used to execute program

void error(string msg)
{
	cerr<<msg<<strerror(errno);
	exit(EXIT_FAILURE);
}

void* counting_thread_fun(void * thread_data)
{
	// current date/time based on current system
   	time_t now = time(0);  
   	// convert now to string form
   	char* dt = ctime(&now);
  	 // convert now to tm struct for UTC
   	tm *gmtm = gmtime(&now);
   	dt = asctime(gmtm);
   	int l_count=0;
	COUNTING_THREAD_DATA *data=(COUNTING_THREAD_DATA*) thread_data;///data is pointer to COUNTING_THREAD_DATA type of structure
	for(int i=0;i<data->bigStringLength;i++)
	{
		bool mismatch=false;///checks for maismatch for data
		for(int j=0,k=i;j<data->subStringLength;j++,k++)
		{

			if(data->bigString[k]=='\0' || data->bigString[k]!=data->subString[j])
			{
				mismatch=true;
				break;
			}
		}
		if(!mismatch)
		{
			pthread_mutex_lock(&counting_mutex);
			match_count++;
			l_count++;
			pthread_mutex_unlock(&counting_mutex);
		}
	}
	pthread_mutex_lock(&writing_mutex);
	if(l_count>0)
	cout<<" thread Id  "<<pthread_self()<<" "<<l_count<<"  match found "<< "UTC time:"<< dt;
	pthread_mutex_unlock(&writing_mutex);
	return NULL;
}


int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		cout<<"usage: Occurrences <BigString> <SubString>\n";
		exit(EXIT_FAILURE);
	}
	char *bigString=argv[1];/// argv[1] is passed as bigger String
	char *subString=argv[2];/// argv[2] is passed as smaller String
	int l;
	for(l=0;bigString[l]!='\0';l++);
	int bigStringLength=l;
	for(l=0;subString[l]!='\0';l++);
	int subStringLength=l;

	if(bigStringLength<subStringLength)
	{
		cout<<"\n Length of Big String can not be smaller than Sub String ";
		exit(EXIT_FAILURE);
	}

	cout<<"Enter Number of threads to count occurrences\t";
	cin>>NO_OF_THREADS;
	if(NO_OF_THREADS<=1)
	{
		cout<<"For Parallel counting no of threads should be greater than one";
		exit(EXIT_FAILURE);
	}
	pthread_t thread_id[NO_OF_THREADS];/// pthread_t array for containing threads id's
	COUNTING_THREAD_DATA thread_data[NO_OF_THREADS];// COUNTING_THREAD_DATA array for containing thread argument data
	int div=bigStringLength/NO_OF_THREADS+1;
	while(div<subStringLength)
	{
		NO_OF_THREADS--;
		div=bigStringLength/NO_OF_THREADS+1;
	}
	if(bigStringLength-div*(NO_OF_THREADS-1) < subStringLength)
		NO_OF_THREADS--;
	for(int i=0;i<NO_OF_THREADS;i++)
      	{
		thread_data[i].bigString=bigString+div*i;
		thread_data[i].subString=subString;
		thread_data[i].bigStringLength=div;
		thread_data[i].subStringLength=subStringLength;
         	if(pthread_create(&thread_id[i], NULL, counting_thread_fun, (void *)&thread_data[i]))
     		{
			string msg="ERROR; return code from pthread_create()";
                    	error(msg);
     	    	}
      	}
	for(int i=0;i<NO_OF_THREADS;i++)
       	{
		pthread_join(thread_id[i],NULL);
	}

	cout<<"\n****************"<<match_count<<"times occurrences found**********\n";
	return EXIT_SUCCESS;

}

