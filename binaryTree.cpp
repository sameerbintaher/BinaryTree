#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Binary Tree Utilities - Public API Documentation
 *
 * This program provides a simple binary tree node type and traversal/utility functions.
 *
 * Public API:
 * - class treeNode
 * - void printSpace(int level)
 * - void printTree(treeNode* root, int level)
 * - void inOrder(treeNode* root, string& out)
 * - void preOrder(treeNode* root, string& out)
 * - void postOrder(treeNode* root, string& out)
 * - void levelOrderTraversal(treeNode* root, string& out)
 * - void printMaxAtLevelK(treeNode* root, int k, int level, int& maxValue)
 * - void printLeaves(treeNode* root)
 * - void printLeftNonLeaves(treeNode* root)
 * - void printRightNonLeaves(treeNode* root)
 * - void boundaryTraversal(treeNode* root)
 *
 * Usage:
 *  - Build: g++ -std=c++17 -O2 -Wall -Wextra -o binaryTree binaryTree.cpp
 *  - Input format:
 *      n
 *      value leftIndex rightIndex   (n lines)
 *      k
 *  - See README for full example and explanations.
 */

// make a tree node
/**
 * Represents a node in a binary tree.
 * Holds integer data and pointers to left and right children.
 */
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
/**
 * Print indentation spaces (3 per level) to stdout.
 *
 * Side effects: writes to std::cout.
 */
void printSpace(int level)
{
     for (int i = 0; i < level; i++)
     {
          cout << "   ";
     }
}

// print a preOrdered tree
/**
 * Pretty-print the tree in a hierarchical form using a pre-order style.
 * @param root  Root node to print.
 * @param level Initial indentation level (usually 0).
 *
 * Side effects: writes to std::cout.
 */
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
/**
 * Perform in-order traversal and append node values to chk without delimiters.
 * @param root Root node to traverse.
 * @param chk  Output string (appended to, not cleared).
 */
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
/**
 * Perform pre-order traversal and append node values to chk without delimiters.
 * @param root Root node to traverse.
 * @param chk  Output string (appended to, not cleared).
 */
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
/**
 * Perform post-order traversal and append node values to chk without delimiters.
 * @param root Root node to traverse.
 * @param chk  Output string (appended to, not cleared).
 */
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
/**
 * Perform level-order (BFS) traversal and append node values to chk without delimiters.
 * @param root Root node to traverse.
 * @param chk  Output string (appended to, not cleared).
 */
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
/**
 * Compute the maximum node value at level k.
 * @param root     Root node of the tree.
 * @param k        Target level (0-based).
 * @param level    Current level (pass 0 on initial call).
 * @param max      Reference to store the maximum value found at level k.
 */
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
/**
 * Print all leaf node values separated by spaces.
 *
 * Side effects: writes to std::cout.
 */
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

/**
 * Print the left boundary non-leaf nodes from the given root downward.
 * Skips leaf nodes to avoid duplication in boundary traversal.
 *
 * Side effects: writes to std::cout.
 */
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

/**
 * Print the right boundary non-leaf nodes from the given root downward.
 * Skips leaf nodes to avoid duplication in boundary traversal.
 *
 * Side effects: writes to std::cout.
 */
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
/**
 * Print the boundary traversal of the tree: root, left boundary non-leaves,
 * leaves (left subtree then right subtree), right boundary non-leaves.
 *
 * Side effects: writes to std::cout.
 */
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