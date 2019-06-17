from typing import List


class Solution:
	def duplicateZeros(self, arr: List[int]) -> None:
		"""
		Do not return anything, modify arr in-place instead.
		"""
		l = len(arr)
		ans = []
		for item in arr:
			if item == 0:
				ans.append(0)
				ans.append(0)
			else:
				ans.append(item)
		
		arr = ans[:l]
		print(arr)
	
	def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
		from collections import defaultdict
		data = []
		for i in range(len(values)):
			data.append([values[i], labels[i]])
		
		data = sorted(data, key=lambda x: x[0], reverse=True)
		label_mp = defaultdict(int)
		ans = 0
		cnt = 0
		for item in data:
			value, label = item
			if label_mp[label] < use_limit and cnt < num_wanted:
				ans += value
				label_mp[label] += 1
				cnt += 1
		
		return ans
	
	def bfs(self, grid, start, goal, width, height):
		from collections import deque
		queue = deque([[start]])
		seen = set([start])
		x, y = start
		if grid[x][y] == 1:
			return -1
		min_path = -1
		while queue:
			path = queue.popleft()
			x, y = path[-1]
			if (x, y) == goal:
				min_path = len(path)
			for x2, y2 in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1), (x + 1, y + 1), (x - 1, y - 1), (x + 1, y - 1), (x - 1, y + 1)):
				if 0 <= x2 < width and 0 <= y2 < height and grid[x2][y2] != 1 and (x2, y2) not in seen:
					queue.append(path + [(x2, y2)])
					seen.add((x2, y2))
		
		return min_path
	
	def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
		n = len(grid)
		ans = self.bfs(grid, (0, 0), (n - 1, n - 1), n, n)
		return ans
	
	def shortestSuperstring(self, A):
		"""
		:type A: List[str]
		:rtype: str
		"""
		
		def findOverlappingPair(s1, s2):
			max_overlap_len = float("-inf")
			n = min(len(s1), len(s2))
			res = ''
			for i in range(1, n + 1):
				if s1.endswith(s2[:i]):
					if max_overlap_len < i:
						max_overlap_len = i
						res = s1 + s2[i:]
			for i in range(1, n + 1):
				if s2.endswith(s1[:i]):
					if max_overlap_len < i:
						max_overlap_len = i
						res = s2 + s1[i:]
			
			return max_overlap_len, res
		
		A_len = len(A)
		
		while A_len != 1:
			p, q = -1, -1
			res = ''
			max_val = float("-inf")
			for i in range(A_len):
				for j in range(i + 1, A_len):
					r, tmp_res = findOverlappingPair(A[i], A[j])
					if max_val < r:
						max_val = r
						res = tmp_res
						p = j
						q = i
			A_len -= 1
			if max_val == float("-inf"):
				A[0] = A[0] + A[A_len]
			else:
				A[p] = res
				A[q] = A[A_len]
		
		return A[0]
	
	def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
		short_str, long_str = "", ""
		if len(str1) < len(str2):
			short_str = str1
			long_str = str2
		else:
			short_str = str2
			long_str = str1
		
		if short_str in long_str:
			return long_str
		else:
			A = []
			A.append(short_str)
			A.append(long_str)
			ans = self.shortestSuperstring(A)
			return ans
		
		
		

sample_func = Solution()
# [[1,0,0],[1,1,0],[1,1,0]]
str1 = "abac"
str2 = "cab"
sample_ans = sample_func.shortestCommonSupersequence(str1, str2)
print(sample_ans)
