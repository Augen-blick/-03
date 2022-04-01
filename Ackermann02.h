#pragma once
#include "SeqStack.h"

int ack02(int m, int n)
{
	SqStack* x, * y;								//xջ��m��yջ��n
	InitStack(x), InitStack(y);
	Push(x, m), Push(y, n);
	ElemType e;

	while (!StackEmpty(x))							//��mջ����ʱѭ��
	{
		while (m != 0)								//m!=0��ʱ��m��n��ջ
		{
			if (n == 0)								//n=0����������һ���洢
			{
				m = m - 1;
				n = 1;
				Push(x, m);
				Push(y, n);
			}
			else									//n!=0���������ְ�����������nջ��-1��ʾ
			{
				n--;								//m����һ��n��һ��Ϊ��һ����ջ����m��n-1
				Push(x, m - 1);
				Push(y, -1);
			}
		}
		
		n++;										//��m=0ʱ��n+1
		while (!StackEmpty(x) && GetTop(y) != -1)	//��m=0��ջ��Ԫ��!=0ʱ��ջ,�����m�������m,����
		{										//�ж��ǳ�ջ���ǽ�ջ,ջ��Ԫ��������Ľ��,��󷵻ؽ��
			Pop(x,e);
			Pop(y,e);
		}
		if (!StackEmpty(x))						//��ջ��Ԫ��Ϊ-1ʱ,��Ҫ����ջ��Ԫ��Ϊn
		{										//������õ��Ľ��
			m = GetTop(x);						//��¼-1��Ӧ��mֵ,��ֵ�����ж���һ���ǳ�ջ���ǽ�ջ
			Pop(y, e);
			Push(y, n);
		}
	}
	return n;
}