#include <bits/stdc++.h>
using namespace std;
class BTNode
{
public:
  int data;
  int height;

  BTNode *left;
  BTNode *right;
  BTNode(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;

    height = 0;
  }
  ~BTNode()
  {
    delete left;
    delete right;
  }
};

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
  if (root == NULL)
  {
    return 0;
  }
  return root->height+1;
}
BTNode *LLrotation(BTNode *root)
{
  BTNode *rootLCH = root->left;         // left child of root
  BTNode *rootLCH_RCH = rootLCH->right; // right child of the left child of root
  // performing rotation
  rootLCH->right = root;
  root->left = rootLCH_RCH;
  // Update heights
  root->height = max(getheight(root->left), getheight(root->right)) + 1;
  rootLCH->height = max(getheight(rootLCH->left), getheight(rootLCH->right)) + 1;
  // Return new root
  return rootLCH;
}
BTNode *RRrotation(BTNode *root)
{
  BTNode *rootRCH = root->right;
  BTNode *rootRCH_LCH = rootRCH->left;
  // performing rotation
  rootRCH->left = root;
  root->right = rootRCH_LCH;

  // Update heights
  root->height = max(getheight(root->left),
                     getheight(root->right)) +
                 1;
  rootRCH->height = max(getheight(rootRCH->left),
                        getheight(rootRCH->right)) +
                    1;

  // Return new root
  return rootRCH;
}

BTNode *LR(BTNode *root)
{
  root->left = RRrotation(root->left);
  return LLrotation(root);
}
BTNode *RL(BTNode *root)
{
  root->right = LLrotation(root->right);
  return RRrotation(root);
}
int getBalance(BTNode *N)
{
    if (N == NULL)
        return 0;
    return  getheight(N->left)-getheight(N->right);
}
BTNode *insert(BTNode *root, int data)
{
  if (root == NULL)
  {
    BTNode *n = new BTNode(data);

    return n;
  }
  else if (root->data > data)
  {
    root->left = insert(root->left, data);
  }
  else if (root->data < data)
  {
    root->right = insert(root->right, data);
  }
  else
  {
    return root;
  }

  // height of root
  int lh = 0;
  int rh = 0;
  
  int BF = getBalance(root);
  root->height = 1 + max(getheight(root->right),getheight(root->left));

  if ((BF > 1) && (data < root->left->data))
  {
    return LLrotation(root);
  }
  if ((BF > 1) && (root->left->data < data)) // left right rotation
  {
    return LR(root);
  }
  if ((BF < -1) && (root->right->data < data))
  {
    return RRrotation(root);
  }
  if ((BF < -1) && (root->right->data > data))
  {

    return RL(root);
  }
  return root;
}

int main()
{
  BTNode *root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  print(root);
}