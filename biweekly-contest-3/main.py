from typing import List


class Solution:
	def twoSumLessThanK(self, A: List[int], K: int) -> int:
		ans = K + 5
		flag = False
		for i in range(len(A)):
			for j in range(i + 1, len(A)):
				if 0 < K - (A[i] + A[j]) < ans:
					flag = True
					ans = K - (A[i] + A[j])
		
		if flag:
			return K - ans
		else:
			return -1
	
	def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
		if K > len(S):
			return 0
		else:
			cnt = 0
			for i in range(len(S) - K + 1):
				prep = S[i:i + K]
				if len(prep) == len(set(prep)):
					print(prep)
					cnt += 1
			return cnt
	
	# visited = []
	# flag = False
	# def dfs(self, relations, cur, target):
	# 	if sum(self.visited) == target - 1:
	# 		self.flag = True
	# 	self.visited[cur] = 1
	# 	for next in relations[cur]:
	# 		if self.visited[next] == 0:
	# 			self.dfs(relations, next, target)
	#
	# def earliestAcq(self, logs: List[List[int]], N: int) -> int:
	# 	relations = {}
	# 	for i in range(N):
	# 		relations[i] = set()
	# 		relations[i].add(i)
	#
	# 	logs = sorted(logs, key=lambda x: x[0])
	# 	for i in range(len(logs)):
	# 		timestamp, first, second = logs[i]
	# 		relations[first].add(second)
	# 		relations[second].add(first)
	# 		self.visited = [0 for i in range(N)]
	# 		self.flag = False
	# 		self.dfs(relations, first, N)
	# 		if self.flag:
	# 			return timestamp
	#
	# 	return -1
	
	visited = []
	n, m = 0, 0
	ans = 0
	dx = [-1, 1, 0, 0]
	dy = [0, 0, -1, 1]
	A = []
	
	def inside(self, i, j):
		if 0 <= i < self.n and 0 <= j < self.m:
			return True
		else:
			return False
	
	def tdfs(self, i, j, cur_ans):
		if i == self.n - 1 and j == self.m - 1:
			self.ans = max(self.ans, cur_ans + self.A[i][j])
		else:
			self.visited[i][j] = 1
			for k in range(4):
				next_i, next_j = i + self.dx[k], j + self.dy[k]
				if self.inside(next_i, next_j) and self.visited[next_i][next_j] == 0:
					self.tdfs(next_i, next_j, cur_ans + self.A[i][j])
			self.visited[i][j] = 0
	
	def maximumMinimumPath(self, A: List[List[int]]) -> int:
		self.n, self.m = len(A), len(A[0])
		self.visited = A
		self.A = A
		for i in range(self.n):
			for j in range(self.m):
				self.visited[i][j] = 0
		
		self.tdfs(0, 0, 0)
		return self.ans


sample_func = Solution()
sample_input = [[5, 4, 5], [1, 2, 6], [7, 4, 6]]
ans = sample_func.maximumMinimumPath(sample_input)
print(ans)
