#include <iostream>
#include <vector>
using namespace std;

//��������n�η�
vector<vector<int>>& MatrixMul(int n, vector<vector<int>>& vv){
	vector<vector<int>> v1 = vv;//����ԭ����
	vector<vector<int>> v2 = vv;
	//�˻�C�ĵ�m�е�n�е�Ԫ�ص��ھ���A�ĵ�m�е�Ԫ�������B�ĵ�n�ж�ӦԪ�س˻�֮��
	//vvΪC����v1ΪA����v2ΪB����
	int row = 0;//����
	int col = 0;//����
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

	TestOfMatrixMul();//����������n�η�


	return 0;
}