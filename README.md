# LeetCode
### Symmetric Tree

A brief thought is to determine whether the right child and left child have the same mid-order sequences?

But actually it's not such easy. But we can simplify this problem from a new perspective

**Comparing this tree with itself in a mirror way.** 

The problem is equal to ask: In what situation can a tree been seen as symmetrical? Well, we can start to traverse this tree from its left and right child. And it should satisfiy these conditions.

1. Mirror root's value should be the same.
2. Root's left child should be symmetrical to its right child.(Recursively)

### Level Order Traverse

Simple question, use `depth` variable to record currrent level. Traverse tree in middle order, push `val` to vector according to current leve.
When `depth > vector.size`, append a new empty vector.

## Solutions-Sorted&DP

### Climbing Stairs

This question equals to ask you if you are already at stair i-1 or i-2, you can step 1 or 2 steps relatively to the final stair i. Then this question can be splited to find ans(i) = ans(i-1) + ans(i-2).
There are few existing solutions:

1. Fibonacci Sequence.

2. Iteratively Computing c = a + b, a = b, b = c;

3. Let $Q_n$

   ![image-20190412140739396](https://ws2.sinaimg.cn/large/006tNc79ly1g1zthc9kjxj304j01vwea.jpg)

   We can compute $F_{n+1}=Q^n[0,0]$

   Initilize $Q_1 = [1,1;1,0]$,  We can compute $F^{n+1}$ by  $Q^n[0][0]$

   ![image-20190412141308086](https://ws1.sinaimg.cn/large/006tNc79ly1g1ztmzkzjxj30i001mq2v.jpg)

   Also, we can use quick power multipy method to accelerate above progression to $O(log(n))$ time.

## Weekly Contest 132

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







