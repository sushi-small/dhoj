#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/* ѭ��������Ľ�㶨��*/
#define ElemType int 

template
struct LinkNode
{
	ElemType data;
	LinkNode* next;
	LinkNode(LinkNode* ptr = NULL) { next = ptr; } //���캯��1�����ڹ���ͷ���
	LinkNode(const ElemType& item, LinkNode* ptr = NULL) //���캯��2�����ڹ����������
	//�����������е��β�������Ĭ��ֵ�����Ǵ�Ĭ��ֵ�Ĳ�����Ҫ�ź���
	{
		next = ptr;
		data = item;
	}
	//int getNum(){ return number; } //ȡ�ý������
	ElemType getData() { return data; } //ȡ�ý����������ֵ
	void SetLink(LinkNode* link) { next = link; } //�޸Ľ���next��
	void SetLink(ElemType value) { data = value; } //�޸Ľ���next��
};

//��ͷ����ѭ��������
template
class CirLinkList {
private:
	LinkNode head; // ͷ���
	LinkNode tail; // β���
public:
	//�޲����Ĺ��캯��
	CirLinkList() { head = new LinkNode; tail = head; head->next = head; }
	//�������Ĺ��캯��
	CirLinkList(const ElemType& item) { head = new LinkNode(item); tail = head; head->next = head; }
	//�������캯��
	CirLinkList(CirLinkList& List);
	//��������
	~CirLinkList() { ListDestroy(); }
	//��������
	void ListDestroy();
	//�������
	void ListClear();
	//��������ĳ���
	int ListLength() const;
	//�ж������Ƿ�Ϊ�ձ�
	bool ListEmpty() const;
	//��ȡѭ������ͷ���
	LinkNode GetHead() { return head; }
	//��ȡѭ������β���
	LinkNode GetTail() { return tail; }
	//��������ͷ���
	void SetHead(LinkNode* p) { head = p; }
	//������ĵ�pos��λ��֮�����eԪ��
	bool ListInsert_next(int pos, ElemType e);
	//���׽��֮ǰ����һ�����
	bool InsFirst(ElemType& e);
	//��β���֮ǰ����һ�����
	bool InsTail(ElemType& e);
	//��ͷ���뷨��̬��������
	void CreateList_Head(vector& A);
	//��β���뷨��̬��������
	void CreateList_Tail(vector& A);
	//��������
	bool ListTraverse() const;
};
