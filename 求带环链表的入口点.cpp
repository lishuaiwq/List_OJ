��Ŀ�������л�����ڽ��

��Ŀ����
һ�������а����������ҳ�������Ļ�����ڽ�㡣


�㷨���ҳ�����������㣬Ȼ��һ��ָ�����㿪ʼ��һ��ָ��������㿪ʼ�ߣ�������ָ��������ʱ�������ڵ�

����

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
			return NULL;
		ListNode* fast = pHead->next->next;
		ListNode* slow = pHead->next;
		ListNode* ret = pHead;
		while (fast != slow)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		while (ret != slow)
		{
			ret = ret->next;
			slow = slow->next;
		}
		return slow;
	}
};