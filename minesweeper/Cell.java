package minesweeper;
/*
 * 지뢰찾기 게임의 각 cell에 관한 클래스.
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
	
	public boolean isBomb() {//해당 cell이 bomb인지 체크하는 함수
		if(this.bomb==true)
			return true;
		else
			return false;
	}
	public boolean changeFlaged() { //해당 flag를 클릭하면 반대로 바꿈 (깃발 체크/해제)
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
