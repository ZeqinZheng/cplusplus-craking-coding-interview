#include<iostream>

using namespace std;

template<class T>
class MyStack{
	private:
		struct StackNode{
			T val;
			StackNode *next;
			StackNode(T x) : val(x) {}
		};
		StackNode *topNode = nullptr;
	public:
		void push(T val){
			StackNode *newTopNode = new StackNode(val);
			newTopNode->next = topNode;
			topNode = newTopNode;
		}
		T top(){
			if(!topNode) throw;
			return topNode->val;
		}
		void pop(){
			if(!topNode) return;
			topNode = topNode->next;
		}
		bool isEmpty(){
			return topNode == nullptr;
		}
};

int main(){
	MyStack<int> s;
	if(s.isEmpty()) cout << "Empty" << endl;
	else cout << "Not Empty" << endl;
	s.push(1);
	cout << s.top() << endl;
	if(s.isEmpty()) cout << "Empty" << endl;
	else cout << "Not Empty" << endl;
	s.pop();
}
