
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

ListNode *deleteNode(ListNode *head, int i){
	if(!head) return head;
	if(head->val == i) return head->next;
	ListNode *res = head;
	while(res->next){
		if(res->next->val == i){
			res->next = res->next->next;
			break;
		}
		res = res->next;
	}
	return head;
}

void printList(ListNode *head){
	ListNode *traversal = head;
	while(traversal){
		cout << traversal->val;
		if(traversal->next) cout << "->";
		traversal = traversal->next;
	}
	cout << endl;
}

int main(){
	ListNode head(0);

	ListNode *tail = &head;
	for(int i = 0; i < 10; i++){
		tail->next = new ListNode(i+1);
		tail = tail->next;
	}
	printList(&head);

	/*
	 * delete a node 7
	 * */
	ListNode *newHead = deleteNode(&head, 7);
	printList(newHead);
}
