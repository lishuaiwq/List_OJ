��Ŀ��ɾ���������ظ��Ľ��

��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

�㷨��������˵һ�����Լ����㷨

ʹ������set���������ظ���Ԫ�أ�һ����������������˺��Ԫ�أ�һ�����������ο���ЩԪ�����ظ��ģ�Ȼ��ʹ�÷��������ͷ�����½�������Ϳ�����

�������룺

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* cur = pHead;
		ListNode* newNode = NULL;
		set<int> s;
		set<int>::reverse_iterator it = s.rbegin();
		set<int>::iterator It;
		set<int> ss;
		while (cur)
		{
			It = s.find(cur->val);
			if (*It == cur->val)
			{
				ss.insert(cur->val);
				s.erase(It);
				cur = cur->next;
				continue;
			}
			if (*(ss.find(cur->val)) != cur->val)
				s.insert(cur->val);
			cur = cur->next;
		}
		while (it != s.rend())
		{
			ListNode* node = new ListNode(*it);
			node->next = newNode;
			newNode = node;
			++it;
		}
		return newNode;
	}
};