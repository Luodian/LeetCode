/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val (x), left (NULL), right (NULL)
	{}
};
class Solution
{
	public:
	int maxDepth (TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left_height = maxDepth (root->left);
		int right_height = maxDepth (root->right);
		return max (left_height, right_height) + 1;
	}
	long res = -0x3f3f3f3f3f3f;
	bool isValidBST (TreeNode *root)
	{
		if (root == nullptr)
		{
			return true;
		}
		if (isValidBST (root->left))
		{
			if (res < root->val)
			{
				res = root->val;
				return isValidBST (root->right);
			}
		}
		return false;
	}
	bool mirror (TreeNode *left_tree, TreeNode *right_tree)
	{
		if (left_tree == nullptr && right_tree == nullptr)
		{
			return true;
		}
		else if (left_tree == nullptr || right_tree == nullptr)
		{
			return false;
		}
		else
		{
			return left_tree->val == right_tree->val && mirror (left_tree->left, right_tree->right)
			       && mirror (right_tree->left, left_tree->right);
		}
	}
	bool isSymmetric (TreeNode *root)
	{
		return mirror (root, root);
	}
	void walker (TreeNode *root, int depth, vector<vector<int>> &ans)
	{
		if (root == nullptr)
		{
			return;
		}
		if (depth >= ans.size ())
		{
			ans.push_back (vector<int> {});
		}
		ans[depth].push_back (root->val);
		walker (root->left, depth + 1, ans);
		walker (root->right, depth + 1, ans);
	}
	vector<vector<int>> levelOrder (TreeNode *root)
	{
		vector<vector<int>> ans;
		walker (root, 0, ans);
		return ans;
	}
	TreeNode *sortedArrayToBST (vector<int> &nums)
	{
		return sortedArrayToBST (nums, 0, nums.size() - 1);
	}
	TreeNode *sortedArrayToBST (vector<int> &nums, int l, int r)
	{
		if (r < l) return nullptr;
		int mid = l + ((r - l) >> 1);
		TreeNode *root = new TreeNode (nums[mid]);
		root->left = sortedArrayToBST (nums, l, mid - 1);
		root->right = sortedArrayToBST (nums, mid + 1, r);
		return root;
	}
};

void trimLeftTrailingSpaces (string &input)
{
	input.erase (input.begin (), find_if (input.begin (), input.end (), [] (int ch)
	{
		return !isspace (ch);
	}));
}

void trimRightTrailingSpaces (string &input)
{
	input.erase (find_if (input.rbegin (), input.rend (), [] (int ch)
	{
		return !isspace (ch);
	}).base (), input.end ());
}

TreeNode *stringToTreeNode (string input)
{
	trimLeftTrailingSpaces (input);
	trimRightTrailingSpaces (input);
	input = input.substr (1, input.length () - 2);
	if (!input.size ())
	{
		return nullptr;
	}
	
	string item;
	stringstream ss;
	ss.str (input);
	
	getline (ss, item, ',');
	TreeNode *root = new TreeNode (stoi (item));
	queue<TreeNode *> nodeQueue;
	nodeQueue.push (root);
	
	while (true)
	{
		TreeNode *node = nodeQueue.front ();
		nodeQueue.pop ();
		
		if (!getline (ss, item, ','))
		{
			break;
		}
		
		trimLeftTrailingSpaces (item);
		if (item != "null")
		{
			int leftNumber = stoi (item);
			node->left = new TreeNode (leftNumber);
			nodeQueue.push (node->left);
		}
		
		if (!getline (ss, item, ','))
		{
			break;
		}
		
		trimLeftTrailingSpaces (item);
		if (item != "null")
		{
			int rightNumber = stoi (item);
			node->right = new TreeNode (rightNumber);
			nodeQueue.push (node->right);
		}
	}
	return root;
}

int main ()
{
	string line;
	while (getline (cin, line))
	{
		TreeNode *root = stringToTreeNode (line);
		
		int ret = Solution ().maxDepth (root);
		
		string out = to_string (ret);
		cout << out << endl;
	}
	return 0;
}