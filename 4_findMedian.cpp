double findMidNum(vector<int>& nums1, vector<int>& nums2)
{
	int iAllCnt = nums1.size() + nums2.size();
	int iIndex = iAllCnt / 2;
	if ((iAllCnt & 1) == 0)
	{
		iIndex--;
	}
	auto iter1 = nums1.begin();
	auto iter2 = nums2.begin();

	while (true)
	{
		if ( (nums1.end() - iter1) >= iIndex/2 && (nums2.end() - iter2) >= iIndex/2 )
		{
			if (*(iter1 + iIndex / 2) < *(iter2 + iIndex / 2))
			{
				iter1 += iIndex / 2;
			}
			else {
				iter2 += iIndex / 2;
			}
		}
		else {
			break;
		}
		iIndex = iIndex - iIndex/2;
		if (iIndex <= 1)
		{
			break;
		}
	}

	double fSum = 0;
	for(int i= iIndex; i>=0; i--)
	{
		if (i == 0)
		{
			fSum += findMinNum(nums1, nums2, iter1, iter2);
			if ((iAllCnt & 1) == 0)
			{
				fSum += findMinNum(nums1, nums2, iter1, iter2);
				fSum = fSum / 2;
			}
		}
		findMinNum(nums1, nums2, iter1, iter2);
	}

	return fSum;
}
