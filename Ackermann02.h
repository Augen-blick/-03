#pragma once
#include "SeqStack.h"

int ack02(int m, int n)
{
	SqStack* x, * y;								//x栈存m，y栈存n
	InitStack(x), InitStack(y);
	Push(x, m), Push(y, n);
	ElemType e;

	while (!StackEmpty(x))							//当m栈不空时循环
	{
		while (m != 0)								//m!=0的时候m，n进栈
		{
			if (n == 0)								//n=0，按函数进一步存储
			{
				m = m - 1;
				n = 1;
				Push(x, m);
				Push(y, n);
			}
			else									//n!=0，函数中又包含函数，用n栈存-1表示
			{
				n--;								//m不减一，n减一因为下一个进栈的是m与n-1
				Push(x, m - 1);
				Push(y, -1);
			}
		}
		
		n++;										//当m=0时，n+1
		while (!StackEmpty(x) && GetTop(y) != -1)	//当m=0且栈顶元素!=0时出栈,这里的m是整体的m,用来
		{										//判断是出栈还是进栈,栈顶元素是运算的结果,最后返回结果
			Pop(x,e);
			Pop(y,e);
		}
		if (!StackEmpty(x))						//当栈顶元素为-1时,需要更换栈顶元素为n
		{										//即上面得到的结果
			m = GetTop(x);						//记录-1对应的m值,该值用来判断下一步是出栈还是进栈
			Pop(y, e);
			Push(y, n);
		}
	}
	return n;
}