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
	vector<int> prevPermOpt1 (vector<int> &A)
	{
		int pos = -1;
		for (int i = A.size () - 2; i >= 0; --i)
		{
			if (A[i] < A[i + 1])
			{
				pos = i;
				break;
			}
		}
		if (pos != -1)
		{
			for (int i = pos + 1; i < A.size (); ++i)
			{
				if (A[i] < A[pos])
				{
					swap (A[i], A[pos]);
					break;
				}
			}
		}
		return A;
	}
	int maxEqualRowsAfterFlips (vector<vector<int>> &matrix)
	{
		map<string, int> sim_mp;
		for (auto x: matrix)
		{
			int first_value = x[0];
			string s = "";
			for (auto item: x)
			{
				if (item == first_value)
				{
					s += "1";
				}
				else
				{
					s += "0";
				}
			}
			sim_mp[s] += 1;
		}
		int ans = 0;
		for (auto item : sim_mp)
		{
			ans = max(item.second, ans);
		}
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
	return 0;
}
