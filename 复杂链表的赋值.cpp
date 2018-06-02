题目：复杂链表的复制

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

解题思路：这里说一个使用unordered_multimap来解决这个问题的方法

即：用新结点复制一个旧结点，然后将旧结点和新结点放入哈希表中，复制的同时也将next指针串起来，
当全部放入哈希表以后，再次去遍历原链表，通过原链表的rand就可以找到现链表的rand因为哈希表中是一一对应的！

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		//定义一个哈希表
		unordered_multimap<RandomListNode*, RandomListNode*> m;

		// 开辟一个头结点
		RandomListNode* newHead = new RandomListNode(pHead->label);
		// pClonedHead->next=NULL;
		// pClonedHead->random=NULL;

		// 将头结点放入map中
		m.insert(make_pair(pHead, newHead));

		//设置操作指针
		RandomListNode* cur = pHead->next;
		RandomListNode* pnewHead = newHead;//指向当前复制的新结点的头结点后面不动这个头结点

		while (cur)
		{
			// 不断开辟pNode的拷贝结点
			RandomListNode* pnew = new RandomListNode(cur->label);
			//  pClonedTail->next=NULL;
			// pClonedTail->random=NULL;


			pnewHead->next = pnew;
			pnewHead = pnew;

			//将对应关系  插入到哈希表中
			m.insert(make_pair(cur, pnew));

			//向后移动操作节点
			cur = cur->next;
		}

		//需从头开始设置random节点，设置操作指针
		cur = pHead;
		RandomListNode* newList = newHead;

		// 根据map中保存的数据，找到对应的节点
		while (cur)
		{

			if (cur->random != NULL)
				newList->random = m.find(cur->random)->second;


			cur = cur->next;
			newList = newList->next;
		}

		return newHead;

	}
};