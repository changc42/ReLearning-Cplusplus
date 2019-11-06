#include<iostream>
#include<vector>
using namespace std;



class Board{
	struct Position{
		int r;
		int c;
	};
	
	public:
	int size;
	vector<vector<int> > b; 		//board
	Position pos; 					//current position on board
	vector<int> placements; 	//locations of pieces that have been placed. index is column. value is row
	int count;						//keeps track of how many solutions found
	
	Board(int s){
		size=s;
		pos.r=0;
		pos.c=0;
		for(int i=0; i<s; i++){
			b.push_back(vector<int>());
			for(int j=0; j<s; j++){
				b.at(i).push_back(0);
			}
		}
		count=0;
	}
	
	bool hasQueens(){
		for(int i=0; pos.c-i>=0; i++){
			if(b[pos.r][pos.c-i]==1){
				return true;
			}
		
			if(pos.r-i >= 0){
				if(b[pos.r-i][pos.c-i]==1){
					return true;
				}
			}
		
			if(pos.r+i < size){
				if(b[pos.r+i][pos.c-i]==1){
					return true;
				}
			}
		}
		return false;
	}
	
	void placeQueen(){
		b[pos.r][pos.c]=1;
		placements.push_back(pos.r);
	}
	
	void backtrack(){
		pos.c--;
		b[placements[pos.c]][pos.c]=0;
		pos.r = placements[pos.c] +1;
		placements.pop_back();
		if(pos.r==size) backtrack();
	}
	
	bool canBacktrack(){
		if(pos.c==1 && placements[0]==size-1) return false;
		else return true;
	}
	
	void nextSol(){
		while(pos.c!=size){ //while the board is not filled
			if(pos.r==size && canBacktrack()){
				backtrack();
			} else if(pos.r==size && !canBacktrack()){
				break;
			}else if(!hasQueens()){
				placeQueen();
				pos.r=0;
				pos.c++;
			} else {
				pos.r++;
			}
		}
	}
	
	void print(){
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				cout << b[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
};


int main(){
	
	Board board(11);
	while(true){
		board.nextSol();
		if(!board.canBacktrack()) break;
		cout << ++board.count << endl;
		board.backtrack();
	}
}