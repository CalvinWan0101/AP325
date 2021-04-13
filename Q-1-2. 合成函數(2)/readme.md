## 題目鏈接
- [Q-1-2. 合成函數(2)](https://judge.tcirc.tw/ShowProblem?problemid=d002)

## 程式碼
- [Q-1-2. 合成函數(2)](https://github.com/CalvinWan0101/AP325/blob/main/Q-1-2.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(2)/Q-1-2.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(2).cpp)

## 解題思路
基本上這一題跟[P-1-1. 合成函數(1)](https://github.com/CalvinWan0101/AP325/tree/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1))一模模一樣樣，只要多增加一個h的狀況就好了,詳細內容可以參考P-1-1的解題報告
- [Q-1-2. 合成函數(2)](https://github.com/CalvinWan0101/AP325/blob/main/Q-1-2.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(2)/Q-1-2.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(2).cpp)

狀況|x,y的取值|回傳
-|-|-
input[0] == 'f'|x=下個輸入(一定是數字)|2*x-3
input[0] == 'g'|x=下個輸入(一定是數字)，y=下下個輸入(一定是數字)|2*x+y-7
input[0]== 'h'|x=下個輸入(一定是數字)，y=下下個輸入(一定是數字),z=下下下個輸入(一定是數字)|3*x-2*y+z
else(數字)||原數字

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
