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
    vector<string> fizzBuzz(int n) {
		std::vector<string> v;
        for (int i = 1; i <= n; ++i)
		{
			if (i % 3 == 0 && i % 15 != 0)
			{
				v.push_back("Fizz");
			}
			else if (i % 5 == 0 && i % 15 != 0)
			{
				v.push_back("Buzz");
			}
			else if (i % 15 == 0)
			{
				v.push_back("FizzBuzz");
			}
			else
			{
				v.push_back(to_string(i));
			}
		}
		return v;
    }
	int countPrimes(int n) {
        bool flag[n+5];
		memset(flag,1,sizeof(flag));
		int sqrt_n = sqrt(n + 0.5);
		for (int i = 4; i <= n; i += 2)
		{
			flag[i] = 0;
		}
		for (int i = 2; i <= sqrt_n; ++i)
		{
			if (flag[i])
			{
				for (int j = i * i; j <= n; j += 2 * i)
				{
					flag[j] = 0;
				}
			}
		}
		int count = 0;
		for (int i = 2; i < n; ++i)
		{
			if (flag[i]){
				count ++;
			}
		}
		return count;
    }
	bool isPowerOfThree(int n) {
        int max_item = pow(3,20);
		return n != 0 && max_item % n == 0;
    }
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
	int romanToInt(string s) {
		int ans = 0;
		std::map<char, int> mp;
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;
		int i = 0;	
		
		while(i < s.size())
		{
			if (i == s.size())
			{
				ans += mp[s[i]];
			}
			else if ((s[i] != 'I' && s[i] != 'X' && s[i] != 'C'))	
			{
				ans += mp[s[i]];
			}
			else
			{
				if (s[i] == 'I')
				{
					if (s[i+1] == 'X' || s[i+1] == 'V')
					{
						ans += (mp[s[i+1]] - mp[s[i]]);
						i += 1;
					}
					else
					{
						ans += mp[s[i]];
					}
				}
				else if (s[i] == 'X')
				{
					if (s[i+1] == 'L' || s[i+1] == 'C')
					{
						ans += (mp[s[i+1]] - mp[s[i]]);
						i += 1;
					}
					else
					{
						ans += mp[s[i]];
					}
				}
				else if (s[i] == 'C')
				{
					if (s[i+1] == 'D' || s[i+1] == 'M')
					{
						ans += (mp[s[i+1]] - mp[s[i]]);
						i += 1;
					}
					else
					{
						ans += mp[s[i]];
					}
				}
			}
			i += 1;
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
		
