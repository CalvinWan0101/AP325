#include <bits/stdc++.h>
int fun()
{
	int x, y;
	char input[10];
	scanf("%s", input);
	if (input[0] == 'f')
	{
		x = fun();
		return 2 * x - 1;
	}
	else if (input[0] == 'g')
	{
		x = fun();
		y = fun();
		return x + 2 * y - 3;
	}
	else
		return atoi(input);
}
int main()
{
	printf("%d\n", fun());
	return 0;
}
