
import java.io.*;

public class Book implements Comparable<Book> {

	private String title;
	private String author;
	private String publication;
	private String edition;
	private String count;
	public Book(String title, String author, String publication, String edition) {

		this(title,author,publication,edition,"1");
	}
	public Book(String title, String author, String publication, String edition,String count) {
		super();

		this.title = title;
		this.author = author;
		this.publication = publication;
		this.edition = edition;
		this.count=count;
	}
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getPublication() {
		return publication;
	}

	public void setPublication(String publication) {
		this.publication = publication;
	}

	public String getEdition() {
		return edition;
	}

	public void setEdition(String edition) {
		this.edition = edition;
	}
	public String getCount() {
		return count;
	}

	public void setCount(String count) {
		this.count = count;
	}
	@Override
	public int compareTo(Book book) {
		// TODO Auto-generated method stub
		return this.author.compareTo(book.author);
	}

	@Override
	public String toString() {
		return "Book [title=" + title + ", author=" + author + ", publication="
				+ publication + ", edition=" + edition + ", count="+count+"]";
	}

	public static void writeBook(BufferedWriter out, Book book) {
		try {
			out.write(book.getTitle() + ":" + book.getAuthor() + ":"
					+ book.getPublication() + ":" + book.getEdition() + ":"+book.getCount()+"\n");

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
