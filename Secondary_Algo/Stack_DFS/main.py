from typing import List


class Node:
	def __init__(self, val, neighbors):
		self.val = val
		self.neighbors = neighbors


class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None


class Solution:
	n, m = 0, 0
	dx = [-1, 0, 1, 0]
	dy = [0, -1, 0, 1]
	grid = list()
	
	def inside(self, i, j):
		if self.n > i >= 0 and self.m > j >= 0:
			return True
		else:
			return False
	
	def dfs(self, i: int, j: int) -> None:
		self.grid[i][j] = '0'
		for k in range(4):
			next_i, next_j = i + self.dx[k], j + self.dy[k]
			if self.inside(next_i, next_j) and self.grid[next_i][next_j] == '1':
				self.dfs(next_i, next_j)
		return
	
	def numIslands(self, grid: List[List[str]]) -> int:
		self.n = len(grid)
		if self.n == 0:
			return 0
		else:
			cnt = 0
			self.grid = grid
			self.m = len(grid[0])
			for i in range(self.n):
				for j in range(self.m):
					if self.grid[i][j] == '1':
						cnt += 1
						self.dfs(i, j)
			return cnt
	
	def build_graph(self, node):
		if node not in self.dic:
			self.dic[node] = copy_node = Node(node, [])
			for nb in node.neighbors:
				copy_node.neighbors.append(self.build_graph(nb))
		return self.dic[node]
	
	def cloneGraph(self, node: 'Node') -> 'Node':
		self.dic = {}
		return self.build_graph(node)
	
	def findTargetSumWays(self, nums: List[int], S: int) -> int:
		_sum = sum(nums)
		if abs(S) > _sum:
			return 0
		else:
			new_S = (S + _sum)
			if new_S % 2 == 0:
				new_S = int(new_S / 2)
				dp = [0 for i in range(new_S + 2)]
				dp[0] = 1
				for item in nums:
					for i in range(new_S, item - 1, - 1):
						dp[i] += dp[i - item]
				return dp[new_S]
			else:
				return 0
	
	ans = []
	
	def inorder(self, root: TreeNode):
		if root is None:
			return
		else:
			if root.left:
				self.inorder(root.left)
			self.ans.append(root.val)
			if root.right:
				self.inorder(root.right)
	
	def inorderTraversal(self, root: TreeNode) -> List[int]:
		self.ans = []
		self.inorder(root)
		return self.ans
	
	def decodeString(self, s: str) -> str:
		st, cnt, chs = [['', 1, '']], '', ''
		for c in s:
			if c.isdigit():
				cnt += c
			elif c.isalpha():
				chs += c
			elif c == ']':
				prev, prev_cnt, cur = st.pop()
				st[-1][-1] += (prev + prev_cnt * (cur + chs))
				chs = ''
			else:
				st.append([chs, int(cnt), ''])
				cnt = ''
				chs = ''
		
		return st.pop()[-1] + chs
	
	def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
		n, m = len(image), len(image[0])
		prev_color = image[sr][sc]
		dx = [1, -1, 0, 0]
		dy = [0, 0, -1, 1]
		visited = [[0 for i in range(m)] for i in range(n)]
		
		def dfs(i, j):
			if 0 <= i < n and 0 <= j < m and image[i][j] == prev_color and visited[i][j] == 0:
				image[i][j] = newColor
				visited[i][j] = 1
				for k in range(4):
					next_i, next_j = i + dx[k], j + dy[k]
					dfs(next_i, next_j)
			else:
				return
		
		dfs(sr, sc)
		return image


sample_func = Solution()
sample_input = [[0, 0, 0], [0, 0, 0]]
ans = sample_func.floodFill(sample_input, 0, 0, 2)
print(ans)
