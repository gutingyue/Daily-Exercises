#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void DlimitedSequence(){
	//int n = 0;
	//cin >> n;
	vector<int> A{ 1,1,1 };
	//	int A_i = 0;
	//	cin >> A_i;
	//	A.push_back(A_i);
	//	n--;
	//}
	size_t frist = 0;
	size_t last = 0; //ÿ�����������ĩβ
	int count = 0; //�����и���
	while (last < A.size()-1){
		if (last < A.size()-1 && A[last]>A[last + 1]){
			while (last < A.size() - 1 && A[last] >= A[last + 1])//��������
				++last;
			count++;
		}
		else if (last < A.size() - 1 && A[last] == A[last + 1]){ 
			while (last < A.size() - 1 && A[last] == A[last + 1])
				++last; //������ȵ����
			continue;
		}
		else{
			while (last < A.size() - 1 && A[last] <= A[last + 1])//��������
				++last;
			count++;
		}
		++last;
		frist = last;
	}
	if (last < A.size() && A[frist] == A[last]){ //i==0˵������������Ԫ�ؾ���Ȼ�last==size-1(���һ��Ԫ��δ����Ϊ�����У�
		count++;
	}
	cout << count;
}

void ReversalStr(string& s, size_t frist, size_t last){
	last--;
	while (frist<last){
		char temp = s[frist];
		s[frist] = s[last];
		s[last] = temp;

		frist++;
		last--;
	}
}

void SwapString(){

	string s="I like.";
	//getline(cin, s);

	size_t frist = 0;
	size_t last = s.size();
	ReversalStr(s, frist, last);

	last = 0;
	while (frist < s.size()){
		while (last < s.size() && s[last] != ' '){
			++last;
		}
		ReversalStr(s, frist, last);
		frist = (++last);
	}
	cout << s;
}



int main(){
	//DlimitedSequence();

	SwapString();

	return 0;
}