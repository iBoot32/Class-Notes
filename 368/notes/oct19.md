# Trees

### Some terminology
- **edge:** connection between two nodes
- **root:** node with no parent
- **leaf:** node with no children
- **degree of a node**: number of children
- **degree of a tree**: maximum degree of any node
- **size of a tree**: number of nodes
- **depth of a node**: number of edges from this node and the root (*not number of nodes**)
- **height of a tree**: maximum depth of any node

### AVL Trees

```
    10
   /  \
  5    15
 / \   / \
2   7 12  20
```

A binary search tree which is balanced. The height of the left and right subtrees of any node differ by at most 1.
- After insertion or deletion:
  - Preserve balance
  - Preserve BST property (left < root < right)
- No duplicates for now
- **Rotate** as needed to preserve balance
  - **CounterClockwise / Left rotation:** move the right child up and the root down
  - **Clockwise / Right rotation:** move the left child up and the root down

Examples of rotations:
```
    10
   /  \
  5    15
       / \
      12  20

after a left rotation about 10:

    15
   /  \
  10   20
 / \
5   12
```
```c
Node* CCW(Node *root) {
  Node *newRoot = root->right; // new root of the subtree is the right child
  root->right = newRoot->left; // the right of orig root is the left child of the new root
  newRoot->left = root;        // the left of the new root is the old root
  return newRoot;              // the root is now the new root
}

Node* CW(Node *root) {
  Node *newRoot = root->left;  // new root of the subtree is the left child
  root->left = newRoot->right; // the left of orig root is the right child of the new root
  newRoot->right = root;       // the right of the new root is the old root
  return newRoot;              // the root is now the new root
}
```

### Time and Space Complexity
Time complexity is dominated by the search 


```
     8
    / \
   4  10
  / \   
 2   6
    / \
   5   7

After a left rotation about 4:

         8
        / \
       6   10
      / \
     4   7
    / \
   2   5

After a right rotation about 6:

           6
          / \
         /   \
        /     \
       4       8
      / \     / \
     2   5   7  10

We are now balanced!
Key is it will rotate down and replace one of the old children, and the old child gets moved to this new child's old position
```
        
```


```