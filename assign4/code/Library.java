import java.util.*;
import java.io.*;

public class Library {

	static void readBookFromFile(List<Book> bookList) {

		try {
			FileReader fileStream = new FileReader("library.ser");

			BufferedReader is = new BufferedReader(fileStream);

			Book book;
			String line = null;
			String arr[] = null;
			while ((line = is.readLine()) != null) {
				arr = line.split(":");
				book = new Book(arr[0], arr[1], arr[2], arr[3],arr[4]);
				bookList.add(book);
				line = null;
				arr = null;
				book = null;
			}

			is.close();
			fileStream.close();
		} catch (Exception e) {

			e.printStackTrace();
		} finally {

			Collections.sort(bookList);
		}

	}

	static void readIssueFromFile(List<Issue> issueList) {

		try {
			FileReader fileStream = new FileReader("issue.ser");

			BufferedReader is = new BufferedReader(fileStream);

			Issue issue;
			String line = null;
			String arr[] = null;
			while ((line = is.readLine()) != null) {
				arr = line.split(":");
				issue = new Issue(arr[0], arr[1], arr[2]);
				issueList.add(issue);
				// System.out.println(book);
				line = null;
				arr = null;
				issue = null;
			}

			is.close();
			fileStream.close();
		} catch (Exception e) {

			e.printStackTrace();
		} finally {

			Collections.sort(issueList);
		}

	}

	static void readInchargeFromFile(List<Incharge> inchargeList) {

		try {
			FileReader fileStream = new FileReader("incharge.ser");

			BufferedReader is = new BufferedReader(fileStream);

			Incharge incharge;
			String line = null;
			String arr[] = null;
			while ((line = is.readLine()) != null) {
				arr = line.split(":");
				incharge = new Incharge(arr[0], arr[1].trim());
				
				inchargeList.add(incharge);
				
				line = null;
				arr = null;
				incharge = null;
			}

			is.close();
			fileStream.close();
		} catch (Exception e) {

			e.printStackTrace();
		} finally {
			Collections.sort(inchargeList);
		}

	}

	static void readStudentFromFile(List<Student> studentList) {

		try {
			FileReader fileStream = new FileReader("student.ser");

			BufferedReader is = new BufferedReader(fileStream);

			Student student;
			String line = null;
			String arr[] = null;
			while ((line = is.readLine()) != null) {
				arr = line.split(":");
				student = new Student(arr[0], arr[1]);
				studentList.add(student);
				// System.out.println(book);
				line = null;
				arr = null;
				student = null;
			}

			is.close();
			fileStream.close();
		} catch (Exception e) {

			e.printStackTrace();
		} finally {
			Collections.sort(studentList);
		}

	}

	static public void writeBookToFile(List<Book> bookList) {

		try {

			FileWriter fileStream = new FileWriter("library.ser");
			BufferedWriter os = new BufferedWriter(fileStream);
			for (Book book : bookList)
				Book.writeBook(os, book);

			os.close();

			fileStream.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			//

		}
	}

	static public void writeStudentToFile(List<Student> studentList) {

		try {

			FileWriter fileStream = new FileWriter("student.ser");
			BufferedWriter os = new BufferedWriter(fileStream);
			for (Student student : studentList)
				Student.writeStudent(os, student);

			os.close();

			fileStream.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			//

		}
	}
	static public void writeIssueToFile(List<Issue> issueList) {

		try {

			FileWriter fileStream = new FileWriter("issue.ser");
			BufferedWriter os = new BufferedWriter(fileStream);
			for (Issue issue : issueList)
				Issue.writeIssue(os, issue);

			os.close();

			fileStream.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			//

		}
	}

	static void insertBook(Scanner sc, List<Book> bookList) {
		System.out.print("Enter Title ofBook: ");
		String title = sc.next();
		System.out.print("Enter Author of book: ");
		String author = sc.next();
		System.out.print("Enter publication: ");
		String publication = sc.next();
		System.out.print("Enter Edition: ");
		String edition = sc.next();
		Book book = new Book(title, author, publication, edition);
		bookList.add(book);
		writeBookToFile(bookList);
	}

	static void insertStudent(Scanner sc, List<Student> studentList) {
		System.out.print("Enter Name of Student: ");
		String name = sc.next();
		System.out.print("Enter Password of Student: ");
		String pass = sc.next();

		Student student = new Student(name, pass);
		studentList.add(student);
		writeStudentToFile(studentList);
						
	}

	public static boolean getStudentLogin(String name, String pass,
			List<Student> studentList) {
		boolean result = false;
		for (Student student : studentList) {
			if (student != null)
				if ((student.getName()).equalsIgnoreCase(name)
						&& (student.getPass()).equals(pass)) {
					result = true;
					break;
				}
		}

		return result;
	}

	public static boolean getInchargeLogin(String name, String pass,
			List<Incharge> inchargeList) {
		boolean result = false;
		for (Incharge incharge : inchargeList) {
			if (incharge != null)
				if ((incharge.getName()).equalsIgnoreCase(name)
						&& (incharge.getPass()).equals(pass)) {
					result = true;
					break;
				}
		}

		return result;
	}

	public static List<Book> searchByTitle(String title, List<Book> bookList) {
		List<Book> result = new ArrayList<Book>();
		for (Book name : bookList) {
			if (name != null)
				if ((name.getTitle()).contains(title)) {
					result.add(name);
				}
		}

		return result;
	}

	public static List<Book> searchByAuthor(String author, List<Book> bookList) {
		List<Book> result = new ArrayList<Book>();
		for (Book name : bookList) {
			if (author != null)
				if ((name.getAuthor()).contains(author)) {
					result.add(name);
				}
		}

		return result;
	}

	public static List<Book> searchByPublication(String publication,
			List<Book> bookList) {
		List<Book> result = new ArrayList<Book>();
		for (Book name : bookList) {
			if (publication != null)
				if ((name.getPublication()).contains(publication)) {
					result.add(name);
				}
		}

		return result;
	}

	public static List<Book> searchByEdition(String edition, List<Book> bookList) {
		List<Book> result = new ArrayList<Book>();
		for (Book name : bookList) {
			if (edition != null)
				if ((name.getEdition()).contains(edition)) {
					result.add(name);
				}
		}

		return result;
	}

	static void printBookList(List<Book> bookList) {
		if (bookList.size() == 0)
			System.out.println("NO Record found \n");
		for (Book book : bookList) {
			System.out.println(book);
		}

	}

	public static void main(String args[]) {
		
		System.out.println("\033[H\033[2J");
		
		List<Book> bookList = new ArrayList<Book>();
		List<Student> studentList = new ArrayList<Student>();
		List<Incharge> inchargeList = new ArrayList<Incharge>();
		List<Issue> issueList=new ArrayList<Issue>();
		
		Scanner sc = new Scanner(System.in);
		Boolean f = true;
		readBookFromFile(bookList);
		readStudentFromFile(studentList);
		readInchargeFromFile(inchargeList);
		readIssueFromFile(issueList);
		System.out.println("Menu :::::::::::::::");
		System.out.println("1----- STUDENT LOGIN");
		System.out.println("2----- INCHARGE LOGIN");
		int choice = sc.nextInt();
		System.out.println("\033[H\033[2J");
		if (choice == 1) {
			int a=3;
			boolean login=false;
			String user=null,pass=null;
			while(a>0)
			{
			System.out.print(" Enter UserName : ");
			user = sc.next();
			System.out.print(" Enter Password : ");
			 pass = sc.next();
			login=getStudentLogin(user, pass, studentList);
			if(login)
				break;
			else 
			{	System.out.println("Wrong username password combiantion ! try again");
				System.out.println("\033[H\033[2J");}
			a--;
			}
			
			if (login) {
				do {
					System.out.println("Menu :::::::::::::::");
					System.out.println("1----- Display record of all books");
					System.out.println("2----- Search Record of any book");
					System.out.println("3----- Issue any  book");
					System.out.println("4----- Return any  book");
					System.out.println("5------ Print Total Imposed Fine");

					System.out.println("6----- Quit");

					int ch = sc.nextInt();
					switch (ch) {
					case 1:
						printBookList(bookList);
						break;
					case 2:
						int schoice;
						boolean s = true;
						do {	
							System.out.println("1----- Search By Title of book");
							System.out.println("2----- Search By Author of book");
							System.out.println("3----- Search By Publication of book");
							System.out.println("4----- Search By Edition of book");
							System.out.println("5----- Back to Main Menu");
							schoice = sc.nextInt();
							switch (schoice) {
							case 1:
								System.out.print("Enter the Title of book  ");
								String title = sc.next();
								List<Book> result1 = searchByTitle(title,
										bookList);
								printBookList(result1);
								break;
							case 2:
								System.out.print("Enter the Author of book   ");
								String author = sc.next();
								List<Book> result2 = searchByAuthor(author,
										bookList);
								printBookList(result2);
								break;
							case 3:
								System.out.print("Enter Publication of book  ");
								String publication = sc.next();
								List<Book> result3 = searchByPublication(
										publication, bookList);
								printBookList(result3);
								break;
							case 4:
								System.out.print("Enter edition of book ");
								String edition = sc.next();
								List<Book> result4 = searchByEdition(edition,
										bookList);
								printBookList(result4);
								break;
							case 5:
								s = false;
								break;
							default:System.out.println("invalid option");
							}
							
						} while (s);
						break;
					case 3:
						System.out.print("Enter the Title of book  ");
						String title = sc.next();
						IssueByTitle(title,user,bookList,issueList);						
						break;
					case 4:
						System.out.print("Enter the Title of book  ");
						String tit = sc.next();
						ReturnByTitle(tit,user,bookList,issueList);						
						break;
					case 5:calculateFine(user,issueList);
						break;
					case 6:
						f = false;
						break;
					default:System.out.println("invalid option");
					}
					
				} while (f == true);
			}
			else 
				System.out.println("You have exceeds max limits ");
		}
		if (choice == 2) {
			int a=3;
			boolean login=false;
			String user=null,pass=null;
			while(a>0)
			{
			System.out.print(" Enter InchargeName : ");
			 user = sc.next();
			System.out.print(" Enter Password : ");
			 pass = sc.next();
			login=getInchargeLogin(user, pass, inchargeList);
			if(login)
				break;
			else 
			{	System.out.println("Wrong username password combiantion ! try again");
				System.out.println("\033[H\033[2J");}
			a--;
			}
			
			if (login) {
				do {
					System.out.println("Menu :::::::::::::::");
					System.out.println("1----- Display record of all books");
					System.out.println("2----- Insert record of one book");
					System.out.println("3----- Increase count of any book");
					System.out.println("4----- Search Record of any book ");
					System.out.println("5----- Delete Record of any book");
					System.out.println("6----- Insert record of one Student");
					System.out.println("7----- Calculate fine imposed on Students");
					System.out.println("8----- Quit");

					int ch = Integer.parseInt(sc.next());
					
					switch (ch) {
					case 1:
						printBookList(bookList);
						break;					
					case 2:
						insertBook(sc, bookList);
						break;
					
					case 3:
						System.out.print("Enter the Title of book  ");
						String titl = sc.next();
						System.out.print("Enter the Count of book  ");
						String count = sc.next();
						increaseBookCount(titl,count,bookList);
						break;
					case 4:
						int schoice;
						boolean s = true;
						do {
							System.out.println("1----- Search By Title of book");
							System.out.println("2----- Search By Author of book");
							System.out.println("3----- Search By Publication of book");
							System.out.println("4----- Search By Edition of book");
							System.out.println("5----- Back to Main Menu");
							schoice = Integer.parseInt(sc.next());
							System.out.println("\033[H\033[2J");
							switch (schoice) {
							case 1:
								System.out.print("Enter the Title of book  ");
								String title = sc.next();
								List<Book> result1 = searchByTitle(title,
										bookList);
								printBookList(result1);
								break;
							case 2:
								System.out.print("Enter the Author of book   ");
								String author = sc.next();
								List<Book> result2 = searchByAuthor(author,
										bookList);
								printBookList(result2);
								break;
							case 3:
								System.out.print("Enter Publication of book  ");
								String publication = sc.next();
								List<Book> result3 = searchByPublication(
										publication, bookList);
								printBookList(result3);
								break;
							case 4:
								System.out.print("Enter edition of book ");
								String edition = sc.next();
								List<Book> result4 = searchByEdition(edition,
										bookList);
								printBookList(result4);
								break;
							case 5:
								s = false;
								break;
							default:System.out.println("invalid option");
							}
						
						} while (s);
						break;
					case 5:
						int dchoice;
						boolean d = true;
						do {	
							System.out.println("1---- Delete By Book Name of book");
							System.out.println("2---- Delete By Author of book");
							System.out.println("3---- Delete By Publication of book");
							System.out.println("4---- Delete By Edition of book");
							System.out.println("5----- Back to Main Menu");
							dchoice = Integer.parseInt(sc.next());
							System.out.println("\033[H\033[2J");
							switch (dchoice) {

							case 1:
								System.out.print("Enter the Title of book  ");
								String tit = sc.next();
								deleteByTitle(tit, bookList);
								break;
							case 2:
								System.out.print("Enter the Name Of Author  ");
								String aut = sc.next();
								deleteByAuthor(aut, bookList);
								break;
							case 3:
								System.out.print("Enter the Publication   ");
								String pub = sc.next();
								deleteByPublication(pub, bookList);
								break;
							case 4:
								System.out.print("Enter the edition  ");
								String ed = sc.next();
								deleteByEdition(ed, bookList);
								break;
							case 5:
								d = false;
								break;
							default:System.out.println("invalid option");
							}
						
						} while (d);
						break;
					case 6:
						insertStudent(sc, studentList);
						break;
					case 7: calculateTotalFine(studentList,issueList);
						break;
					case 8:
						f = false;
						break;
					default:System.out.println("invalid option");
					}
		
				} while (f == true);
			}else 
				System.out.println("You have exceeds max limits ");
		}

	}

	 static void IssueByTitle(String title,String user, List<Book> bookList,
			List<Issue> issueList) {
		
		 boolean b=false;
			Book book=null;
			int count=0;
			for (Book name : bookList) {
				if (name != null)
					if ((name.getTitle()).equalsIgnoreCase(title)) {
						book=name;
						b=true;
					}
			}
			for (Issue name : issueList) {
				if (name != null)
					if ((name.getBook()).equalsIgnoreCase(title)) {
						count+=1;	
						
					}
			}
			if(b==false)
			{	System.out.println("Book Not Found Try Again");
				return;
			}
				
			if(b==true && Integer.parseInt(book.getCount())>count)
			{
				issueList.add(new Issue(user,title ,new Date().getTime()+""));
				System.out.println(book+"is now  Issued to You");
				writeIssueToFile(issueList);
			}
			else
			{
				System.out.println("Book is already issued  Try Another");
				return;

			}
			
		
	}
	static void ReturnByTitle(String title,String user, List<Book> bookList,
			List<Issue> issueList) {
		
		 boolean b=false,i=false;
			Book book=null;
			Issue issue=null;
			for (Book name : bookList) {
				if (name != null)
					if ((name.getTitle()).equalsIgnoreCase(title)) {
						book=name;
						b=true;
					}
			}
			for (Issue name : issueList) {
				if (name != null)
					if ((name.getBook()).equalsIgnoreCase(title)&&(name.getStudent()).equalsIgnoreCase(user)) {
						issue=name;
						i=true;
					}
			}
			if(b==false)
			{	System.out.println("NO such Book exist! Try Again");
				return;
			}
			if(i==false)
			{	System.out.println("This Book is not  issued to you Try Another book");
				return;
			}	
			if(b==true && i==true)
			{
				calculateFine(user,issueList);				
				issueList.remove(issue);
				System.out.println("You have returned "+book);
			}
			writeIssueToFile(issueList);
		
	}

	static void deleteByTitle(String tit, List<Book> bookList) {
		

		for (Book name : bookList) {
			if (name != null)
				if ((name.getTitle()).equalsIgnoreCase(tit)) {
					System.out.println(name + " Record Deleted \n");
					bookList.remove(name);
					break;
				}
		}
		writeBookToFile(bookList);
	}

	static void deleteByAuthor(String aut, List<Book> bookList) {
		boolean found=false;
		for (int i=bookList.size()-1; i> -1; i--) {
   			if (bookList.get(i).getAuthor().equals(aut) ) 
        		{	
				System.out.println(bookList.get(i) + " Record Deleted \n");
				bookList.remove(i);
				found=true;				
    			}
		}
		if(!found)
			System.out.println("NO such record found");
		writeBookToFile(bookList);
	}

	static void deleteByPublication(String pub, List<Book> bookList) {
		
		boolean found=false;
		for (int i=bookList.size()-1; i> -1; i--) {
   			if (bookList.get(i).getPublication().equals(pub) ) 
        		{	
				System.out.println(bookList.get(i) + " Record Deleted \n");
				bookList.remove(i);
				found=true;				
    			}
		}
		writeBookToFile(bookList);
		if(!found)
			System.out.println("NO such record found");
	}

	static void deleteByEdition(String ed, List<Book> bookList) {
		boolean found=false;
		for (int i=bookList.size()-1; i> -1; i--) {
   			if (bookList.get(i).getEdition().equals(ed) ) 
        		{	
				System.out.println(bookList.get(i) + " Record Deleted \n");
				bookList.remove(i);
				found=true;				
    			}
		}
		writeBookToFile(bookList);
		if(!found)
			System.out.println("NO such record found");

	}
	static void calculateFine(String user,List<Issue> issueList)
	{
		int fine=0;
		for (Issue name : issueList) {
			if (name != null)
				if ((name.getStudent()).equalsIgnoreCase(user)) {
					long days= (Long.parseLong(name.getDate()) - (new Date()).getTime()) / (24 * 60 * 60 * 1000);
					if(days>7)
					fine+=(days-7)*10;
					System.out.println(name.getBook()+" is "+days+ " days late ");					
				}				
		}
		System.out.println("Total Fine imposed on you is "+fine+ " Rs \n");
	}
	static void increaseBookCount(String title,String count,List<Book> bookList)
	{
		for (Book name : bookList) {
			if (name != null)
				if ((name.getTitle()).equalsIgnoreCase(title)) {
					name.setCount(count);
					System.out.println(name + " Count Changed \n");
					break;
				}
		}
		writeBookToFile(bookList);

	}
	static void calculateTotalFine(List<Student> studentList,List<Issue> issueList)
	{
		int totfine=0;
		for(Student i: studentList)
		{
			int fine=0;
			for(Issue j: issueList)
			{
				if(i.getName().equalsIgnoreCase(j.getStudent()))
				{
				long days= (Long.parseLong(j.getDate()) - (new Date()).getTime()) / (24 * 60 * 60 * 1000);
					if(days>7)
					fine+=(days-7)*10;

				}	

			}
			System.out.println("Student "+i.getName()+" has fine "+fine+" Rs");
			totfine+=fine;
		}
		System.out.println("Total fine Imposed on all Students is  "+totfine+" Rs");

	}
	private static void Clear()
	{
    try
    {
        String os = System.getProperty("os.name");

        if (os.contains("Windows"))
        {
            Runtime.getRuntime().exec("cls");
        }
        else
        {
            Runtime.getRuntime().exec("clear");
        }
    }
    catch (Exception exception)
    {
    }
}
}
