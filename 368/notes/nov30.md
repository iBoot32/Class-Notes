# Dijkstra's Algorithm

From vertex `V0` find shortest path to all other vertices.
Suppose `V0` is "A".

table in markdown
Node | Visited | dist(A) iter 1 | dist(A) iter 2 | dist(A) iter 3 | dist(A) iter 4
--- | --- | --- | --- | --- | ---
A | Yes | 0 | 0 | 0 | 0
B | No | inf | 4 | 4 | 4
C | No | inf | 2.5 | 2.5 | 5.5
D | No | inf | 8 | 8 | 8
E | No | inf | inf | 8.5 | 8.5
~ | through A| through B | through C | through D | through E

Then we take the min of all the results, and that's the shortest path.

According to slides, we keep tabs on the distance to each node, and also the node we came from.
