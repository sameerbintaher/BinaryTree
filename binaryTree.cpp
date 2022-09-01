#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// make a tree node
class treeNode
{
public:
     int data;
     treeNode *leftChild;
     treeNode *rightChild;
     treeNode(int data)
     {
          this->data = data;
          this->leftChild = NULL;
          this->rightChild = NULL;
     }
};

// print space
void printSpace(int level)
{
     for (int i = 0; i < level; i++)
     {
          cout << "   ";
     }
}

// print a preOrdered tree
void printTree(treeNode *root, int level)
{
     if (root == NULL)
     {
          return;
     }
     if (root->leftChild == NULL && root->rightChild == NULL)
     {
          cout << root->data << endl;
          return;
     }
     else
     {
          cout << endl;
          printSpace(level);
          cout << "Root: " << root->data << endl;
     }
     if (root->leftChild != NULL)
     {
          printSpace(level);
          cout << "Left: ";
          printTree(root->leftChild, level + 1);
     }
     if (root->rightChild != NULL)
     {
          printSpace(level);
          cout << "Right: ";
          printTree(root->rightChild, level + 1);
     }
}

// inOrder
void inOrder(treeNode *root, string &chk)
{
     if (root == NULL)
     {
          return;
     }
     inOrder(root->leftChild, chk);
     chk += to_string(root->data);
     inOrder(root->rightChild, chk);
}

// preOrder
void preOrder(treeNode *root, string &chk)
{
     if (root == NULL)
     {
          return;
     }
     chk += to_string(root->data);
     preOrder(root->leftChild, chk);
     preOrder(root->rightChild, chk);
}

// postOrder
void postOrder(treeNode *root, string &chk)
{
     if (root == NULL)
     {
          return;
     }
     postOrder(root->leftChild, chk);
     postOrder(root->rightChild, chk);
     chk += to_string(root->data);
}

// level order traversal
void levelOrderTraversal(treeNode *root, string &chk)
{
     if (root == NULL)
     {
          return;
     }
     queue<treeNode *> q;
     q.push(root);
     while (!q.empty())
     {
          treeNode *temp = q.front();
          q.pop();
          chk += to_string(temp->data);
          if (temp->leftChild != NULL)
          {
               q.push(temp->leftChild);
          }
          if (temp->rightChild != NULL)
          {
               q.push(temp->rightChild);
          }
     }
}

// print maximum value at level k
void printMaxAtLevelK(treeNode *root, int k, int level, int &max)
{
     if (root == NULL)
     {
          return;
     }
     if (level == k)
     {
          if (root->data > max)
          {
               max = root->data;
          }
          return;
     }
     printMaxAtLevelK(root->leftChild, k, level + 1, max);
     printMaxAtLevelK(root->rightChild, k, level + 1, max);
}

// print leaves
void printLeaves(treeNode *root)
{
     if (root == NULL)
     {
          return;
     }
     if (root->leftChild == NULL && root->rightChild == NULL)
     {
          cout << root->data << " ";
     }
     printLeaves(root->leftChild);
     printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode *root)
{
     if (root == NULL)
     {
          return;
     }
     if (root->leftChild != NULL)
     {
          cout << root->data << " ";
          printLeftNonLeaves(root->leftChild);
     }
     else if (root->rightChild != NULL)
     {
          cout << root->data << " ";
          printLeftNonLeaves(root->rightChild);
     }
}

void printRightNonLeaves(treeNode *root)
{
     if (root == NULL)
     {
          return;
     }
     if (root->rightChild != NULL)
     {
          cout << root->data << " ";
          printRightNonLeaves(root->rightChild);
     }
     else if (root->leftChild != NULL)
     {
          cout << root->data << " ";
          printRightNonLeaves(root->leftChild);
     }
}

// boundary traversal
void boundaryTraversal(treeNode *root)
{
     if (root == NULL)
     {
          return;
     }
     cout << root->data << " ";

     // left boundary non leaves
     printLeftNonLeaves(root->leftChild);

     // left boundary leaves
     printLeaves(root->leftChild);

     // right boundary leaves
     printLeaves(root->rightChild);

     // right boundary non leaves
     printRightNonLeaves(root->rightChild);
}

int main()
{
     int n;
     cin >> n;
     treeNode *allNodes[n];
     for (int i = 0; i < n; i++)
     {
          allNodes[i] = new treeNode(-1);
     }
     for (int i = 0; i < n; i++)
     {
          int value, left, right;
          cin >> value >> left >> right;
          allNodes[i]->data = value;

          if (left > n - 1 || right > n - 1)
          {
               cout << "Invalid input" << endl;
               return 0;
          }

          if (left != -1)
          {
               allNodes[i]->leftChild = allNodes[left];
          }
          if (right != -1)
          {
               allNodes[i]->rightChild = allNodes[right];
          }
     }
     printTree(allNodes[0], 0);

     cout << endl; // print a blank line
     string inOrderTraversal = "";
     inOrder(allNodes[0], inOrderTraversal);
     cout << "In order traversal: " << inOrderTraversal << endl;

     string preOrderTraversal = "";
     preOrder(allNodes[0], preOrderTraversal);
     cout << "Pre order traversal: " << preOrderTraversal << endl;

     string postOrderTraversal = "";
     postOrder(allNodes[0], postOrderTraversal);
     cout << "Post order traversal: " << postOrderTraversal << endl;

     string LevelOrderTraversal = "";
     levelOrderTraversal(allNodes[0], LevelOrderTraversal);
     cout << "Level order traversal: " << LevelOrderTraversal << endl;

     cout << "Boundary order traversal: ";
     boundaryTraversal(allNodes[0]);

     cout << endl
          << endl;
     cout << "Enter the level that you want to know maximum value: ";
     int k;
     cin >> k;
     int max = -1;
     printMaxAtLevelK(allNodes[0], k, 0, max);
     cout << "Maximum value at level " << k << ": " << max << endl;

     return 0;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/