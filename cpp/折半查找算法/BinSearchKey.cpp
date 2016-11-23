/**********************折半查找*************************/

#include <iostream>
using namespace std ;

int BinSuccess ;  //查找是否成功（1成功，0不成功）
int BinPos ;  //查找位置（0表示不成功）
int BinCount ;  //查找次数

int BinList[32] ; //有序表
int BinListLen ;  //有序表长度

//利用直接插入排序，将输入的关键字排成有序序列
void CreateSequence (int *r , int n)
{
  int i , j , temp ;

  BinListLen = n ;

  //利用直接插入排序算法将顺序表元素排成升序序列
  for (i = 1 ; i < n ; i ++)
  {
    if (r[i+1] < r[i])
    {
      temp = r[i+1] ;
      for (j = i ; j >= 1 ; j -= 1)
      {
        if (temp < r[j])
        {
          r[j+1] = r[j] ;
        }
        else
        {
          break ;
        }
      }
      r[j+1] = temp ;
    }
  }

  //将排好序的序列放到有序顺序表中
  for (i = 1 ; i <= n ; i ++)
  {
    BinList[i] = r[i] ;
  }
}

//折半查找算法实现
int BinSearchKey (int Key)
{
  int Low , Mid , High ;

  Low = 1 ; //Low指向待查元素所在区间的下界
  High = BinListLen ; //high指向待查元素所在区间的上界
  BinSuccess = 0 ;
  BinPos = 0 ;
  BinCount = 0 ;  //初始化

  //折半查找
  for ( ; Low <= High ; BinCount ++)
  {
    Mid = (Low + High) / 2 ;
    if (Key < BinList[Mid])
    {
      High = Mid - 1 ;  //[上半区间]
    }
    else if (Key > BinList[Mid])
    {
      Low = Mid + 1 ; //[下半区间]
    }
    else
    {
      BinCount ++ ;
      BinSuccess = 1 ;
      BinPos = Mid ;
      break ; //查找成功，跳出循环
    }
  }

  return (BinCount) ; //返回查找次数
}

//主函数
int main ()
{
  int r[32] ;
  int i , j , Key ;
  int TestNum , SampleNum ;

  cin >> TestNum ;  //输入测试次数
  for (i = 0 ; i < TestNum ; i ++)
  {
    cin >> SampleNum ;  //输入样本数目
    for (j = 1 ; j <= SampleNum ; j ++)
    {
      cin >> r[j] ; //输入样本数据
    }

    CreateSequence (r , SampleNum) ;  //生成升序序列

    cin >> Key ;  //输入1个查找数据
    BinSearchKey (Key) ;  //调用折半查找函数

    //输出最终结果，用于测试
    cout << BinSuccess << " " << BinPos << " " << BinCount << endl ;
  }

  return 0 ;
}

/**********************折半查找*************************/
