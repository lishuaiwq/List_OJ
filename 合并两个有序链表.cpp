合并两个有序链表

题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则

算法：

首先创建以一个新的结点用来作为连接后的新结点的头部,还有个指向新连接后的链表的最后一个最新的结点，
用这个最新的结点去连接新结点的

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
		p = NewNode;//P永远指向新合并的链表的最新刚和并上来的结点
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