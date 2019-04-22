import numpy as np

class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
    	data = np.array(costs)
    	idex=np.lexsort([data[:,1], -1*data[:,0]])
    	sorted_data = data[idex, :]
    	print(sorted_data)
    	ans = 0
    	N = costs.size() / 2
    	for i in range(N):
    		ans += costs[i][0]
    	for i in range(N,costs.size()):
    		ans += costs[i][1]

    	return ans
