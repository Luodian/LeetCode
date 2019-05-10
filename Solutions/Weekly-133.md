# [Weekly Contest 133](https://leetcode-cn.com/contest/weekly-contest-133)

#### [Two City Scheduling](https://leetcode-cn.com/contest/weekly-contest-133/problems/two-city-scheduling/)

Actually, in order to save more, we need to rearrange the array by the largest difference. We should overload `cmp` function like this.

```cpp
	static bool cmp (vector<int> &a, vector<int> &b)
	{
		return abs(a[0] - a[1]) > abs(b[0] - b[1]);
	}
```

Then, we obtain the array by largest difference item first, and we count each item to determine people $i$ should go to city 1 or city 2. If city 1 reach its maximum, then we send people $i$ to city 2, and vice versa.

#### [Maximum Sum of Two Non-Overlapping Subarrays](https://leetcode-cn.com/contest/weekly-contest-133/problems/maximum-sum-of-two-non-overlapping-subarrays/)

Enumerate L and M's place. Be careful of add-by-one error. 

Time complexity $O(len(A) * M * L)$

