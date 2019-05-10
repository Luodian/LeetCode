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
class Solution {
public:
	int n,m;
	set<pair<int, int>> st;
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	void bfs(vector<vector<char>> & grid, int x, int y)
	{
		std::queue<pair<int, int>> Q;
		while(!Q.empty())
		{
			Q.pop();
		}
		Q.push(make_pair(x,y));
		while(!Q.empty())
		{
			pair<int, int> cur = Q.front();
			st.insert(cur);
			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> next;
				next.first = cur.first + dx[i];
				next.second = cur.second + dy[i];
				if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m && st.count(next) != 1 && grid[next.first][next.second] == '1')
				{
					Q.push(next);
				}
			}
		}
	}
	int numIslands(vector<vector<char>>& grid)
	{
		st.clear();
		int cnt = 0;
		n = grid.size();
		m = grid[0].size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == '1' && st.count(make_pair(i, j)) == 0)
				{
					cnt += 1;
					bfs(grid, i, j);
				}
			}
		}
		return cnt;
	}
};

int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	return 0;
}
