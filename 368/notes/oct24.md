# AVL Trees continued

How is a balance score calculated?

$\text{Balance} = H(\text{Root -> left}) - H(\text{Root -> right})$


```
    o (h=2)
   / \
  o   o (h=1) (b=-1) since -1 - 0 = -1
 /     \
o       o (h=0)
```

Avl property states balance of each node is in {-1, 0, 1}

### Get height

```c
int getHeight(Node *root) {
  if (root == NULL) return -1;
  return 1 + max(getHeight(root->left), getHeight(root->right));
}
```

We need the + 1 since we will get height of each subtree and we need to add the root's existence.