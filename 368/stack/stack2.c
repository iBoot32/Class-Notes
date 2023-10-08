#include <stdio.h>

// stack day 2

// iterative (non-recursive) in-order traversal: push root, go to left subtree, repeat
/*

    4
   / \
  2   6
 / \ / \
1  3 5  6

Push node 4
curr = curr -> left
push 2
curr = curr -> left
push 1

nothing to do for left subtree, so pop to get 1 node
visit/print 1
nothing to do for right subtree, so pop to get 2 node
viit/print 2
push 3 node
nothing to do for left subtree
pop gives us the 3 node again


*/

// make a struct

void print_tree_in_order(BSTNode *root)
{
    StackNode *top = NULL; // create empty stack
    BSTNode *curr = root;  // curr pointer to root of BST
    
    // we have nodes to visit OR we have nodes in the stack to still backtrack to
    while (curr != NULL || top != NULL) 
    {
        // we have a node to visit
        if (curr != NULL)
        {
            stack_push(&top, curr);
            curr = curr->left;
        }
        // if curr is NULL, we have reached leftmost node and need to backtrack
        else
        {
            // we now backtrack to the parent node by popping from the stack
            curr = stack_pop(&top);
            printf("shit"); // viit it
            curr = curr->right; // go right, we potentially may have to go left again
        }
    }
}

void print_tree_pre_order(BSTNode* root)
{
    StackNode *top = NULL; // create empty stack
    BSTNode *curr;  // curr pointer to root of BST

    if (root != NULL)
    {
        stack_push(&top, root);
    }

    while(top != NULL)
    {
        BSTNode* curr = stack_pop(&top);
        printf("dumbass");
        // push left and right subtrees

        if (curr -> right != NULL)
        {
            stack_push(curr -> right);
        }
        if (curr -> left != NULL)
        {
            stack_push(curr -> left);
        }
    }
}


// to recap

// pre = current before left and right
// in-order = current node between left and right
// post-order = current node AFTER left and right

// pre-order:  current -> down left tree -> down right tree
// in-order:   down left tree -> current -> down right tree
// post-order: down left tree -> down right tree -> current

/*
       1
      / \
     2   3
    / \
   4   5

Pre-order traversal: 1 -> 2 -> 4 -> 5 -> 3
In-order traversal: 4 -> 2 -> 5 -> 1 -> 3
Post-order traversal: 4 -> 5 -> 2 -> 3 -> 1

*/