#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void Team(){
	int n = 0;
	cin >> n;

	vector<int> team;
	int i = 0;
	while (i<3 * n){
		int a_i;
		cin >> a_i;
		team.push_back(a_i);
		i++;
	}
	sort(team.begin(), team.end());
	long long max = 0; //int max 只能通过60%的用例
	for (auto it = team.begin() + n; it < team.end();){
		max += *it;
		it += 2;
	}
	cout << max << endl;
}

void twoSting(){
	string s1;
	getline(cin, s1); //获取一行字符串

	string s2;
	getline(cin, s2);

	auto ps1 = s1.begin();
	auto ps2 = s2.begin();

	while (ps1 != s1.end()){
		ps2 = s2.begin();
		while (ps2 != s2.end()){
			if (*ps1 == *ps2 && isalnum(*ps1)){
				ps1 = s1.erase(ps1);
				if (ps1 != s1.begin()){
					ps1--;
				}
				break;
			}
			ps2++;
		}
		ps1++;
	}

	cout << s1 << endl;

}

int main(){
	//Team();
	twoSting();

	return 0;
}