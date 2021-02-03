#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isRotation(string s1, string s2){
	if(s1.length() != s2.length() || s1.length() == 0){
		return false;
	}
	s1 += s1;
	if(s1.find(s2)) return true;
	return false;
}

int main(){
	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	cout << isRotation(s1, s2) << endl;
}
