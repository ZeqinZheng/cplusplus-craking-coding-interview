#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<class T> 
class MyStack{
	private:
	   	struct stackNode{
			stackNode *next;
			T val;
			stackNode(T x) : val(x) {}
		};
		stackNode *topNode;

	public:
		void pop(){
			if(!topNode) return;
			topNode = topNode->next;
		}
		T top(){
			if(!topNode) throw;

			return topNode->val;
		}
		void push(int val){
			stackNode *newTopNode = new stackNode(val);
			newTopNode->next = topNode;
			topNode = newTopNode;
		}

		bool isEmpty(){
			return topNode == nullptr;
		}
};
		


int main(){
	stack<int> s;
	MyStack<int> s1;
	s1.push(1);
	cout << s1.top() << endl;
}

