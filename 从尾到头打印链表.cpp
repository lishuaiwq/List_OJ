����һ��������β��ͷ��ӡ����

�㷨������ʹ�õݹ��ջ��ʵ������㷨���ܼ�����Ͳ���������

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