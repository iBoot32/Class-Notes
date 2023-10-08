# Reviewing topics we've covered

All of these are divide and conquer algorithms, and are easier to understand
when you think of them recursively versus iteratively.
- binary search
- stacks and implementation (expression eval, tree traversals, iterative)
- going between recursive and iterative
- merge sort
- quicksort
- selection sort

- iterative tree trraversals (preorder, inorder, postorder)
- expression evaluation (math)


# Individual Topic review
- ### Quicksort
  1. partition the array s.t. everything in first subarray is < everything in second subarray
  2. quicksort the subarrays

  - #### Psuedocode:
    ```c
    void qsort(r[], lidx, ridx){
        if (lidx < ridx) {
            int pidx = partition(r, lidx, ridx);
            qsort(r, lidx, pidx-1);
            qsort(r, pidx+1, ridx);
        }
    }
    ```
    - #### Partitioning (pivot is underlined)
    - partitioning works as such:
    - 1. pick a pivot (usually the last element)
    - 2. move all elements < pivot to the left of the pivot
    - 3. move all elements > pivot to the right of the pivot
    - 4. return the index of the pivot
    - 5. quicksort the subarrays

    