#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPermutation(string s1, string s2){
	vector<int> v1(26, 0), v2(26, 0);
	for(char c : s1){
		v1[c - 'a']++;
	}
	for(char c : s2){
		v2[c - 'a']++;
	}
	return v1==v2;
}

int main(){
	string s1 = "aabcd";
	string s2 = "dcba";

	cout << isPermutation(s1, s2) << endl;
}
