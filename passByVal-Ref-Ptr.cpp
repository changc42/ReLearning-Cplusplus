#include<iostream>
using namespace std;

void passByVal(int val){
	val = 10;
	cout << val << endl;
}

void passByRef(int& ref){
	red = 10;
	cout << ref << endl;
}


int main(){
	
	int x = 5;
	cout << x << endl;
	passByVal(x);
	cout << x << endl;
	passByRef(x);
	cout << x << endl;
	
	return 0;
}