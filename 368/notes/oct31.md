# Heapify

### Takes whatever is at root and puts it in the right place
Correct heap property: **parent is always greater than children**

### Showing the heapify process
```
    1                        5
   / \    ---heapify-->     / \
  5   2                    1   2
  WRONG                   CORRECT
```

```
          1                         9                        9   
       /     \                   /     \                  /     \
      5       9       ---->     5       1      ---->     5       7
     / \     / \               / \     / \              / \     / \
    4   3   7   6             4   3   7   6            4   3   1   6
        WRONG                     WRONG                   CORRECT
```

"Left heap" is left subtree of root, "right heap" is right subtree of root. The "value" is the value of the root.

Root of "joined" aka "correct" heap is `max(left_heap_value, right_heap_value, value)`

### Heap sort
1. say max value is index 0 (root)
2. swap max value (root) with last value
3. decrement size of heap

### Insert
1. append new value to end of array
2. swap root and end
3. heapify root

### Delete
1. swap victim and end
2. swap new end and root
3. heapify root

### Pseudocode
```c
void heapify() 
{
    // goal is to find the index of the max among root, L, R
    size_t idx_of_max = idx_of_root;

    // is left the max?
    size_t idx_of_left = 2 * idx_of_root + 1;
    if (num[idx_of_left] > num[idx_of_root]) // if left > root, left=max
    {
        idx_of_max = idx_of_left;
    }

    // is right the max?
    size_t idx_of_right = 2 * idx_of_root + 2;
    if (num[idx_of_right] > num[idx_of_max]) // if right > root, right=max
    {
        idx_of_max = idx_of_right;
    }

    // if root is not the max, swap max into root
    if (idx_of_max != idx_of_root) 
    { 
        // swap child value with root value
        int max_value = num[idx_of_max];
        num[idx_of_max] = num[idx_of_root];
        num[idx_of_root] = max_value;

        // heapify the subtree that was swapped
        // if the max used to be the left, we then need to heapify the left
        heapify(idx_of_max);
    }
}

void make_heap()
{
    // start at last value in array, get parent, heapify
    size_t idx_of_last = num_numbers - 1;
    size_t idx_of_last_parent = (idx_of_last - 1) / 2;
    for(int i = idx_of_last_parent; i >= 0; i--)
    {
        heapify(numbers, num_numbers, i);
    }
}
```