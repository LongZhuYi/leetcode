/*
��һ˼·
1����NС��������һ����ʹ������
2��ð���㷨

���õİ취?

TODO
priority_queue��ʹ��
priority_queue<int, vector<int>, std::less<int>> que( vec.begin(), vec.end() );

���˵�˼·

�����ܽ�

*/



#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
	vector<int> min = { INT_MAX,INT_MAX, INT_MAX };

	for (int i = 0; i < nums.size(); i++)
	{
		if (min[0] > nums[i])
		{
			min[2] = min[1];
			min[1] = min[0];
			min[0] = nums[i];
		}
		else if (min[1] > nums[i])
		{
			min[2] = min[1];
			min[1] = nums[i];
		}
		else if (min[2] > nums[i])
		{
			min[2] = nums[i];
		}
	}
	return min[2];
}

//ð��
int NthSmallest(vector<int>& nums, int m)
{
	for (int index = 0; index < m; index++)
	{
		for (int i = index + 1; i < nums.size(); i++)
		{
			if (nums[index] > nums[i])
			{
				swap(nums[index], nums[i]);
			}
		}
	}
	return nums[m - 1];
}

#include <queue>

int NthSmallest2(vector<int>& nums, int m)
{
	priority_queue <int, vector<int>, less<int> >  heap;
	for (int i = 0; i < nums.size(); i++)
	{
		if (heap.size() < m)
		{
			heap.push(nums[i]);
		}
		else if (heap.top() > nums[i])
		{
			heap.pop();
			heap.push(nums[i]);
		}
	}
	return heap.top();
}