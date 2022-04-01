#pragma once
#include <iostream>
using namespace std;

int ack(int m, int n)							//°¢¿ËÂüº¯Êıµİ¹éËã·¨
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ack(m - 1, 1);
	else
		return ack(m - 1, ack(m, n - 1));
}