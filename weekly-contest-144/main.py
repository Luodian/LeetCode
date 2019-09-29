from typing import List


class Solution:
	def defangIPaddr(self, address: str) -> str:
		return address.replace('.', '[.]')
	
	c = {}
	n = 0
	
	def lowbit(self, t: int):
		return (t & (-t))
	
	def add(self, t: int, d: int):
		while t <= self.n:
			self.c[t] += d
			t += self.lowbit(t)
	
	def sum(self, t: int):
		ret = 0
		while t > 0:
			ret += self.c[t]
			t -= self.lowbit(t)
		return ret
	
	def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
		self.n = n
		for i in range(1, n + 1):
			self.c[i] = 0
		
		for item in bookings:
			i, j, k = item
			self.add(i, k)
			self.add(j + 1, -k)
		
		ans = []
		for i in range(1, n + 1):
			ans.append(self.sum(i))
		return ans
	
	class TreeNode:
		def __init__(self, x):
			self.val = x
			self.left = None
			self.right = None
	
	forest = list()
	
	def dfs(self, cur: TreeNode, target: List[int]):
		if cur is None:
			return
		self.dfs(cur.left, target)
		self.dfs(cur.right, target)
		if cur.val in target:
			if cur.left:
				self.dfs(cur.left, target)
				self.forest.append(cur.left)
			if cur.right:
				self.dfs(cur.right, target)
				self.forest.append(cur.right)
		if cur.left and cur.left.val in target:
			cur.left = None
		if cur.right and cur.right.val in target:
			cur.right = None
		
	
	def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
		self.forest = []
		self.forest.append(root)
		self.dfs(root, to_delete)
		return self.forest


sample_func = Solution()
sample_input = [[1, 2, 10], [2, 3, 20], [2, 5, 25]]
ans = sample_func.corpFlightBookings(sample_input, 5)
print(ans)
