#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

/*
第一思路：
1、当前位 = 两个当前位和 + 第位进位

更好的办法？：

todo：

别人的思路：

题型总结：
链表操作
*/

/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output : 7 -> 0 -> 8
Explanation : 342 + 465 = 807.
*/

//Definition for singly-linked list.
 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr, *ptrTemp=nullptr;
		int add = 0;
		ListNode* node1 = l1, *node2 = l2;
		while (node1 != nullptr && node2 != nullptr)
		{
			int sum = node1->val + node2->val + add;
			add = sum / 10;
			sum = sum % 10;
			if ( nullptr == head )
			{
				head = new ListNode( sum );
				ptrTemp = head;
			}
			else {
				ptrTemp->next = new ListNode(sum);
				ptrTemp = ptrTemp->next;
			}
			node1 = node1->next;
			node2 = node2->next;
		}

		while (nullptr != node1)
		{
			int sum = node1->val + add;
			add = sum / 10;
			sum = sum % 10;
			ptrTemp->next = new ListNode(sum);
			ptrTemp = ptrTemp->next;

			node1 = node1->next;
		}

		while (nullptr != node2)
		{
			int sum = node2->val + add;
			add = sum / 10;
			sum = sum % 10;
			ptrTemp->next = new ListNode(sum);
			ptrTemp = ptrTemp->next;
			node2 = node2->next;
		}

		if (add > 0)
		{
			ptrTemp->next = new ListNode(add);
		}

		return head;
	}
};

ListNode* BuildList(const vector<int>& nums)
{
	ListNode* list1=nullptr, *tmp=nullptr;
	for (auto& n : nums)
	{
		if (nullptr == list1)
		{
			list1 = new ListNode(n);
			tmp = list1;
		}
		else
		{
			tmp->next = new ListNode(n);
			tmp = tmp->next;
		}
	}
	return list1;
}

void PrintList(ListNode* list)
{
	while ( nullptr != list )
	{
		std::cout << list->val << " ";
		list = list->next;
	}
	cout << endl;
}

void ReleaseList(ListNode* list)
{
	while (nullptr != list)
	{
		ListNode* t = list->next;
		delete list;
		list = t;
	}
}

int main2()
{
	Solution s;
	ListNode* list1=nullptr, *list2=nullptr;
	vector<int> nums = {1,2,5,6,7,9};

	list1 = BuildList(nums);
	std::reverse(nums.begin(), nums.end());
	list2 = BuildList(nums);

	ListNode* ans = s.addTwoNumbers( list1, list2 );

	PrintList(ans);

	//ReleaseList(ans);
	//ReleaseList(list1);
	//ReleaseList(list2);

	return 0;
}
