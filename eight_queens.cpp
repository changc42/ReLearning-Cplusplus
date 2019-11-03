#include<iostream>
using namespace std;

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

void backtrack(int b[][8], int solutions[8], int &r, int &c)
{
	if(c==1 && solutions[0]==7){
		cout << "Cannot backtrack anymore" << endl;
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
				if(c==1 && solutions[0]==7) break;
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
		if(c==1 && solutions[0]==7) break;
		cout << ++count << endl;
		print(b);
		
		backtrack(b,solutions,r,c);
	}
	
	
	
	return 0;
}