
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

ListNode *deleteDupHash(ListNode *head){
	if(!head || !head->next) return head;
	unordered_map<int, int> m;
	ListNode dummy(0);
	dummy.next = head;

	ListNode *cur = &dummy;

	while(cur->next){
		if(m[cur->next->val] > 0){
			cur->next = cur->next->next;
		}
		m[cur->val]++;
		cur = cur->next;
	}
	return head;
}

ListNode *deleteDupNonHash(ListNode *head){
	if(!head || !head->next) return head;
	ListNode *cur = head;
	while(cur){
		ListNode *tmp = cur;
		while(tmp->next){
			if(tmp->next->val == cur->val){
				tmp->next = tmp->next->next;
			}
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return head;
}

int main(){
	ListNode head(2);

	ListNode *tail = &head;
	for(int i = 10; i > 0; i--){
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	printList(&head);

	//deleteDupHash(&head);
	deleteDupNonHash(&head);
	printList(&head);

}
