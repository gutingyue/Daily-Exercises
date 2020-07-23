#include <iostream>
#include <vector>
using namespace std;



	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}

	//要么奇数全是奇数，要么偶数位全是偶数
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int even = 0;//偶数位
		int odd = 1;//奇数位
		for (; even<len&&odd<len;){
			for (; even<len&&arr[even] % 2 == 0;)//找到一个偶数位上的奇数
				even += 2;
			for (; odd<len&&arr[odd] % 2 == 1;)//找到一个奇数位上的偶数
				odd += 2;
			swap(arr[even], arr[odd]);
			odd += 2;//从下一个奇数位开始找奇数位上的偶数
			even += 2;//从下一个偶数位开始找偶数位上的奇数

		}
	}

	int main(){
		vector<int> arr = { 7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6 };
		oddInOddEvenInEven(arr, 11);

		for (auto e : arr){
			cout << e << " " ;
		}
		return 0;
	}