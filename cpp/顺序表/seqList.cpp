#include <iostream>
using namespace std ;
int Error = 0 ;

#define MAXLISTLEN 100
int ListLen = 0 ;
int SeqList [MAXLISTLEN + 1] ;

//顺序表查找
int SearchSeqList (int i)
{
	if ((i > ListLen) || (i < 1) || (ListLen == 0))
	{
		Error = -1 ;
		return (-1) ;	//查找出错返回
	}
	else
	{
		return SeqList [i] ;	//返回指定位置的元素值
	}
}

//顺序表的插入
void InsertSeqList (int NewItem , int i)
{
	int j ;

	if ((i > ListLen + 1) || (i < 1) || (ListLen == MAXLISTLEN))
	{
		Error = -2 ;    //插入出错返回
		cout << "插入出错啦！！！";
	}
	else
	{
		for (j = ListLen ; j >= i ; j -- )	//从后往前移
		{
			SeqList [j+1] = SeqList [j] ;
		}
		SeqList [i] = NewItem ;		//插入新元素
		ListLen = ListLen + 1 ;		//表长加一
	}
}

//顺序表指定位置数据的删除
void DeleteSeqList (int i)
{
	int j ;

	if ((i > ListLen)||(i < 1) || (ListLen == 0))
	{
		Error = -3 ;	//删除出错返回
		cout << "删除出错啦！！！" ;
	}
	else
	{
		for (j = i ; j < ListLen ; j ++ )	//从前往后移
		{
			SeqList [j] = SeqList [j+1] ;
		}
		ListLen = ListLen - 1 ;		//表长减一
	}
}

//顺序表显示
void ShowSeqList ()
{
	int i ;

    cout << "The list : " ;
	for (i = 1 ; i <= ListLen ; i ++ )
	{
		cout <<SeqList[i]<<" " ;	//逐个显示数据元素
	}
	cout << endl ;			//换行

}

//主函数
int main (int argc , char * argv[])
{
int r[MAXLISTLEN] , i , SearchPos , NewPos , NewItem , DelPos ;

cout << "Please input the ListLen : " ;
cin >> ListLen ;    //输入样本数目（表长）
//创建顺序表
for (i = 1 ; i <= ListLen ; i++)
{
	cout << "Please input No." << i <<"Item : " ;
	cin >> SeqList[i] ;
	cout << endl ;
}
ShowSeqList () ;	//显示顺序表

cout << "Please input the search pos : " ;
cin >> SearchPos ;	//输入查找位置

cout << "Your Searched Item is : " <<SearchSeqList (SearchPos) << endl ;	//输出查找的数据元素值

cout << "Please input the NewPos where you want to insert : " ;
cin >> NewPos ;		//插入位置输入
cout << "Please input the NewItem what you want to insert : " ;
cin >> NewItem ;	//插入元素输入
InsertSeqList (NewItem , NewPos) ;	//新数据插入顺序表中
cout << "After insert : " ;
ShowSeqList () ;		//插入数据后，输出新的顺序表

cout << "Please input the DelPos where you want to delete : " ;
cin >> DelPos ;		//输入删除元素位置
DeleteSeqList (DelPos) ;	//按位置删除数据
cout << "After delete : " ;
ShowSeqList () ;

if (Error < 0) cout <<"Error" << Error << endl ;

return 0 ;
}
#include <iostream>
using namespace std ;
int Error = 0 ;

#define MAXLISTLEN 100
int ListLen = 0 ;
int SeqList [MAXLISTLEN + 1] ;

//顺序表查找
int SearchSeqList (int i)
{
	if ((i > ListLen) || (i < 1) || (ListLen == 0))
	{
		Error = -1 ;
		return (-1) ;	//查找出错返回
	}
	else
	{
		return SeqList [i] ;	//返回指定位置的元素值
	}
}

//顺序表的插入
void InsertSeqList (int NewItem , int i)
{
	int j ;

	if ((i > ListLen + 1) || (i < 1) || (ListLen == MAXLISTLEN))
	{
		Error = -2 ;    //插入出错返回
		cout << "插入出错啦！！！";
	}
	else
	{
		for (j = ListLen ; j >= i ; j -- )	//从后往前移
		{
			SeqList [j+1] = SeqList [j] ;
		}
		SeqList [i] = NewItem ;		//插入新元素
		ListLen = ListLen + 1 ;		//表长加一
	}
}

//顺序表指定位置数据的删除
void DeleteSeqList (int i)
{
	int j ;

	if ((i > ListLen)||(i < 1) || (ListLen == 0))
	{
		Error = -3 ;	//删除出错返回
		cout << "删除出错啦！！！" ;
	}
	else
	{
		for (j = i ; j < ListLen ; j ++ )	//从前往后移
		{
			SeqList [j] = SeqList [j+1] ;
		}
		ListLen = ListLen - 1 ;		//表长减一
	}
}

//顺序表显示
void ShowSeqList ()
{
	int i ;

    cout << "The list : " ;
	for (i = 1 ; i <= ListLen ; i ++ )
	{
		cout <<SeqList[i]<<" " ;	//逐个显示数据元素
	}
	cout << endl ;			//换行

}

//主函数
int main (int argc , char * argv[])
{
int r[MAXLISTLEN] , i , SearchPos , NewPos , NewItem , DelPos ;

cout << "Please input the ListLen : " ;
cin >> ListLen ;    //输入样本数目（表长）
//创建顺序表
for (i = 1 ; i <= ListLen ; i++)
{
	cout << "Please input No." << i <<"Item : " ;
	cin >> SeqList[i] ;
	cout << endl ;
}
ShowSeqList () ;	//显示顺序表

cout << "Please input the search pos : " ;
cin >> SearchPos ;	//输入查找位置

cout << "Your Searched Item is : " <<SearchSeqList (SearchPos) << endl ;	//输出查找的数据元素值

cout << "Please input the NewPos where you want to insert : " ;
cin >> NewPos ;		//插入位置输入
cout << "Please input the NewItem what you want to insert : " ;
cin >> NewItem ;	//插入元素输入
InsertSeqList (NewItem , NewPos) ;	//新数据插入顺序表中
cout << "After insert : " ;
ShowSeqList () ;		//插入数据后，输出新的顺序表

cout << "Please input the DelPos where you want to delete : " ;
cin >> DelPos ;		//输入删除元素位置
DeleteSeqList (DelPos) ;	//按位置删除数据
cout << "After delete : " ;
ShowSeqList () ;

if (Error < 0) cout <<"Error" << Error << endl ;

return 0 ;
}
