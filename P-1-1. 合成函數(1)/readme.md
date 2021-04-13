## 題目鏈接
[P-1-1. 合成函數(1)](https://judge.tcirc.tw/ShowProblem?problemid=d001)

## 程式碼
- [P-1-1. 合成函數(1)a](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)a.cpp)
- [P-1-1. 合成函數(1)b](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)b.cpp)
- [P-1-1a (中正大學吳邦一教授)](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/p_1_1a.cpp)
- [P-1-1b (中正大學吳邦一教授)](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/p_1_1b.cpp)

## 解題報告

狀況|回傳
-|-
f|2*x-1
g|x+2*y-3
數字|數字

因為輸入的每個東西不論是數字還是字母中間都會用空格隔起來，所以可以直接讓每次輸入都是不同的東西。


```c++
//完整程式碼
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
```
