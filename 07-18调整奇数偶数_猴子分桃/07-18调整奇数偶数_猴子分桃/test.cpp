#include <iostream>
#include <vector>
using namespace std;



	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}

	//Ҫô����ȫ��������Ҫôż��λȫ��ż��
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int even = 0;//ż��λ
		int odd = 1;//����λ
		for (; even<len&&odd<len;){
			for (; even<len&&arr[even] % 2 == 0;)//�ҵ�һ��ż��λ�ϵ�����
				even += 2;
			for (; odd<len&&arr[odd] % 2 == 1;)//�ҵ�һ������λ�ϵ�ż��
				odd += 2;
			swap(arr[even], arr[odd]);
			odd += 2;//����һ������λ��ʼ������λ�ϵ�ż��
			even += 2;//����һ��ż��λ��ʼ��ż��λ�ϵ�����

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