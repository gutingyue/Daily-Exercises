// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void GetCount(vector<vector<char>> vc, int x, int y){
	if (x >= vc.size() || y >= vc[0].size() || vc[x][y] == '#' || vc[x][y] == '@')
		return;
	count++;
	vc[x][y] = '@';
	GetCount(vc, x--, y);//ио
	GetCount(vc, x++, y);//об
	GetCount(vc, x, y--);//вС
	GetCount(vc, x, y++);//ср

}

int main(){
	int m = 0, n = 0;
	while (cin >> m >> n){
		vector<vector<char>> vc;
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				cin >> vc[i][j];
			}
		}
		GetCount(vc, 0, 0);
		cout << count << endl;
	}


	return 0;
}