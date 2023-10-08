# Master's Theorem and related stuff

Recall that if we say $f(n) = 3n + O(1)$, what we really mean is $f(n) \leq 3n + g(n)$ for all $n >= \text{some } k$. This is because $O(n)$ is not a function.

### Binary Search
Let $T(n) = \text{time to search for element in array of size "n"}$
$$

T(n) = T(\frac{n}{2}) \newline
T(\frac{n}{2}) \rightarrow T(\frac{n}{4}) \rightarrow T(\frac{n}{8}) \rightarrow ... \rightarrow T(1) \newline = n/2^k = 1 \newline
n = 2^k \newline
k = \log_2 n \newline
\text{This proves binary search is } O(\log n)
$$

### Divide and conquer algorithms

- Given an alg of the form:
  - If n < k, solve directly
  - Else, divide into a subproblem of size n/b and solve recursively, combine solutions from subproblems

Runtime is given by this recurrence relation:
$$ T(n) = a * T(\frac{n}{b}) + f(n) $$
- $a$ is the number of subproblems
- $b$ is the factor by which the input size (n) is reduced
- $f(n)$ is the time to divide and combine solutions


&nbsp;

***
# Master's Theorem

What is $c_{crit}$?
$$
c_{crit} = \log_b a \newline = \frac{log(\text{number of subproblems})} {log(\text{relative subroblem size})} \newline
$$

### Piecewise result of Master's Theorem

$$
\text{For runtime T(n) given as:} \newline
T(n) = aT(\frac{n}{b}) + O(n^{d})\newline
$$


$$
T(n) = \begin{cases} 
      O(n^{d}) & d > c_{crit} \\
      O(n^{d}\log(n)) & d = c_{crit} \\
      O(c_{crit}) & d < c_{crit} \\
   \end{cases}
$$

Expalined simply, master's theorem says: 
- If the number of subproblems is greater than the relative subproblem size, then the runtime is $O(n^{d})$. 
- If the number of subproblems is equal to the relative subproblem size, then the runtime is $O(n^{d} \log n)$. 
- If the number of subproblems is less than the relative subproblem size, then the runtime is $O({c_{crit}})$.

### Example 1: Merge Sort

For merge sort, we know for each iteration we must create an addition factor of 2 subproblems, and the relative subproblem size is 2. 

$$ 
\underset{\text{time to sort array of size n}}{T(n)} = \underset{\text{subproblems}}{2T(\frac{n}{2})} + \underset{\text{time to combine}}{O(n)} \newline
$$
$$
\text{Therefore we can solve for the variables in the master's theorem:} \newline
T(n) = aT(\frac{n}{b}) + O(n^{d})\newline
\text{Therefore a = 2, b = 2, d = 1} \newline
$$

$$ \text{We can now solve for } c_{crit} \text{ using the formula:} \newline
c_{crit} = \frac{log_b a} {log_b b} \newline
c_{crit} = \frac{log(2)} {log(2)} = 1 \newline
$$

$$ \text{Now we can use the piecewise result of the master's theorem to solve for the runtime:} \newline
d = 1 = c_{crit} \newline
\text{Therefore runtime is } O(n^{d} \log n) = O(n \log n) \newline
$$

### Example 2: Binary Search
For binary search the coefficients a b and d are 1, 2, and 0 respectively. This is because binary search splits the array into half each time (b = 2), but we only focus on one of the splitted arrays (a = 1), and there is no combining of solutions (d = 0). Therefore, $c_{crit} = \frac{log(1)} {log(2)} = 0$. D = $c_{crit}$, and the runtime is therefore $O(n^{d}\log n) = O(\log n)$.

### Example 3: get_kth_smallest_element
For this example, we still only have one subproblem (a = 1) since we only use one of the partitioned sections. If we split the size in half for each call, then b = 2. The upper-level time to combine/partition is O(n), so d = 1. Therefore, $c_{crit} = \frac{log(1)} {log(2)} = 0$. D > $c_{crit}$, and the runtime is therefore $O(n^{d}) = O(n)$.