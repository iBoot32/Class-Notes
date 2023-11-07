# B-Trees
A B-Tree of order M is a tree that either is empty or comprises k-nodes with the following properties:
1. k-1 keys
2. k links
3. following structural properties:
    1. $\text{k} \in [2, M]$ at the root
    2. $\text{k} \in [\frac{M}{2}, M ]$ at all other nodes
    3. all links at the same distance from the root

**So for k=6, k-1=5 at the root**:

$\boxed{\text{k0}}\boxed{\text{k1}}\boxed{\text{k2}}\boxed{\text{k3}}\boxed{\text{k4}}$


***
### Add key examples
```c
// adds key to existing node (level)
bool add_key(int new_key, int* a_key, BTreeNode* node)
{
    if NULL: *a_key = new_key; return true;

    else:
    int pos = 0; // suppose child belongs in first interval
    if (new_key >= node -> keys[1]) // if new_key is >= than first key
    {
        pos = node -> num_keys; // then we suppose it belongs at the last
        while (new_key < node -> keys[pos]) // while new_key is < than the last key
        {
            pos--; // we move it back until we find the right spot
        }
    } 

    // we now know where the child belongs
    if (need_to_restructure)
    {
        if (node -> num_keys < MAX_NUM_KEYS)
        {
            insert_node(...);
            return false; // no need to restructure since node was not full
        }
    }
}

void insert_node(int key, int pos, BTreeNode* node)
{
    int i = node - num_keys; // suppose should be appended (i.e. last node)
    while (i > pos)
    {
        node -> keys[i+1] = node -> keys[i];
        node -> subtrees[i+1] = node -> subtrees[i];
        i--;
    }
    node -> keys[i+1] = key;
    node -> subtrees[i+1] = child;
    node -> num_keys++;
}

```

### Recapping
`main` 
$\newline\downarrow\newline$
`insert`
$\newline\downarrow\newline$
`add_key`
$\newline\downarrow\newline$
`insert_node || split`
