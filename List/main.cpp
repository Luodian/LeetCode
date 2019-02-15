#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList (ListNode *head)
	{
		ListNode *new_head = nullptr;
		while (head)
		{
			ListNode *t = head->next;
			head->next = new_head;
			new_head = head;
			head = t;
		}
		return new_head;
	}
	bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == nullptr)
        {
            return false;
        }
        if (head->next == nullptr)
        {
            return true;
        }
        while(fast != nullptr)
        //cout<<slow->val<<endl;
        while(fast!=nullptr)
        {
        	slow = slow->next;
            cout<<slow->val<<endl;
        	fast = fast->next->next;
            cout<<fast->val<<endl;
        }
        ListNode *new_middle = reverseList(slow);
        cout<<new_middle->val<<endl;
        cout<<slow->val<<endl;
        while(head!=nullptr && new_middle!=nullptr && head->val == new_middle->val)
        {
            cout<<head->val<<" "<<new_middle->val<<endl;
        	head = head->next;
        	new_middle = new_middle->next;
        }
        if (head == nullptr && new_middle == nullptr)
        {
        	return true;
        }
        else
        {
        	return false;
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
