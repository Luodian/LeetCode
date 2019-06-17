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
	
	def confusingNumber(self, N):
		"""
		:type N: int
		:rtype: bool
		"""
		# 如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。
		# 2, 3, 4, 5, 7 旋转 180° 后,得到的不是数字。
		
		mapping = {0: 0, 1: 1, 6: 9, 8: 8, 9: 6}
		invalid = [2, 3, 4, 5, 7]
		
		n = N
		tmp = 0
		res = list()
		while (n):
			n, tmp = divmod(n, 10)
			if tmp in invalid:
				return False
			res.append(mapping[tmp])
		
		res = res[::-1]
		r = 0
		for i, x in enumerate(res):
			r += 10 ** i * x
		
		return r != N
	
	def confusingNumberII(self, N: int) -> int:
		ans = []
		cnt = 0
		for i in range(1, int(1e9 + 1)):
			if self.confusingNumber(i):
				cnt += 1
				ans.append(cnt)
		
		return ans

# 199999999
sample_func = Solution()
sample_input = 100
ans = sample_func.confusingNumberII(sample_input)
file = open("a.txt")
file.write(ans)
file.close()
