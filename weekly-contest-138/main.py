import collections
import queue
from typing import List


class Solution:
	def heightChecker(self, heights: List[int]) -> int:
		sorted_height = sorted(heights)
		cnt = 0
		for ind, item in enumerate(heights):
			sorted_item = sorted_height[ind]
			if item != sorted_item:
				cnt += 1
		
		return cnt
	
	def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
		ans = 0
		for ind, item in enumerate(customers):
			grp_item = grumpy[ind]
			if grp_item == 0:
				ans += item
		
		sad_customers = []
		for i in range(len(customers)):
			sad_customers.append(customers[i] if grumpy[i] == 1 else 0)
		
		gain = sum(sad_customers[:X])
		max_gain = gain
		for i in range(X, len(customers)):
			gain += sad_customers[i]
			gain -= sad_customers[i - X]
			max_gain = max(max_gain, gain)
		
		return ans + max_gain
	
	def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
		m = len(matrix)
		n = len(matrix[0])
		for row in matrix:
			for i in range(n - 1):
				row[i + 1] += row[i]
		
		res = 0
		for i in range(n):
			for j in range(i, n):
				c = collections.Counter({0: 1})
				cur_value = 0
				for k in range(m):
					cur_value += (matrix[k][j] - (matrix[k][i - 1] if i > 0 else 0))
					res += c[cur_value - target]
					c[cur_value] += 1
		
		return res
	
	def prevPermOpt1(self, A: List[int]) -> List[int]:
		idx = -1
		for i in range(len(A) - 1, 0, -1):
			if A[i] < A[i - 1]:
				idx = i - 1
				break
		
		max_value = -float("inf")
		swp_idx = -1
		if idx != -1:
			for i in range(idx + 1, len(A)):
				if A[i] < A[idx]:
					if A[i] > max_value:
						swp_idx = i
						max_value = A[i]
			
			A[idx], A[swp_idx] = A[swp_idx], A[idx]
		
		return A
	
	def lastStoneWeight(self, stones: List[int]) -> int:
		pque = queue.PriorityQueue()
		for item in stones:
			pque.put(item)
		
		while pque.qsize() >= 2:
			f_item = pque.get()
			l_item = pque.get()
			if f_item != l_item:
				pque.put(abs(f_item - l_item))
		
		if pque.qsize() == 1:
			return pque.get()
		elif pque.qsize() == 2:
			f_item = pque.get()
			l_item = pque.get()
			return abs(f_item - l_item)
		else:
			return 0


sample = Solution()
sample_matrix = [3, 1, 1, 3]
print(sample.prevPermOpt1(sample_matrix))
