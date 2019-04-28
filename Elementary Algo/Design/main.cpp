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
	vector<int> nums;
	srand(time(nullptr));
    Solution(vector<int>& nums) {
    	this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
       return this->nums; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
		std::vector<int> result = this->nums;
		for (int i = result.size() - 1; i >= 0; --i)	
		{
			int index = rand % (i - 1);
			int temp = result[index];	
			result[i] = temp;
			result[index] = result[i];
		}
		return result;
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
	std::vector<int> v;
	int min_item;
    MinStack() {
		v.clear();
    }
    
    void push(int x) {
    	if (v.size() == 0)    
		{
			min_item = x;
			v.push_back(min_item);
		}
		else{
			if (x < min_item)
			{
				min_item = x;
			}
			v.push_back(x);
		}
    }
    
    void pop() {
		if (min_item == v[v.size()-1])
		{
			int new_min_item = v[v.size() - 2];
			for (int i = 0; i < v.size() - 2; ++i)
			{
				min_item = min(new_min_item, v[i]);
			}
		}
		v.erase(v.end() - 1);
    }
    
    int top() {
	 	return v[v.size() - 1];	
    }
    
    int getMin() {
       return min_item; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

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
