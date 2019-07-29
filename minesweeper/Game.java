package minesweeper;

import java.util.Scanner;

public class Game {
	int flagCnt=0;
	User user=new User();
	Panel panel=new Panel();
	Tuple[] dir=new Tuple[8];
	
	void initialize() { //panel �ʱ� ����.
		int bombCnt;
		int row,col;
		
		System.out.print("<initial state setting>\n������ ������ �Է��ϼ��� : ");
		Scanner sc=new Scanner(System.in);
		bombCnt=sc.nextInt();
		
		panel.setBombCnt(bombCnt);
		panel.showDisplay();
		System.out.println("������ ��ġ�� �Է��ϼ��� (row,col) ");
		for(int i=0;i<bombCnt;i++) {
			System.out.print(i+1+"�� ");
			row=sc.nextInt();
			col=sc.nextInt();
			panel.setInitBombAround(row, col);
		}
	}

	void gameStart() {
		System.out.println("\n<game start>\n");
		int row,col;
		Tuple clickpair=new Tuple(-1,-1);

		while(terminationCondition()==false) {
				clickpair=user.Click(); //user�� �Է��� col,row�� ��
				row=clickpair.getA();
				col=clickpair.getB();
			if(!user.Flag()) {//���� flag�� �ƴϸ�
				
			if(panel.hasFlag(row, col)&&panel.isChecked(row, col))
				System.out.println("Ŭ���� �� �����ϴ�.");
			//���� flag�̰�, �̹� check�� ���¸� Ŭ�� �Ұ���
			else {
				if(panel.isBomb(row, col)) {//���� ������ cell�� ���ڸ�
					panel.showDisplay();//��� ���
					end(0);//���� lose �ߵ��� ����
					}
				panel.checkBoundary(row, col);//���� ����
				panel.showDisplay();//��� ���		
				}
			}
			
			else {
				if(panel.isChecked(row, col)) {
					System.out.println("�̹� check�� ��ǥ�Դϴ�.");
				}
				else {
					panel.changeFlaged(row, col); 
					panel.showDisplay();
				}
			}
		
			if(terminationCondition()==true) //������ �� �����
				end(1);
			
			}//while terminationCondition == false
		}

	void end(int num) {
		if(num==1) System.out.println("Win!");
		else {
			System.out.println("Lose!");
		}
		System.exit(1);
	}
	
	public boolean terminationCondition() {
		boolean answer=false;
		if(panel.allCellChecked()==false)
			answer=false;
		else {
			if(panel.getflagCnt()>panel.getBombCnt()) {
				System.out.println("flag�� ���ں��� ����.");
			}
			else
				answer=true;
		}
		return answer;
	}
}
