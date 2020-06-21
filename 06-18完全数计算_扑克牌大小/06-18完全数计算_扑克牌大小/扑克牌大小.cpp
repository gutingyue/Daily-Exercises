#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

//比较两幅牌大小
int Compare(vector<int>& v1,vector<int>& v2){
	if (v1.size() == 2 && v1[1] == 14){ //v1王炸
		return 1;
	}
	if (v2.size() == 2 && v2[1] == 14){ //v2王炸
		return 2;
	}

	//v1 v2牌数相等
	if (v1.size() == v2.size()){
		////v1 v2 是顺子
		if (v1.size() == 5){
			if (v1[0] > v2[0])
				return 1;
			else
				return 2;
		}
		////v1 v2 是单张/对儿/三张/炸弹
		if (v1[0] > v2[0])
			return 1;
		return 2;
	}

	//v1 v2 牌数不相等
	if (v1.size() == 4)
		return 1;
	if (v2.size() == 4)
		return 2;

	return 0;//无法比较

}

void Push(string& s, size_t& i, vector<int>& v){
	if (s[i] == 'J'&&s[i + 1] == 'O'){
		i++;
	}//避免JOKER与J，查找时重了

	switch (s[i])
	{
	case '3':v.push_back(0); break;
	case '4':v.push_back(1); break;
	case '5':v.push_back(2); break;
	case '6':v.push_back(3); break;
	case '7':v.push_back(4); break;
	case '8':v.push_back(5); break;
	case '9':v.push_back(6); break;
	case '10':v.push_back(7); break;
	case 'J':v.push_back(8); break;
	case 'Q':v.push_back(9); break;
	case 'K':v.push_back(10); break;
	case 'A':v.push_back(11); break;
	case '2':v.push_back(12); break;
	case 'j':v.push_back(13);
		i += 5;
		break;
	case 'O':v.push_back(14);
		i += 4;
		break;
	}
}

void vPrint(vector<int>& v){
	switch (v[0])
	{
	case 0:cout << '3'; break;
	case 1:cout << '4'; break;
	case 2:cout << '5'; break;
	case 3:cout << '6'; break;
	case 4:cout << '7'; break;
	case 5:cout << '8'; break;
	case 6:cout << '9'; break;
	case 7:cout << '10'; break;
	case 8:cout << 'J'; break;
	case 9:cout << 'Q'; break;
	case 10:cout << 'K'; break;
	case 11:cout << 'A'; break;
	case 12:cout << '2'; break;
	case 13:cout << "joker"; break;
	case 14:cout << "JOKER"; break;
	}

	for (int i=1;i<v.size();i++){
		cout << " ";
		switch (v[i])
		{
		case 0:cout << '3'; break;
		case 1:cout << '4'; break;
		case 2:cout << '5'; break;
		case 3:cout << '6'; break;
		case 4:cout << '7'; break;
		case 5:cout << '8'; break;
		case 6:cout << '9'; break;
		case 7:cout << '10'; break;
		case 8:cout << 'J'; break;
		case 9:cout << 'Q'; break;
		case 10:cout << 'K'; break;
		case 11:cout << 'A'; break;
		case 12:cout << '2'; break;
		case 13:cout << "joker"; break;
		case 14:cout << "JOKER"; break;
		}
	}
}

int main(){
	string s = {"2 2-3 3"};
	vector<int> v1;
	vector<int> v2;

	//getline(cin,s);
	size_t i = 0;
	while (s[i] != '-'){
		if (s[i] != ' ')
			Push(s, i, v1);//将数据插入v1
		++i;
	}
	i++;
	while (i<s.size()){ //将剩余数据插入v2
		if (s[i] != ' ')
			Push(s, i, v2);
		++i;
	}

	int temp = Compare(v1, v2);//1：v1大  2：v2大  0：无法比较
	if (temp == 0){
		cout << "ERROR" << endl;
	}
	else if (temp == 1){
		vPrint(v1);
	}
	else{
		vPrint(v2);
	}

	return 0;
}