��Ŀ����������ĸ���

����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�

����˼·������˵һ��ʹ��unordered_multimap������������ķ���

�������½�㸴��һ���ɽ�㣬Ȼ�󽫾ɽ����½������ϣ���У����Ƶ�ͬʱҲ��nextָ�봮������
��ȫ�������ϣ���Ժ��ٴ�ȥ����ԭ����ͨ��ԭ�����rand�Ϳ����ҵ��������rand��Ϊ��ϣ������һһ��Ӧ�ģ�

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		//����һ����ϣ��
		unordered_multimap<RandomListNode*, RandomListNode*> m;

		// ����һ��ͷ���
		RandomListNode* newHead = new RandomListNode(pHead->label);
		// pClonedHead->next=NULL;
		// pClonedHead->random=NULL;

		// ��ͷ������map��
		m.insert(make_pair(pHead, newHead));

		//���ò���ָ��
		RandomListNode* cur = pHead->next;
		RandomListNode* pnewHead = newHead;//ָ��ǰ���Ƶ��½���ͷ�����治�����ͷ���

		while (cur)
		{
			// ���Ͽ���pNode�Ŀ������
			RandomListNode* pnew = new RandomListNode(cur->label);
			//  pClonedTail->next=NULL;
			// pClonedTail->random=NULL;


			pnewHead->next = pnew;
			pnewHead = pnew;

			//����Ӧ��ϵ  ���뵽��ϣ����
			m.insert(make_pair(cur, pnew));

			//����ƶ������ڵ�
			cur = cur->next;
		}

		//���ͷ��ʼ����random�ڵ㣬���ò���ָ��
		cur = pHead;
		RandomListNode* newList = newHead;

		// ����map�б�������ݣ��ҵ���Ӧ�Ľڵ�
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