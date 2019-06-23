from typing import List


class Solution:
	def sampleStats(self, count: List[int]) -> List[float]:
		convert = []
		common = 0
		indx_max = -1
		ans = 0
		for ind, item in enumerate(count):
			if item != 0:
				if item > indx_max:
					indx_max = item
					common = ind
				
				for i in range(item):
					convert.append(ind)
					ans += ind
		
		min_value = float(convert[0])
		max_value = float(convert[-1])
		common = float(common)
		avg_value = ans / len(convert)
		if len(convert) % 2 == 0:
			mid_value = convert[int(len(convert) / 2)] + convert[int(len(convert) / 2) - 1]
			mid_value /= 2
		else:
			mid_value = float(convert[int(len(convert) / 2)])
		return [min_value, max_value, avg_value, mid_value, common]
	
	def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
		trips_with_flag = [item.append(True) for item in trips]
		trips = sorted(trips, key=lambda x:x[1])
		cur_pas = trips[0][0]
		for ind, item in enumerate(trips):
			if ind == 0:
				continue
			else:
				cur_pas += item[0]
				for j in range(ind - 1, -1, -1):
					if item[1] >= trips[j][2] and trips[j][3] == True:
						cur_pas -= trips[j][0]
						trips[j][3] = False
				if cur_pas > capacity:
					return False
				
		return True
				
			
		
	

sample_func = Solution()
# sample_input = [[3,2,7],[3,7,9],[8,3,9]]
sample_input = [[7,5,6],[6,7,8],[10,1,6]]
# sample_input = [[2,1,5],[3,5,7]]
# sample_input = [[3,2,8],[4,4,6],[10,8,9]]
ans = sample_func.carPooling(sample_input, 16)
print(ans)
