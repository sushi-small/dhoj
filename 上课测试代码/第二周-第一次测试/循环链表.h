#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/* 循环单链表的结点定义*/
#define ElemType int 

template
struct LinkNode
{
	ElemType data;
	LinkNode* next;
	LinkNode(LinkNode* ptr = NULL) { next = ptr; } //构造函数1，用于构造头结点
	LinkNode(const ElemType& item, LinkNode* ptr = NULL) //构造函数2，用于构造其他结点
	//函数参数表中的形参允许有默认值，但是带默认值的参数需要放后面
	{
		next = ptr;
		data = item;
	}
	//int getNum(){ return number; } //取得结点的序号
	ElemType getData() { return data; } //取得结点的数据域的值
	void SetLink(LinkNode* link) { next = link; } //修改结点的next域
	void SetLink(ElemType value) { data = value; } //修改结点的next域
};

//带头结点的循环单链表
template
class CirLinkList {
private:
	LinkNode head; // 头结点
	LinkNode tail; // 尾结点
public:
	//无参数的构造函数
	CirLinkList() { head = new LinkNode; tail = head; head->next = head; }
	//带参数的构造函数
	CirLinkList(const ElemType& item) { head = new LinkNode(item); tail = head; head->next = head; }
	//拷贝构造函数
	CirLinkList(CirLinkList& List);
	//析构函数
	~CirLinkList() { ListDestroy(); }
	//销毁链表
	void ListDestroy();
	//清空链表
	void ListClear();
	//返回链表的长度
	int ListLength() const;
	//判断链表是否为空表
	bool ListEmpty() const;
	//获取循环链表头结点
	LinkNode GetHead() { return head; }
	//获取循环链表尾结点
	LinkNode GetTail() { return tail; }
	//设置链表头结点
	void SetHead(LinkNode* p) { head = p; }
	//在链表的第pos个位置之后插入e元素
	bool ListInsert_next(int pos, ElemType e);
	//在首结点之前插入一个结点
	bool InsFirst(ElemType& e);
	//在尾结点之前插入一个结点
	bool InsTail(ElemType& e);
	//表头插入法动态生成链表
	void CreateList_Head(vector& A);
	//表尾插入法动态生成链表
	void CreateList_Tail(vector& A);
	//遍历链表
	bool ListTraverse() const;
};
