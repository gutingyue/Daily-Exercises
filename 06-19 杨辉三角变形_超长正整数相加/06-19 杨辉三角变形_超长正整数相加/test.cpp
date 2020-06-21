#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//杨辉三角的变形
int main(){
	int n = 0;
	while (cin >> n){
		if (n <= 2){
			cout << -1 << endl;
			continue;
		}
		vector<int> v1 = { 1, 1, 1 };
		while (n>2){
			vector<int> v2;
			v2.push_back(1);
			for (int i = 1; i<v1.size(); i++){ //填充第n层
				int num = 0;
				for (int n = 0; i - n >= 0 && n<3; ++n){ //计算头上三个数字之和
					num += v1[i - n];
				}
				v2.push_back(num);
			}
			v2.push_back(v1[v1.size() - 2] + 1);
			v2.push_back(1);
			v1 = v2;
			n--;
		}
		for (int i = 0; i<v1.size(); i++){
			if (v1[i] % 2 == 0){
				cout << i << endl;
				return 0;
			}
			
		}
		cout << -1 << endl;
	}

	return 0;
}