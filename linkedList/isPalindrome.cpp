#include<string>
#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
	ListNode *traversal = head;
	while(traversal){
		cout << traversal->val;
		if(traversal->next) cout << "->";
		traversal = traversal->next;
	}
	cout << endl;
}

ListNode *reverseListAndClone(ListNode *head){
	ListNode *res = nullptr;
	while(head){
		ListNode *tmp = new ListNode(head->val);
		tmp->next = res;
		res = tmp;
		head = head->next;
	}
	return res;
}

ListNode *reverseList(ListNode *head){
	if(!head || !head->next) return head;
	ListNode *res = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	return res;
}

bool isPalindromeReversed(ListNode *head){
	ListNode *head2 = reverseListAndClone(head);
	while(head && head2){
		if(head->val != head2->val) return false;
		head = head->next;
		head2 = head2->next;
	}	
	return !head && !head2;
}

bool isPalindromeStack(ListNode *head){
	stack<int> s;
	ListNode *slow = head, *fast = head;
	while(fast && fast->next){
		s.push(slow->val);
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast){
		slow = slow->next;
	}
	while(slow){
		if(s.top() != slow->val) return false;
		s.pop();
		slow = slow->next;
	}
	return true;
}

ListNode *createList(vector<int> v){
	ListNode *dummy = new ListNode(0);
	ListNode *cur = dummy;
	for(int i = 0; i < v.size(); i++){
		ListNode *tmp = new ListNode(v[i]);
		cur->next = tmp;
		cur = cur->next;
	}
	return dummy->next;
}

int main(){

	vector<int> v = {0,1,2,2,1,0};
	ListNode *head = createList(v);
	printList(head);
	cout << isPalindromeStack(head) << endl;
}
