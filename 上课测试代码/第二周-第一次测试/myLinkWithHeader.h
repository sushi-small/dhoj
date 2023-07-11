struct ListNode
{
	int  num;
	struct ListNode* next;
};

//从键盘读入数据创建链表，新结点插入到尾部
struct ListNode* createByTail();

//从键盘读入数据创建链表，新结点插入到头部
struct ListNode* createByHead();

//根据数组arr创建链表，新结点插入到尾部
struct ListNode* createByArray(int arr[], int n);

//输出链表中的信息（num）
void  displayLink(struct ListNode* head);

//获得链表的长度（结点数目）
int  getLength(struct ListNode* head);

//根据传入的num查找结点，返回指针指向该结点
//若未找到，则返回NULL
struct ListNode* Locate(struct ListNode* head, int num);

//将stu指向的结点插入到有序链表中，并保持链表按num有序
void insertNodeInOrder(struct ListNode* head, struct ListNode* stu);

//删除链表中学号为num的学生。由于学号不重复，因此本函数最多只删除一个结点
void deleteNode(struct ListNode* head, int num);

//逆置单链表
void invertLink(struct ListNode* head);

//插入法对链表排序
void insertSort(struct ListNode* head);

//将s结点插到p结点的前面
void insertNode(ListNode* head, ListNode* p, ListNode* s);
