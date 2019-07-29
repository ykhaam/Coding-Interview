package minesweeper;

/*
 * ����ã�� ��ġ�� �����ϰ� �ٷ�� Ŭ����.
 * 
 * <direction>
 * -1  1    0  1    1  1
 * -1  0   (0  0)   1  0
 * -1 -1    0 -1    1 -1
 *
 * */
public class Panel {
	Cell[][] cell=new Cell[10][10]; //10x10 �������� panel ����.
	Tuple[] dir=new Tuple[8]; //8���� ���� �����ϴ� �迭.
	int bombCnt; //��ź�� ��ü ����
	int flagCnt; //����� ��ü ����

	public Panel() { //������
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				cell[i][j]=new Cell();
				}
			}
		dir[0]=new Tuple(-1,1);
		dir[1]=new Tuple(0,1);
		dir[2]=new Tuple(1,1);
		dir[3]=new Tuple(-1,0);
		dir[4]=new Tuple(1,0);
		dir[5]=new Tuple(-1,-1);
		dir[6]=new Tuple(0,-1);
		dir[7]=new Tuple(1,-1);
	}
	
	public boolean isRange(int row,int col) {
		if(row>=10||col>=10||row<0||col<0)
			return false;
		else {
			return true;
		}
	}
	
	public boolean hasFlag(int row,int col) {
		if(cell[row][col].getFlag()==true)
			return true;
		else
			return false;
	}
	
	public boolean isChecked(int row,int col) {
		if(cell[row][col].getCheck()==true)
			return true;
		else
			return false;
	}
	
	public boolean isBomb(int row,int col) {
		if(cell[row][col].isBomb()==true)
			return true;
		else
			return false;
	}
	
	public void checkBoundary(int row,int col) {
		int r,c;
		if(isRange(row,col)==false||isChecked(row,col)||isBomb(row,col)||hasFlag(row,col)) {
			return;
		}
		cell[row][col].setCheck(true);
		if(cell[row][col].getValue()==0) {
			for(int i=0;i<8;i++) { //������ �ʰ����� �ʴ� ������, ������ ���쳪��
				r=row+dir[i].getA();
				c=col+dir[i].getB();
				checkBoundary(r,c);
			}	
		}
	}
	
	public void increaseCell(int row,int col) {
		if(isRange(row,col)==true)
			cell[row][col].increaseValue();
	}
	
	public void showDisplay() { //print method
		for(int i=0;i<10;i++) {
			System.out.print(" ");
			for(int j=0;j<10;j++) {
				if(cell[i][j].getCheck()==true){
					if(cell[i][j].getBomb()==true)
						System.out.print("��");
					else {
						if(cell[i][j].getValue()!=0)
							System.out.print(cell[i][j].getValue());
						else 
							System.out.print("/");
						}
					}
				else {
					if(cell[i][j].getFlag()==true)
						System.out.print("f");
					else
						System.out.print("?");
					}
				}
			System.out.println();
		}
		System.out.println();
	}
	
	public void setInitBombAround(int row, int col) {
		//���ڰ� ������, �� �ֺ� 8���� ������ cell value increase
		cell[row][col].setBomb(true); //�ش� cell�� �������� üũ��.
		for (int i=0;i<8;i++) {
			if(row+dir[i].getA()<0||col+dir[i].getB()<0) continue;
			this.increaseCellValue(row+dir[i].getA(), col+dir[i].getB());
			}
	}
	
	public void increaseCellValue(int row,int col) { //cell�� �� ����.
		cell[row][col].increaseValue();
	}
	public void setBombCnt(int cnt) {
		this.bombCnt=cnt;
	}
	public int getBombCnt() {
		return this.bombCnt;
	}
	
	public void setFlagCnt(int cnt) {
		this.flagCnt=cnt;
	}
	public int getflagCnt() {
		return this.flagCnt;
	}
	public boolean allCellChecked() { //panel�� ��� cell üũ�Ǿ����� Ȯ��.
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if(cell[i][j].getCheck()==false&&cell[i][j].getFlag()==false)
					return false;
				//����� �ƴѵ� check�ȵȰ� ������ false
			}
		}
		return true;
	}
	public void decreaseFlag() {
		flagCnt--;
	}
	public void increaseFlag() {
		flagCnt++;
	}
	public void changeFlaged(int row, int col) {
		if(cell[row][col].changeFlaged())
			//false->true ���� ��� ������
			increaseFlag();
		else
			decreaseFlag();
	}
}
