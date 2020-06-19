#include <iostream>
#include <vector>
using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int leftnum = 0;//左手套个数
	int rightnum = 0;//右手套个数
	int max = 0;
	for (int i = 0; i<n; i++){
		if (right[i] == 0){//若某颜色右手套个数为0 拿左手套数量应大于该左颜色手套数
			leftnum += left[i];
		}
	}
	leftnum++;
	for (int i = 0; i<n; i++){
		if (left[i] != 0 && right[i] != 0){
			rightnum = 0;
			for (int j = 0; j<n; j++){//除i颜色外的所有颜色相加
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
	//答案是9，我输出是10
	//我觉得答案有问题。。。

	cout<<findMinimum(n, left, right);

	return 0;
}