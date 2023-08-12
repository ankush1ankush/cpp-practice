#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BTNode
{
public:
  T data;
  BTNode<T> *left;
  BTNode<T> *right;
  BTNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~BTNode() // recurssive disrtuctor
  {
    delete left;
    delete right;
  }
};
class Pair
{ 
  public:
  BTNode<int> *head=NULL ;
  BTNode<int> *tail =NULL;
};

class BST
{
private:
  BTNode<int> *root;
  void printBT(BTNode<int> *BTroot)
  {
    if (BTroot == NULL)
    {
      return;
    }
    cout << BTroot->data << " : ";
    if (BTroot->left != NULL)
    {
      cout << BTroot->left->data << " , ";
    }
    if (BTroot->right != NULL)
    {
      cout << BTroot->right->data;
    }
    cout << endl;
    printBT(BTroot->left);

    printBT(BTroot->right);
  }
  BTNode<int> *insert(int data, BTNode<int> *BTroot)
  {
    if (BTroot == NULL)
    {
      BTNode<int> *n = new BTNode(data);
      return n;
    }
    else if (BTroot->data > data)
    {
      BTroot->left = insert(data, BTroot->left);
      return BTroot;
    }
    else
    {
      BTroot->right = insert(data, BTroot->right);
      return BTroot;
    }
  }
  bool hasdata(int data, BTNode<int> *BTroot)
  {
    if (BTroot == NULL)
    {
      return false;
    }
    else if (BTroot->data == data)
    {
      return true;
    }
    if (BTroot->data > data)
    {
      return hasdata(data, BTroot->left);
    }
    else
    {
      return hasdata(data, BTroot->right);
    }
  }
  int rightMin(BTNode<int> *BTroot)
  {
    if (BTroot == NULL)
    {
      return INT_MAX;
    }
    int min = rightMin(BTroot->left);
    if (min > BTroot->data)
    {
      min = BTroot->data;
    }
    return min;
  }
  BTNode<int> *Delete(int data, BTNode<int> *BTroot)
  {
    if (BTroot == NULL)
    {
      return NULL;
    }
    if (BTroot->data > data)
    {
      BTroot->left = Delete(data, BTroot->left);
    }
    if (BTroot->data < data)
    {
      BTroot->right = Delete(data, BTroot->right);
    }
    else // BTroot->data=data
    {
      if (BTroot->left == NULL && BTroot->right == NULL)
      {
        delete BTroot;
        return NULL;
      }
      if (BTroot->left == NULL && BTroot->right != NULL)
      {
        BTNode<int> *Tem = BTroot->right;
        BTroot->right = NULL;
        delete BTroot;
        return Tem;
      }
      if (BTroot->left != NULL && BTroot->right == NULL)
      {
        BTNode<int> *Tem = BTroot->left;
        BTroot->left = NULL; // issolation step mendatory as our constructor is recurrsive destructor
        delete BTroot;
        return Tem;
      }
      if (BTroot->left != NULL && BTroot->right != NULL)
      {
        int min = rightMin(BTroot->right);          // finding right minimum
        BTroot->data = min;                         // replacing node data with right minimum
        BTroot->right = Delete(min, BTroot->right); // deleting data replaced in the right subtree;
      }
    }

    return BTroot;
  }
  Pair convertToLL(BTNode<int> *root)
  {
    if(root==NULL)
    {
      Pair p;
      return p;
    }
    if(root->left==NULL&&root->right==NULL)
    {
      Pair p;
      p.head=root;
      p.tail=root;
      return p;
    }
    else if(root->left!=NULL&&root->right==NULL)
    {
      Pair leftLL;
      leftLL=convertToLL(root->left);
      root->left=NULL;
      leftLL.tail->right=root;
      leftLL.tail=root;
      return leftLL;
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
      Pair rightLL;
      rightLL=convertToLL(root->right);
      root->right=rightLL.head;
      rightLL.head=root;
      return rightLL;
    }
    else{
      Pair leftll=convertToLL(root->left);
      root->left=NULL;
      leftll.tail->right=root;
      leftll.tail=root;
      Pair rightll=convertToLL(root->right);
      leftll.tail->right=rightll.head;
      leftll.tail=rightll.tail;
      return leftll;

    }

  }
public: // scope specifier
  BST()
  {
    root = NULL;
  }
  void insert(int data)
  {
    root = insert(data, root);
  }
  void print()
  {
    printBT(root);
  }
  bool hasdata(int data)
  {
    return hasdata(data, root);
  }
  void Delete(int data)
  {
    root = Delete(data, root);
  }
  BTNode<int> *convertToLL()
  {
    Pair p=convertToLL(root);
    return p.head;
  }
};
int main()
{
  BST b;
  b.insert(10);
  b.insert(5);
  b.insert(6);
  b.insert(4);
  b.insert(16);
  b.insert(14);
  b.insert(18);
  b.print();
  cout << b.hasdata(14) << endl;
 // b.Delete(16);
 // b.print();
  BTNode<int> *head=b.convertToLL();
  BTNode<int> *tem=head;
  while(tem!=NULL)
  {
    cout<<tem->data<<"->";
    tem=tem->right;

  }
  cout<<endl;

  return 0;
}
