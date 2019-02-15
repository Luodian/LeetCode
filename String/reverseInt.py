class Solution :
	def reverse ( self , x ) :
		"""
		:type x: int
		:rtype: int
		"""
		x = str(x)
		rev_x = x[::-1]
		flag = True
		if rev_x[-1] == '-':
			flag = False
			rev_x = rev_x[:-1]
		
		i = 0
		while i < len(rev_x):
			if rev_x[i] == '0':
				i += 1
			else:
				break
		rev_x = rev_x[i:]
		if not flag :
			rev_x = '-' + rev_x
		
		if rev_x == '':
			rev_x = '0'
		return int(rev_x)
	
p = Solution()

print (p.reverse(0))
		
	
		
		