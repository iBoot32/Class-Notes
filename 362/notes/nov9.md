# B-Trees 

If we have an existing node like `50|60|80`, and we want to add 70:

1. malloc a new node ("new_right"): 

`|50|60|80| |x|x|x|`

2. move the right half of key into new node: 

`|50|60|x| |80|x|x|`

3. add new value to new_left (the node we wanna split)
   
 `|50|60|x| |70|80|x|`

1. clip from new left

    `|60|`

`|50|x|x| |70|80|x|`

5. send up the rightmost key in the new_left

In code, we first check if num_keys is MAX_KEYS. If so, we split the tree and return true since we have restructuring to do. If not, we insert the key AND SUBTREE and then return false.