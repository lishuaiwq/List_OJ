�ϲ�������������

��Ŀ����
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������

�㷨��

���ȴ�����һ���µĽ��������Ϊ���Ӻ���½���ͷ��,���и�ָ�������Ӻ����������һ�����µĽ�㣬
��������µĽ��ȥ�����½���

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL&&pHead2 != NULL)
			return pHead2;
		else if (pHead1 != NULL&&pHead2 == NULL)
			return pHead1;
		else if (pHead1 == NULL&&pHead2 == NULL)
			return NULL;
		ListNode* NewNode = NULL;
		ListNode* p = NULL;
		if (pHead1->val<pHead2->val)
		{
			NewNode = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			NewNode = pHead2;
			pHead2 = pHead2->next;
		}
		p = NewNode;//P��Զָ���ºϲ�����������¸պͲ������Ľ��
		while (pHead1&&pHead2)
		{
			if (pHead1->val<pHead2->val)
			{
				p->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				p->next = pHead2;
				pHead2 = pHead2->next;
			}
			p = p->next;
		}
		if (pHead1 == NULL)
		{
			p->next = pHead2;
		}
		else{
			p->next = pHead1;
		}
		return NewNode;
	}
};