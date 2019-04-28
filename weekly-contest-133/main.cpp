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

string removeOuterParentheses (string S)
{
	int n = S.size ();
	string ret;
	std::vector<char> v;
	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		if (S[i] == '(')
		{
			if (v.empty ())
			{
				cur = i;
			}
			v.push_back (S[i]);
		}
		else
		{
			v.pop_back ();
			if (v.empty ())
			{
				for (int j = cur + 1; j <= i - 1; ++j)
				{
					ret += S[j];
				}
			}
		}
	}
	return ret;
}
class Solution {
	public:
		static bool cmp (vector<int> &a, vector<int> &b)
		{
			return abs(a[0] - a[1]) > abs(b[0] - b[1]);
		}
		int twoCitySchedCost (vector<vector<int>> &costs)
		{
			int ans = 0;
			sort(costs.begin(), costs.end(), cmp);
			for (int i = 0; i < costs.size(); ++i)
			{
				cout<<costs[i][0]<<" "<<costs[i][1]<<endl;
			}
			int cntA = 0;
			int cntB = 0;
			for (int i = 0; i < costs.size(); ++i)
			{
				if (costs[i][0] < costs[i][1])
				{
					if (cntA != costs.size() / 2)
					{
						ans += costs[i][0];
						cntA += 1;
					}
					else ans += costs[i][1]; cntB += 1;
				}
				else
				{
					if (cntB != costs.size() / 2)
					{
						ans += costs[i][1];
						cntB += 1;
					}
					else
					{
						ans += costs[i][0];
						cntA += 1;
					}
				}
			}
			return ans;
		}
		static bool cell_cmp(vector<int> &a, vector<int> &b, int g_r0, int g_c0)
		{
			return (abs(a[0] - g_r0) + abs(a[1] - g_c0)) < (abs(b[0] - g_r0) + abs(b[1] - g_c0));
		}
		struct Node
		{
			int r,c;
			int r0,c0;
			bool operator <(Node a) const  
			{
				return abs(r - r0) + abs(c - c0) < abs(a.r - r0) + abs(a.c - c0);
			}
			Node(int x,int y,int x0,int y0)
			{
				r = x;
				c = y;
				r0 = x0;
				c0 = y0;
			}
		};
		vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
			vector<Node> v;
			for (int i = 0; i < R; ++i)
			{
				for (int j = 0; j < C; ++j)
				{
					Node n(i,j,r0,c0);
					v.push_back(n);
				}
			}
			sort(v.begin(),v.end());
			vector<vector<int>> res;
			for (auto item : v)
			{
				res.push_back({item.r, item.c});	
			}
			return res;
		}
		int sub_max(vector<int> &A, int L, int M)
		{
			int ans = 0;
			for (int i = 0; i < A.size(); ++i)	
			{
				// solve for 0->i-1
				int sum = 0;
				int ret = 0;
				int sum_m = 0;
				int ret_m = 0;
				if (i >= L)
				{
					for (int j = 0; j < i;++j)
					{
						sum += A[j];
						if (j >= L)
						{
							sum -= A[j-L];
							ret = max(ret, sum);
						}
					}
				}
				if (A.size() - i >= M)	
				{
					for (int j = i; j < A.size(); ++j)
					{
						sum_m += A[j];
						if (j - i >= M)
						{
							sum_m -= A[j - M];
							ret_m = max(ret_m, sum_m);	
						}
					}
				}
				ans = max(ret, ret_m);
				// solve for i->n-1
			}
			return ans;
		}
		int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
			return max(sub_max(A,L,M), sub_max(A,M,L));
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
	vector<int> v = {0,6,5,2,2,5,1,9,4};
	Solution tmp;
	cout<<tmp.maxSumTwoNoOverlap(v,1,2)<<endl;
	return 0;
}
