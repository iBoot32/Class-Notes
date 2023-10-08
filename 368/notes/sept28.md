# partitioning 

Assume we pick last element as pivot value (underlined)

End of lower partition is denoted by `|`

Element we are checking is boxed

$$ \vert \space 5, 1, 2, 3, \underline{4} $$
$$ \vert \space \boxed{5}, 1, 2, 3, \underline{4} $$
$$ \text{See if 5 <= pivot. No, so advance} $$
$$ \vert \space 5, \boxed{1}, 2, 3, \underline{4} $$
$$ \text{See if 1 <= pivot. Yes, so expand lower partition and swap with 5. Advance box}$$
$$ 5, \vert \space \boxed{1}, 2, 3, \underline{4}  $$
$$ 1, \vert \space 5, \boxed{2}, 3, \underline{4}  $$
$$ \text{See if 2 <= pivot. Yes, so expand lower parititon and swap with 5. Advance box}$$
$$ 1, 5, \vert \space \boxed{2}, 3, \underline{4}  $$
$$ 1, 2, \vert \space 5, \boxed{3}, \underline{4}  $$
$$ \text{See if 3 <= pivot. Yes, so expand lower parititon and swap with 5. Advance box}$$
$$ 1, 2, 5, \vert \space \boxed{3}, \underline{4}  $$
$$ 1, 2, 3, \vert \space 5, \boxed{\underline{4}}  $$
$$ \text{See if 4 <= pivot. Yes, so expand lower parititon and swap with 5. Advance box}$$
$$ 1, 2, 3, 5, \vert \space \boxed{\underline{4}}  $$
$$ 1, 2, 3, \underline{4}, \vert \space \boxed{5}  $$
$$ \text{Base case: num elements - num in lower = 1} $$
$$ \text{return.} $$

## next example

$$ \text{now assuming array sorted already} $$
$$ \vert \space 1, 2, 3, 4, \underline{5} $$
$$ \vert \space \boxed{1}, 2, 3, 4, \underline{5} $$
$$ \text{See if 1 <= pivot. No, so only advance box}$$
$$ \vert \space 1, \boxed{2}, 3, 4, \underline{5} $$
$$ \text{See if 2 <= pivot. No, so only advance box}$$
$$ \vert \space 1, 2, \boxed{3}, 4, \underline{5} $$
$$ \text{See if 3 <= pivot. No, so only advance box}$$
$$ \vert \space 1, 2, 3, \boxed{4}, \underline{5} $$
$$ \text{See if 4 <= pivot. No, so only advance box}$$
$$ \vert \space 1, 2, 3, 4, \boxed{\underline{5}} $$
$$ \text{size of array is now 0 so return} $$

## next example
$$ \text{assume array is sorted in reverse order} $$

