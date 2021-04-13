## 題目鏈接
[P-1-1. 合成函數(1)](https://judge.tcirc.tw/ShowProblem?problemid=d001)

## 程式碼
- [P-1-1. 合成函數(1)a](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)a.cpp)
- [P-1-1. 合成函數(1)b](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)b.cpp)
- [P-1-1a (中正大學吳邦一教授)](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/p_1_1a.cpp)
- [P-1-1b (中正大學吳邦一教授)](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/p_1_1b.cpp)

## AP325中的敘述
位於AP325講義P18
題解：合成函數的意思是它的傳入參數可能是個數字也可能是另外一個函數值。以遞迴
的觀念來思考，我們可以將一個合成函數的表示式定義為一個函式 eval()，這個函式
從輸入讀取字串，回傳函數值。其流程只有兩個主要步驟，第一步是讀取一個字串，根
據題目定義，這個字串只有 3 種情形：f, g 或是一個數字。第二步是根據這個字串分
別去進行 f 或 g 函數值的計算或是直接回傳字串代表的數字。至於如何計算 f 與 g
的函數值呢？如果是 f，因為它有一個傳入參數，這個參數也是個合成函數，所以我們
遞迴呼叫 eval()來取得此參數值，再根據定義計算。如果是 g，就要呼叫 eval()兩
次取得兩個參數。 以下是演算法流程：

```c++
int eval() // 一個遞迴函式，回傳表示式的值
 讀入一個空白間隔的字串 token;
 if token 是 f then
 x = eval();
 return 2*x - 1;
 else if token 是 g then 
 x = eval();
 y = eval();
 return x + 2*y - 3;
 else // token 是一個數字字串
 return token 代表的數字
end of eval()
```

程式實作時，每次我們用字串的輸入來取得下一個字串，而字串可能需要轉成數字，這
可以用庫存函數 atoi()來做。

- [P-1-1a (中正大學吳邦一教授)](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/p_1_1a.cpp)

```c++
// p_1_1
#include <bits/stdc++.h>
int eval()
{
	int val, x, y, z;
	char token[7];
	scanf("%s", token);
	if (token[0] == 'f')
	{
		x = eval();
		return 2 * x - 1;
	}
	else if (token[0] == 'g')
	{
		x = eval();
		y = eval();
		return x + 2 * y - 3;
	}
	else
	{
		return atoi(token);
	}
}

int main()
{
	printf("%d\n", eval());
	return 0;
}
```
atoi()是一個常用的函數，可以把字串轉成對應的整數，名字的由來是 ascii-toint。當然也有其它的方式來轉換，這一題甚至可以只用 scanf()就可以，這要利用
scanf()的回傳值。我們可以將 eval()改寫如下，請看程式中的註解。

- [P-1-1b (中正大學吳邦一教授)](https://github.com/CalvinWan0101/AP325/blob/main/P-1-1.%20%E5%90%88%E6%88%90%E5%87%BD%E6%95%B8(1)/p_1_1b.cpp)

```c++
// p 1.1b
#include <stdio.h>

int eval()
{
	int val, x, y, z;
	char c;
	// first try to read an int, if successful, return the int
	if (scanf("%d", &val) == 1)
	{
		return val;
	}
	// otherwise, it is a function name: f or g
	scanf("%c", &c);
	if (c == 'f')
	{
		x = eval(); // f has one variable
		return 2 * x - 1;
	}
	else if (c == 'g')
	{
		x = eval(); // g has two variables
		y = eval();
		return x + 2 * y - 3;
	}
}

int main()
{
	printf("%d\n", eval());
	return 0;
}
```

## 我的解題思路

首先是輸入的部分,因為我之前都用cin,cout很少用scanf,printf，我這邊整理一下。這個所輸入的就會是在空格前的所有字元,如輸入"Cal eee"就只有"Cal"會被記錄進去。
```c++
char input[10];
scanf("%s", input);
```
然後是atoi的部分,可以用atoi把剛剛抓到的東西變成數字。下面這個輸入"123 998"會分別輸出"123","223"
```c++
char input[10];
scanf("%s", input);
printf("%d\n", atoi(input));
printf("%d\n", atoi(input) + 100);
```

在每一次呼叫fun函數時都要先讀入一次,然後將會遇到的狀況分為以下三種

狀況|回傳
-|-
input[0] == 'f'|2*x-1
input[0] == 'g'|x+2*y-3
else(數字)|原數字

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
