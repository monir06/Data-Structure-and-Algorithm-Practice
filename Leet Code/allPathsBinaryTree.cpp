#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
#include <iomanip>

vector<string> v;
void allPaths(TreeNode* root,string& s)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        int l=s.length();
        if(s=="")
            s=to_string(root->val);
        else
            s=s+"->"+to_string(root->val);
        v.push_back(s);
        s=s.substr(0,l);
        return;
        
    }
    int le=s.length();
    if(s=="")
        s=to_string(root->val);
    else
        s=s+"->"+to_string(root->val);
    //v.push_back(s);
    allPaths(root->left,s);
    allPaths(root->right,s);
    s=s.substr(0,le);
    
}

vector<string> binaryTreePaths(TreeNode* root) {
    string s="";
    allPaths(root,s);
    return v;
}