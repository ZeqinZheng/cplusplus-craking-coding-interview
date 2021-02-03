#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool oneInsert(string longer, string shorter){
	int indexLong = 0, indexShort = 0;
	while(indexLong < longer.length() && indexShort < shorter.length()){
		if(longer[indexLong] != shorter[indexShort]){
			if(indexLong != indexShort) return false;
			indexLong++;
		}
		else{
			indexShort++;
			indexLong++;
		}
	}
	return true;
}

bool oneReplace(string s1, string s2){
	bool isDiff = false;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] != s2[i]){
			if(isDiff) return false;	
			isDiff = true;
		}
	}
	return true;
}

bool oneEdit(string s1, string s2){
	int len1 = s1.length(), len2 = s2.length();
	if(len1 == len2){
		return oneReplace(s1, s2);
	}
	else if(len1 - 1 == len2){
		return oneInsert(s1, s2);
	}
	else if(len1 + 1 == len2){
		return oneInsert(s2, s1);
	}
	return false;
}


int main(){
	string s1 = "bcc";
	string s2 = "ab";

	cout << oneEdit(s1, s2) << endl;
}
