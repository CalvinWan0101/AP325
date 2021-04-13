## 題目鏈接
- [Q-1-2. 合成函數(2)](https://judge.tcirc.tw/ShowProblem?problemid=d002)

## 程式碼

```c++
#include <bits/stdc++.h>
int fun()
{
	int x, y, z;
	char input[10];
	//每次呼叫fun函數都要讀入一次
	scanf("%s", input);
	//開始判斷讀入的狀況
	if (input[0] == 'f')
	{
		//x=下個輸入
		x = fun();
		return 2 * x - 3;
	}
	else if (input[0] == 'g')
	{
		//x=下個輸入
		x = fun();
		//y=下下個輸入
		y = fun();
		return 2 * x + y - 7;
	}
	else if (input[0] == 'h')
	{
		//x=下個輸入
		x = fun();
		//y=下下個輸入
		y = fun();
		//z=下下下個輸入
		z = fun();
		return 3 * x - 2 * y + z;
	}
	//讀入的為數字
	else
		return atoi(input);
}
int main()
{
	printf("%d\n", fun());
	return 0;
}
```
