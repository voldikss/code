// #include "../include/global.hpp"
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    string val;
    char type;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string s) : val(s), type(' '), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入一个长度为 2^N (1<=N<=10 的整数) 的字符串，字符串由{0,1}构成。返回由 BPG 树后续遍历得到的字符串。
     * @param s string字符串 一个长度为 2^N (1 <= N <= 10 的整数) 的字符串，字符串由{0,1}构成
     * @return string字符串
     */
    string bpg(string s) {
        TreeNode* root = new TreeNode(s);
        root->type = 'G';
        build(root);
        // cout << root << endl;
        string res;
        print(root, res);
        return res;
    }

    void build(TreeNode* root) {
        if (root->val.size() == 1) return;
        string& str = root->val;
        int n = str.size();
        TreeNode* left = new TreeNode(string(str.substr(0, n / 2)));
        TreeNode* right = new TreeNode(str.substr(n / 2, n / 2));
        if (root->type == 'B' || root->type == 'P') {
            left->type = root->type;
            right->type = root->type;
        } else {
            int has0 = false;
            int has1 = false;
            for (const char ch : left->val) {
                if (ch == '0') {
                    if (!has0) has0 = true;
                } else {
                    if (!has1) has1 = true;
                }
            }
            if (has0 && has1)
                left->type = 'G';
            else if (has0)
                left->type = 'B';
            else
                left->type = 'P';
            // right
            has0 = false;
            has1 = false;
            for (const char ch : right->val) {
                if (ch == '0') {
                    if (!has0) has0 = true;
                } else {
                    if (!has1) has1 = true;
                }
            }
            if (has0 && has1)
                right->type = 'G';
            else if (has0)
                right->type = 'B';
            else
                right->type = 'P';
        }
        root->left = left;
        root->right = right;
        build(root->left);
        build(root->right);
    }

    void print(const TreeNode* root, string& res) {
        if (!root) return;
        print(root->left, res);
        print(root->right, res);
        res.push_back(root->type);
    }
};

int main(int argc, char** argv) {
    Solution s;
    string str = "10001101";
    auto res = s.bpg(str);
    cout << res << endl;
    return 0;
}
