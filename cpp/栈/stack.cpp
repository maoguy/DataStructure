#include <iostream>
#include <string.h>
using namespace std ;

#define ERROR -1
#define CORRECT 1

//堆栈的定义，定义一个堆栈结构，其存储结构包含栈底指针哦base和栈顶指针top
#define MAXSTACKSIZE 100
typedef struct SqStack
{
	char base[MAXSTACKSIZE] ;
	char *top ;
} SqStack ;

SqStack MBStack ;

//初始化堆栈，若栈不存在（base == NULL），返回ERROR，将top指向base
int InitStack (SqStack &S)
{
	if (S.base == NULL)
	{
		return (ERROR) ;
	}
	else
	{
		S.top = S.base ;	//初始化堆栈（清空）
		return (CORRECT) ;
	}
}

//进栈，若top超出范围，返回ERROR，将数据（e）插入栈顶指定位置（top）上，栈顶指针（top）加一
int Push (SqStack &S , char e)
{
	if ((S.top-S.base) >= MAXSTACKSIZE)
	{
		return (ERROR) ;
	}
	else
	{
		S.base[S.top - S.base] = e ;
		S.top++ ;
		return (CORRECT) ;
	}
}

//出栈，若为空，返回ERROR，否则取出一个数据放入变量e中，top--
int Pop (SqStack &S , char &e)
{
	if (S.top <= S.base)
	{
		return (ERROR) ;
	}
	else
	{
		e = S.base[S.top - S.base - 1] ;
		S.top-- ;
		return (CORRECT) ;
	}
}

//判断栈空
int StackEmpty (SqStack &S)
{
	if (S.top <= S.base)
	{
		return (ERROR) ;
	}
	else
	{
		return (CORRECT) ;
	}
}

//括号匹配
int MatchBracket (SqStack &S , char *BracketString)
{
	int i ;
	char C , sC ;

	InitStack (S) ;	//清空堆栈
	for (i = 0 ; i < strlen (BracketString) ; i++)
	{
		C = BracketString[i] ;

		if ((C == '(') || (C == '[') || (C == '{'))
		{
			Push (S , C) ;
		}
		if ((C == ')') || (C == ']') || (C == '}'))
		{
			if (StackEmpty (S) == ERROR)
			{
				return (-2) ;	//右多于左
			}
			Pop (S , sC) ;
			if ((C == ')') && (sC != '('))
			{
				return (-1);	//左右次序不对
			}
			if ((C == ']') && (sC != '['))
			{
				return (-1);	//左右次序不对
			}
			if ((C == '}') && (sC != '{'))
			{
				return (-1);	//左右次序不对
			}						
		}
	}

	if (StackEmpty (S) != ERROR)	//非空
	{
		return (-3) ;  //左多于右
	}

	else
	{
		return (0) ;	//栈空则正确
	}
}

//主函数
int main (int argc , char* argv[])
{
	int i , SampleNum ;
	char BracketString[MAXSTACKSIZE] ;

	cin >> SampleNum ;
	for (i = 0 ; i < SampleNum ; i ++)
	{
		cin >> BracketString ;
		cout << MatchBracket (MBStack , BracketString) << endl ;
	}
	return 0 ;
}