��Ŀ��ɾ���������ظ��Ľ��

��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

�㷨��������˵һ�����Լ����㷨

ʹ������set���������ظ���Ԫ�أ�һ����������������˺��Ԫ�أ�һ�����������ο���ЩԪ�����ظ��ģ�Ȼ��ʹ�÷��������ͷ�����½�������Ϳ�����

�������룺

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

//��Ϊ�п��ܻ�ɾ������ĵ�һ����㣬����������Ҫ�Լ������ͷ���listnode* p1=NULL;
//��Ϊp1��Ҫ��ʱ���µ����µ�Ԫ�أ�����������Ҫ����p1��ֵ   listnode* head=p1;
//����Ҫһ�������������������ָ��

//��p1->val=p1->next->val�Ļ���ʾ���ǽ������ظ�����,������p2ѭ������ߣ�
//�ҵ���һ���������Ⱥ�е�Ԫ��,Ȼ����p1->nextָ��p2
//������ض������p1,p2

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* p1 = new ListNode(0);//ͷ���
		ListNode* head = p1;//����p1,��Ϊp1���ƶ�
		ListNode* p2 = pHead;//�����������������

		while (p2)
		{
			if (p2->next&&p2->val == p2->next->val)//
			{
				while (p2->next&&p2->val == p2->next->val)//�����ظ���Ԫ��
				{
					p2 = p2->next;
				}
				p2 = p2->next;//p2�ߵ�����ȵ�Ԫ��
				p1->next = p2;
			}
			else
			{
				p1->next = p2;//p1ָ����ȵ��Ǹ�Ԫ��
				p1 = p2;//p1�ߵ���ǰ����ȵ�λ��
				p2 = p2->next;//p2��������
			}
		}
		return head->next;
	}
};
