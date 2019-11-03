/*
how many ways are there to put 8 queens on a chess board such that none of the queens can eat
each other in one move?
print out all the solutions
*/

#include<iostream>
using namespace std;

//determines if a coordinate is in another queens attacking range
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
}

/*removes the last placed queen and checks if the spaces below the coordinate where the queen was removed
are valid for placement. if there is a space, place a queen. if not, call back track again.
if c==1 and there is a queen at (7,0), this function will do nothing.
*/
void backtrack(int b[][8], int solutions[8], int &r, int &c)
{
	if(c==1 && solutions[0]==7){
		cout << "Cannot backtrack anymore" << r << ", " << c << endl;
		return;
	}
	
	c--;
	b[solutions[c]][c]=0;
	
	if(solutions[c]+1<8)
	{
	r=solutions[c]+1;
	solutions[c]=r;
	} else
	backtrack(b,solutions,r,c);
}

bool can_backtrack(int solutions[8],int c){
	if(c==1 && solutions[0]==7) return false;
	else return true;
	//return (c!=1 || solutions[0]!=7);
}



void print(int b[][8]){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << b[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	int b[8][8]={0};
	int c=0;
	int r=0;
	int solutions[8];
	int count = 0;
	
	while(true)
	{
		while(c!=8)
		{
			
			
			if(r>=8)
			{
				if(!can_backtrack(solutions, c)) break;
				backtrack(b,solutions,r,c);
			}
		
			else if(!has_queens(b,r,c))
			{
				b[r][c]=1;
				solutions[c]=r;
				c++;
				r=0;
			}
			else {
				r++;
			}
		}
		if(!can_backtrack(solutions, c)) break;
		cout << ++count << endl;
		print(b);
		
		backtrack(b,solutions,r,c);
	}
	
	
	
	return 0;
}