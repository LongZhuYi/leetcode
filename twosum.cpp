/*
第一思路
1、遍历 136ms n^2
2、map保存需要的另一个值 8ms n
3、排序+查找 nlogn xx 忙活半天才发现排序把下标改变了，关键是还把mergeSort算法写错了。错了哪里自己看，囧~~~

更好的办法?


别人的思路


题型总结

 */

//遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
        {
        	for(int j=i+1; j<nums.size(); j++)
        	{
        		if( nums[i]+nums[j] == target )
        		{
        			return {i,j};
        		}
        	}
        }
        return {};
    }
};

//2
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int, std::vector<int>> mapNeed2IndexSet;
    	for(int i=0; i<nums.size(); i++)
    	{
    		auto iNeed = target-nums[i];
    		auto iter = mapNeed2IndexSet.find( iNeed );
    		if( iter != mapNeed2IndexSet.end() )
    		{
    			for( auto index : iter->second )
    			{
    				if( index != i )
    				{
    					return {i, index};
    				}
    			}
    		}
    		mapNeed2IndexSet[ nums[i] ].push_back( i );
    	}
    	return {};
    }
};

//3
class Solution3 {
public:
	void quickSort(vector<int>& nums)
	{

	}

	void mergeSortHelper(vector<int>& nums, int left, int right, int m)
	{
		int index = 0;
		vector<int> vecTemp;
		vecTemp.resize( right-left+1 );

		int i=left, j=m+1;
		for( ; i<=m && j<=right;  )
		{
			if( nums[i] > nums[j] )
			{
				vecTemp[index++] = nums[j++];
			}else{
				vecTemp[index++] = nums[i++];
			}
		}
		for( ; i<=m; i++ )
		{
			vecTemp[index++] = nums[i];
		}
		for(; j<=right; j++)
		{
			vecTemp[index++] = nums[j];
		}
		for( int i=left; i<=right; i++ )
		{
			nums[i] = vecTemp[ i-left ];
		}
	}

	void mergeSort(vector<int>& nums, int left, int right)
	{
		if( right - left <= 0 )
		{
			return;
		}

		if( right - left == 1 )
		{
			if( nums[left] > nums[right] )
			{
				swap(nums[left], nums[right]);
			}
			return;
		}

		int m = (right - left)/2; // xxx错误
		mergeSort(nums, left, m);
		mergeSort(nums, m+1, right);
		mergeSortHelper(nums, left, right, m);
	}

    vector<int> twoSum(vector<int>& nums, int target) {
    	mergeSort(nums, 0, nums.size() -1 );
    	for( int left=0, right=nums.size()-1; left<right;  )
    	{
    		int s = nums[left] + nums[right];
    		if( s == target )
    		{
    			return {left, right};
    		}else if( s > target )
    		{
    			right--;
    		}else
    		{
    			left++;
    		}
    	}
    	return {};
    }
};