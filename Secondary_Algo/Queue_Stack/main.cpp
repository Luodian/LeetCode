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
class Solution
{
	public:
	char move_forward (char ch)
	{
		if (ch != '9')
		{
			return (ch - '0' + 1) + '0';
		}
		else
		{
			return '0';
		}
	}
	char move_backward (char ch)
	{
		if (ch != '0')
		{
			return (ch - '0' - 1) + '0';
		}
		else
		{
			return '9';
		}
	}
	int openLock (vector<string> &deadends, string target)
	{
		set<string> st;
		for (auto item : deadends)
		{
			st.insert (item);
		}
		if (st.count ("0000") == 1)
		{
			return -1;
		}
		queue<pair<string, int>> Q;
		Q.push (make_pair ("0000", 0));
		int step = 0;
		while (!Q.empty ())
		{
			string cur = Q.front ().first;
			step = Q.front ().second;
			Q.pop ();
			st.insert (cur);
			string next = cur;
			if (cur == target)
			{
				return step;
			}
			for (size_t i = 0; i < cur.length (); ++i)
			{
				next = cur;
				next[i] = move_forward (cur[i]);
				if (st.count (next) != 1)
				{
					Q.push (make_pair (next, step + 1));
					st.insert (next);
					cout << next << " " << step + 1 << endl;
				}
				next = cur;
				next[i] = move_backward (cur[i]);
				if (st.count (next) != 1)
				{
					Q.push (make_pair (next, step + 1));
					st.insert (next);
					cout << next << " " << step + 1 << endl;
				}
			}
		}
		return -1;
	}
	int numSquares (int n)
	{
		vector<int> v (n + 5, 0);
		for (int i = 1; i <= n; ++i)
		{
			int min_value = 0x3f3f3f3f;
			for (int j = 1; j * j <= i; ++j)
			{
				min_value = min (min_value, v[i - j * j]);
			}
			v[i] = min_value + 1;
		}
		return v[n];
	}
	vector<int> dailyTemperatures (vector<int> &T)
	{
		stack<pair<int, int>> ascend;
		vector<int> ans (T.size () - 1, 0);
		if (T.size () == 1)
		{
			ans.push_back (0);
			return ans;
		}
		ascend.push (make_pair (T[0], 0));
		for (size_t i = 1; i < T.size (); ++i)
		{
			if (!ascend.empty ())
			{
				if (T[i] > ascend.top ().first)
				{
					while (!ascend.empty () && T[i] > ascend.top ().first)
					{
						ans[ascend.top ().second] = i - ascend.top ().second;
						ascend.pop ();
					}
					ascend.push (make_pair (T[i], i));
				}
				else
				{
					ascend.push (make_pair (T[i], i));
				}
			}
			else
			{
				ans[i] = 0;
			}
		}
		ans.push_back (0);
		return ans;
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
	Solution a;
	std::vector<int> v = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
	std::vector<int> ret = a.dailyTemperatures (v);
	for (auto item : ret)
	{
		cout << item << endl;
	}
	return 0;
}
