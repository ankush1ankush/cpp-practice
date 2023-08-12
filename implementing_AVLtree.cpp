#include<bits/stdc++.h>
using namespace std;
class BTNode{
    public:
    int data;
    int height;
    int BF;
    BTNode *left;
    BTNode *right;
    BTNode(int data)
    {
      this->data=data;
      left=NULL;
      right=NULL;
      BF=0;
      height=0;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }

};
class AVL{
   BTNode *BTroot;
   void print(BTNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    cout << root->data << " : ";
    if (root->left != NULL)
    {
      cout << root->left->data << " , ";
    }
    if (root->right != NULL)
    {
      cout << root->right->data;
    }
    cout << endl;
    print(root->left);

    print(root->right);
  }
   int getheight(BTNode *root)
   {
      if(root==NULL)
      {
        return 0;
      }
      return root->height;
   }
   BTNode *insert(BTNode *root,int data)
   {
      if(root==NULL)
      {
         BTNode *n=new BTNode(data);

         return n;
      }
      else if(root->data>data)
      {
        root->left=insert(root->left,data);
       
       
      }
      else if(root->data<data)
      {
        root->right=insert(root->right,data);
        
      }
      else{
        return root;
      }

      // height of root
        int lh=0;
        int rh=0;
        if(root->left!=NULL)
        {
            lh=getheight(root->left);
        }
        if(root->right!=NULL)
        {
            rh=getheight(root->right);
        }
        root->BF=lh-rh;
        root->height=1+max(lh,rh);
        
      if((root->BF>1)&&(data<root->left->data))
      {
        BTNode *tem=root;
        root=root->left;
        tem->left=root->right;
        root->right=tem;
        tem->height=1+max(getheight(tem->left),getheight(tem->right)); // updating height of right node of new root; 
        tem->BF=getheight(tem->left)-getheight(tem->right);            // updating BF of left node of new root;
        root->height=1+max(getheight(root->left),getheight(root->right));// updating height of root node; 
        root->BF=getheight(root->left)-getheight(root->right);     //updating BF of root node; 
        
      }
      if((root->BF>1)&&(root->left->data<data))
      {
        BTNode *tem1=root->left; // left child
        BTNode *tem2=root->left->right; // left right child of imbalance node;
        root->left=tem2->right;   
        tem1->right=tem2->left;
        tem2->left=tem1;
        tem2->right=root;     // now tem2 is the new root;
        tem1->height=1+max(getheight(tem1->left),getheight(tem1->right));
        tem1->BF=getheight(tem1->left)-getheight(tem1->right);
        tem2->height=1+max(getheight(tem2->left),getheight(tem2->right));
        tem2->BF=getheight(tem2->left)-getheight(tem2->right);
        root->height=1+max(getheight(root->left),getheight(root->right));
        root->BF=getheight(root->left)-getheight(root->right);
        root=tem2;
      }
      if((root->BF<-1)&&(root->right->data<data))
      {
        BTNode *tem=root;
        root=root->right;
        tem->right=root->left;
        root->left=tem;
        tem->height=1+max(getheight(tem->left),getheight(tem->right)); // updating height of right node of new root; 
        tem->BF=getheight(tem->left)-getheight(tem->right);            // updating BF of left node of new root;
        root->height=1+max(getheight(root->left),getheight(root->right));// updating height of root node; 
        root->BF=getheight(root->left)-getheight(root->right);     //updating BF of root node; 
      }
      if((root->BF<-1)&&(root->right->data>data))
      {
       
        BTNode *tem1=root->right; // right child
        BTNode *tem2=root->right->left; // right left child of imbalance node;
        root->right=tem2->left;   
        tem1->left=tem2->right;
        tem2->right=tem1;
        tem2->left=root;     // now tem2 is the new root;
        tem1->height=1+max(getheight(tem1->left),getheight(tem1->right));
        tem1->BF=getheight(tem1->left)-getheight(tem1->right);
        tem2->height=1+max(getheight(tem2->left),getheight(tem2->right));
        tem2->BF=getheight(tem2->left)-getheight(tem2->right);
        root->height=1+max(getheight(root->left),getheight(root->right));
        root->BF=getheight(root->left)-getheight(root->right);
        root=tem2;
      }
       return root;
   }
   public:
   void insert(int data)
   {
     BTroot=insert(BTroot,data);
   }
   void print()
   {
     print(BTroot);
   }
};
int main()
{
  AVL b;
  b.insert(10);
  b.insert(5);
  b.insert(6);
  b.insert(4);
  b.insert(16);
  b.insert(14);
  b.insert(18);
  b.print();
}