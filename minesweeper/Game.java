package minesweeper;

import java.util.Scanner;

public class Game {
	int flagCnt=0;
	User user=new User();
	Panel panel=new Panel();
	Tuple[] dir=new Tuple[8];
	
	void initialize() { //panel 초기 설정.
		int bombCnt;
		int row,col;
		
		System.out.print("<initial state setting>\n지뢰의 개수를 입력하세요 : ");
		Scanner sc=new Scanner(System.in);
		bombCnt=sc.nextInt();
		
		panel.setBombCnt(bombCnt);
		panel.showDisplay();
		System.out.println("지뢰의 위치를 입력하세요 (row,col) ");
		for(int i=0;i<bombCnt;i++) {
			System.out.print(i+1+"번 ");
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
				clickpair=user.Click(); //user가 입력한 col,row의 쌍
				row=clickpair.getA();
				col=clickpair.getB();
			if(!user.Flag()) {//만약 flag가 아니면
				
			if(panel.hasFlag(row, col)&&panel.isChecked(row, col))
				System.out.println("클릭할 수 없습니다.");
			//만약 flag이고, 이미 check한 상태면 클릭 불가능
			else {
				if(panel.isBomb(row, col)) {//만약 선택한 cell이 지뢰면
					panel.showDisplay();//결과 출력
					end(0);//게임 lose 중도에 종료
					}
				panel.checkBoundary(row, col);//게임 진행
				panel.showDisplay();//결과 출력		
				}
			}
			
			else {
				if(panel.isChecked(row, col)) {
					System.out.println("이미 check한 좌표입니다.");
				}
				else {
					panel.changeFlaged(row, col); 
					panel.showDisplay();
				}
			}
		
			if(terminationCondition()==true) //무사히 잘 종료됨
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
				System.out.println("flag가 지뢰보다 많음.");
			}
			else
				answer=true;
		}
		return answer;
	}
}
