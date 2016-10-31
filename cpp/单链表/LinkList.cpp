#include <iostream>
using namespace std ;

#define ERROR -1
#define CORRECT 1

struct LNode 
{
	int data ;
	LNode *next ;
};
LNode *LinkList ;

//单链表的查找，输出位置i的数据结点指针
LNode *SearchLinkList (LNodes *L , int i)
{
	int j ;
	LNode *p ;

	p = L ;
	j = 1 ;
	while (p && j < i)
	{
		p = p -> next ;
		j ++ ;
	}
	return (p) ;
}

//单链表的插入，将新数据e插入到指定位置i上
int InsertLinkList (LNode *L , int e , int i)
{
	LNode *p , *s ;
	p = SearchLinkList (L , i-1) ;
	if (!p)
	{
		return (ERROR) ;
	}
	s = new LNode ;
	s -> data = e ;
	//新节点插入L中
	s -> next = p -> next ;
	p -> next = s ;

	return (CORRECT) ;
}

//单链表创建,将输入的关键字依次放入单链表中
LNode *CreateLinkList (int *r , int n)
{
	int j;
	LNode *L , *p , *s ;

	if (n <= 0)
	{
		return NULL ;
	}
	s = new Lnode ;
	s -> data = r[1] ;
	s -> next = NULL ;	//创建第一个结点
	L = s ;
	p = L ;
	for (j = 2 ; j <= n ; j++)
	{
		s = new LNode ;
		s -> data = r[j] ;
		s -> next = NULL ;	//创建第j个结点
		p -> next = s ;
		p = s ;
	}
	return (L) ;
}

//单链表的删除,将位置i的数据元素删除
int DeleteLinkList (LNode *L , int i)
{
	int e ;
	Lnode *p , *q ;

	p = SearchLinkList (L , i-1) ;
	if (!p)
	{
		return (ERROR) ;
	}
	q = p -> next ;

	p -> next = p -> next -> next ;	//此处不能用q指针作为被赋值变量，因为后面要清空内存

	e = q -> data ;
	delete (q) ;	//注意！！！q指针指向的内存将被清空
	return (e) ;
}

//按格式输出单链表
int ShowLinkList (LNode *L)
{
	LNode *p ;
	if (!L)
	{
		return (ERROR) ;
	}
	p = L ;
	while (p -> next)
	{
		cout << p -> data <<" " ;
		p = p -> next ;
	}
	cout << p -> data << endl ;
	return (CORRECT) ;
}

int main (int argc , char *argv[])
{
	int r[100] , i , SampleNum , SearchPos , NewPos , NewItem , DelPos ;
	LNode *p ;

	cin >> SampleNum ;
	for (i = 1 ; i <= SampleNum ; i++)
	{
		cin >> r[i] ;
	}

	LinkList = CreateLinkList (r , SampleNum) ;
	ShowLinkList (LinkList) ;

	cin >> SearchPos ;
	p = SearchLinkList (LinkList , SearchPos) ;
	cout << p -> data << endl ;

	cin >> NewPos ;
	cin >> NewItem ;
	InsertLinkList (LinkList , NewItem , NewPos) ;
	ShowLinkList (LinkList) ;

	cin >> DelPos ;
	DeleteLinkList (LinkList , DelPos) ;
	ShowLinkList (LinkList) ;

	return 0 ;
}


