#include <iostream>
#include <vector>
using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int leftnum = 0;//�����׸���
	int rightnum = 0;//�����׸���
	int max = 0;
	for (int i = 0; i<n; i++){
		if (right[i] == 0){//��ĳ��ɫ�����׸���Ϊ0 ������������Ӧ���ڸ�����ɫ������
			leftnum += left[i];
		}
	}
	leftnum++;
	for (int i = 0; i<n; i++){
		if (left[i] != 0 && right[i] != 0){
			rightnum = 0;
			for (int j = 0; j<n; j++){//��i��ɫ���������ɫ���
				if (j == i){
					continue;
				}
				rightnum += right[j];
			}
			if (rightnum>max){
				max = rightnum;
			}
		}
	}
	max++;
	return leftnum + max;
}

int main(){
	int n = 6;
	vector<int> left = { 1, 2, 0, 1, 3, 1 };
	vector<int> right = { 0, 0, 0, 2, 0, 1 };
	//����9���������10
	//�Ҿ��ô������⡣����

	cout<<findMinimum(n, left, right);

	return 0;
}