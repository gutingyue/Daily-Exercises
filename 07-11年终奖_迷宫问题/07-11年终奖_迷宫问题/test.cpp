#include <iostream>
#include <vector>
using namespace std;


int getMost(vector<vector<int> > board) {
	// write code here
	int most = board[0][0];
	int i = 0;
	int j = 0;
	for (; i<board.size() && j<board.size();){
		if (i == board.size() - 1){ //走到了右边界
			most += board[i][++j];
		}
		else if(j == board.size() - 1){ //走到了左边界
			most += board[++i][j];
		}
		else{
				//看右边格子和下边格子哪个奖金多
			if (board[i + 1][j]>board[i][j + 1]){
				most += board[i + 1][j];
				i++;
			}
			else{
				most += board[i][j + 1];
				j++;
			}
		}
	}
	return most;
}

	int main(){
		vector < vector<int> > board;
		int most=getMost(board);
		return 0;
	}