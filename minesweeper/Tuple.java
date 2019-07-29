package minesweeper;

public class Tuple {

	private int a;
	private int b;

	public Tuple(int a, int b) {
		this.a = a;
		this.b = b;
	}

	public static <A, B> Tuple of(final int a, final int b) {
		return new Tuple(a, b);
	}

	public int getA() {
		return a;
	}

	public int getB() {
		return b;
	}
	public void setA(int a) {
		this.a=a;
	}
	public void setB(int b) {
		this.b=b;
	}
}