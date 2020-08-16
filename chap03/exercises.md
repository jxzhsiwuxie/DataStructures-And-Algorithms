# 第三章 渐进记法

## 练习

1\.利用公式（3-1）证明下面的 $p(n)$ 渐进大于 $q(n)$。
1）$p(n)=3n^4+2n^2, q(n)=100n^2+6$
2）$p(n)=6n^{15}+12, q(n)=100n$
3）$7n^2\log n, q(n)=10n^2$
4）$p(n)=17n^22^n, q(n)=100n2^n+33n$

1）
$$
\lim_{n\to\infty}\frac{q(n)}{p(n)}=\lim_{n\to\infty}\frac{100n^2+6}{3n^4+2n^2}=
\lim_{n\to\infty}\frac{100/n^2+6/n^4}{3+2/n^2}=\frac{0}{3}
$$

2）
$$
\lim_{n\to\infty}\frac{q(n)}{p(n)}=\lim_{n\to\infty}\frac{100n}{6n^{15}+12}=
\lim_{n\to\infty}\frac{100/n^{14}}{6+12/n^{15}}=\frac{0}{6}=0
$$

3）
$$
\lim_{n\to\infty}\frac{q(n)}{p(n)}=\lim_{n\to\infty}\frac{10n^2}{7n^2\log n}=
\lim_{n\to\infty}\frac{10/\log n}{7}=\frac{0}{7}=0
$$

4）
$$
\lim_{n\to\infty}\frac{q(n)}{p(n)}=\lim_{n\to\infty}\frac{100n2^n+33n}{17n^22^n}=
\lim_{n\to\infty}\frac{100/n+33/2^n}{17}=\frac{0}{17}=0
$$

2\. 利用大 O 记法解释下面的步数。函数 $g(n)$ 应该是最小的单元项、
1）$2n^3-6n+30$
2）$44n^{1.5}+33n-200$
3）$16n^2\log n + 5n^2$
4）$31n^3+17n^2\log{n}$
5）$23n2^n-3n^3$

1）$2n^3-6n+30 = O(n^3)$
2）$44n^{1.5}+33n-200 = O(n^{1.5})$
3）$16n^2\log n + 5n^2 = O(n^2\log{n})$
5）$23n2^n-3n^3 = O(n2^n)$

3\. 使用大 O 记法的实用性和公式（3-1）证明下面的式子：
1）$2n+7\neq O(1)$
2）$12n^2+8n+7\neq O(n)$
3）$15n^3+6n^2\neq O(n^2)$
4）$15n^3\log{n}+16n^2\neq O(n^3)$

$f(n)=O(g(n))$ 表示 $f(n)$ 渐进小于或等于 $g(n)$，即 $g(n)$ 是 $f(n)$ 的上界。所以在最高次项系数为 1 的时候
$$\lim_{n\to\infty}\frac{f(n)}{g(n)} = c, c\in[0,1]$$

1）$$\lim_{n\to\infty}\frac{2n+7}{1} = \infty$$
2）$$\lim_{n\to\infty}\frac{12n^2+8n+7}{n} = \infty$$
3）$$\lim_{n\to\infty}\frac{15n^3+6n^2}{n^2} = \infty$$
4）$$\lim_{n\to\infty}\frac{15n^3\log{n}+16n^2}{n^3} = \lim_{n\to\infty}\log{n} = \infty$$

4\. 使用 $\Omega$ 记法表示练习 2 的步数。
1）$2n^3-6n+30 = \Omega(1)$
2）$44n^{1.5}+33n-200 = \Omega(n)$
3）$16n^2\log n + 5n^2 = \Omega(n^2)$
5）$23n2^n-3n^3 = \Omega(n2^n)$

5\. 使用 $\Omega$ 记法的实用性定义和公式 3-1 证明下面的式子：
1）$2n+7\neq\Omega(n^2)$
2）$12n^2+8n+7\neq\Omega(n^3)$
3）$5n^3+6n^2\neq\Omega(n^3\log{n})$
4）$15n^3\log{n}+16n^2\neq\Omega(n^4)$

$f(n)=\Omega(g(n))$ 表示 $f(n)$ 渐进大于或等于 $g(n)$，即 $g(n)$ 是 $f(n)$ 的下界。
所以在最高次项系数为 1 的时候
$$\lim_{n\to\infty}\frac{f(n)}{g(n)} = c, c\in[1,\infty)$$

1）$$\lim_{n\to\infty}\frac{2n+7}{n^2} = 0$$
2）$$\lim_{n\to\infty}\frac{12n^2+8n+7}{n^3} = 0$$
3）$$\lim_{n\to\infty}\frac{5n^3+6n^2}{n^3\log{n}} = 0$$
4）$$\lim_{n\to\infty}\frac{15n^3\log{n}+16n^2}{n^4} = 0$$

6\. 使用 $\Theta$ 记法表示练习 2 的步数。
1）$2n^3-6n+30 = \Theta(n^3)$
2）$44n^{1.5}+33n-200 = \Theta(n^{1.5})$
3）$16n^2\log n + 5n^2 = \Theta(n^2\log{n})$
5）$23n2^n-3n^3 = \Theta(n2^n)$

7\. 令 $t(n)$ 是一个程序的步数。使用渐进记法表示下面的步数。使用最合适的 $g(n)$ 函数。
1）$6\leq t(n) \leq 20$
2）$6 \leq t(n) \leq 2n$
3）$3n^2+1 \leq t(n) \leq 4n^2+3n+9$
4）$3n^2+1 \leq t(n) \leq 4n^2\log{n}+3n^2+9$
5）$t(n) \geq 5n^3+7$
6）$t(n) \geq 32n\log{n}+77n-6$
7）$t(n) = 17n^2+3n$

1）$t(n) = \Theta(1)$
2）$t(n) = O(n)$
3）$t(n) = \Theta(n^2)$
4）$t(n) = O(n^2\log{n})$
5）$t(n) = \Omega(n^3)$
6）$t(n) = \Omega(n\log{n})$
7）$t(n) = \Theta(n^2)$

8\. 使用大 O 记法表示下面的步数，其中 m 和 n 是实例特征。
1）$7m^2n^2+2m^3n+mn+5mn^2$
2）$2m^2\log{n}+3mn+5m\log{n}+m^2n^2$
3）$m^4+n^3+m^3n^2$
4）$3mn^2+7m^2n+4mn+8m+2n+16$

1）$7m^2n^2+2m^3n+mn+5mn^2 = O(m^2n^2+m^3n)$
2）$2m^2\log{n}+3mn+5m\log{n}+m^2n^2 = O(m^2n^2)$
3）$m^4+n^3+m^3n^2 = O(m^4+n^3+m^3n^2)$
4）$3mn^2+7m^2n+4mn+8m+2n+16 = O(mn^2+m^2n)$

9\. 使用 $O$、$\Omega$、$\Theta$ 和 $o$ 的定义之一，证明下列等式的正确性。不用定理 3-1 至定理 3-6，也不用图 3-7 和图 3-8。
1）$5n^2-6n=\Theta(n^2)$
2）$n!=O(n^n)$
3）$2n^22^n+n\log{n}=\Theta(n^22^n)$
4）$\sum_{i=0}^ni^2=\Theta(n^3)$
5）$\sum_{i=0}^ni^3=\Theta(n^4)$
6）$n^{2^n}+6\ast 2^n=\Theta(n^{2^n})$
7）$n^3+10^6n^2=\Theta(n^3)$
8）$6n^3/(\log{n}+1)=O(n^3)$
9）$n^{1.001}+n\log{n}=\Theta(n^{1.001})$
10）$n^{k+\varepsilon}+n^k\log{n}=\Theta(n^{k+\varepsilon})$，$k\geq 0$ 且 $\varepsilon > 0$

$\Theta$记法的定义：$f(n)=\Theta(g(n))$，当且仅当存在常数 $c_1 >0$，$c_2 > 0$ 和 $n_0$，使得对于所有的 $n\geq n_0$，有 $c_1g(n)\leq f(n) \leq c_2g(n)$。

1）令 $c_1=4, c_2=5, n_0=6$，可得到，对于任意 $n\geq n_0$ 有 $f(n)=5n^2-6n\geq 5n^2-n^2=4n^2$ 同时 $5n^2-6n < 5n^2$，即 $4n^2\leq f(n) \leq 5n^2$，所以 $5n^2-6n=\Theta(n^2)$。

$O$ 记法的定义：$f(n)=O(g(n))$，当且仅当存在常数 $c\gt0$ 和 $n_0$，使得对于所有的 $n\geq n_0$，有 $f(n)\leq cg(n)$。

2）对于任意的 $n\geq 0$，有 $n!=\prod_{i=1}^{i=n}i \leq \prod_{i=1}^{i=n}n = n^n$，所以 $n!=O(n^n)$。

3）
$$\lim_{n\to\infty}\frac{n^22^n}{n\log{n}}=\lim_{n\to\infty}\frac{(n2^n)'}{(\log{n})'}=\lim_{n\to\infty}\frac{2^n+n2^n\ln{2}}{1/n}=\lim_{n\to\infty}n2^n(1+n\ln{2}) > 1$$
所以存在 $n_0>0$ 使得当 $n\geq n_0$ 时有 $n^22^n > n\log{n}$。因而当 $n\geq n_0$ 时 $2n^22^n \leq 2n^22^n + n\log{n} \leq 3n^22^n$。所以 $2n^22^n + n\log{n}=\Theta(n^22^n)$。

4）$\sum_{i=0}^ni^2=\frac{n(n+1)(2n+1)}{6}=\frac{n^3}{3}+\frac{n^2}{2}+\frac{n}{6}=\Theta(n^3)$

5）$\sum_{i=0}^ni^3=\frac{n^4}{4}+\frac{n^3}{2}+\frac{n^2}{4}+n = \Theta(n^4)$

6）对于任意 $n\geq 0$ 有 $n^{2^n}+6\ast 2^n \geq n^{2^n}$；同时由3）可知 $2^n\log{n}\geq n\log{n}$，所以当 $n\geq 2$ 时 $2^n\log{n}\geq n\log{n}\geq n\log2 \Rightarrow n^{2^n}\geq 2^n$，因而当 $n\geq 2$ 时 $n^{2^n}+6\ast 2^n \leq n^{2^n}+6n^{2^n}=7n^{2^n}$，也即是 $n^{2^n}\leq n^{2^n}+6\ast2^n\leq 7n^{2^n}$，所以 $n^{2^n}+6\ast 2^n=\Theta(n^{2^n})$。

7）$n^3+10^6n^2=\Theta(n^3)$

8）当 $n\geq 1$ 时 $\log{n}+1 \geq 1 \Rightarrow 6n^3/(\log{n}+1)=O(n^3) \leq 6n^3$ 所以 $6n^3/(\log{n}+1)=O(n^3)$。

9）当 $n\geq 1$ 时 $n\log{n} \geq 0 \Rightarrow n^{1.001}+n\log{n} \geq n^{1.001}$
$$\lim_{n\to\infty}\frac{n^{1.001}}{n\log{n}}=\lim_{n\to\infty}\frac{(n^{0.001})'}{(\log{n)'}}=0.001n^{0.001}=\infty$$
所以存在 $n_0 > 0$ 使得当 $n\geq n_0$ 时 $n^{1.001} \geq n\log{n}$，所以当 $n\geq n_0$ 时 $n^{1.001}\leq n^{1.001}+n\log{n} \leq 2n^{1.001}$，所以 $n^{1.001}+n\log{n}=\Theta(n^{1.001})$。

10）$$\lim_{n\to\infty}\frac{n^{k+\varepsilon}}{n^k\log{n}}=\lim_{n\to\infty}\frac{(n^\varepsilon)'}{(\log{n)'}}=\varepsilon n^{\varepsilon}=\infty$$
与9）同理得到 $n^{k+\varepsilon}+n^k\log{n}=\Theta(n^{k+\varepsilon})$。

10\. 使用定理 3-2、定理 3-3 和定理 3-6，完成练习9。

**定理 3-2【大 O 比率定理】** 假设函数 $f(n)$ 和 $g(n)$ 有极限 $\lim_{n\to\infty}f(n)/g(n)$ 存在，那么关系式 $f(n)=O(g(n))$ 成立，当且仅当存在常数 $c$， 使得 $\lim_{n\to\infty}f(n)/g(n) \leq c$。

**定理 3-3** 如果 $f(n)=a_mn^m+ \cdots +a_1n + a_0$，且 $a_m>0$，则 $f(n)=\Omega(n^m)$。

**定理 3-6【$\Theta$ 比率定理】** 假设 $f(n)$ 和 $g(n)$ 有极限 $\lim_{n\to\infty}f(n)/g(n)$ 和 $\lim_{n\to\infty}g(n)/f(n)$ 存在，那么关系式 $f(n)=\Theta(g(n))$ 成立，当且仅当存在常数 $c$，使 $\lim_{n\to\infty}f(n)/g(n)\leq c$ 以及 $\lim_{n\to\infty}g(n)/f(n)\leq c$ 成立。

11\. 证明下列等式不正确。
1）$10n^2+9=O(n)$
2）$n^2\log{n}=\Theta(n^2)$
3）$n^2/log{n}=\Theta(n^2)$
4）$n^32^n+6n^23^n=O(n^32^n)$

4）$$\lim_{n\to\infty}\frac{n^32^n+6n^23^n}{n^32^n}=\lim_{n\to\infty}\frac{6}{n}(\frac{3}{2})^n=\lim_{n\to\infty}\frac{6n}{1}(\frac{3}{2})^{n-1}=\infty$$

12\. 证明定理 3-3 和定理 3-5。
**定义 3-4【$\Omega$记法】** $f(n)=\Omega(g(n))$ 当且仅当存在常数 $c>0$ 和 $n_0$，使得对所有的 $n\geq n_0$，有 $f(n)\geq cg(n)$。
**定理 3-3** 如果 $f(n)=a_mn^m+ \cdots +a_1n + a_0$，且 $a_m>0$，则 $f(n)=\Omega(n^m)$。
$$\sum_{i=0}^ma_in^i=(a_m-\varepsilon)n^m + \varepsilon n^m+\cdots+a_1n+a_0=(a_m-\varepsilon)n^m+\varepsilon n^m +\sum_{i=0}^{m-1}a_in^i$$
其中 $\varepsilon > 0$，令 $a_x=max\{|a_0|,\cdots,|a_{m-1}|\}$，则
$$(a_m-\varepsilon)n^m+\varepsilon n^m +\sum_{i=0}^{m-1}a_in^i > (a_m-\varepsilon)n^m+\varepsilon n^m -(m-1)a_xn^{m-1} $$
令 $n_0=\frac{(m-1)a_x}{\varepsilon}$，则当 $n\geq n_0$ 时，有
$$(a_m-\varepsilon)n^m+\varepsilon n^m -(m-1)a_xn^{m-1} \geq (a_m-\varepsilon)n^m$$

所以如果取 $(a_m-\varepsilon)>0$ 同时 $n_0=\frac{(m-1)a_x}{\varepsilon}$，则可以得到当 $n\geq n_0$ 时
$$f(n)=a_mn^m+ \cdots +a_1n + a_0 > (a_m-\varepsilon)n^m$$
所以定理 3-3 成立。

**定理 3-5** 如果 $f(n)=a_mn^m+ \cdots +a_1n + a_0$，且 $a_m>0$，则 $f(n)=\Theta(n^m)$。
**定义 3-5【$\Theta$ 记法】** $f(n)=\Theta(g(n))$，当且仅当存在常数 $c_1 >0$，$c_2 > 0$ 和 $n_0$，使得对于所有的 $n\geq n_0$，有 $c_1g(n)\leq f(n) \leq c_2g(n)$。
结合定义 3-5、定理 3-1 以及定理 3-3 则自然得到定理 3-5。

13\. 证明定理 3-4 和定理 3-6。
**定理 3-4【$\Omega$ 比率定理】** 假设函数 $f(n)$ 和 $g(n)$ 有极限 $\lim_{n\to\infty}g(n)/f(n)$ 存在，那么关系式 $f(n)=O(g(n))$ 成立，当且仅当存在常数 $c$， 使得 $\lim_{n\to\infty}g(n)/f(n) \leq c$。
**定理 3-6【$\Theta 比率定理$】** 假设 $f(n)$ 和 $g(n)$ 有极限 $\lim_{n\to\infty}f(n)/g(n)$ 和 $\lim_{n\to\infty}g(n)/f(n)$ 存在，那么关系式 $f(n)=\Theta(g(n))$ 成立，当且仅当存在常数 $c$，使 $\lim_{n\to\infty}f(n)/g(n)\leq c$ 以及 $\lim_{n\to\infty}g(n)/f(n)\leq c$ 成立。

由定义 3-4 自然得到顶伦理 3-4。  

由定义 3-5 同时令 $c=max\{1/c_1, c_2\}$ 则自然得到定理 3-6。

14\. 证明等式 $f(n)=o(g(n))$ 成立，当且仅当 $\lim_{n\to\infty}f(n)/g(n)=0$。
**定义 3-6【小 o 记法】** $f(n)=o(g(n))$，当且仅当 $f(n)=O(g(n))$ 且 $f(n)\neq\Omega(g(n))$。
**定义 3-3【大 O 记法】** $f(n)=O(g(n))$，当且仅当存在常数 $c\gt0$ 和 $n_0$，使得对于所有的 $n\geq n_0$，有 $f(n)\leq cg(n)$。
1）当 $\lim_{n\to\infty}f(n)/g(n)=0$ 时，令 $c=1$，显然有存在 $n_0>0$，当 $n\geq n_0$ 时，$f(n)\lt g(n) \leq g(n)$，即 $f(n)=O(g(n))$；又由定义3-4可知，若 $f(n)=\Omega(g(n))$ 则存在 $c\gt0, n_0$ 使得对于所有 $n\geq n_0$ 都有 $f(n)\geq cg(n) \Rightarrow f(n)/g(n) = c \gt 0$，与 $\lim_{n\to\infty}f(n)/g(n)=0$ 矛盾，所以 $f(n)\neq \Omega(g(n))$；所以 $f(n)=o(g(n))$。
2）若 $f(n)=o(g(n))$ 成立，由定义 3-6 首先得到 $f(n)=O(g(n)) \Rightarrow \lim_{n\to\infty}f(n)/g(n) \leq c, (c\gt 0)$，可以假设 $0\leq\varepsilon\leq c$ 并且 $\lim_{n\to\infty}f(n)/g(n)=\varepsilon$，如果 $\varepsilon\neq 0$ 则有 $\lim_{n\to\infty}g(n)/f(n)=1/\varepsilon$，由定义3-4便可得到 $f(n)=\Omega(g(n))$，这与 $f(n)=o(g(n))$ 定义相矛盾，所以必然有 $\varepsilon=0$，即 $\lim_{n\to\infty}f(n)/g(n)=0$。
综合 1）与 2）得证。

15\. 证明图 3-7 的等式 E5~E8。
E5：$\sum_{i=1}^ni^k, k\gt 0 = \oplus(n^{k+1})$
E6：$\sum_{i=0}^nr^i, r\gt 1 = \oplus(r^n)$
E7：$n! = \oplus(\sqrt{n}(n/e)^n)$
E8：$\sum_{i=1}^n1/i = \oplus(\log{n})$

E5：
$$S_n = \sum_{i=1}^ni^k \Rightarrow S_n - S_{n-1} = n^k \Rightarrow S_n' - S_{n-1}' = kn^{k-1} \Rightarrow S_n'=S_1'+k\sum_{i=1}^ni^{k-1}$$
同样的推理可以得到
$$S_n^{(l)}=S_1^{(l)}+\frac{k!}{(k-l)!}\sum_{i=1}^ni^{k-l}$$
1）$k\in N$，即 $k$ 为自然数，则有
$$S_n^{(k)}=S_1^{(k)}+k!\sum_{i=1}^ni^0 = S_1^{(k)}+k!n \Rightarrow S_n = \sum_{i=0}^ka_in^i + \frac{n^{k+1}}{k+1}$$
2）$k\notin N \Leftrightarrow k = l + \varepsilon$ 其中 $l\in N, 0\lt \varepsilon \lt 1$。则有
$$S_n^{(l)}=S_1^{(l)}+k\ast(k-1)\ast\cdots\ast(1+\varepsilon)\sum_{i=1}^ni^\varepsilon \gt S_1^{(l)}+k\ast(k-1)\ast\cdots\ast(1+\varepsilon)n^\varepsilon \Rightarrow S_n = \sum_{i=0}^la_in^i + \frac{n^{k+1}}{k+1}$$

由定理 3-1、3-3 和 3-5 得到 E5 成立。


16\. 证明图 3-8 的推理规则 I1~I6。

17\. 下面的推理规则哪一个是正确的？为什么？
1）$\{f(n)=O(F(n)),g(n)=O(G(n))\} \rightarrow f(n)/g(n) = O(F(n)G(n))$
2）$\{f(n)=O(F(n)),g(n)=O(G(n))\} \rightarrow f(n)/g(n) = \Omega(F(n)G(n))$
3）$\{f(n)=O(F(n)),g(n)=O(G(n))\} \rightarrow f(n)/g(n) = \Theta(F(n)G(n))$
4）$\{f(n)=\Omega(F(n)),g(n)=\Omega(G(n))\} \rightarrow f(n)/g(n) = \Omega(F(n)G(n))$
5）$\{f(n)=\Omega(F(n)),g(n)=\Omega(G(n))\} \rightarrow f(n)/g(n) = O(F(n)G(n))$
6）$\{f(n)=\Omega(F(n)),g(n)=\Omega(G(n))\} \rightarrow f(n)/g(n) = \Theta(F(n)G(n))$
7）$\{f(n)=\Theta(F(n)),g(n)=\Theta(G(n))\} \rightarrow f(n)/g(n) = \Theta(F(n)G(n))$
8）$\{f(n)=\Theta(F(n)),g(n)=\Theta(G(n))\} \rightarrow f(n)/g(n) = \Omega(F(n)G(n))$
9）$\{f(n)=\Theta(F(n)),g(n)=\Theta(G(n))\} \rightarrow f(n)/g(n) = O(F(n)G(n))$
