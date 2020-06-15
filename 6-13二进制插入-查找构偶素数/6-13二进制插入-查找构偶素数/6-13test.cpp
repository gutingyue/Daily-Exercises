#include<iostream>
using namespace std;
#include<bitset>
#include <cmath>

bool isPrime(int x){ //判断x是否为素数
	for (int i = 2; i <= sqrt(x); i++){
		if (x%i == 0){
			return false;
		}
	}
	return true;
}

void TestPrime(){ //查找组成一个偶数最接近的两个素数
	int x = 0;
	while (cin >> x){
		int i = x / 2;
		int j = x / 2;
		while (i>0 && j<x){ //i比x小，j比x大
			if (isPrime(i) && isPrime(j)){
				if (i + j == x){
					cout << i << endl;
					cout << j << endl;
					break;
				}
				else{ //x=20---->避免i=7,j=11造成的死循环
					if ((x / 2 - i)>(j - x / 2)){
						++j;
					}
					else{
						--i;
					}
				}
			}else if(isPrime(i) && !isPrime(j))
			{
				j++;
			}else if(!isPrime(i) && isPrime(j))
			{
				i--;
			}
			else{
				j++;
				i--;
			}
		}
	}
}

int binInsert(int n, int m, int j, int i) {
	int temp = 0;
	int x = j;//将后i位保存在tenp中
	for (; x>0; x--){
		temp *= 2;
		if (n % 2 == 1){
			++temp;
		}
		n /= 2;
	}
	n |= m;
	for (; j>0; j--){
		n *= 2;
		if (temp % 2 == 1){
			++n;
		}
		temp /= 2;
	}
	return n;
}

void TestBit(){
	//4355,4,2,7
	int n = 4355;
	int m = 4;
	int j = 2;
	int i = 7;

	int x = binInsert(n, m, j, i);
	cout << (bitset<11>)x << endl;
	cout << x << endl;
}

int main(){
	//TestBit();
	TestPrime();
	return 0;
}