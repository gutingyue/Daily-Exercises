#include <iostream>
#include <vector>
using namespace std;

//��ǰ�������ܼ�ֵ = max(���������ܼ�ֵ����ߵ������ܼ�ֵ) + ��ǰ���ֵ

int getMost(vector<vector<int> > board) {
	// write code here
	int most = board[0][0];
	int i = 0;
	int j = 0;
	for (; i < board.size()-1 || j < board.size()-1;){
		if (i == board.size() - 1){ //�ߵ����ұ߽�
			most += board[i][++j];
			
		}
		else if (j == board.size() - 1){ //�ߵ�����߽�
			most += board[++i][j];
		}
		else{
				//���ұ߸��Ӻ��±߸����ĸ������
			if (board[i + 1][j]>board[i][j + 1]){
				most += board[i + 1][j];
				i++;
			}else{
				most += board[i][j + 1];
				j++;
			}
		}
	}
	return most;
}
int main(){
	vector < vector<int> > board{ 
		{ 138, 457, 411, 440, 433, 149 },
		{ 203, 288, 318, 597, 246, 686 },
		{ 442, 105, 424, 544, 406, 532 },
		{ 172, 592, 626, 410, 511, 636 },
		{ 394, 596, 644, 454, 343, 389 },
		{ 573, 460, 307, 221, 325, 104 }
	};

	int most=getMost(board);
	cout << "most: " << most << endl;

	return 0;
}