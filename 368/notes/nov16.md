# Hash Tables

> "What I'm going to do today is take a very intuitive concept and make it a little bit muddy" <br> - Professor Alexander Quinn, 2023

**For every unordered key, you have some corresponding value**

### Hashing
Take a key, put it through `hash(key)` which maps a key to a vald index of an array called hash table (`table[hash(key)]`) in constant time.

$$
\text{hash(key)} \rightarrow \text{index} \rightarrow \text{table[index]}
$$

We can constrain the hash table size to, let's say, 997 (we typically pick prime numbers, which results in well-distributed results). We can do `hash(key) % 997` to force the index to fit in our hash table (which is literally just a big array).

Must distribute evenly across 0 to 996, appears random, and uses all useful info in the key (doesn't just take last 3 digits). 


### Collisions

Suppose `aq` and `mj` both hash to 448. We will then try to add `mj` into the hash table where `aq` already is. This is a collision. How do we fix this?

### Chaining!
Instead of each cell in the hash table pointing to a single value, have each cell point to a linked list instead. Then, we can add `mj` to the linked list at `table[448]`.

### Coalesced Chaining
idk

### Linear probing
If we have a collision, we can just look at the next cell in the hash table and see if it's empty. If it is, we can put the value there. If not, we can look at the next cell, and so on. **"Just try the next slot"**.

If we can limit the number of times we need to probe / insert / delete / find, we are back to constant time!
s
```python
def insert(key, table):
    _insert_key(...)
    if table full:
        expand table
```

Expanding the table like this still yields constant time!

### Quadratic Probing
On retry #i, try the i^2th slot. This is a little better than linear probing, but still not great.