struct ListNode
{
	int  num;
	struct ListNode* next;
};

//�Ӽ��̶������ݴ��������½����뵽β��
struct ListNode* createByTail();

//�Ӽ��̶������ݴ��������½����뵽ͷ��
struct ListNode* createByHead();

//��������arr���������½����뵽β��
struct ListNode* createByArray(int arr[], int n);

//��������е���Ϣ��num��
void  displayLink(struct ListNode* head);

//�������ĳ��ȣ������Ŀ��
int  getLength(struct ListNode* head);

//���ݴ����num���ҽ�㣬����ָ��ָ��ý��
//��δ�ҵ����򷵻�NULL
struct ListNode* Locate(struct ListNode* head, int num);

//��stuָ��Ľ����뵽���������У�����������num����
void insertNodeInOrder(struct ListNode* head, struct ListNode* stu);

//ɾ��������ѧ��Ϊnum��ѧ��������ѧ�Ų��ظ�����˱��������ֻɾ��һ�����
void deleteNode(struct ListNode* head, int num);

//���õ�����
void invertLink(struct ListNode* head);

//���뷨����������
void insertSort(struct ListNode* head);

//��s���嵽p����ǰ��
void insertNode(ListNode* head, ListNode* p, ListNode* s);
