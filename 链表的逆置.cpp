逆置链表

题目描述
输入一个链表，反转链表后，输出链表的所有元素

算法：核心代码只有四行

举个例子1->2

三个指针front指向NULL，mid和end指向phead，最开始的时候

然后核心代码
end = end->next;//end提前走不然逆置了话路就断了，这个指针主要是来保持通路的
mid->next = front;//用来逆置的
front = mid;//用来保持逆置重点的
mid = end;//往后走

//注意最后链表逆置完了以后应该是mid最后为空即while(mid)

代码

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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		ListNode* mid = pHead;
		ListNode* front = NULL;
		ListNode* end = pHead;
		if (pHead->next == NULL)
			return pHead;
		while (mid)
		{
			end = end->next;
			mid->next = front;
			front = mid;
			mid = end;
		}
		return front;
	}
};


