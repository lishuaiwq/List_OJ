题目描述
输入一个链表，输出该链表中倒数第k个结点

算法：快慢指针

快指针先走k - 1步，然后慢指针再开始走（和快指针同步），当快指针到达最后一个结点的时候，慢指针所指的位置就是倒数第K个结点

注意：快指针走k - 1步，如果K给的值大于现有元素那么当心fast为空时发生段错误，这个也可以很好的用来判断k是否大于链表元素个数，因为如果大于链表个数那么fast一定会为null, 所以if(fast == NULL)return NULL;

第二个需要注意的是快慢指针一起走的时候while(fast&&fast->next)两个位置不能反

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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)
			return NULL;
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		while (fast&&--k)
		{
			fast = fast->next;
		}
		while (fast&&fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast)
			return NULL;
		return slow;
	}
};