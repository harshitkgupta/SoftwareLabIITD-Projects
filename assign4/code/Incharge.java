import java.io.*;

public class Incharge implements Comparable<Incharge> {
	private String name;
	private String pass;

	public Incharge(String name, String pass) {
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

	@Override
	public String toString() {
		return "Incharge [name=" + name + ", pass=" + pass + "]";
	}

	@Override
	public int compareTo(Incharge incharge) {
		// TODO Auto-generated method stub
		return this.name.compareTo(incharge.name);
	}

	public static void writeIncharge(BufferedWriter out, Incharge incharge) {
		try {
			out.write(incharge.getName() + ":" + incharge.getPass() + "\n");

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
