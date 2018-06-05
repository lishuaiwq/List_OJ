题目：删除链表中重复的结点

题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

算法：这里先说一个我自己的算法

使用两个set用来过滤重复的元素，一个链表用来保存过滤后的元素，一个链表用来参考哪些元素是重复的，然后使用反向迭代器头插重新建立链表就可以了

给出代码：

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