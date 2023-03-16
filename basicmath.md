# Activity 1.1 Basic Math
Reference for math symbols:
https://www.overleaf.com/learn/latex/List_of_Greek_letters_and_math_symbols
## Names:
- Fernanda Cantú A01782232
- Alina Rosas A01252720
## Exercises:
1. Let $X$ be a finite set. Give a recursive definition of the set of subsets
    of $X$ (the Power set of $X$) $P(X)$.
    Use union as the operator on the definition <br>

    _**SOLUTION:**_<br>

    **I. Basis:** $n \in X$ where X is a finite set $X = \{1,2,3...n\}$
        $Y =\{1,2,3...n-1\} \subseteq X$ <br>

    **II. Recursive Step:** $P(X) = P(Y) \cup \{S \cup \{n\} : S \in P(Y) \}$ <br>

    **III. Closure:** $n \in X$ only if it can be obtained from the base case using the finite number of applications of the recursive step. <br>

2. Prove by induction on $n$ that:
    $\sum_{i=0}^{n}i^3 = \frac{n^2(n+1)^2}{4}$ <br> 

    _**SOLUTION:**_ <br>

    **I. Basis:** n=0 <br>

    **II. Inductive Hypothesis:** <br>
    Assume that n = k, then: $\sum_{i=0}^{k}i^3 = \frac{k^2(k+1)^2}{4}$ <br> 

    **III. Inductive Step:** n = k + 1 <br> <br>
    $\sum_{i=0}^{k+1}i^3 = \frac{(k+1)^2((k+1)+1)^2}{4}$ <br> <br>
    $\sum_{i=0}^{k}(k+1)^3 = \frac{(k+1)^2((k+1)+1)^2}{4}$ <br> <br>
    $\frac{k^2(k+1)^2}{4} + (k+1)^3 = \frac{(k+1)^2((k+1)+1)^2}{4}$ <br> <br>
    $\frac{k^2(k+1)^2+4(k+1)^3}{4} = \frac{(k+1)^2((k+1)+1)^2}{4}$ <br> <br>
    $\frac{(k+1)^2(k^2+4(k+1))}{4} = \frac{(k+1)^2((k+1)+1)^2}{4}$<br> <br>
    $\frac{(k+1)^2(k^2+4k+4)}{4} = \frac{(k+1)^2((k+1)+1)^2}{4}$<br> <br>
    $\frac{(k+1)^2(k+2)^2}{4} = \frac{(k+1)^2(k+2)^2}{4}$<br> <br>



3. Using the tree below, give the values of each of the items:
![Tree image](sample_tree.png) 
    a. the depth of the tree = 5 <br>
    b. the ancestors of x18 = 4 (x15, x10, x4, x1) <br>
    c. the internal nodes of the tree = 9 (x1, x2, x3, x4, x5, x7, x10, x13, x15) <br>
    d. the length of the path from x3 to x14 = 3 (x3 -> x7 -> x14) <br>
    e. the vertex that is the parent of x16 = x10 <br>
    f. the vertices children of x7 = x13, x14<br>