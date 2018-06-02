输入一个链表，从尾到头打印链表

算法：可以使用递归和栈来实现这个算法，很简单这里就不多描述了

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>  v;
		stack<int>  s;
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};