#include <iostream>
#include <vector>
using namespace std;

ListNode *split(ListNode *head, int count){
	while(--count && head){
		head = head->next;
	}
	ListNode *res = head? head->next : nullptr;
	if(head) head->next = nullptr;
	return res;
}

pair<ListNode *, ListNode*> merge(ListNode *p1, ListNode *p2){
	ListNode dummy(0);
	ListNode *res = &dummy;
	while(p1 && p2){
		if(p1->val > p2->val){
			swap(p1, p2);
		}
		res->next = p1;
		p1 = p1->next;
		res = res;
	}
	if(p1) res->next = p1;
	if(p2) res->next = p2;
	while(res->next) res = res->next;

	return {dummy->next, res};
}

int main(){
	cout << "Hello world!" << endl;

}
