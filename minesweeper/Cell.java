package minesweeper;
/*
 * ����ã�� ������ �� cell�� ���� Ŭ����.
 * 
 * */
public class Cell {
	boolean flag;
	boolean check;
	boolean bomb;
	int value;
	
	public Cell() { //default constructor
		this.flag=false;
		this.check=false;
		this.bomb=false;
		this.value=0;
	}
	public void increaseValue() {
		this.value++;
	}
	
	public boolean isBomb() {//�ش� cell�� bomb���� üũ�ϴ� �Լ�
		if(this.bomb==true)
			return true;
		else
			return false;
	}
	public boolean changeFlaged() { //�ش� flag�� Ŭ���ϸ� �ݴ�� �ٲ� (��� üũ/����)
		if(this.flag==false) {
			this.flag=true;
			return true;
			}
		else {
			this.flag=false;
			return false;
			}
	}
	
	public void setFlag(boolean flag) {
		this.flag=flag;
	}
	public void setCheck(boolean check) {
		this.check=check;
	}
	public void setBomb(boolean bomb) {
		this.bomb=bomb;
	}
	public void setValue(int value) {
		this.value=value;
	}
	public boolean getFlag() {
		return flag;
	}
	public boolean getCheck() {
		return check;
	}
	public boolean getBomb() {
		return bomb;
	}
	public int getValue() {
		return value;
	}
	
}
