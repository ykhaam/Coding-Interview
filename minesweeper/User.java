package minesweeper;

import java.util.Scanner;
/*
 * ������ ������ User�� function class
 * click �Լ� & flag �Լ�
 * */
public class User {
	/* �� ���� click -> click�ؾ� �� row,column�� �Է��ϴ� ������ ��ü�Ѵ�.
	 */
	public Tuple Click() {
		int r,c;
		Scanner sc=new Scanner(System.in);
		System.out.print("row�� column�� �Է��ϼ���. : ");
		r=sc.nextInt();
		c=sc.nextInt();
		Tuple pair=new Tuple(r,c);
		return pair;
	}
	
	public boolean Flag() {
		/*��߷� ������ �������� ��� ��, ����� �����Ѵ�. */
		Scanner sc=new Scanner(System.in);
		System.out.println("����� �����ðڽ��ϱ�? (yes-1/no-0)");
		int ans=sc.nextInt();
		if(ans==1) {
			return true;
		}
		else
			return false;
	}
}
