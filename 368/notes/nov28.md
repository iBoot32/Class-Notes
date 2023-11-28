# Graph Traversals

A graph G(V,E) consists of a set of nodes (vertices) V and a set of edges E. Each edge is a pair of nodes. Example: `Edges{(A,B),(B,C),(C,D),(D,A)}`:

### Euler Circuit:
- Visit every edge exactly once

### Degree of a node:
- Number of edges incident on a node

A graph has an Euler circuit if and only if every node has **even** degree

***

### **Adjacency and incidence:** 

**For a DIRECTED EDGE:**
- Edge `<u,v>` is **incident from** (or leaves) `u` and **incident to** (or enters) `v`. Node `v` is **adjacent** to `u`.
- `u` is the predecessor of `v`. `v` is the successor of `u`.
- `u` is the **source** of `<u,v>`. `v` is the **destination** of `<u,v>`.

**For an UNDIRECTED EDGE:**
- Edge `(u,v)` is **incident on** `u` and `v`. Nodes `u` and `v` are **adjacent**.
- `u` and `v` are **neighbors**.
- `u` and `v` are **endpoints** of `(u,v)`.

***

### **Edge Weight:**
- A weight can be assigned to each edge. Example: `Edges{(A,B,3),(B,C,2),(C,D,1),(D,A,4)}`. So there is a COST associated with each edge.

***

### **Path and cycles:**
A path of length `k` is a sequence of `k+1` adjacent nodes. 
- A path from a node to itself (following arrows) is a **cycle**.
- If there is a cycle in a graph, it's called a **cyclic graph**. Otherwise, it's called an **acyclic graph**.
- A directed acyclic graph is denoted as a **DAG**.

A graph is **connected** if every node is reachable from every other node. A **connected component** is a maximal connected subgraph.

**Strongly connected components** are maximal **subgraphs** in which every node is reachable from every other node.

***

### Adjacency Matrix:
A matrix `A` of size `n*n` where `n` is the number of nodes in the graph. Specifies as a boolean value whether there is an edge between two nodes. 

$$
A_{ij} = \begin{cases}
1 & \text{if there is an edge from i to j}\\
0 & \text{otherwise}
\end{cases}
$$

$$

\text{\space \space \space \space \space \space \space \space A \space \space B \space \space C \space \space D} \newline

M = \begin{bmatrix}
0 & 1 & 0 & 0\\
0 & 0 & 1 & 0\\
1 & 0 & 0 & 1\\
1 & 0 & 0 & 0
\end{bmatrix}
$$

### Adjacency List: More Compact
An array of all the nodes. Each node has a list of all the nodes it is connected to. If the graph is weighted, the list will also contain the weight of the edge.

***

### Coding this

```c
struct node {
    int val;
    struct node *next;
};
```

$$
\begin{array}{c|c}
\text{Node} & \text{List of Nodes it is connected to} \\
\hline
A & B \rightarrow C \\
B & C \\
C & D \\
D & A
\end{array}
$$

$$
\boxed{\text{A}} \rightarrow \boxed{\text{B}} \rightarrow \boxed{\text{C}} \rightarrow \boxed{\text{D}}
\newline
\boxed{\text{B}} \rightarrow \boxed{\text{C}}
\newline
\boxed{\text{C}} \rightarrow \boxed{\text{D}}
\newline
\boxed{\text{D}} \rightarrow \boxed{\text{gnd}}
