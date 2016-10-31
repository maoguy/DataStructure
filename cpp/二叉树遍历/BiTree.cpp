/********************二叉树遍历实验************************/

#include <iostream>
using namespace std ;

//定义一个二叉树结构，其存储结构包含数据元素data和左右孩子指针lchild、rchild
struct BiNode 
{
	char data ;
	BiNode *lchild , *rchild ;
} ;
BiNode *BiTree ;

int NodeID ;	//全局变量，表示“先根”遍历存储表示序列序号

//递归创建二叉树的函数，返回二叉树指针T
BiNode *CreateBiTree (char *c , int n)
{
	BiNode *T ;	//创建新节点指针
	NodeID ++ ;	//节点计数变量自增
	//递归返回的条件设置
	if (NodeID > n)	
	{
		return (NULL) ;
	}
	if (c[NodeID] == '0')
	{
		return (NULL) ;
	}
	T = new BiNode ;	//生成一个节点
	T -> data = c[NodeID] ;	//将数据元素存入
	T -> lchild = CreateBiTree (c , n) ;	//左子树的递归
	T -> rchild = CreateBiTree (c , n) ;	//右子树的递归
	return (T) ;	//返回树的节点指针
}

//先根遍历函数
void PreOrderTraverse (BiNode *T)
{
	if (T)	//判断节点指针T是否为空
	{
		cout << T -> data << " ";	//输出节点数据
		PreOrderTraverse (T -> lchild) ;	//先根递归左子树
		PreOrderTraverse (T -> rchild) ;	//先根递归右子树
	}
}

//中根遍历函数
void InOrderTraverse (BiNode *T)
{
	if (T)
	{
		InOrderTraverse (T -> lchild) ;
		cout << T -> data << " ";
		InOrderTraverse (T -> rchild) ;
	}
}

//后根遍历函数
void PostOrderTraverse (BiNode *T)
{
	if (T)
	{
		PostOrderTraverse (T -> lchild) ;
		PostOrderTraverse (T -> rchild) ;
		cout << T -> data << " ";
	}
}

int main ()
{
	int i , SampleNum ;
	char c[100] ;
	cout << "请输入节点数目 ： " ;
	cin >> SampleNum ;
	cout << "请输入节点数据 ： " ;
	for (i = 1 ; i <= SampleNum ; i ++)
	{
		cin >> c[i] ;
	}
	NodeID = 0 ;	//节点计数变量初始化
	BiTree = CreateBiTree (c , SampleNum) ;	//调用创建二叉树函数
	cout << "先根遍历 ： " ;
	PreOrderTraverse (BiTree) ;	//调用先根遍历函数
	cout << endl ;
	cout << "中根遍历 ： " ;
	InOrderTraverse (BiTree) ;	//调用中根遍历函数
	cout << endl ;
	cout << "后根遍历 ：" ;
	PostOrderTraverse (BiTree) ; //调用后跟遍历函数
	cout << endl ;
	return 0 ;
}

/********************二叉树遍历实验************************/