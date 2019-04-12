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
};

int main ()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
