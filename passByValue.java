class test{
	static void changeNumber(int originalNum, int newNum){
			originalNum = newNum;
			return;
	}
	
	public static void main(String[] args){
		integerClass y = new integerClass();
		y.setANumber(10);
		System.out.println("aNumber in object y is: " + y.aNumber);
		
		int number = 5;
		
		changeNumber(number, 10);
		
		System.out.println("primitive number has the value: " + number);
	}
}