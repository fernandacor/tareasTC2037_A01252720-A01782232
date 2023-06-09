# Activity 3.1 - Regular languages

Reference for math symbols:
https://www.overleaf.com/learn/latex/List_of_Greek_letters_and_math_symbols

## Names:
- Alina Rosas A01252720
- Fernanda Cantú A01782232


## Exercises:


1. Give a recursive definition of the set of strings over $\{a, b\}$ that
    contain at least one $b$ and have an even number of $a$’s before the
    first $b$.
    For example: $aab$, $bab$ and $aaaabbabababa$ are in the set,
    but $abb$, $aaab$ and $aa$ are not

    _**SOLUTION:**_ <br>

    **I. Basis:** $b \in L$ <br>

    **II. Recursive Step:** If $ u \in L$ , then $aau \in L, ua \in L, ub \in L$<br>

    **III. Closure:** $u \in L$ only if it can be obtained from the base case using a finite number of applications of the recursive step <br>


2. Let $X = \{aa, bb\}$ and $Y = \{\lambda, b, ab\}$.

    **a. List the strings in set $XY$**

    #|string|#|string|#|string
    -|-|-|-|-|-
    1| aa |2| aab |3| aaab |
    4 | bb | 5 | bbb | 6 | bbab | 

    **b. How many strings of length 6 are there in $X^*$?** <br>
    There are 8 strings of length 6 in $X^*$: <br>
    <ol>
    <li>aa-aa-aa
    <li>aa-aa-bb
    <li>aa-bb-aa
    <li>bb-aa-aa
    <li>bb-bb-aa
    <li>aa-bb-bb
    <li>bb-aa-bb
    <li>bb-bb-bb
    </ol> <br>

    c. List the strings in set $Y^*$ of length three or less

    #|string|#|string|#|string
    -|-|-|-|-|-
    | 1 | b | 2 | bb | 3 | bbb |
    | 4 | ab | 5 | abb | 6 | bab |
    | 7 | $\lambda$

    d. List the strings in set $X^* Y^*$ of length four or less

    #|string|#|string|#|string
    -|-|-|-|-|-
    1 | aa | 2 | bb | 3 | b |
    4 | ab | 5 | aab | 6 | aaab |
    7 | bbb | 8 | bbab | 9 | aaaa |
    10 | bbbb | 11 | abab | 12 | $\lambda$

3. Give a recursive definition of the set $\{a^ib^j | 0 ≤ i ≤ j ≤ 2i\}$

    _**SOLUTION:**_

    **I. Basis:** $[i,j] = [0,0] \rightarrow \{0 ≤ 0 ≤ 0 ≤ 0\}$

    **II. Recursive Step:** If $u \in L$, then $a≤u≤b \in L$, $ua \in L$, $ub \in L$.<br>

    If $w = a^ib^j$, then

    **III. Closure:** only if it can be obtained from the base case using a finite number of applications of the recursive step <br>


4. Let $L$ be the set of strings over $\{a, b\}$ generated by the recursive definition

    **I. Basis:** $b \in L$

    **II. Recursive Step**: If $u \in L$ then $ub \in L$, $uab \in L$, $uba \in
    L$ and $bua \in L$

    **III. Closure**: A string $u \in L$ only if it can be obtained from the
    basis using a finite number of applications of the recursive step.

    **a.** List the elements in the sets $L_0, L_1, L_2$ <br>
    $L_0 = \lambda$ <br>
    $L_1 =$ b <br>
    $L_2 =$ {bb, bab, bba, bba} <br>
        
    EXTRA: <br>
    $L_3 =$ {bbb, bbab, bbba, bbba, babb, babab, babba, bbaba, bbab, bbaab, bbaba, bbbaa}


    **b.** Is the string $bbaaba$ in $L$? If so, trace how it is produced.
    If not, explain why not.

    The string $bbaaba$ is not a part of L. This can be seen when $L_3$ (check subsection 3.a) is traced, for the only two possible options for bbaaba to occur are $uba \in L$ where $u = bbaa$, or $bua \in L$ when $u = baab$. This does not happen in $L_3$, and for $L_4$ the string's length grows.

    Another explanation is that a string when $L_1$ can be $b$. Then, there's a recursive step $uba$ that converts the string to $bba$. To continue, there's a recursive step $uab$ that converts the string to $bbaab$. To get $bbaaba$, a recursive step $ua \in L$ would be required, but it does not exist, hence $bbaaba$ is not a part of $L$.

    **c.** Is the string $bbaaaabb$ in $L$? If so, trace how it is produced.
    If not, explain why not

    The string $bbaaaabb$ is not a part of $L$. 
    
    According to the recursive step, the only possible option for $bbaaaaabb$ to occur is $ub \in L$ where $u = bbaaaab$.

    Addittionally, a string when $L_1$ can be $b$. Then, there's a recursive step $uba$ that converts the string to $bba$. To get $bbaaaabb$, a recursive step $ua \in L$ would be required, but it does not exist, hence $bbaaaabb$ is not a part of $L$.

5. Prove, using induction on the length of a string, that $(w^R)^R = w$ for all string $w \in \Sigma$

    _**SOLUTION:**_ <br>
    **I. Basis:** If $length(w) = 0$, then $w = \lambda$ and $\lambda^R = \lambda$ and $(\lambda^R)^R = \lambda$ <br>

    **II. Inductive Hypothesis:** Let $w$ be a string where $length(w) = n + 1$ where $a$ is the first character, $b$ is the last character, and $u$ is a string of $length(u) = n - 1$. Assume that $u \in \Sigma$

    **III. Inductive Step:** Demonstrate that the hypothesis holds for strings of length $n + 1$. <br>

    $(w^R)^R = ((aub)^R)^R$ <br>
    $((aub)^R)^R = (b^Rua^R)^R$ // definition of reversal <br>
    $(b^Rua^R)^R = (a^R)^Ru(b^R)^R$ // associativity of concatenation <br>
    $(a^R)^Ru(b^R)^R = (aub)$ // inductive hypothesis <br>

    $\square$


