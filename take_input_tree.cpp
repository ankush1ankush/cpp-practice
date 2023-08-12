#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
     T data;
     vector<TreeNode<T>*> children;
     TreeNode(T data)
     {
        this->data=data;
     }
     ~TreeNode()
     {
        for(int i=0;i<children.size();i++)
        {
            delete children[i];
        }
     }
};
template<typename T>
void printtree(TreeNode<T> *node)
{
        cout<<node->data<<" : ";
        for(int i=0;i<node->children.size();i++)
        {
            cout<<node->children[i]->data<<",";
        }
        cout<<endl;
        for(int i=0;i<node->children.size();i++){
        printtree(node->children[i]);
        }
}

TreeNode<int> * takeInput()
{
   int data;
   cout<<"Enter data : "<<endl;
   cin>>data;
   TreeNode<int> *node=new TreeNode<int>(data);
   int children;
   cout<<"enter the number of the children of node with data "<<data<<" : "<<endl;
   cin>>children;
   for(int i=0;i<children;i++)
   {
      cout<<"enter the data of "<<(i+1)<<"th child of "<<data<<endl;
      TreeNode<int> *childNode=takeInput();
      node->children.push_back(childNode);
    }
    return node;
}
TreeNode<int>* takeInputlw()      //taking input level wise;
{
    int data; 
    cout<<"enter the data  "<<endl;
    cin>>data;                                     // entering the root data;

    TreeNode<int> *root=new TreeNode<int>(data);       // creating the root node;

    queue<TreeNode<int>*> q;                          

    q.push(root);                                     // pushing the root node into the qeue 


    while(!q.empty())                                // calling while loop untill q is not empty (Note call is to be made only after pushing root element first into queue 
                                                     //because queue was initially empty)
    {
       TreeNode<int> *parent=q.front();              
       cout<<"Enter the number of children of node with data "<<parent->data<<" : "<<endl; // asking the no of children of node at front(parent node)
       int children;
       cin>>children;
       for(int i=0;i<children;i++)
       {
        int childdata;
        cout<<"enter the data of child "<<i+1<<" of node with data "<<parent->data<<" : "<<endl; // entring the children data
        cin>>childdata;
        TreeNode<int> *childNode=new TreeNode<int>(childdata);   //creating child node
        parent->children.push_back(childNode);                   // making connection with parent
        q.push(childNode);                                       // pushing chilnode into queue to make node at same level togather
       } 
       q.pop();                                                // poping the parent node out of queue 
    }
    return root;
}
void printLevelwise(TreeNode<int> *root){      //level wise print of the tree
queue<TreeNode<int>*> q;                       // pushing root node as queue is empty
q.push(root);
while(!q.empty())                             // setting while loop to run untill queue is empty
{
    TreeNode<int> *currentNode=q.front();     // extracteing the front element the of queue
    q.pop();                                  // poping out the front element of the queue
    cout<<currentNode->data<<" : ";           // print poped node data
    int childcount=currentNode->children.size();
    for(int i=0;i<childcount;i++)
    {
        cout<<currentNode->children[i]->data<<",";  // print the children of poped node
        q.push(currentNode->children[i]);           // pushing the children of poped node into the queue
    }
    cout<<endl;

}
}
int count(TreeNode<int>* root)
{
    int childcount=root->children.size();
    if(childcount==0)
    {
        return 1;      //base case 
    }
    int ans=0;
    for(int i=0;i<childcount;i++)
    {
         ans=ans+count(root->children[i]);  //reccursive  nth term
    } 
    return ans+1;                          // n-1th term
}
int countHeight(TreeNode<int> *Node)
{
    int max=0;
    if(Node->children.size()==0)
    {
        return 0;
        }
    for(int i=0;i<Node->children.size();i++)
    {
        int childHeight=countHeight(Node->children[i]);
        if(childHeight>max)
        {
            max=childHeight;
        }
        
    }
    return max+1;
}
void printAtLevelk(TreeNode<int>*root,int k)
{
     if(root==NULL)
     {
        return ;
     }
     if(k==0)                      // print node at depth k
     {
        cout<<root->data<<endl;
        return ;
     }
     for(int i=0;i<root->children.size();i++)
     {
        printAtLevelk(root->children[i],k-1);  // ittrative reccursive call for the node at same depth
     }
     return ;
}
int countLeaf(TreeNode<int> *root)
{
    if(root->children.size()==0)
    {
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans=ans+ countLeaf(root->children[i]);
    }
    return ans;
}
void preOrderTraversal(TreeNode<int> *root) // preorder traversal first print parent node then print child node.
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
       preOrderTraversal(root->children[i]);   
    }
    return;
  
}
void postOrder(TreeNode<int> *root)  // post order traversal first print children then print parent
{
    for(int i=0;i<root->children.size();i++)
    {
       postOrder(root->children[i]); 
    }
    cout<<root->data<<" ";
}
void DeleteTree(TreeNode<int> *root)
{
    for(int i=0;i<root->children.size();i++)
    {
        DeleteTree(root->children[i]);
    }
    delete root;
}
int main()
{
    cout<<"root data  element of the TREE"<<endl;
    TreeNode<int> *root=takeInputlw();
   // printLevelwise(root);
    int ans=count(root);
    cout<<"no of node :"<<ans<<endl;
    int height=countHeight(root);
    cout<<"height : "<<height<<endl;
    printAtLevelk(root,3);
    cout<<"no of leaf node "<<countLeaf(root)<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrder(root);
    DeleteTree(root);
}