#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



class Board{
	struct Position{
		int row;
		int col;
	};
	
	public:
	int rows;
	int cols;
	vector<vector<int> > b; 		//board
	Position pos; 					//current position on board
	vector<Position> placements; 	//locations of pieces that have been placed
	int count;						//keeps track of how many solutions found
	
	Board(int r, int c){
		rows=r;
		cols=c;
		pos.row=0;
		pos.col=0;
		for(int i=0; i<r; i++){
			b.push_back(vector<int>());
			for(int j=0; j<c; j++){
				b.at(i).push_back(0);
			}
		}
		count=0;
	}
	
	bool hasQueens{
		for(int i=0; cols-i>=0; i++){
			if(b[pos.r][pos.c-i]==1){
				return true;
			}
		
			if(pos.r-i >= 0){
				if(b[pos.r-i][pos.c-i]==1){
					return true;
				}
			}
		
			if(pos.r+i < 8){
				if(b[pos.r+i][pos.c-i]==1){
					return true;
				}
			}
		}
	}
	
	void placeQueen(){
		b[pos.r][pos.c]=1;
		placements.push_back(pos);
	}
	
	void backtrack(){
		pos.c--;
		pos.r = placements[c].r +1;
		placements.erase(c);
		if(pos.r==rows) backtrack();
	}
	
	bool canBacktrack(){
		if(pos.c==2 && placements[0].row==rows-1) return false;
		else return true;
	}
	
	void nextSol(){
		while(c!=cols){ //while the board is not filled
			if(pos.r==rows && canBacktrack){
				backtrack();
			} else if(!canBacktrack){
				break;
			}else if(!hasQueens){
				placeQueens();
				pos.r=0;
				pos.col++;
			} else {
				pos.r++;
			}
		}	
	}
	
	bool has_queens(int b[][8], int r, int c){
	for(int i=0; c-i>=0; i++){
		if(b[r][c-i]==1){
			return true;
		}
		
		if(r-i>=0){
			if(b[r-i][c-i]==1){
				return true;
			}
		}
		
		if(r+i<8){
			if(b[r+i][c-i]==1){
				return true;
			}
		}
		
		
	}
	return false;
	
	void print(){
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				cout << b[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
};


int main(){
	
	Board board(8,8);
	while(true){
		board.nextSol();
		if(!canBacktrack) break;
		cout << ++count << endl;
		board.print();
	}
}