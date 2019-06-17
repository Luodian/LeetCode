#include <vector>
using namespace std;

class Solution {
	public:
	void duplicateZeros(vector<int>& arr) {
		vector<int> ans;
		for (auto item: arr)
		{
			if (item == 0)
			{
				ans.push_back (0);
				ans.push_back (0);
			}
			else
			{
				ans.push_back(item);
			}
		}
		for (int i = 0; i < arr.size(); ++i)
		{
			arr[i] = ans[i];
		}
	}
};