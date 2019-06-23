from typing import List


class Solution:
	def evalRPN(self, tokens: List[str]) -> int:
		st = []
		for item in tokens:
			if item is "+" or item is "-" or item is "*" or item is "/":
				second = st.pop()
				first = st.pop()
				if item is "+":
					st.append(first + second)
				elif item is "-":
					st.append(first - second)
				elif item is "*":
					st.append(first * second)
				elif item is "/":
					st.append(int(first / second))
			else:
				st.append(int(item))
		
		ans = st[-1]
		return ans
	
sample_func = Solution()
sample_input = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
ans = sample_func.evalRPN(sample_input)
print(ans)
