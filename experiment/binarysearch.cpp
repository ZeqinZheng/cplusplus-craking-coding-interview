#include<iostream>
#include<vector>

using namespace std;

void binarysearch(vector<int> v, int target){
	int l = 0, r = v.size()-1;
	int i = 0;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(i > 100) break;
		if(v[mid] < target){
			l = mid+1;
		}
		else if(v[mid] > target){
			r = mid-1;
		}
		else{
			cout << l << endl;
			break;
		}
	}
}

int main(){
	vector<int> v(1, 1);
	int target = 1;
	binarysearch(v, target);
}
