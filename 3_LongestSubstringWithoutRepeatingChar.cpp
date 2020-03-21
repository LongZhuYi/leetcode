#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

/*
��һ˼·��
1��map������ֹ���char�Ͷ�Ӧ�±꣬��������ظ��ľʹ��ظ����±�+1��ʼ����һ���ظ�substring
   FIX1 һ��ʼ��ȫ�����map,���ǲ���ѽȫ������� iLeft+1 -> iRight �������ı�־Ҳû�ˡ�
   FIX2 map[c] = iRight ���Ҳ���У���Ϊ��iLeft+1 ֮ǰ�ı�־û�����
   FIX3 ������м�Ļ������� iRight - iLeft , ��������ǽ�β�Ļ��� iRight - iLeft + 1 FIX ��βӦ����iRight-iLeft����Ϊ iRight==s.size()
   HOW �ǵ���һ���ⷨ�ǲ��û��˵ģ�������ô�����������������أ�

 2��������map��¼char���±꣬Ȼ��iLeft,iRight�����´��ظ����±꿪ʼ

���õİ취����

todo�� 

���˵�˼·��

�����ܽ᣺
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

		if (iRight - iLeft > iSubLen) // FIX iRight - iLeft + 1, ��Ҫ+1ѽ����ΪiRight == s.size() 
		{
			iSubLen = iRight - iLeft; // FIX iRight - iLeft + 1, ��Ҫ+1ѽ����ΪiRight == s.size() 
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