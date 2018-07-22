
两个链表的第一个公共的交点

算法思想：

给出代码：

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		while (cur1 != cur2)
		{
			//这里是cur不是cur->next因为如果不相交的话则两个都能取到空
			cur1 = (cur1 != NULL ? cur1->next : pHead2);
			cur2 = (cur2 != NULL ? cur2->next : pHead1);
		}
		return cur1;
	}
};