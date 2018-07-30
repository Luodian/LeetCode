#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <numeric>
#include <set>
#include <list>
#include <map>
#include <fstream>

using namespace std;
#define lower_bound LB
#define upper_bound UB
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back
#define gcd(a,b) _gcd(a,b)


typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const LL mod=1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

class Solution {
	public:
	bool isValidSudoku(vector<vector<char>> & board)
	{
		bool vis[10];
		memset(vis,0,sizeof(vis));
		bool flag = true;
		// check rows
		for (int i = 0; i < board.size() && flag; ++i)
		{
			memset(vis,0,sizeof(vis));
			for (int j = 0; j < board.size(); ++j)
			{
				if (board[i][j] != '.')
				{
                    int value = (board[i][j] - '0');
                    if (!vis[value])
                    {
                        vis[value] = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
				}
			}
		}
		// check cols
		for (int j = 0; j < board.size() && flag; ++j)
		{
			memset(vis,0,sizeof(vis));
			for (int i = 0; i < board.size(); ++i)
			{
				if (board[i][j] != '.')
				{
					if (board[i][j] != '.')
					{
						if (board[i][j] != '.')
						{
							int value = (board[i][j] - '0');
							if (!vis[value])
							{
								vis[value] = true;
							}
							else
							{
								flag = false;
								break;
							}
						}
					}
				}
			}
		}
		// check small rectangles
		for (int i = 0; i < 9 && flag; i += 3)
		{
			for (int j = 0; j < 9 && flag; j += 3)
			{
				memset(vis,0,sizeof(vis));
				int x = i;
				int y = j;
				for (int xi = 0; xi < x && flag; ++xi)
				{
					for (int yi = 0; yi < y && flag; ++yi)
					{
						if (board[xi][yi] != '.')
						{
							int value = (board[xi][yi] - '0');
							if (value > 0 && !vis[value])
							{
								vis[value] = true;
							}
							else
							{
								flag = false;
								break;
							}
						}
					}
				}
			}
		}
		return flag;
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/this.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution a;
	vector<vector<char>> mat;
	mat.resize(9);
	ifstream infile;
	infile.open("/Users/luodian/Desktop/this.txt",ios::in);
	int cnt = 0;
	while(!infile.eof())
	{
		string line;
		infile>>line;
		if (line[0] != '[' || line[0] != ']')
		{
			for (int i = 0; i < line.size(); ++i)
			{
				if (isdigit(line[i]) || line[i] == '.')
				{
					mat[0].push_back(line[i]);
				}
			}
			cnt ++;
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}