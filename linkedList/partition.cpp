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

ListNode *partition(ListNode *head, int val){
	// ls -- left-start      le -- left-end
	ListNode *ls = nullptr, *le = nullptr;
	ListNode *rs = nullptr, *re = nullptr;

	ListNode *cur = head;
	while(cur){
		if(cur->val < val){
			if(!ls){
				ls = cur;
				le = ls;
			}
			else{
				le->next = cur;
				le = le->next;
			}
		}
		else{
			if(!rs){
				rs = cur;
				re = rs;
			}
			else{
				re->next = cur;
				re = re->next;
			}
		}
		cur = cur->next;
	}

	if(!ls) return rs;

	le->next = rs;
	re->next = nullptr;

	return ls;
}

ListNode *reverseList(ListNode *head){
	if(!head || !head->next) return head;
	ListNode *res = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;

	return res;
}

int main(){
	ListNode head(0);

	ListNode *tail = &head;
	for(int i = 0; i < 10; i++){
		tail->next = new ListNode(i+1);
		tail = tail->next;
	}
	printList(&head);

	ListNode *res = reverseList(&head);	
	printList(res);
	res = partition(res, 5);
	printList(res);
}
