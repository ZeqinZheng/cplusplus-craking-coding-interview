#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getCharVal(char c){
	if(c < 'a' || c > 'z') return -1;
	return c - 'a';
}

bool isPalindrome_bit(string s){
	int bits = 0;
	for(char c : s){
		int num = getCharVal(c);
		if(num == -1) return false;
		if((bits & (1<<num)) == 0){
			bits |= 1<<num;
		}
		else{
			bits &= ~(1<<num);
		}
	}
	return bits == 0 || (((bits-1) & bits) == 0);
}

bool isPalindrome(string s){
	vector<int> v(26, 0);
	int res = 0;
	for(char c : s){
		int num = getCharVal(c);
		if(num != -1){
			v[num]++;

			if(v[num] % 2 == 1){
				res++;
			}
			else{
				res--;
			}
		}
		else{
			return false;
		}
	}
	return res <= 1;
}

int main(){
	string s = "hgnekoneko";

	cout << isPalindrome_bit(s) << endl;
}
