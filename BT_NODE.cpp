#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BTNode{
    public:
      T data;
      BTNode<T> *left;
      BTNode<T> *right;
      BTNode( T data)
      {
        this->data=data;
        left=NULL;
        right=NULL;
      }
      ~BTNode()
        {
        delete left;
        delete right;
        }

};
template<typename T>
void printBT(BTNode<T> *root)
{   
  if(root==NULL)
  {
    return;
  }
    cout<<root->data<<" : ";
    if(root->left!=NULL)
    {
      cout<<root->left->data<<" , ";

      }
      if(root->right!=NULL)
    {
      cout<<root->right->data;
      
      }
      cout<<endl;
    printBT(root->left);

   
    printBT(root->right);
   
}
BTNode<int> *takeinput()
{
   
   int data;
   cin>>data;
   if(data==-1)
   {
    return NULL;
   }
   BTNode<int> *Node=new BTNode(data);
   cout<<"enter the data of left child of node with data "<<data<<" else enter -1 :"<<endl;
   BTNode<int>* left=takeinput();
   cout<<"enter the data of right child of node with data  "<<data<<" else enter -1 :"<<endl; 
   BTNode<int> * right=takeinput();
   Node->left=left;
   Node->right=right;
   return Node;
}

BTNode<int> *takeinputlw()
{
  int data;
  cin>>data;
  if(data==-1)
  {
    return NULL;
  }
  queue<BTNode<int>*> q;
  BTNode<int> *Node=new BTNode<int>(data);
  q.push(Node);
  while(!q.empty())
  {
    BTNode<int> *newNode=q.front();
    q.pop();
    int Ldata;
    int Rdata;
    BTNode<int>* left;
    BTNode<int> * right;
   cout<<"enter the data of left child of node with data "<<newNode->data<<" else enter -1 :"<<endl;
   cin>>Ldata;
   if(Ldata==-1)
   {
     left=NULL;
   }
   else{
     left=new BTNode<int>(Ldata);
     newNode->left=left;
     q.push(left);
   }
   cout<<"enter the data of right child of node with data  "<<newNode->data<<" else enter -1 :"<<endl;
   cin>>Rdata; 
    if(Rdata==-1)
   {
     right=NULL;
   }
   else{
     right=new BTNode<int>(Rdata);
     newNode->right=right;
     q.push(right);
   }
   
   
   
  }
   return Node;
}
void printLW(BTNode<int> *root)
{
    if(root==NULL)
    {
      return ;
    }
    queue<BTNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
       BTNode<int> *node= q.front();
       q.pop();
       cout<<node->data<<" : ";
       if(node->left!=NULL)
       {
          cout<<node->left->data; 
          q.push(node->left); 
             
       }
       cout<<" , ";
       if(node->right!=NULL)
       {
          cout<<node->right->data; 
          q.push(node->right); 
             
       }
       cout<<endl;
    }
    
}
bool findKey(BTNode<int> *root,int key)
{
  if(root==NULL)
  {
    return false;
  }
  if(root->data==key)
  {
    return true;
  }
  bool ans1=findKey(root->left,key);
  if(ans1==true)
  {
    return true;
  } 
  bool ans2=findKey(root->right,key);
  if(ans2==true)
  {
    return true;
  }
  return false;
}
int Min(BTNode<int> *root)
{
  int ans1=INT_MAX;
  int ans2=INT_MAX;
  if(root->left!=NULL){
   ans1=Min(root->left);
  }
  if(root->right!=NULL){
   ans2=Min(root->right);
  }
   
   return min(ans1,min(ans2,root->data));
}
int Max(BTNode<int> *root)
{
  int ans1=INT_MIN;
  int ans2=INT_MIN;
  if(root->left!=NULL){
   ans1=Max(root->left);
  }
  if(root->right!=NULL){
   ans2=Max(root->right);
  }
   
   return max(ans1,max(ans2,root->data));
}
int countLeaf(BTNode<int> *root)
{ 
  if(root==NULL)
  {
    return 0;
  }
  if(root->left==NULL&&root->right==NULL)
  {
    return 1;
  }
  return countLeaf(root->right)+countLeaf(root->left);

}
bool getPath(BTNode<int> *root,int val, vector<int> &vec)
{
   if(root->data==val)
   {
    vec.push_back(root->data);
    return true;
   }
   if(root==NULL)
   {
    return false;
   }
   vec.push_back(root->data);
   bool leftans=getPath(root->left,val,vec);
   
   bool rightans=getPath(root->right,val,vec);
   if(leftans||rightans)
   {
    return true;
   }
   vec.pop_back();
   return false;
}
int main()
{
    cout<<"enter the root data else enter -1 :"<<endl;
    BTNode<int> *root=takeinputlw();
   // printBT(root);
    /*if(findKey(root,5))
    {
      cout<<"true"<<endl;
    }
    else{
      cout<<"flase"<<endl;
    }
    //cout<<Max(root)<<endl;
    //cout<<countLeaf(root)<<endl;*/
    vector<int> vec;
    int val;
    cout<<"enter the value to be find"<<endl;
    cin>>val;
    
    bool ans=getPath(root,val,vec);
    if(ans==true)
    {
      for(int i=0;i<vec.size();i++)
      {
        cout<<vec[i]<<" ";
      }
    }
    else{
      cout<<"val not found"<<endl;
    }
}

