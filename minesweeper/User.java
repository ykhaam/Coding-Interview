package minesweeper;

import java.util.Scanner;
/*
 * 게임을 진행할 User의 function class
 * click 함수 & flag 함수
 * */
public class User {
	/* 한 번의 click -> click해야 할 row,column을 입력하는 것으로 대체한다.
	 */
	public Tuple Click() {
		int r,c;
		Scanner sc=new Scanner(System.in);
		System.out.print("row와 column을 입력하세요. : ");
		r=sc.nextInt();
		c=sc.nextInt();
		Tuple pair=new Tuple(r,c);
		return pair;
	}
	
	public boolean Flag() {
		/*깃발로 설정할 것인지를 물어본 후, 깃발을 설정한다. */
		Scanner sc=new Scanner(System.in);
		System.out.println("깃발을 꽂으시겠습니까? (yes-1/no-0)");
		int ans=sc.nextInt();
		if(ans==1) {
			return true;
		}
		else
			return false;
	}
}
