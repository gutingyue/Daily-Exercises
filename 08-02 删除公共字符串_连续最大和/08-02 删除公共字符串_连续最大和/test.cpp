#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	while (cin >> n){
		vector<int> v(n, 0);
		for (int i = 0; i<n; i++){
			int num;
			cin >> num;
			v[i] = num;
		}
		int max = v[0];
		int count = 0;
		for (int i = 0; i<v.size(); i++){
			count += v[i];
			if (count>max){
				max = count;
			}
			if (count < 0)
				count = 0;
		}
		cout << max << endl;
	}

}