��������

��Ŀ����
����һ��������ת�����������������Ԫ��

�㷨�����Ĵ���ֻ������

�ٸ�����1->2

����ָ��frontָ��NULL��mid��endָ��phead���ʼ��ʱ��

Ȼ����Ĵ���
end = end->next;//end��ǰ�߲�Ȼ�����˻�·�Ͷ��ˣ����ָ����Ҫ��������ͨ·��
mid->next = front;//�������õ�
front = mid;//�������������ص��
mid = end;//������

//ע������������������Ժ�Ӧ����mid���Ϊ�ռ�while(mid)

����

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


