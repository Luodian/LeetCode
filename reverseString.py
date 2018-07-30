class Solution :
	def reverseString ( self , s ) :
		"""
		:type s: str
		:rtype: str
		"""
		return s[::-1]


s = "hello"
p = Solution ( )
print ( p.reverseString ( s ) )
