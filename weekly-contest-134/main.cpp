#include<iostream>
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

using namespace std;
#define lower_bound LB
#define upper_bound UB
#define mem(a, x) memset(a,x,sizeof(a))
#define rep(i, a, n) for (int i=a;i<n;i++)
#define per(i, a, n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back
#define gcd(a, b) _gcd(a,b)

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const LL mod = 1000000007;
const double PI = acos (-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

vector<int> numMovesStones (int a, int b, int c)
{
	vector<int> res {a, b, c};
	sort (res.begin (), res.end ());
	int min_value = res[0];
	int mid_value = res[1];
	int max_value = res[2];
	int min_step = 0;
	if (max_value - mid_value == 1 && mid_value - min_value == 1)
	{
		min_step = 0;
	}
	else if (max_value - mid_value == 1 || mid_value - min_value == 1)
	{
		min_step = 1;
	}
	else
	{
		min_step = min (max_value - mid_value - 1, mid_value - min_value - 1);
		min_step = min (min_step, 2);
	}
	
	int max_step = (mid_value - min_value - 1) + (max_value - mid_value - 1);
	
	return vector<int> {min_step, max_step};
}

void dfs (vector<vector<int>> &grid, int r, int c, int r0, int c0, int consistent_color, int color)
{
	if (r0 < 0 || c0 < 0 || r0 >= r || c0 >= c || grid[r0][c0] != consistent_color)
	{
		if (grid[r0][c0] != consistent_color)
		{
			grid[r0][c0] = color;
		}
		else return;
	}
	else
	{
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if (abs (i) = !abs (j))
				{
					dfs (grid, r, c, r0 + i, c0 + j, consistent_color, color);
				}
			}
		}
	}
}

//class Solution {
//	public:
//	bool Inside(int x, int y, int n, int m) {
//		return x >= 0 && x < n && y >= 0 && y < m;
//	}
//	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
//		int i, n = grid.size(), m = grid[0].size();
//		queue<pair<int, int> >q;
//		int dir[2][4] = {{0, 1, 0, -1},
//		                 {1, 0, -1, 0}};
//		vector<vector<bool> >vis;
//		vis.resize(n, vector<bool>(m, false));
//		q.emplace(r0, c0);
//		vis[r0][c0] = true;
//		vector<pair<int, int> >save;
//		while(!q.empty()) {
//			int cnt = 0, x, y;
//			auto cur = q.front(); q.pop();
//			for (i = 0; i < 4; i++) {
//				x = cur.first + dir[0][i];
//				y = cur.second + dir[1][i];
//				if (Inside(x, y, n, m) && grid[x][y] == grid[cur.first][cur.second]) {
//					++cnt;
//					if (!vis[x][y]) {
//						vis[x][y] = true;
//						q.emplace(x, y);
//					}
//				}
//			}
//			if (cnt != 4)
//				save.push_back(cur);
//		}
//		for (i = 0; i < save.size(); i++)
//			grid[save[i].first][save[i].second] = color;
//		return grid;
//	}
//};

vector<vector<int>> colorBorder (vector<vector<int>> &grid, int r0, int c0, int color)
{
	int r = grid.size ();
	int c = grid[0].size ();
	int c_color = grid[r0][c0];
	dfs (grid, r, c, r0, c0, c_color, color);
	return grid;
}

int maxUncrossedLines (vector<int> &A, vector<int> &B)
{
	int len_a = A.size ();
	int len_b = B.size ();
	int dp[len_a + 5][len_b + 5];
	memset (dp, 0, sizeof (dp));
	for (int i = 0; i <= len_a; ++i)
	{
		for (int j = 0; j <= len_b; ++j)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[len_a][len_b];
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen (".txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	return 0;
}