#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

/*
第一思路：
1、map保存出现过的char和对应下标，如果出现重复的就从重复的下标+1开始查下一个重复substring
   FIX1 一开始是全部清掉map,但是不对呀全部清掉后 iLeft+1 -> iRight 这个区间的标志也没了。
   FIX2 map[c] = iRight 这个也不行，因为在iLeft+1 之前的标志没有清掉
   FIX3 如果是中间的话长度是 iRight - iLeft , 但是如果是结尾的话是 iRight - iLeft + 1 FIX 结尾应该是iRight-iLeft，因为 iRight==s.size()
   HOW 记得有一个解法是不用回退的，那是怎么解决上面两个问题的呢？

 2、笨方法map记录char的下标，然后iLeft,iRight都重新从重复的下标开始

更好的办法？：

todo： 

别人的思路：

题型总结：
MUST_MEDIUM
*/


//1
class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		map<uint8_t, int> mapChar2Index;
		int iSubLen = 0;
		int iLeft = 0, iRight = 0;
		while (iRight < s.size())
		{
			int c = s[iRight] - 'a';
			if (mapChar2Index.find(c) == mapChar2Index.end()) //FIX != 
			{
				mapChar2Index[c] = iRight;
			}else if (mapChar2Index[c] < iLeft){
				mapChar2Index[c] = iRight;
			}else{
				if ( (iRight - iLeft) > iSubLen) //FIX iRight - iLeft + 1
				{
					iSubLen = iRight - iLeft; //FIX iRight - iLeft + 1
				}
				iLeft = mapChar2Index[c] + 1;
				mapChar2Index[c] = iRight; //FIX mapChar2Index.clear() FIX mapChar2Index.erase( c ) 
			}
			iRight++;
		}

		if (iRight - iLeft > iSubLen) // FIX iRight - iLeft + 1, 不要+1呀，因为iRight == s.size() 
		{
			iSubLen = iRight - iLeft; // FIX iRight - iLeft + 1, 不要+1呀，因为iRight == s.size() 
		}

		return iSubLen;
	}
};

class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		return 0;
	}
};

int main()
{
	Solution1 s;

	cout << s.lengthOfLongestSubstring("qsbwxdqysuqiopkl") << endl;
	return 0;
}