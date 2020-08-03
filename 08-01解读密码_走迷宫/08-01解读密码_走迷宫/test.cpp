#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Ω‚∂¡√‹¬Î
void password(){
	string s;
	while (getline(cin, s)){
		for (size_t i = 0; i<s.size();){
			if (!isdigit(s[i])){
				s.erase(i, 1);
				continue;
			}
			i++;
		}
		cout << s << endl;
	}
}


int max = 0;
void walk(vector<vector<char>>& vv, int x, int y, int count){
	if (x<0 || x>10 || vv[x][y] == '#'){
		count = 0;
		return;
	}
	if (x == 9 && y == 9){
		if (count<max)
			max = count;
	}
	walk(vv,x + 1, y, count++);
	walk(vv,x - 1, y, count++);
	walk(vv,x, y + 1, count++);
	walk(vv,x, y - 1, count++);
}


//◊ﬂ√‘π¨
void Map(){
	vector<vector<char>> vv(10,vector<char>(10));
	for (int i = 0; i<10; i++){
		for (int j = 0; j<10; j++){
			char c;
			cin >> c;
			vv[i][j] = c;
		}
	}
	walk(vv, 0, 1, 0);
	cout << max << endl;
}

int main(){
	//password();
	Map();

	return 0;
}