#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string stringCompression(string s){
	int consecutive = 0;
	string res = "";
	for(int i = 0; i < s.length(); i++){
		consecutive++;
		if(i+1 >= s.length() || s[i] != s[i+1]){
			res += s[i];
			res += to_string(consecutive);
			consecutive = 0;
		}
	}
	return res;
}

int main(){
	string s1 = "aabbbczzc";

	cout << stringCompression(s1) << endl;
}
