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

pair<ListNode *, ListNode*> createList(vector<int> v){
	ListNode *dummy = new ListNode(0);
	ListNode *cur = dummy;
	ListNode *circleNode = nullptr;
	for(int i = 0; i < v.size(); i++){
		ListNode *tmp = new ListNode(v[i]);
		if(v[i] == 2) circleNode = tmp;
		cur->next = tmp;
		cur = cur->next;
	}
	return {dummy->next, circleNode};
}

ListNode *appendList(ListNode *firstNode, ListNode *lastNode){
	ListNode *head= firstNode;
	if(!head) return head;
	while(head->next){
		head = head->next;
	}
	head->next = lastNode;
	return firstNode;
}

ListNode *getCircledNode(ListNode *circleHead){
	ListNode *slow = circleHead, *fast = circleHead;
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) break;
	}
	if(!fast || !fast->next) return nullptr;

	slow = circleHead;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main(){
	vector<int> v1 = {1, 2, 3, 4, 5};
	auto circleList = createList(v1);
	ListNode *circleHead = circleList.first;
	circleHead = appendList(circleHead, circleList.second);
	ListNode *res = getCircledNode(circleHead);
	if(res) cout << res->val << endl;
}
