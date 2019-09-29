from typing import List


class Solution:
	def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
		arr = sorted(arr)
		ans = []
		min_diff = int(2 * 1e6)
		for i in range(len(arr) - 1):
			if arr[i + 1] - arr[i] < min_diff:
				min_diff = arr[i + 1] - arr[i]
		
		for i in range(len(arr) - 1):
			if arr[i + 1] - arr[i] == min_diff:
				ans.append([arr[i], arr[i + 1]])
		
		return ans
	
	def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
		ans = set()
		ans_list = []
		for i in range(1, n + 1):
			if i * a not in ans:
				ans.add(i * a)
				ans_list.append(i * a)
			if i * b not in ans:
				ans.add(i * b)
				ans_list.append(i * b)
			if i * c not in ans:
				ans.add(i * c)
				ans_list.append(i * c)
		print(ans_list)
		return sorted(ans_list)[n - 1]
	
	def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
		from math import gcd
		
		def lcm(a, b):
			return a // gcd(a, b) * b
		
		def calc(m):
			return m // a + m // b + m // c - m // lcm(a, b) - m // lcm(a, c) - m // lcm(b, c) + m // lcm(lcm(a, b), c)
		
		l = 1
		r = 2000000000
		while l < r:
			m = (l + r) // 2
			if calc(m) >= n:
				r = m
			else:
				l = m + 1
		return l
	
	def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
		def ffind(a):
			if a == fa[a]:
				return a
			f = ffind(fa[a])
			fa[a] = f
			return f
		
		# 并查集的union函数
		def union(a, b):
			a = ffind(a)
			b = ffind(b)
			fa[a] = b
		
		import numpy as np
		n = len(s)
		fa = np.arange(n)
		for a, b in pairs:
			union(a, b)
		for i in range(n):
			ffind(i)
			
		unique_fa = np.unique(fa)
		fa_str = {x: '' for x in unique_fa}
		for i in range(n):
			fa_str[fa[i]] += s[i]
		
		for x in unique_fa:
			fa_str[x] = sorted(fa_str[x])
		
		f_cnt = {x: 0 for x in unique_fa}
		ans = ''
		for i in range(n):
			x = fa[i]
			ans += fa_str[x][f_cnt[x]]
			f_cnt[x] += 1
		
		return ans


sample_func = Solution()
s = "dcab"
pairs = [[0, 3], [1, 2], [0, 2]]
ans = sample_func.smallestStringWithSwaps(s, pairs)
print(ans)
