#include <iostream>
#include <vector>
using namespace std;

//计算矩阵的n次方
vector<vector<int>>& MatrixMul(int n, vector<vector<int>>& vv){
	vector<vector<int>> v1 = vv;//保存原矩阵
	vector<vector<int>> v2 = vv;
	//乘积C的第m行第n列的元素等于矩阵A的第m行的元素与矩阵B的第n列对应元素乘积之和
	//vv为C矩阵，v1为A矩阵，v2为B矩阵
	int row = 0;//行数
	int col = 0;//列数
	while(n){
		for (; row<vv.size(); row++){
			for (; col<vv.size(); col++){
				for (int i = 0; i<vv.size(); i++){
					vv[row][col] += v2[i][row] * v1[i][col];
				}
			}
		}
		v2 = vv;
		--n;
	}
	return vv;
}
void TestOfMatrixMul(){
	vector<vector<int>> _vv = { { 1, 1, 0 }, { 1, 1, 1 }, { 1, 2, 1 } };
	MatrixMul(2, _vv);
	for (int i = 0; i < _vv.size(); i++){
		for (int j = 0; j < _vv[0].size(); j++){
			cout << _vv[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	//int _n = 0;
	//vector<int> _vv;

	TestOfMatrixMul();//检测计算矩阵的n次方


	return 0;
}