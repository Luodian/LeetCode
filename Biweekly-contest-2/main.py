from typing import List


class Solution:
	def fixedPoint(self, A: List[int]) -> int:
		ans = -1
		for ind, item in enumerate(A):
			if item == ind:
				ans = ind
				break
		
		return ans
	
	def sumOfDigits(self, A: List[int]) -> int:
		sorted_array = sorted(A)
		min_value = sorted_array[0]
		ans = 0
		while min_value != 0:
			ans += (min_value % 10)
			min_value = int(min_value / 10)
		
		if ans % 2 == 0:
			return 1
		else:
			return 0
	
	def highFive(self, items: List[List[int]]) -> List[List[int]]:
		stu_scores = dict()
		for item in items:
			stu_id = item[0]
			stu_score = item[1]
			if stu_id not in stu_scores.keys():
				stu_scores[stu_id] = [stu_score]
			else:
				stu_scores[stu_id].append(stu_score)
		
		ans = []
		for k in stu_scores.keys():
			if len(stu_scores[k]) < 5:
				sorted_v = sorted(stu_scores[k], reverse=True)
				ans.append([k, int(sum(sorted_v) / len(sorted_v))])
			else:
				sorted_v = sorted(stu_scores[k], reverse=True)[:5]
				ans.append([k, int(sum(sorted_v) / 5)])
		
		return ans
	
	def permute(self, S: str) -> List[str]:
		words = dict()
		group_id = 0
		i = 0
		while i < len(S):
			if S[i] == "{":
				j = i + 1
				while j < len(S) and S[j] != "}":
					if S[j] is not ',':
						if group_id not in words.keys():
							words[group_id] = [S[j]]
						else:
							words[group_id].append(S[j])
					j += 1
				group_id += 1
				i = j
			elif S[i] == "}":
				i += 1
			else:
				j = i
				while j < len(S) and S[j] != "{":
					if S[j] is not ',':
						if group_id not in words.keys():
							words[group_id] = S[j]
						else:
							words[group_id] += S[j]
					j += 1
				group_id += 1
				i = j
		
		st = []
		for item in words.keys():
			st.append(words[item])
		
		while len(st) != 1:
			top_item = st[-1]
			st.pop()
			second_item = st[-1]
			st.pop()
			sub_ans = []
			for item in second_item:
				for sub_item in top_item:
					sub_ans.append(item + sub_item)
			st.append(sub_ans)
		if isinstance(st[0], str):
			return sorted([st[0]])
		else:
			return sorted(st[0])
	
	cnt = 0
	V = [0, 1, 8, 6, 9]
	mp = {0: 0, 1: 1, 8: 8, 6: 9, 9: 6}
	
	
	def cache(func):
		from functools import wraps
		caches = {}
		@wraps(func)
		def wrap(*args):
			if args not in caches:
				caches[args] = func(*args)
			return caches[args]
		
		return wrap
	
	def dfs(self, cur: int, rev: int, base: int, N: int) -> None:
		if base > 1e9:
			return
		if cur > N:
			return
		
		if cur != rev:
			self.cnt += 1
		
		for item in self.V:
			if cur == 0 and item == 0:
				continue
			self.dfs(cur * 10 + item, self.mp[item] * base + rev, base * 10, N)
	
	dfs_with_cache = cache(dfs)
	
	def confusingNumberII(self, N: int) -> int:
		self.dfs_with_cache(0, 0, 1, N)
		return self.cnt


sample_func = Solution()
sample_input = 100000000
ans = sample_func.confusingNumberII(sample_input)
print(ans)
