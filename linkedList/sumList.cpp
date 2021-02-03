#include<string>
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

ListNode *sumList(ListNode *l1, ListNode *l2, int carry){
	if(!l1 && !l2 && !carry){
		return nullptr;
	}
	ListNode *res = new ListNode();
	int val = carry;
	if(l1) val += l1->val;
	if(l2) val += l2->val;

	res->val = val % 10;

	if(l1 || l2){
		ListNode *node = sumList(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, val >= 10 ? 1 : 0);
		res->next = node;
	}
	printList(res);
	return res;
}

int main(){
	ListNode *head = new ListNode(7);
	head->next = new ListNode(1);
	head->next->next = new ListNode(6);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(2);

	printList(head);
	printList(l2);

	ListNode *res = sumList(head, l2, 0);
	printList(res);
}
