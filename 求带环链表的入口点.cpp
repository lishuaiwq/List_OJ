题目：链表中环的入口结点

题目描述
一个链表中包含环，请找出该链表的环的入口结点。


算法：找出链表的相遇点，然后一个指针从起点开始走一个指针从相遇点开始走，当两个指针相遇的时候就是入口点

代码

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