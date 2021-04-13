#include <bits/stdc++.h>
int fun()
{
	int val, x, y;
	char a;
	if (scanf("%d", &val) == 1)
	{
		return val;
	}
	scanf("%c", &a);
	if (a == 'f')
	{
		x = fun();
		return 2 * x - 1;
	}
	else if (a == 'g')
	{
		x = fun();
		y = fun();
		return x + 2 * y - 3;
	}
}
int main()
{
	printf("%d\n", fun());
	return 0;
}
