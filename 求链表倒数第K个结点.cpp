��Ŀ����
����һ����������������е�����k�����

�㷨������ָ��

��ָ������k - 1����Ȼ����ָ���ٿ�ʼ�ߣ��Ϳ�ָ��ͬ����������ָ�뵽�����һ������ʱ����ָ����ָ��λ�þ��ǵ�����K�����

ע�⣺��ָ����k - 1�������K����ֵ��������Ԫ����ô����fastΪ��ʱ�����δ������Ҳ���Ժܺõ������ж�k�Ƿ��������Ԫ�ظ�������Ϊ����������������ôfastһ����Ϊnull, ����if(fast == NULL)return NULL;

�ڶ�����Ҫע����ǿ���ָ��һ���ߵ�ʱ��while(fast&&fast->next)����λ�ò��ܷ�

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