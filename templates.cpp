#include<iostream>
using namespace std;

template<typename T> T myMax(T x, T y){
		return x>y ? x:y;
}

int main(){
	cout << myMax('a','d') << endl;
	return 0;
}