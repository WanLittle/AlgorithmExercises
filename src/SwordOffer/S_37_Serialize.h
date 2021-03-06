#pragma once
#include "../BASE.h"

class S_37_Serialize : public BASE {
public:
	virtual void main()
	{
	}
    struct TreeNode
    {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) { }
    };

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp) 
            {
                out << tmp->val << " ";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else 
            {
                out << "null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val) 
        {
            if (val == "null") 
            {
                vec.push_back(NULL);
            }
            else 
            {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1; // i每往后移动一位，j移动两位，j始终是当前i的左子下标
        for (int i = 0; j < vec.size(); ++i)  // 肯定是j先到达边界，所以这里判断j < vec.size()
        {
            if (vec[i] == NULL) continue;   // vec[i]为null时跳过。
            if (j < vec.size())             // 当前j位置为i的左子树
                vec[i]->left = vec[j++];
            if (j < vec.size())             // 当前j位置为i的右子树
                vec[i]->right = vec[j++];
        }
        return vec[0];
    }

};