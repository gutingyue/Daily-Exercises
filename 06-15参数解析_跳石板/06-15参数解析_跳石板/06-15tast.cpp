#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

//²ÎÊý½âÎö
void TestParameter(){
	string s = "xcopy /s c:\\ d:\\";
	auto cur = s.begin();
	auto pre = cur + 1;
	int count = 0;
	vector<string> ss;
	while (pre != s.end()){
		if (*pre == '"'){
			++pre;
			while (*pre != '"')
				++pre;
			++cur;
			string c(cur, pre);
			ss.push_back(c);

			//while (cur != pre){
			//	cout << *cur;
			//	++cur;
			//}
			++count;
			cur=pre+1;
		}
		else if (pre != s.end() && *pre == ' '&& *cur != ' ')
		{
			string c(cur, pre);
			ss.push_back(c);

			//while (cur != pre){
			//	cout << *cur;
			//	++cur;
			//}
			++count;
			cur = pre+1;
		}
		++pre;
	}
	string c(cur, pre);
	ss.push_back(c);
	count++;

	cout << count << endl;
	for (auto e : ss)
		cout << e << endl;
}


int main(){
	TestParameter();
	

	return 0;
}