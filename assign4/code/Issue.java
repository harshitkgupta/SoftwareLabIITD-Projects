import java.io.*;
public class Issue implements Comparable<Issue> {
	String student;
	String book;
	String date;

	public Issue(String student, String book, String date) {
		super();

		this.student = student;
		this.book = book;
		this.date = date;
	}

	public String getStudent() {
		return student;
	}

	public void setStudent(String student) {
		this.student = student;
	}

	public String getBook() {
		return book;
	}

	public void setBook(String book) {
		this.book = book;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	@Override
	public int compareTo(Issue issue) {
		// TODO Auto-generated method stub
		return this.student.compareTo(issue.student);
	}
	public static void writeIssue(BufferedWriter out,Issue issue) {
		try {
			out.write(issue.getStudent() + ":" + issue.getBook() +":"+issue.getDate()+ "\n");

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
