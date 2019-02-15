from collections import defaultdict


class Solution :
	def isValidSudoku ( self , board ) :
		"""
		:type board: List[List[str]]
		:rtype: bool
		"""
		flag = True
		for i in range ( 9 ) :
			vis = defaultdict ( int )
			for j in range ( 9 ) :
				if board [ i ] [ j ] == '.' :
					continue
				elif vis [ int ( board [ i ] [ j ] ) ] == 0 :
					vis [ int ( board [ i ] [ j ] ) ] = 1
				else :
					flag = False
					break
		
		for j in range ( len ( board ) ) :
			vis = defaultdict ( int )
			for i in range ( len ( board [ j ] ) ) :
				if board [ i ] [ j ] == '.' :
					continue
				elif vis [ int ( board [ i ] [ j ] ) ] == 0 :
					vis [ int ( board [ i ] [ j ] ) ] = 1
				else :
					flag = False
					break
		
		for i in range ( 0 , 9 , 3 ) :
			for j in range ( 0 , 9 , 3 ) :
				vis = defaultdict ( int )
				for ii in range ( i , i + 3 ) :
					for jj in range ( j , j + 3 ) :
						if board [ ii ] [ jj ] == '.' :
							continue
						elif vis [ int ( board [ ii ] [ jj ] ) ] == 0 :
							vis [ int ( board [ ii ] [ jj ] ) ] = 1
						else :
							flag = False
							break
		return flag


board = [ [ "." , "." , "." , "." , "5" , "." , "." , "1" , "." ] ,
          [ "." , "4" , "." , "3" , "." , "." , "." , "." , "." ] ,
          [ "." , "." , "." , "." , "." , "3" , "." , "." , "1" ] ,
          [ "8" , "." , "." , "." , "." , "." , "." , "2" , "." ] ,
          [ "." , "." , "2" , "." , "7" , "." , "." , "." , "." ] ,
          [ "." , "1" , "5" , "." , "." , "." , "." , "." , "." ] ,
          [ "." , "." , "." , "." , "." , "2" , "." , "." , "." ] ,
          [ "." , "2" , "." , "9" , "." , "." , "." , "." , "." ] ,
          [ "." , "." , "4" , "." , "." , "." , "." , "." , "." ] ]
a = Solution ( )
print ( a.isValidSudoku ( board ) )
