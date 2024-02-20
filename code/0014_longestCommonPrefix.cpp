#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

struct Tree
{
    Tree* child[26];
    int childnums;
    int indexnums;
    char value;
    Tree()
    {
        childnums = 0;
        indexnums = 0;
        for(int i = 0; i < 26; i++) child[i] = nullptr;
    };
    void createChild(char x)
    {
        this->child[x-'a'] = new Tree();
        this->childnums += 1;
        if(childnums == 1) value = x;
    };

};


string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    Tree* root = new Tree();
    Tree* p;
    for (string str : strs)
    {
        p = root;
        p->indexnums += 1;
        for (int i = 0; i < str.length(); i++)
        {
            if (p->child[str[i] - 'a'] == nullptr) p->createChild(str[i]);
            p = p->child[str[i] - 'a'];
            p->indexnums += 1;
        }
    }
    while (true)
    {
        if(root->childnums > 1 || root->childnums == 0) break;
        if(root->child[root->value - 'a']->indexnums != strs.size()) break;
        ans += root->value;
        root = root->child[root->value - 'a'];
    }
    return ans;
}

int main()
{
    vector<string> strs = {"a", "ab"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}