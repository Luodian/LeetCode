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

bool valid (int a, int b)
{
	int temp = 0;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	if (a == 1) return 1;
	else return 0;
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int T;
	int n;
	cin >> T;
	int arr[15];
	while (T--)
	{
		mem(arr, 0);
		cin >> n;
		rep(i, 0, n)
		{
			cin >> arr[i];
		}
		int max_ans = 0;
		rep(i, 0, (1 << n))
		{
			bool flag = 1;
			std::vector<int> sub_set;
			sub_set.clear ();
			rep(j, 0, n)
			{
				if (i & (1 << j))
				{
					sub_set.push_back (arr[j]);
				}
			}
			rep(j, 0, int(sub_set.size()))
			{
				rep(k, 0, j)
				{
					if (!valid (sub_set[k], sub_set[j]))
					{
						flag = 0;
					}
				}
			}
			if (flag)
			{
				max_ans = std::max (max_ans, int (sub_set.size ()));
			}
		}
		cout << max_ans << endl;
	}
	return 0;
}
