#include<iostream>
#include<stack>

void sort(stack<int> s){
	stack<int> r;
	while(!s.empty()){
		int tmp = s.top(); s.pop();
		while(!r.empty() && r.top() > tmp){
			int top = r.top(); r.pop();
			s.push(top);
		}
		r.push(tmp);
	}
	while(!r.empty()){
		int tmp = r.top(); r.pop();
		s.push(tmp);
	}
}

int main(){
	stack<int> s;
}
