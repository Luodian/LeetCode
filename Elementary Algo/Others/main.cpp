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
    int hammingWeight(uint32_t n) {
        int cnt = 0;
		while(n != 0)
		{
			if (n % 2 == 1)
			{
				cnt += 1;
			}
			n = n >> 1;	
		}
		return cnt;
    }
	int hammingDistance(int x, int y) {
		int cnt = 0;
		while(x > 0 && y > 0)
		{
			if (((x % 2) ^ (y % 2)) == 1)
			{
				cnt += 1;
			}
			x = x >> 1;
			y = y >> 1;
		}
		while(x > 0)
		{
			if (x % 2 == 1)
			{
				cnt += 1;
			}
			x = x >> 1;
		}
		while(y > 0)
		{
			if (y % 2 == 1)
			{
				cnt += 1;
			}
			cnt += 1;
			y = y >> 1;
		}
		return cnt;
    }
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		if (numRows == 0)
		{
			return ans;
		}
		else
		{
			vector<int> cur_row{1};
			ans.push_back(cur_row);
			for (int i = 1; i < numRows; ++i )
			{
				vector<int> cur_row{1};
				vector<int> prev = ans[i-1];
				for (int j = 1; j <= i - 1; ++j)
				{
					cur_row.push_back(prev[j-1] + prev[j]);
				}
				cur_row.push_back(1);
				//cout<<cur_row.size()<<endl;
				ans.push_back(cur_row);
			}
			//cout<<ans.size()<<endl;
			return ans;
		}
    }
	bool isValid(string s) {
		std::stack<char> st;
		for (int i = 0; i < s.size(); ++i)
		{
			if (st.empty() == true)
			{
				st.push(s[i]);
			}
			else
			{
				if (s[i] == '(' && st.top() == ')')
				{
					st.pop();
				}
				else if (s[i] == '[' && st.top() == ']')
				{
					st.pop();
				}
				else if (s[i] == '{' && st.top() == '}')
				{
					st.pop();
				}
				else
				{
					cout<<s[i]<<endl;
				}
			}
		}
		return st.empty();
    }
	int missingNumber(vector<int>& nums) {
		
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
	a.generate(5);
	return 0;
}

