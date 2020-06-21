#include <iostream>
#include <cstdio>

using namespace std;
bool isPerfectNumber(int num){ //验证是否为完全数
	int sum = 0;
	//for (int i = 1; i <= sqrt(num); i++){
	//	if (num%i == 0){
	//		if (i == num / i)
	//			sum += i;
	//		else
	//			sum += (i + num / i);
	//	}
	//}

	for (int i = 1; i < num; i++){
		if (num%i == 0){
			sum += i;
		}
	}
	if (sum == num){
		cout << num << endl;
		return true;
	}
	return false;
}

//int main(){
//	int count = 0;
//	int n = 2670;
//	//while (cin >> n){
//	//	for (int i = 1; i<n; i++){
//	//		if (isPerfectNumber(i)){
//	//			++count;
//	//		}
//	//	}
//	//	cout << count << endl;
//	//}
//	
//	for (int i = 1; i<=n; i++){
//		if (isPerfectNumber(i)){
//			++count;
//		}
//	}
//	cout << "n=" << n << endl;
//	cout << "count" << count << endl;
//
//	return 0;
//}