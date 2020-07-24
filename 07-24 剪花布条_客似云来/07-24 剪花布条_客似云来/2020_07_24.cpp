
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s1;
	string s2;
	while (cin>>s1>>s2){
		int count = 0;
		for (size_t pos = 0; pos<s1.size() && pos != -1;){
			pos = s1.find(s2, pos); //·µ»Ø-1Î´ÕÒµ½
			if (pos != -1){
				count++;
				pos += s2.size();
			}
		}
		cout << count << endl;
	}

	return 0;
}