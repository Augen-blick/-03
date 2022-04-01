#include "Ackermann02.h"

int main()
{
	int m, n;

	cout << "请分别输入阿克曼函数的m与n：" << endl;

	cin >> m >> n;

	cout << "Ack(" << m << "," << n << ")= " << ack02(m, n);
}