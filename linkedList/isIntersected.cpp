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

ListNode *mergeList(ListNode *n1, ListNode *n2){
	ListNode *dummy = new ListNode();
	ListNode *res = dummy;
	while(n1){
		res->next = n1;
		n1 = n1->next;
		res = res->next;
	}
	res->next = n2;
	return dummy->next;
}

ListNode *getIntersectionNode(ListNode *h1, ListNode *h2){
	ListNode *n1 = h1, *n2 = h2;
	if(!n1 || !n2) return nullptr;
	while(n1 != n2){
		n1 = n1 ? n1->next : h2;
		n2 = n2 ? n2->next : h1;
	}
	return n1;
}

int main(){

	vector<int> v1 = {3,1,5,9};
	vector<int> v2 = {4,6};
	vector<int> commonV = {7,2,1};
	ListNode *head1 = createList(v1);
	ListNode *head2 = createList(v2);
	ListNode *commonHead = createList(commonV);
	head1 = mergeList(head1, commonHead);
	head2 = mergeList(head2, commonHead);
	ListNode *res = getIntersectionNode(head1, head2);
	printList(head1);
	printList(head2);
	cout << res->val << endl;
}
