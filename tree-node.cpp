#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
       T data;
       vector<TreeNode*> children;
       TreeNode(T data)
       {
        this->data=data;
       }
};
template<typename T>
void printTree( TreeNode<T> *root)              // here leafNode act as the base case as we hit the leaf we backtrack.
{    
     
     if(root==NULL)
     {
        return;
     }
     int childs=root->children.size();
     cout<<root->data<<" : ";
     
     for(int i=0;i<childs;i++)
     {
       cout<<root->children[i]->data<<" ";
     }
     cout<<endl;
     for(int i=0;i<childs;i++)
     {
        printTree(root->children[i]);
     }
}
int main()
{
    
    TreeNode<int> *root=new TreeNode<int>(1);
    TreeNode<int> *n1=new TreeNode<int>(2);
    TreeNode<int> *n2=new TreeNode<int>(3);
     root->children.push_back(n1) ;
     root->children.push_back(n2);
     printTree(root);
     return 0;
}