import java.io.*;

public class Student implements Comparable<Student> {
	String name;
	String pass;

	public Student(String name, String pass) {
		super();

		this.name = name;
		this.pass = pass;

	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPass() {
		return pass;
	}

	public void setPass(String pass) {
		this.pass = pass;
	}

	public static void writeStudent(BufferedWriter out, Student student) {
		try {
			out.write(student.getName() + ":" + student.getPass() + "\n");

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@Override
	public int compareTo(Student student) {
		// TODO Auto-generated method stub
		return this.name.compareTo(student.name);
	}
}
