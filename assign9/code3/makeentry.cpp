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


int main()
{
	
	student_issue_record stu_record;
	FILE * record_file;
	record_file=fopen("issue_record","ab");
	
	
		//time_t now = time(0);
		
		char username[15];
		cout<<"username";
		gets(username);
		cout<<"book name";
		char  bookName[50];
		gets(bookName);
		cout<<"day";
		int yday;
		cin>>yday;
		strcpy(stu_record.student_id,username);
		strcpy(stu_record.book_name,bookName);
		stu_record.day_in_year=yday;
		stu_record.year=2014;
		fwrite(&stu_record, sizeof(stu_record), 1, record_file);
	
	//outputfile.close();
	fclose(record_file);
	cout<<"book issued"<<endl;
	return 1;
}
