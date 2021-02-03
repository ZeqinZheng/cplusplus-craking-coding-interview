#include<iostream>

using namespace std;

bool isUnique_(string s){
	int checker = 0;
	for(char c:s){
		int tmp = c - 'a';
		cout << bitset<32>(tmp) << ' ' << bitset<32>(1<<tmp) << endl;
		//cout << checker << ' ' << tmp << ' ' << (checker & tmp) << endl;
		if((checker & (1 <<tmp)) > 0){
			return false;
		}
		checker |= (1<<tmp);
	}

	return true;
}

bool isUnique(string s){
	int checker = 0;
	for(char c : s){
		int a = c - 'a';
		if((checker & (1 << a)) > 0){
			return false;
		}
		cout << checker << ' ' << (1<<a) << ' ' << (checker & (1<<a)) << endl;
		checker |= (1 << a);
		//cout << checker << ' ' << (1<<a) << endl;
	}
	return true;
}

int main(){
	string s = "IlveYou";
	cout << isUnique_(s) << endl;
}
