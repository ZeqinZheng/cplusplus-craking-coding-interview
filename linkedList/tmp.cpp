void deleteDup(ListNode *head){
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
}
