
��������ĵ�һ�������Ľ���

�㷨˼�룺

�������룺

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		while (cur1 != cur2)
		{
			//������cur����cur->next��Ϊ������ཻ�Ļ�����������ȡ����
			cur1 = (cur1 != NULL ? cur1->next : pHead2);
			cur2 = (cur2 != NULL ? cur2->next : pHead1);
		}
		return cur1;
	}
};