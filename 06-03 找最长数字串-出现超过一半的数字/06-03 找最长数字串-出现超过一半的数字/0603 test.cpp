#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	vector<int> count;
	count.resize(10, 0);

	for (int i = 0; i<numbers.size(); ++i){
		++count[numbers[i]];
	}

	for (int i = 0; i<count.size(); ++i){
		if (count[i] >= (numbers.size() / 2))
			return i;
	}

	return 0;
}


bool isnumber(char c){
	if (c >= 48 && c <= 57){
		return true;
	}
	return false;
}

void MaxNumstr(){
	string s = "12abc123a";
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
}


int main(){
	//MaxNumstr();

	vector<int> numbers{ 1, 2, 2, 2, 2, 3, 4, 2 };
	MoreThanHalfNum_Solution(numbers);

	return 0;
}

