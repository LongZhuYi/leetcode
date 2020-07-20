#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

/*
第一思路：
1、中序遍历树，然后把遍历到的节点指针保存到vector中。顺序连接vector中的节点指针。
更好的办法？：

TODO：
别人的思路：
void flatten(TreeNode* root) {
	while(root!=NULL) {
		if(root->left==NULL)  root=root->right;//考虑下一节点
		else{
			TreeNode* pre=root->left;
			while(pre->right!=NULL) pre=pre->right;// 找左子树最右节点
			pre->right=root->right;//将原右子树接到左子树的最右节点
			root->right=root->left;//将左子树插到右子树处
			root->left=NULL;//令左子树为空
		}
	}
}
题型总结：
*/

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 class Tree
 {
 public:
	 Tree():m_root(nullptr){}
	 void Insert(int x);
	 void __InsertHelper(TreeNode*& ptr, int x);
	 //void Wark();
 //private:
	 TreeNode* m_root;
 };

 void Tree::__InsertHelper(TreeNode*& ptr, int x)
 {
	 if (ptr == nullptr)
	 {
		 ptr = new TreeNode(x);
	 }
	 else if (ptr->val > x)
	 {
		 __InsertHelper(ptr->left, x);
	 }
	 else {
		 __InsertHelper(ptr->right, x);
	 }
 }

 void Tree::Insert(int x)
 {
	 __InsertHelper(m_root, x);
 }

class Solution
{
public:

	void flatten1(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		if (root->left != nullptr)
		{
			TreeNode* prv = root->left;
			while (prv->right != nullptr)
			{
				prv = prv->right;
			}
			prv->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}

		flatten1(root->right);
	}

    void flatten(TreeNode* root)
    {
		if (root == nullptr)
		{
			return;
		}
		if (root->left != nullptr)
		{
			
		}
		flatten(root->right);
    }

    void rebuildTreeNode()
    {
        TreeNode* parentPtr = nullptr;
        for( auto& ptr : m_vecNodes )
        {
            if(parentPtr != nullptr)
            {
                parentPtr->right = ptr;
            }
            parentPtr = ptr;
            parentPtr->left = nullptr;
           // parentPtr->right = nullptr;
        }
    }

    void flattenHelper(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        m_vecNodes.emplace_back( root );
		flattenHelper(root->left);
		flattenHelper(root->right);
    }
private:
    vector<TreeNode*> m_vecNodes;
};

uint32_t GenCycleBeginTs(uint32_t beginTs)
{
	const static unsigned int DaySec = 24 * 3600;
	int unsigned tmpTs = beginTs;

	if ((tmpTs + 16 * 3600) % 24 * 3600 == 0)
	{
		return tmpTs;
	}
	
	int unsigned passSec = (tmpTs % DaySec);
	if (passSec > 0)
	{
		tmpTs = tmpTs +(DaySec - passSec) ;
	}
	tmpTs = tmpTs + 16 * 3600;

	if ( (tmpTs - 24 * 3600) > beginTs)
	{
		tmpTs = tmpTs - 24 * 3600;
	}

	return tmpTs;
}

int main()
{
	Tree t;
	vector<int> vecTmp = {10,5,8,9,12,13,8,7,6,1,2,3,4};
	for (auto i : vecTmp)
	{
		t.Insert(i);
	}

	Solution s;
	s.flatten1(t.m_root);

	return 0;
}