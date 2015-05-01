#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

class student_issue_record
{
public:
	char student_id[15];
	char book_name[50];
	int day_in_year;
	int year;
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
	cout<<"Book no.                     Title                          Author                  Ed.     Publication "<<endl;
	for(int j=0;j<i;j++)
	{
		cout<<"book "<<setw(2)<<j+1<<" : ";
		cout<<setw(30)<<booksArray[j].bookName<<"\t"<<setw(20)<<booksArray[j].authorName<<"\t\
		"<<setw(2)<<booksArray[j].edition<<"\t"<<setw(20)<<booksArray[j].publication<<endl;
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
			cout<<"entry "<<setw(2)<<j<<" : ";
			matched_index=j;
			//cout<<booksArray[j].bookName<<"\t"<<booksArray[j].authorName<<"\t"<<booksArray[j].edition<<"\t"<<booksArray[j].publication<<endl;
			cout<<setw(30)<<booksArray[j].bookName<<"\t"<<setw(20)<<booksArray[j].authorName<<"\t\
			"<<setw(2)<<booksArray[j].edition<<"\t"<<setw(20)<<booksArray[j].publication<<endl;
		}
	cout<<"*************     Your query returned "<<results<<" entries    **********************"<<endl;
	return matched_index;
}

int issue_book(int book_no,char *username)
{
	ofstream outputfile;
	student_issue_record stu_record;
	FILE * record_file;
	record_file=fopen("issue_record","ab");
	outputfile.open("issuelist.txt",std::ofstream::out | std::ofstream::app);	
	int j=book_no;
	if(j>=0 && j<no_of_records)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		struct tm ts;
		localtime_r(&now, &ts);
		outputfile<<username<<"\t";
		outputfile<<booksArray[j].bookName<<"\t";
		outputfile<<booksArray[j].authorName<<"\t";
		outputfile<<booksArray[j].edition<<"\t";
		outputfile<<booksArray[j].publication<<"\t";
		outputfile<<dt<<endl;
		strcpy(stu_record.student_id,username);
		strcpy(stu_record.book_name,booksArray[j].bookName);
		stu_record.day_in_year=ts.tm_yday;
		stu_record.year=ts.tm_year+1900;
		fwrite(&stu_record, sizeof(stu_record), 1, record_file);
	}
	else
	{
		cout<<"Invalid Entry"<<endl;
		return 0;		
	}
	outputfile.close();
	fclose(record_file);
	cout<<"book issued"<<endl;
	return 1;
}

void cal_fine(char *username)
{
	FILE * record_file;
	record_file=fopen("issue_record","rb");
	time_t now = time(0);
	char* dt = ctime(&now);
	struct tm ts;
	localtime_r(&now, &ts);
	student_issue_record stu_record;
	int fine=0;
	int day_in_year=ts.tm_yday;
	int year=ts.tm_year+1900;
	int difference_in_days=0;

	while(fread(&stu_record,sizeof(stu_record),1,record_file))
	{
		//cout<<stu_record.student_id<<stu_record.book_name<<stu_record.day_in_year<<stu_record.year<<endl;
		if(strcmp(stu_record.student_id,username)==0)
		{
			
			difference_in_days=(year-stu_record.year)*365+(day_in_year-stu_record.day_in_year);
			//cout<<day_in_year<<stu_record.day_in_year<<difference_in_days<<endl;
			if(difference_in_days>7)
			{
				fine=fine+(difference_in_days-7)*10;
			}
			cout<<"book name "<<stu_record.book_name<<"; day of year "<<stu_record.day_in_year<<endl;
		}
	}
	cout<<"You have accumulated total fine of Rs."<<fine<<endl;

}

int main(void)
{
	create_array();
	

		//user interface
	while(1)
	{
		cout<<"\n\
		#######################################\n\
		Enter 1 for login admin.\n\
		Enter 2 to search for books.\n\
		Enter 3 for student login.\n\
		Enter any other key to exit.\n\
		#######################################\n"<<endl;
		char response1;
		cin>>response1;
		if(response1=='1')
		{
			char username[20];char password[20];
			int logoff_admin=0;
			cout<<"username: ";
			cin>>username;
			cout<<"password: ";
			cin>>password;
			//cout<<username<<password<<endl;
			if(admin_login(username,password)==1)
			{
			   while(1)
			   {
				cout<<"\n\
				#####################################\n\
				Enter 1 to add a book.\n\
				Enter 2 to delete books.\n\
				Enter any other key to log off.\n\
				#####################################\n";
				cin>>response1;
				//cout<<response1;
				if(response1=='1')
				{
					write_file();
					continue;
				}
				else if(response1=='2')
				{
					list_book();
					cout<<"\nEnter book number you want to delete:";
					int book_index;
					cin>>book_index;
					delete_entry(book_index);
					continue;
				}
				else 
				{
					cout<<"#################### Logging Off ########################"<<endl;
					break;
				}
			   }//end while loop for admin login
			}
			else
			{
				cout<<"@@@@@@@@@@@@@@@@@@@ Wrong username or password @@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
				continue;
			}

		}
		else if(response1=='2')
		{
			search_book();
		}
		else if(response1=='3')/*for student login*/
		{
		   
			char username[20];
			cout<<"\nusername: ";
			cin>>username;
			char password[20];
			cout<<"password: ";
			cin>>password;
			int logoff_student=0;
			int login_res=student_login(username,password);
			if(login_res!=1)
			{
				cout<<"Wrong username or password"<<endl;
				continue;
			}
			while(1)
		   	{
				cout<<"\n\
				###################################################\n\
				Enter 1 to veiw list of books\n\
				Enter 2 to issue a book\n\
				Enter 3 to search a book.\n\
				Enter 4 to see the books issued and fines accumulated\n\
				Enter any other key to return to previous menu.\n\
				###################################################\n";
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
					case '4':
					{
						cal_fine(username);
						break;
					}
					default:
						cout<<"****************** Logging Off *******************\n";
						logoff_student=1;
						break;					
				}
				if(logoff_student==1)
					break;
		  	}//end while loop for student
		}
		else
		{
			cout<<"\t\t*************** Exiting *************\n";
			return 0;
		}
	}
}
