#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace  std;

int main(){
	vector<int> v = {9,34,30,5};
    vector<string> s;
	for(int i = 0; i < v.size(); i++)
		s.push_back(to_string(v[i]));
	sort(s.begin(), s.end(), [](string l, string r){
		return l+r > r+l; // sort in descending order (default is ascending)
	});
	for(int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << endl;
}
