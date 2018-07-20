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

//因为有可能会删除链表的第一个结点，所以我们需要自己定义个头结点listnode* p1=NULL;
//因为p1需要随时更新到最新的元素，所以我们需要保存p1的值   listnode* head=p1;
//还需要一个用来遍历整个链表的指针

//当p1->val=p1->next->val的话表示我们进入了重复区域,所以让p2循环向后走，
//找到第一个不是这个群中的元素,然后让p1->next指向p2
//如果不重读则更新p1,p2

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* p1 = new ListNode(0);//头结点
		ListNode* head = p1;//保存p1,因为p1会移动
		ListNode* p2 = pHead;//用来遍历整个链表的

		while (p2)
		{
			if (p2->next&&p2->val == p2->next->val)//
			{
				while (p2->next&&p2->val == p2->next->val)//过滤重复的元素
				{
					p2 = p2->next;
				}
				p2 = p2->next;//p2走到不相等的元素
				p1->next = p2;
			}
			else
			{
				p1->next = p2;//p1指向不相等的那个元素
				p1 = p2;//p1走到当前不相等的位置
				p2 = p2->next;//p2往后面走
			}
		}
		return head->next;
	}
};
