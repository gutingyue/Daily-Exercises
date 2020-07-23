#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Date{
public:
	Date(int year, int month, int day)
		:_year(year), _month(month), _day(day){}

	int GetDay(){//获取当月天数
		if (_month == 2){ //2月
			if (_year % 4 == 0 && _year % 100 != 0){ //是闰年
				return 29;
			}
			else{
				return 28;
			}
		}
		//1、3、5、7、8、10、12月
		if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12){
			return 31;
			//4、6、9、11月
		}
		else{
			return 30;
		}
	}

	void operator++(){
		_day++;
		if (_day>GetDay()){
			_month++;
			_day = 1;
			if (_month>12){
				_year++;
				_month = 1;
			}
		}
	}

	bool operator!=(Date& d){
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return false;
		return true;
	}

	bool operator==(Date& d){
		if (*this!=d)
			return false;
		return true;
	}

public:
	int _year;
	int _month;
	int _day;
};

bool isPrime(const int num){
	if (num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++){
		if (num%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	string _s;
	vector<int> v = { 0, 0, 0, 0, 0, 0 };

	//2000 1 1 2000 1 31
	while (getline(cin,_s)){
		char s[30];
		strcpy_s(s, _s.c_str());
		auto cur = 0;
		auto prev = cur;
		for (int i = 0; cur<_s.size();++i){
			while (s[prev] != ' ' && prev<_s.size()){
				++prev;
			}
			s[prev] = '\0';
			v[i] = atoi(&s[cur]);
			cur = ++prev;
		}

		Date d1(v[0], v[1], v[2]);
		Date d2(v[3], v[4], v[5]);
		
		int count = 0;
		while(d1!=d2){
			if (isPrime(d1._month)){
				count += 1;
				++d1;
			}
			else{
				count += 2;
				++d1;
			}
		}
		if (isPrime(d2._month))
			count += 1;
		else
			count += 2;

		cout << count << endl;
	}

	return 0;
}
