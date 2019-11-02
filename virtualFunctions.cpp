#include<iostream>
using namespace std;

class Bird{
	public:
	string color;
	string location;
	string food;
	
	Bird(){
		color = "any color";
		location = "any location";
		food = "hamburgers";
	}
	
	virtual void eat(){
		cout << "The bird eats " << food << endl;
	}
};

class BlueJay : public Bird{
	public:
	BlueJay(){
		color = "blue";
		location = "Canada";
		food = "sunflower seeds";
	}
	
	void eat(){
		cout << "The bird pecks " << food << endl;
	}
	
};

class Tom:public BlueJay{
	public:
	void eat(){
		cout << "REEEEEE" << endl;
	}
};

int main(){
	
	
	Bird* pBird = new Bird();
	Bird* pBlueJay = new BlueJay();
	Bird* pTom = new Tom();
	
	
	pBird->eat();
	pBlueJay->eat();
	pTom->eat();
	
	return 0;
}