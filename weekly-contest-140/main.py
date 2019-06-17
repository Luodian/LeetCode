import queue
from typing import List


class Solution:
	def lastStoneWeight(self, stones: List[int]) -> int:
		pque = queue.PriorityQueue()
		for item in stones:
			pque.put(-1 * item)
		
		while pque.qsize() >= 2:
			f_item = pque.get()
			l_item = pque.get()
			if f_item != l_item:
				pque.put(-1 * abs(f_item - l_item))
		
		if pque.qsize() == 1:
			return -1 * pque.get()
		elif pque.qsize() == 2:
			f_item = pque.get()
			l_item = pque.get()
			return -1 * abs(f_item - l_item)
		else:
			return 0
	
	def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
		ans = []
		text = text.split(" ")
		for indx, item in enumerate(text):
			if indx <= len(text) - 3:
				if item == first and text[indx + 1] == second:
					ans.append(text[indx + 2])
		
		return ans
	
	def PowerSetsBinary(self, items):
		# generate all combination of N items
		N = len(items)
		# enumerate the 2**N possible combinations
		for i in range(2 ** N):
			combo = []
			for j in range(N):
				# test jth bit of integer i
				if (i >> j) % 2 == 1:
					combo.append(items[j])
			yield combo
	
	def numTilePossibilities(self, tiles: str) -> int:
		from itertools import permutations
		ans_set = set()
		for sub_set in self.PowerSetsBinary(tiles):
			l = permutations(sub_set)
			for x in l:
				short = ''.join(x)
				if short != '':
					ans_set.add(short)
		
		return len(ans_set)
	
	class TreeNode:
		def __init__(self, x):
			self.val = x
			self.left = None
			self.right = None
	
	def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
		if not root:
			return None
	
	def smallestSubsequence(self, text: str) -> str:
		last = {c: i for i, c in enumerate(text)}
		
		stack = []
		for indx, ch in enumerate(text):
			if ch in stack:
				continue
			while stack and ch < stack[-1] and last[stack[-1]] > indx:
				stack.pop()
			stack.append(ch)
		
		return "".join(stack)


sample = Solution()
sample_input = "cdadabcc"
ans = sample.smallestSubsequence(sample_input)
print(ans)
