#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class book
{
	public:
		char bookName[50];
		char authorName[50];
		char edition[50];
		char publication[50];
};
class login_details
{
	public:
		char username[20];
		char password[20];
};

void chop( char *s )
{
    int len=strlen(s);
    *(s+(len-1))='\0';
}

int student_login(char * username,char * password)
{
	FILE *ifile = fopen ("studentlogin", "r" );
		login_details templogin ;
		int i=0;

		while(fgets ( templogin.username, 20, ifile ) != NULL)
		{
			chop(templogin.username);
			//cout<<templogin.username<<endl;
			//fgets(booksArray[i].bookName,50,ifile);
			//cout<<booksArray[i].bookName<<endl;
			if(fgets(templogin.password,20,ifile)==NULL)
				break;
			chop(templogin.password);
			//cout<<templogin.password<<endl;
			//cout<<booksArray[i].authorName<<endl;
			if(strcmp(username,templogin.username)==0 && strcmp(password,templogin.password)==0)
				return 1;

		}		
		
		fclose(ifile);
		return 0;

}
int admin_login(char * username,char * password)
{
		FILE *ifile = fopen ("adminlogin", "r" );
		login_details templogin ;
		int i=0;

		while(fgets ( templogin.username, 20, ifile ) != NULL)
		{
			chop(templogin.username);
			//cout<<templogin.username<<endl;
			//fgets(booksArray[i].bookName,50,ifile);
			//cout<<booksArray[i].bookName<<endl;
			if(fgets(templogin.password,20,ifile)==NULL)
				break;
			chop(templogin.password);
			//cout<<templogin.password<<endl;
			//cout<<booksArray[i].authorName<<endl;
			if(strcmp(username,templogin.username)==0 && strcmp(password,templogin.password)==0)
				return 1;

		}		
		
		fclose(ifile);
		return 0;

}
book booksArray[100];
int no_of_records;
//To append to the file

void create_array()
{
	FILE *ifile = fopen ("libDatabase.txt", "r" );
		book tempBook;
		int i=0;
		while(fgets ( booksArray[i].bookName, 50, ifile ) != NULL)
		{
			chop(booksArray[i].bookName);
			//fgets(booksArray[i].bookName,50,ifile);
			//cout<<booksArray[i].bookName<<endl;
			if(fgets(booksArray[i].authorName,50,ifile)==NULL)
				break;
			chop(booksArray[i].authorName);
			//cout<<booksArray[i].authorName<<endl;
			if(fgets(booksArray[i].edition,50,ifile)==NULL)
				break;
			chop(booksArray[i].edition);
			//cout<<booksArray[i].edition<<endl;
			if(fgets(booksArray[i].publication,50,ifile)==NULL)
				break;
			chop(booksArray[i].publication);			//cout<<booksArray[i].publication<<endl;
			i++;
		}		
		cout<<i<<" files read"<<endl;
		no_of_records=i;
		fclose(ifile);
}
void list_book()
{
	//For printing all the content stored in the array
	int i=no_of_records;
	for(int j=0;j<i;j++)
	{
		cout<<"book "<<j+1<<" : ";
		cout<<booksArray[j].bookName<<"\t"<<booksArray[j].authorName<<"\t"<<booksArray[j].edition<<"\t"<<booksArray[j].publication<<endl;
	}
}
void write_file()
{
	ofstream ofile ("libDatabase.txt",fstream::out|fstream::app);
	book a;
	/*a.bookName="Brief History of time";
	a.authorName="S. Hawkins";
	a.edition=1;
	a.publication="unknown";
	ofile.write((char*)&a,sizeof(book));*/
	char qName[50];
	char qAuthor[50];
	char qPub[40];
	char qEd[10];
	cout<<"enter Book's title"<<endl;
	gets(qName);
	gets(qName);
	//cout<<"name of book"<<qName<<endl;
	cout<<"enter Author "<<endl;
	gets(qAuthor);
	cout<<"enter Publication "<<endl;
	gets(qPub);
	cout<<"enter edition "<<endl;
	gets(qEd);
	ofile<<qName<<endl;
	ofile<<qAuthor<<endl;
	ofile<<qEd<<endl;
	ofile<<qPub<<endl;
	ofile.close();
	create_array();
}
void delete_entry(int book_index)
{
	ofstream outputfile;
	outputfile.open("templibmanagement.txt");
	for(int j=0;j<no_of_records;j++)
	{
		if((j+1)!=book_index)
		{
			outputfile<<booksArray[j].bookName<<endl;
			outputfile<<booksArray[j].authorName<<endl;
			outputfile<<booksArray[j].edition<<endl;
			outputfile<<booksArray[j].publication<<endl;
		}		
	}
	remove("libDatabase.txt");

	outputfile.close();
	rename("templibmanagement.txt","libDatabase.txt");
	cout<<"book deleted"<<endl;
	create_array();
}



int search_book()
{
	char qName[50];
	char qAuthor[50];
	char qPub[40];
	char qEd[10];
	cout<<"enter Book's title or press $"<<endl;
	gets(qName);
	gets(qName);
	cout<<"enter Author or press $"<<endl;
	gets(qAuthor);
	cout<<"enter Publication or press $"<<endl;
	gets(qPub);
	cout<<"enter edition or press $"<<endl;
	gets(qEd);
	int matched_index;
	cout<<"********************Searching for your queries****************************"<<endl;
	/*searching  for the book in the database*/
	int results=0;
	int i=no_of_records;
	for(int j=0;j<i;j++)
		{
			//cout<<"in loop "<<j<<endl;
			int flag=1;
			if(strcmp(qName,"$"))
			{
				//cout<<"looking for name"<<endl;
				if(strcmp(qName,booksArray[j].bookName)!=0)
				{
					flag=0;
					continue;	
				}

			}
			if(strcmp(qAuthor,"$"))
			{
				//cout<<"looking for author"<<endl;
				if(strcmp(qAuthor,booksArray[j].authorName)!=0)
				{
					flag=0;
					continue;	
				}
					
			}
			if(strcmp(qPub,"$"))
			{
				//cout<<"looking for publication"<<endl;
				if(strcmp(qPub,booksArray[j].publication)!=0)
				{
					flag=0;
					continue;	
				}
					
			}
			if(strcmp(qEd,"$"))
			{
				//cout<<"looking for edition"<<endl;
				if(strcmp(qEd,booksArray[j].edition)!=0)
				{
					flag=0;
					continue;	
				}				
			}
			results++;
			cout<<"entry "<<j<<endl;
			matched_index=j;
			cout<<booksArray[j].bookName<<"\t"<<booksArray[j].authorName<<"\t"<<booksArray[j].edition<<"\t"<<booksArray[j].publication<<endl;
		}
	cout<<"*************     Your query returned "<<results<<" entries    **********************"<<endl;
	return matched_index;
}

int issue_book(int book_no,char *username)
{
	ofstream outputfile;
	outputfile.open("issuelist.txt",std::ofstream::out | std::ofstream::app);	
	int j=book_no;
	if(j>0 && j<no_of_records)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		outputfile<<username<<"\t";
		outputfile<<booksArray[j].bookName<<"\t";
		outputfile<<booksArray[j].authorName<<"\t";
		outputfile<<booksArray[j].edition<<"\t";
		outputfile<<booksArray[j].publication<<"\t";
		outputfile<<dt<<endl;
	}
	else
	{
		cout<<"Invalid Entry"<<endl;
		return 0;		
	}
	outputfile.close();
	cout<<"book issued"<<endl;
	return 1;
}

int main(void)
{
	create_array();
	

		//user interface
	while(1)
	{
		cout<<"Enter 1 for login admin.\nEnter 2 to search for books.\nEnter 3 for student login.\nEnter any other key to exit.\n"<<endl;
		char response1;
		cin>>response1;
		if(response1=='1')
		{
			char username[20];char password[20];
			cout<<"username: ";
			cin>>username;
			cout<<"password: ";
			cin>>password;
			//cout<<username<<password<<endl;
			if(admin_login(username,password)==1)
			{
			cout<<"Enter 1 to add a book.\nEnter 2 to delete books.\n";
			cin>>response1;
			if(response1=='1')
			{
				write_file();
				continue;
			}
			if(response1='2')
			{
				list_book();
				cout<<"Enter book number you want to delete:";
				int book_index;
				cin>>book_index;
				delete_entry(book_index);
				continue;
			}
			}
			else
			{
				cout<<"wrong username or password"<<endl;
				continue;
			}

		}
		else if(response1=='2')
		{
			search_book();
		}
		else if(response1=='3')
		{
			char username[20];
			cout<<"username: ";
			cin>>username;
			char password[20];
			cout<<"password: ";
			cin>>password;
			int login_res=student_login(username,password);
			if(login_res!=1)
			{
				cout<<"Wrong username or password"<<endl;
				continue;
			}
			cout<<"Enter 1 to veiw list of books\nEnter 2 to issue a book\nEnter 3 to search a book.\nEnter any other key to exit. ";
			cin>>response1;
			switch(response1)
			{
				case '1':
					list_book();
					break;
				case '2':
				{
					int book_no=search_book();
					issue_book(book_no,username);
					break;
				}
				case '3':
				{
					search_book();
					break;
				}
				default:
					cout<<"******************Exiting*******************\n";
					exit(1);					
			}
		}
		else
		{
			cout<<"\t\t*************** Exiting *************\n";
			return 0;
		}
	}
}
