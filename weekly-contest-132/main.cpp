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
#include <unordered_map>

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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val (x), left (NULL), right (NULL)
	{}
};

class Solution
{
	public:
	int game[1005];
	bool divisorGame (int N)
	{
		memset (game, 0, sizeof (game));
		game[2] = 1;
		game[3] = 0;
		for (int i = 4; i <= N; ++i)
		{
			bool flag = false;
			for (int j = 1; j < i; ++j)
			{
				if (i % j == 0)
				{
					if (game[i - j] == 0)
					{
						flag = true;
					}
				}
			}
			if (flag) game[i] = 1;
			else game[i] = 0;
		}
		return game[N];
	}
	int ans = 0;
	void findmaxdiff (TreeNode *root, TreeNode *child)
	{
		if (child == nullptr)
		{
			return;
		}
		else
		{
			if (abs (root->val - child->val) > ans)
			{
				ans = abs (root->val - child->val);
			}
			findmaxdiff (root, child->left);
			findmaxdiff (root, child->right);
		}
	}
	void dfs (TreeNode *root)
	{
		if (root == nullptr)
		{
			return;
		}
		else
		{
			findmaxdiff (root, root);
			findmaxdiff (root->left, root->left);
			findmaxdiff (root->right, root->right);
		}
	}
	int maxAncestorDiff (TreeNode *root)
	{
		dfs (root);
		return ans;
	}
	struct PairHash
	{
		size_t operator() (const pair<int, int> &p) const
		{
			size_t h1 = hash<int> () (p.first);
			size_t h2 = hash<int> () (p.second);
			return h1 ^ (h2 << 1);
		}
	};
	int longestArithSeqLength (vector<int> &A)
	{
		sort (A.begin (), A.end ());
		int n = A.size ();
		if (n <= 2) return n;
		unordered_map<pair<int, int>, int, PairHash> dp;
		int max_length = 2, diff = A[1] - A[0], first_num = A[0];
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = n - 1; j > i; --j)
			{
				pair<int, int> current (i, A[j] - A[i]);
				pair<int, int> previous (j, A[j] - A[i]);
				if (dp.find (previous) == dp.end ())
					dp[current] = 2;
				else
					dp[current] = dp[previous] + 1;
				if (dp[current] > max_length)
				{
					max_length = dp[current];
					diff = A[j] - A[i];
					first_num = A[i];
				}
			}
		}
		return max_length;
	}
	int longestArithSeqLength(vector<int>& A) {
		int n = A.size();
		std::vector<map<int, int>> counter(n);
		int ans = 0;
		for (int i = 1; i < n;++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int d = A[i] - A[j];
				counter[i][d] = counter[j][d] + 1;
				ans = max(ans,counter[i][d]);	
			}
		}
		return ans + 1;
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
