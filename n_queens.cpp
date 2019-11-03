#include<iostream>
#include<cstring>
using namespace std;

class Board{
	public:
	int rows;
	int cols;
	int **b;
	
	Board(int r, int c){
		rows=r;
		cols=c;
		b=new int*[r];
		for(int i=0; i<r; i++){
			b[i] = new int[c];
		}
	}
	
	void print(){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				cout << b[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
};


int main(){
	
	Board board(8,8);
	fill(board.b[0], board.b[0]+64, 3);
	board.print();
}