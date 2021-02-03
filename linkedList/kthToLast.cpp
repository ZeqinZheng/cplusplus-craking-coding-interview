#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

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

bool deleteMiddle(ListNode *mid){
	if(!mid || !mid->next) return false;
	ListNode *next = mid;
	mid->val = next->val;
	mid->next = next->next;
	cout << "middle node deleted" << endl;
	return true;
}

/* Recursive */
ListNode *printKthToLast(ListNode *head, int kth, int &index){
	if(!head || kth <= 0) return 0;
	ListNode *res = printKthToLast(head->next, kth, index);
	index++;
	if(index == kth) return head;
	return res;
}

ListNode *goToKthNode(ListNode *head, int kth){
	for(int i = 0; i < kth; i++){
		if(head->next) head = head->next;
		else return NULL;
	}
	return head;
}

/* iterative */
ListNode *printKthToLastI(ListNode *head, int kth){
	ListNode *fast = head;
	ListNode *slow = head;
	for(int i = 1; i < kth; i++){
		if(fast->next) fast = fast->next;
		else return NULL;
	}
	while(fast->next){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}	

int main(){
	ListNode head(2);

	ListNode *tail = &head;
	for(int i = 10; i > 0; i--){
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	printList(&head);
	
	int index = 0;
	//ListNode *res = printKthToLast(&head, 3, index);
	//ListNode *res = printKthToLastI(&head, 3);
	//cout << "The return node val equals " << res->val << endl;
	
	ListNode *mid = goToKthNode(&head, 10/2);
	deleteMiddle(mid);
	printList(&head);
}
