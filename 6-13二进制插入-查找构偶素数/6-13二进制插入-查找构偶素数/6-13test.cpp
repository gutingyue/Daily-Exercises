#include<iostream>
using namespace std;
#include<bitset>

int binInsert(int n, int m, int j, int i) {
	int temp = 0;
	int x = j;//将后i位保存在tenp中
	for (; x>0; x--){
		if (n % 2 == 1){
			++temp;
		}
		n /= 2;
		temp *= 2;
	}
	n |= m;
	for (; j>0; j--){
		n *= 2;
		if (temp % 2 == 1){
			++n;
		}
		temp /= 1;
	}
	return n;
}

int main(){
	//4355,4,2,7
	int n = 4355;
	int m = 4;
	int j = 2;
	int i = 7;

	int x = binInsert(n, m, j, i);
	cout <<(bitset<11>)x << endl;
	cout << x << endl;
	return 0;
}