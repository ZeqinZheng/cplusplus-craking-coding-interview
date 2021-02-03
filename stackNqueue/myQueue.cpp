#include<iostream>

using namespace std;

template<class T>
class MyQueue{
	private:
	   	struct QueueNode{
			T data;
			QueueNode *next;
			QueueNode(T x) : data(x) {}
		};
		QueueNode *first = nullptr;
		QueueNode *last = nullptr;
	
	public:
		void add(T x){
			QueueNode *node = new QueueNode(x);
			if(last){
				last->next = node;	
			}
			last = node;
			if(!first){
				first = last;
			}
		}

		T remove(){
			if(!first) throw;
			T data = first->data;
			first = first->next;
			if(!first){
				last = nullptr;
			}
			return data;
		}

		T peek(){
			if(!first) throw;
			return first->data;
		}

		bool isEmpty(){
			return first == nullptr;
		}
	
};

int main(){
	MyQueue<int> q;
	q.add(1);
	q.add(2);
	cout << q.peek() << endl;
	q.remove();
	cout << q.peek() << endl;
}
