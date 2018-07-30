from collections import defaultdict

class Solution :
	def isValidSudoku ( self , board ) :
		"""
		:type board: List[List[str]]
		:rtype: bool
		"""
		flag = True
		for i in range(len(board)):
			vis = defaultdict(int)
			for j in range(len(board[i])):
				if board[i][j] == '.':
					continue
				elif vis[board[i][j]] == 0:
					vis[board[i][j]] = 1
				else:
					flag = False
					break
		
		for j in range(len(board)):
			vis = defaultdict(int)
			for i in range(len(board[j])):
				if board[i][j] == '.':
					continue
				elif vis[board[i][j]] == 0:
					vis[board[i][j]] = 1
				else:
					flag = False
					break
		
		for i in range(0,3,9):
			for j in range(0,3,9):
				vis = defaultdict(int)
				for ii in range(i,i+3):
					for jj in range(j,j+3):
						if board [ ii ] [ jj ] == '.' :
							continue
						elif vis [ board [ i ] [ j ] ] == 0 :
							vis [ board [ i ] [ j ] ] = 1
						else :
							flag = False
							break
		return flag
			
