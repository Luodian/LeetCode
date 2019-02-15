# define _CRT_SECURE_NO_DEPRECATE
# define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include <iostream>
#include <stdio.h>
using namespace std;

int map[9][9];    //存储数独
char ch;          //输入数独数字和字符'？'
int num;          //记录有多少个'?'
int p = 0;        //"同一行相邻的两个数用一个空格分开"根据题意，设置个变量记录是否输出空行
bool flag;        //记录是否已找到满足题意的数独
struct Node       //记录'?'的横纵坐标
{
	int x;
	int y;
}node[81];

bool Judge(int t, int number)
{
	//同行同列是否有相同
	for (int i = 0; i < 9; i++)
	{
		if (t == map[node[number].x][i] || t == map[i][node[number].y])
			return 0;
	}

	//同一3*3方格里的数字是否重复
	int x = node[number].x - node[number].x % 3;
	int y = node[number].y - node[number].y % 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[x + i][y + j] == t)
				return 0;
		}
	}
	//满足要求的话，返回1
	return 1;
}

void DFS(int number)
{
	if (number == num)//已找到满足要求的数独，可以输出
	{
		flag = true;
		for (int i = 0; i < 9; i++)
		{
			cout << map[i][0];
			for (int j = 1; j < 9; j++)
				cout << " " << map[i][j];
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (!flag && Judge(i, number))
		{
			map[node[number].x][node[number].y] = i;
			DFS(number + 1);
			map[node[number].x][node[number].y] = 0;
		}
	}

}

int main()
{
	while (cin>>ch)
	{
		flag = false;
		num = 0;

		if (ch == '?')
		{
			map[0][0] = 0;
			node[num].x = 0;
			node[num].y = 0;
			num++;
		}
		else
			map[0][0] = ch - '0';

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i + j == 0) continue;//

				cin >> ch;
				if (ch == '?')
				{
					map[i][j] = 0;
					node[num].x = i;
					node[num].y = j;
					num++;
				}
				else
					map[i][j] = ch - '0';
			}
		}
		if (p)
			cout << endl;
		p++;
		DFS(0);

	}

	return 0;
}