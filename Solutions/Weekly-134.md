# [Weekly Contest 134](https://leetcode-cn.com/contest/weekly-contest-134)

#### [1035. Uncrossed Lines](https://leetcode-cn.com/problems/uncrossed-lines/)

We can see this problem as find Longest Common Subsequence, we can use dp\[i][j] to represent current max value in A\[i] with B\[j].

Here's a simple logic to update dp\[i][j] 2d-array.

```cpp
int maxUncrossedLines (vector<int> &A, vector<int> &B)
{
	int len_a = A.size ();
	int len_b = B.size ();
	int dp[len_a + 5][len_b + 5];
	memset (dp, 0, sizeof (dp));
	for (int i = 0; i <= len_a; ++i)
	{
		for (int j = 0; j <= len_b; ++j)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[len_a][len_b];
}
```

#### [1036. Escape a Large Maze](https://leetcode-cn.com/problems/escape-a-large-maze/)

It's tricky, we can't simply dfs from source to target. But, here's a conclusion that you can use maximum 200 points to cover at most (200 - 1) * 200 / 2 areas in a 2-d matrix like image. So we can ensure we will reach the target point if we've tarversed more points than that value(the block stones didn't block our way).

![image-20190505180024704](https://ws1.sinaimg.cn/large/006tNc79ly1g2qlgljbuwj30j10fpwi0.jpg)

```cpp
    set<pair<int, int>> st;
    bool dfs_escape (int sx, int sy, int tx, int ty)
    {
        if ((sx == tx && sy == ty) || (st.size () > 20000))
        {
            return true;
        }
        else if (sx < 0 || sy < 0 || sx > 999999 || sy > 999999 || st.count (make_pair (sx, sy)) != 0)
        {
            return false;
        }
        st.insert (make_pair (sx, sy));
        return dfs_escape (sx - 1, sy, tx, ty) || dfs_escape (sx, sy - 1, tx, ty) || dfs_escape (sx + 1, sy, tx, ty)
               || dfs_escape (sx, sy + 1, tx, ty);
    }

    bool isEscapePossible (vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
    {
        st.clear ();
        for (auto &i : blocked)
        {
            st.insert (make_pair (i[0], i[1]));
        }
        return dfs_escape(source[0],source[1],target[0],target[1]) && dfs_escape(target[0], target[1], source[0], source[1]);
    }
```

