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

void printSpace(int level);

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

// print space
void printSpace(int level)
{
     for (int i = 0; i < level; i++)
     {
          cout << "   ";
     }
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
}