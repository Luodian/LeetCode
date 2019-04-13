#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
	void merge (vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		vector<int> new_nums1;
		int i = 0;
		int j = 0;
		while (j < n && i < m)
		{
			if (nums1[i] < nums2[j])
			{
				new_nums1.push_back (nums1[i]);
				i++;
			}
			else
			{
				new_nums1.push_back (nums2[j]);
				j++;
			}
		}
		while (j < n)
		{
			new_nums1.push_back (nums2[j]);
			j++;
		}
		while (i < m)
		{
			new_nums1.push_back (nums1[i]);
			i++;
		}
		nums1 = new_nums1;
	}
	// Forward declaration of isBadVersion API.
	bool isBadVersion (int version);
	int firstBadVersion (int n)
	{
		int l = 1;
		int r = n;
		while (l < r)
		{
			int mid = (l + (r - l) >> 1);
			if (isBadVersion (mid))
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		return l;
	}
	int climbStairs(int n) {
		if (n <= 2)
		{
			return n;
		}
		int first = 1;
		int second = 2;
		int ans = 0;
		for(int i = 3; i <= n; ++i)	
		{
			ans = first + second;
			first = second;
			second = ans;
		}
		return ans;
    }
	int maxProfit(vector<int>& prices)
	{    
		int min_value = 0x3f3f3f3;
		int max_value = 0;
		int ans = 0;
		for (int i = 0; i < prices.size(); ++i)
		{
			if (prices[i] < min_value)
			{
				min_value = prices[i];
			}
			if (prices[i] - min_value > max_value)
			{
				max_value = prices[i] - min_value;
			}
		}
		return max_value;
    }
	int maxSubArray(vector<int>& nums)
	{
		int fn = 0;
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < nums.size(); ++i)
		{
			fn = max(nums[i], fn + nums[i]);
			ans = max(ans,fn);
		}
		return ans;
    }
	int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> mp;
		for (int i = 0;i < nums.size(); ++i)
		{
			mp[nums[i]].push_back(i);
		}
		int max_len = 0;
		for (auto &item : mp)
		{
			max_len = max(max_len, item.second.size());	
		}
		int min_ans = 0x3f3f3f3f;
		for (auto &item : mp)
		{
			if (item.second.size() == max_len)
			{
				min_ans = min(min_ans, item.second[-1] - item.second[0]);
			}
		}
		return min_ans;
    }
};

int main ()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
