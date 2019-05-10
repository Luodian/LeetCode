# [Weekly Contest 132](https://leetcode-cn.com/contest/weekly-contest-132)

### Longest Arithmetic Sequence

This question asks us to find longest arithmetic subsequence. We can solve it using 2-d DP.

By using 2-d array counter\[i][diff] to represent current longest length in condition of index $i$ , diff = $diff$ .

```cpp
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
```