#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool isnumber(char c){
	if (c >= 48 && c <= 57){
		return true;
	}
	return false;
}

int main(){
	string s="12abc123a";
	//getline(cin, s);

	size_t frist = 0;
	size_t last = 0;
	int max = 0;
	int num = 0;

	while (last<s.size()){
		if (last < s.size() && isnumber(s[last])){
			num = 0;
			while (last<s.size() && isnumber(s[last])){
				last++;
				num++;
			}
		}
		if (num>max){
			frist = last - num;
			max = num;
		}
		last++;
	}
	int i = 0;
	while (i<max){
		cout << s[frist + i];
		i++;
	}
	return 0;
}

