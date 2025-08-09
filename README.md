# Binary Tree Utilities

A simple C++ program that constructs a binary tree from indexed input and provides multiple traversal and utility functions.

## Build

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o binaryTree binaryTree.cpp
```

## Run

Provide input via stdin or a file:

```bash
./binaryTree < input.txt
```

## Input Format

- First line: `n` (number of nodes, 0-indexed indices from 0 to n-1)
- Next `n` lines: `value leftIndex rightIndex`
  - `leftIndex`/`rightIndex` are `-1` if a child does not exist
  - Indices must be within `[0, n-1]` when not `-1`
- Final line: `k` (zero-based level to query for maximum value)

### Example Input

```
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
2
```

### Example Output

```
Root: 0
Left: 
   Root: 1
   Left: 3
   Right: 4
Right: 
   Root: 2
   Left: 
      Root: 5
      Left: 7
      Right: 8
   Right: 6

In order traversal: 314075826
Pre order traversal: 013425786
Post order traversal: 341785620
Level order traversal: 012345678
Boundary order traversal: 0 1 3 4 7 8 6 2 

Enter the level that you want to know maximum value: Maximum value at level 2: 6
```

## Public API Reference

All APIs are defined in `binaryTree.cpp`.

- **class `treeNode`**: Node structure for a binary tree.
  - **public data**:
    - `int data`
    - `treeNode* leftChild`
    - `treeNode* rightChild`
  - **constructor**: `treeNode(int data)`

- **`void printSpace(int level)`**: Prints 3 spaces per indentation level to stdout.
  - **params**:
    - `level`: indentation depth

- **`void printTree(treeNode* root, int level)`**: Pretty-prints the tree in a structured, pre-order-like view.
  - **params**: `root` (tree root), `level` (initial indentation)
  - **example**:
    ```cpp
    printTree(root, 0);
    ```

- **`void inOrder(treeNode* root, std::string& out)`**: Appends in-order traversal values to `out`.
  - **example**:
    ```cpp
    std::string s; inOrder(root, s); // s -> nodes in in-order
    ```

- **`void preOrder(treeNode* root, std::string& out)`**: Appends pre-order traversal values to `out`.
  - **example**:
    ```cpp
    std::string s; preOrder(root, s);
    ```

- **`void postOrder(treeNode* root, std::string& out)`**: Appends post-order traversal values to `out`.
  - **example**:
    ```cpp
    std::string s; postOrder(root, s);
    ```

- **`void levelOrderTraversal(treeNode* root, std::string& out)`**: Appends level-order traversal values to `out`.
  - **example**:
    ```cpp
    std::string s; levelOrderTraversal(root, s);
    ```

- **`void printMaxAtLevelK(treeNode* root, int k, int level, int& maxValue)`**: Computes maximum value at level `k` and stores it in `maxValue`.
  - Pass `level = 0` at the initial call.
  - **example**:
    ```cpp
    int maxAtLevel = -1;
    printMaxAtLevelK(root, /*k=*/2, /*level=*/0, maxAtLevel);
    ```

- **`void printLeaves(treeNode* root)`**: Prints all leaf node values to stdout.

- **`void printLeftNonLeaves(treeNode* root)`**: Prints left boundary non-leaf node values.

- **`void printRightNonLeaves(treeNode* root)`**: Prints right boundary non-leaf node values.

- **`void boundaryTraversal(treeNode* root)`**: Prints the boundary traversal: root, left boundary non-leaves, leaves (left then right), right boundary non-leaves.
  - **example**:
    ```cpp
    std::cout << "Boundary order traversal: ";
    boundaryTraversal(root);
    std::cout << std::endl;
    ```

## Notes

- The traversal APIs append concatenated integer values to the provided `std::string`. If you need delimiters, adapt the functions or post-process the string.
- The program assumes node indices form a valid tree rooted at index 0.
