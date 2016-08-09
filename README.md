Title: traceu
<script src='https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML'></script>

**Piecewise-linear tracing utility for implicitly defined curves**

![example plot]({filename}/images/ltrace-plot1.png)

###Example: Fixpoints
Let \\(g:\mathbb{R}^n \rightarrow \mathbb{R}^n, g_k(x) = \exp\Big(\cos\Big(k
\cdot\sum\limits_{i=1}^n x_i \Big)\Big) \text{ for } k = 1,\ldots,n\\)

Considering the homotopy
$$H: [0,1]\times\mathbb{R}^{n} \rightarrow \mathbb{R}^n, (\lambda, x) \mapsto x-\lambda g(x)$$
it is obvious, that \\(H(0,x)=x\\) and \\(H(1,x)=0 \Leftrightarrow x=g(x)\\).  
One approach to find fixpoints of \\(g\\) is therefore to follow
\\(H^{-1}(0)\\) starting at \\(x=0\\) until \\(\lambda = 1\\) holds.
**ltrace** provides piecewise linear approximations of such curves with upper
bounds for the error enabling further (e.g. newton-type) methods to be
successfully applied on the results. The picture above depicts a trace of
\\(H^{-1}(0)\\) for \\(n=10\\).

##About the Project

- Still quite beta, under development.
- Written in C.
